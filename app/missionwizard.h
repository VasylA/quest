#ifndef MISSIONWIZARD_H
#define MISSIONWIZARD_H

#include "settingscontainer.h"

#include <QWizard>

QT_BEGIN_NAMESPACE
class QMediaPlayer;
QT_END_NAMESPACE


class MissionWizard : public QWizard
{
    Q_OBJECT

public:
    enum
    {
        Page_Intro,
        Page_KevinInfo,
        Page_MarkInfo,
        Page_MissionInfo,
        Page_MissionAccepted,
        Page_MissionRejected,
        Page_None
    };

    MissionWizard(QWidget *parent = 0);
    ~MissionWizard();

private:
    void initSoundPlayer();

    void setupWindowStyle();
    void setupPages();

private:
    static QString settingsFilePath;
    static QString soundsDirPath;
    static QString imagesDirPath;

    SettingsContainer _settingsContainer;
};

#endif // MISSIONWIZARD_H
