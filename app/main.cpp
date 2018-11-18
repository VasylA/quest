#include "missionwizard.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
//    MissionWizard window;
    MainWindow window;

    window.show();

    return app.exec();
}
