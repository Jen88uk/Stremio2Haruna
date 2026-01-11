#include "configdialog.h"
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLabel>
#include <QVBoxLayout>

ConfigDialog::ConfigDialog(QWidget *parent)
    : QDialog(parent), m_pollingRateSpinBox(new QDoubleSpinBox(this)),
      m_launchDelaySpinBox(new QDoubleSpinBox(this)) {

  setWindowTitle("Stremio2Haruna Settings");
  setModal(true);
  setMinimumWidth(350);

  // Create main layout
  QVBoxLayout *mainLayout = new QVBoxLayout(this);

  // Create form layout for settings
  QFormLayout *formLayout = new QFormLayout();

  // Configure polling rate spin box
  m_pollingRateSpinBox->setRange(0.5, 10.0);
  m_pollingRateSpinBox->setSingleStep(0.1);
  m_pollingRateSpinBox->setDecimals(1);
  m_pollingRateSpinBox->setSuffix(" s");
  m_pollingRateSpinBox->setValue(3.5); // Default
  formLayout->addRow("Clipboard Polling Rate:", m_pollingRateSpinBox);

  // Configure launch delay spin box
  m_launchDelaySpinBox->setRange(0.0, 10.0);
  m_launchDelaySpinBox->setSingleStep(0.1);
  m_launchDelaySpinBox->setDecimals(1);
  m_launchDelaySpinBox->setSuffix(" s");
  m_launchDelaySpinBox->setValue(2.5); // Default
  formLayout->addRow("Launch Delay:", m_launchDelaySpinBox);

  mainLayout->addLayout(formLayout);

  // Add some spacing
  mainLayout->addSpacing(10);

  // Create dialog buttons
  QDialogButtonBox *buttonBox = new QDialogButtonBox(
      QDialogButtonBox::Save | QDialogButtonBox::Cancel, Qt::Horizontal, this);
  connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
  connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

  mainLayout->addWidget(buttonBox);

  setLayout(mainLayout);
}

ConfigDialog::~ConfigDialog() {}

int ConfigDialog::getPollingRateMs() const {
  // Convert seconds to milliseconds
  return static_cast<int>(m_pollingRateSpinBox->value() * 1000);
}

int ConfigDialog::getLaunchDelayMs() const {
  // Convert seconds to milliseconds
  return static_cast<int>(m_launchDelaySpinBox->value() * 1000);
}

void ConfigDialog::setPollingRateMs(int ms) {
  // Convert milliseconds to seconds for display
  m_pollingRateSpinBox->setValue(ms / 1000.0);
}

void ConfigDialog::setLaunchDelayMs(int ms) {
  // Convert milliseconds to seconds for display
  m_launchDelaySpinBox->setValue(ms / 1000.0);
}
