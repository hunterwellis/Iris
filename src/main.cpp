#include <QApplication>
#include <QDebug>

#include "ui/main_window.hpp"

int main(int argc, char * argv[]){
    QApplication app(argc, argv);

    MainWindow w;
    w.showFullScreen();

    return app.exec();
}

