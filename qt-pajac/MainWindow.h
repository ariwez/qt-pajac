#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QMainWindow>
#include <QMenu>
#include <QSystemTrayIcon>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void quit();

    void on_pushButton_clicked();

    void trayTriggered();

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon tray;
    QMenu trayMenu;
    QAction *quitAction;
};

#endif // MAINWINDOW_H
