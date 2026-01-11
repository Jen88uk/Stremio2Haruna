#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include <QDoubleSpinBox>
#include <QPushButton>

class ConfigDialog : public QDialog {
  Q_OBJECT

public:
  explicit ConfigDialog(QWidget *parent = nullptr);
  ~ConfigDialog();

  // Getters return milliseconds (internal storage format)
  int getPollingRateMs() const;
  int getLaunchDelayMs() const;

  // Setters accept milliseconds and convert to seconds for display
  void setPollingRateMs(int ms);
  void setLaunchDelayMs(int ms);

private:
  QDoubleSpinBox *m_pollingRateSpinBox;
  QDoubleSpinBox *m_launchDelaySpinBox;
  QPushButton *m_saveButton;
  QPushButton *m_cancelButton;
};

#endif // CONFIGDIALOG_H
