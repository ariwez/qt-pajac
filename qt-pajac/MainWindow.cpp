#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QDesktopServices>
#include <QMessageBox>
#include <QUrl>

const QString url = "http://www.pah.org.pl/nasze-dzialania/8/pajacyk";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    setWindowModality(Qt::ApplicationModal);

    quitAction = new QAction(tr("Koniec"), this);
    connect(quitAction, SIGNAL(triggered()), this, SLOT(quit()));

    connect(&tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(trayTriggered()));

    trayMenu.addAction(quitAction);
    tray.setIcon(QIcon(":images/off"));
    tray.setContextMenu(&trayMenu);
    tray.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::quit()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_clicked()
{
    if (false == QDesktopServices::openUrl(QUrl(url))) {
        qWarning() << "Couldn't open link: " << url;
        QMessageBox::critical(0, "The horror!", "Nie mogę uruchomić domyślnej przeglądarki, upewnij się że takową posiadasz :|");
    }

    this->close();
}

void MainWindow::trayTriggered()
{
    if (this->isVisible()) {
        this->close();
    } else {
        this->show();
    }
}
