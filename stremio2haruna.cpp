#include "stremio2haruna.h"
#include <QApplication>
#include <QDBusConnection>
#include <QDBusInterface>
#include <QDBusReply>
#include <QDebug>
#include <QProcess>
#include <QThread>
#include <QTimer>
#include <QUrl>

Stremio2Haruna::Stremio2Haruna(QObject *parent)
    : QObject(parent), m_trayIcon(nullptr), m_trayMenu(nullptr),
      m_enabledAction(nullptr), m_quitAction(nullptr),
      m_clipboard(QApplication::clipboard()), m_enabled(true),
      m_clipboardTimer(new QTimer(this)), m_lastClipboardText(""),
      m_harunaProcess(nullptr) {
  setupSystemTray();

  connect(m_clipboard, &QClipboard::dataChanged, this,
          &Stremio2Haruna::onClipboardChanged);
  connect(m_clipboard, &QClipboard::selectionChanged, this,
          &Stremio2Haruna::onClipboardChanged);

  connect(m_clipboardTimer, &QTimer::timeout, this,
          &Stremio2Haruna::checkClipboard);
  m_clipboardTimer->start(3500); // Poll every 3.5 seconds
}

Stremio2Haruna::~Stremio2Haruna() { delete m_trayIcon; }

void Stremio2Haruna::setupSystemTray() {
  // Create system tray icon
  m_trayIcon = new QSystemTrayIcon(this);
  m_trayIcon->setIcon(QIcon(QStringLiteral(":/icons/Stremio2Haruna.png")));

  // Create menu
  m_trayMenu = new QMenu();

  // Enabled/Disabled toggle
  m_enabledAction = new QAction("Enabled", this);
  m_enabledAction->setCheckable(true);
  m_enabledAction->setChecked(m_enabled);
  connect(m_enabledAction, &QAction::triggered, this,
          &Stremio2Haruna::onToggleEnabled);

  // Quit action
  m_quitAction = new QAction("Quit", this);
  connect(m_quitAction, &QAction::triggered, this, &Stremio2Haruna::onQuit);

  // Add actions to menu
  m_trayMenu->addAction(m_enabledAction);
  m_trayMenu->addSeparator();
  m_trayMenu->addAction(m_quitAction);

  // Set menu to tray icon
  m_trayIcon->setContextMenu(m_trayMenu);

  // Show the tray icon
  m_trayIcon->show();
}

void Stremio2Haruna::onClipboardChanged() {

  // Only proceed if enabled
  if (!m_enabled) {
    return;
  }

  // Get clipboard text
  QString clipboardText = m_clipboard->text();

  // Check if clipboard contains a valid URL
  if (!isValidUrl(clipboardText)) {
    return;
  }

  // Check if Stremio is the active window
  bool stremioActive = isStremioActive();

  if (!stremioActive) {
    return;
  }

  // Wait 2.5 seconds before launching Haruna
  QThread::msleep(2500);

  launchHaruna(clipboardText);
}

void Stremio2Haruna::onToggleEnabled(bool enabled) {
  m_enabled = enabled;

  // Optionally change the tray icon to indicate state
  if (m_enabled) {
    m_trayIcon->setIcon(QIcon::fromTheme("media-playback-start"));
  } else {
    m_trayIcon->setIcon(QIcon::fromTheme("media-playback-pause"));
  }
}

void Stremio2Haruna::onQuit() { QApplication::quit(); }

bool Stremio2Haruna::isStremioActive() {
  // Check if Stremio is running (not necessarily focused)
  // This is more reliable with delayed clipboard polling
  QProcess process;
  process.start("kdotool", QStringList() << "search" << "--class"
                                         << "com.stremio.stremio");
  process.waitForFinished(500);

  QString output = QString::fromUtf8(process.readAllStandardOutput()).trimmed();

  bool stremioRunning = !output.isEmpty();

  return stremioRunning;
}

bool Stremio2Haruna::isValidUrl(const QString &text) {
  if (text.isEmpty()) {
    return false;
  }

  QUrl url(text);

  // Check if it's a valid URL with a scheme
  if (!url.isValid() || url.scheme().isEmpty()) {
    return false;
  }

  // Check for common URL schemes
  QStringList validSchemes = {"http", "https", "ftp", "ftps",
                              "rtmp", "rtsp",  "mms", "mmsh"};

  bool schemeValid = validSchemes.contains(url.scheme().toLower());

  return schemeValid;
}

void Stremio2Haruna::launchHaruna(const QString &url) {
  // Launch Haruna and keep track of the process
  if (m_harunaProcess) {
    delete m_harunaProcess;
  }

  m_harunaProcess = new QProcess(this);
  connect(m_harunaProcess,
          QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this,
          [this]() {
            // Haruna closed, resume clipboard monitoring
            m_clipboardTimer->start(3500);
          });

  m_harunaProcess->start("haruna", QStringList() << url);
}

void Stremio2Haruna::checkClipboard() {
  // Poll clipboard with wl-paste
  QProcess process;
  process.start("wl-paste", QStringList() << "-n");
  process.waitForFinished(100);

  QString currentText =
      QString::fromUtf8(process.readAllStandardOutput()).trimmed();

  // Only process if clipboard text has actually changed and is not empty
  if (currentText != m_lastClipboardText && !currentText.isEmpty()) {
    m_lastClipboardText = currentText;

    // Only proceed if enabled
    if (!m_enabled) {
      return;
    }

    // Check if clipboard contains a valid URL
    if (!isValidUrl(currentText)) {
      return;
    }

    // Check if Stremio is running
    bool stremioActive = isStremioActive();

    if (!stremioActive) {
      return;
    }

    // Stop polling to avoid interfering with Haruna fullscreen
    m_clipboardTimer->stop();

    // Wait 2.5 seconds before launching Haruna
    QThread::msleep(2500);

    launchHaruna(currentText);
  }
}
