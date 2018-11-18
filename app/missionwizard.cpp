#include "missionwizard.h"

#include "pages/intropage.h"
#include "pages/kevininfopage.h"
#include "pages/markinfopage.h"
#include "pages/missioninfopage.h"
#include "pages/missionacceptedpage.h"
#include "pages/missionrejectedpage.h"

#include "settingsmanager.h"

#include <QPalette>
#include <QtWidgets>
#include <QApplication>
#include <QLinearGradient>

#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>

#include <stdlib.h>

QString MissionWizard::settingsFilePath = "";
QString MissionWizard::soundsDirPath = "";
QString MissionWizard::imagesDirPath = "";

MissionWizard::MissionWizard(QWidget *parent)
    : QWizard(parent)
{
    settingsFilePath = QApplication::applicationDirPath() + "/config.xml";
    soundsDirPath = QApplication::applicationDirPath() + "/sounds/";
    imagesDirPath = QApplication::applicationDirPath() + "/images/";

    setupWindowStyle();
    setupPages();

    initSoundPlayer();
}

MissionWizard::~MissionWizard()
{
}

void MissionWizard::initSoundPlayer()
{
}

void MissionWizard::setupWindowStyle()
{
    QLinearGradient bgGradient;
    bgGradient.setStart(0, 0);
    bgGradient.setFinalStop(0, 1);
    bgGradient.setColorAt(0.0, QColor(150, 150, 200));
    bgGradient.setColorAt(0.2, QColor(150, 100, 200));
    bgGradient.setColorAt(1.0, QColor(150, 100, 150));
    bgGradient.setCoordinateMode(QGradient::StretchToDeviceMode);

    QPalette colorScheme(palette());
    colorScheme.setBrush(QPalette::Background, bgGradient);

    setAutoFillBackground(true);
    setPalette(colorScheme);

    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

    setWindowTitle(tr("Захищений канал"));
}

void MissionWizard::setupPages()
{
    setPage(Page_Intro,           new IntroPage);
    setPage(Page_KevinInfo,       new KevinInfoPage);
    setPage(Page_MarkInfo,        new MarkInfoPage);
    setPage(Page_MissionInfo,     new MissionInfoPage);
    setPage(Page_MissionAccepted, new MissionAcceptedPage);
    setPage(Page_MissionRejected, new MissionRejectedPage);
    setPage(Page_None,            new QWizardPage);

    setStartId(Page_Intro);

    setOption(NoBackButtonOnStartPage, true);
    setOption(NoBackButtonOnLastPage, true);
    setOption(NoCancelButtonOnLastPage, true);

    button(QWizard::BackButton)->hide();
    button(QWizard::FinishButton)->hide();

    setWizardStyle(NStyles);
}
