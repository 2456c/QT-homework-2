#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // 加载样式表
    QFile styleFile(":/style.qss");
    if(styleFile.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(styleFile.readAll());
        a.setStyleSheet(styleSheet);
        styleFile.close();
    } else {
        // 直接从文件路径加载
        QFile directFile("style.qss");
        if(directFile.open(QFile::ReadOnly)) {
            QString styleSheet = QLatin1String(directFile.readAll());
            a.setStyleSheet(styleSheet);
            directFile.close();
        }
    }
    
    MainWindow w;
    w.show();
    return a.exec();
}
