#include "MainWindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    QApplication::setQuitOnLastWindowClosed(false);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    QRect screen = QApplication::desktop()->availableGeometry(&window);

    // move to right-bottom corner
    window.move(screen.right() - window.width(), screen.bottom() - window.height());
    
    return app.exec();
}
