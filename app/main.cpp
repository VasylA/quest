#include "missionwizard.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MissionWizard window;

    window.show();

    return app.exec();
}
