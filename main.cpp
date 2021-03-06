#include "about.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QTranslator>
#include <QDebug>
#include <QStandardPaths>
#include <fcntl.h>
#include <syslog.h>
#include <X11/Xlib.h>


int main(int argc, char *argv[])
{
    Display *display = XOpenDisplay(NULL);
    Screen *scrn = DefaultScreenOfDisplay(display);
    if(scrn == nullptr) {
        return 0;
    }
    int width = scrn->width;
//    QApplication app(argc,argv);
    if (width >= 2560) {
    #if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
        QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
        QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    #endif
    }

    QApplication a(argc, argv);

    //Singleton
    QStringList homePath = QStandardPaths::standardLocations(QStandardPaths::HomeLocation);
    QString lockPath = homePath.at(0) + "/.config/ukui-about";
    int fd = open(lockPath.toUtf8().data(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0) { exit(1); }
    if (lockf(fd, F_TLOCK, 0)) {
        syslog(LOG_ERR, "Can't lock single file, ukui-about is already running!");
        qDebug()<<"Can't lock single file, ukui-about is already running!";
        exit(0);
    }

    //tanslate
    QString locale = QLocale::system().name();
    QTranslator translator;
    if (locale == "zh_CN"){
        if (translator.load("ukui-about_zh_CN.qm", "/usr/share/ukui/"))
            a.installTranslator(&translator);
        else
            qDebug() << "Load translations file" << locale << "failed!";
    }
    About about;
    about.show();
    return a.exec();
}
