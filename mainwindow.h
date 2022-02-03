#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

  protected:
    void calculateAge();

  private slots:
    void on_btnInfo_clicked();
    void on_dateBirthday_dateChanged(const QDate& date);
    void on_dateCurrent_dateChanged(const QDate& date);

  private:
    Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
