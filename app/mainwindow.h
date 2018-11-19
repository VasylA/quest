#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settingscontainer.h"

#include <QMainWindow>
#include <QTimer>

class IntroWidget;
class KevinInfoWidget;
class MarkInfoWidget;
class MissionInfoWidget;
class MissionAcceptedWidget;
class MissionRejectedWidget;

QT_BEGIN_NAMESPACE
class QStackedWidget;
class QPushButton;
class QLabel;
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

    enum MissionStatus
    {
        MS_Intro,
        MS_KevinInfo,
        MS_MarkInfo,
        MS_MissionInfo,
        MS_MissionAccepted,
        MS_MissionRejected
    };

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    void initTimer();

    void setupWindow();
    void setupWidgets();
    void setupStackedWidget();

    void switchToKevinInfo();
    void switchToMarkInfo();
    void switchToMissionInfo();
    void switchToMissionAccepted();
    void switchToMissionRejected();

    void loadSettingsFromFile();

private slots:
    void popup();

    void reactOnNextPressed();
    void reactOnBackPressed();

private:
    static QString settingsFilePath;


    MissionStatus _missionStatus = MS_Intro;

    QStackedWidget *_stackedWidget = nullptr;

    IntroWidget    *_introWidget = nullptr;
    KevinInfoWidget *_kevinInfoWidget = nullptr;
    MarkInfoWidget *_markInfoWidget = nullptr;
    MissionInfoWidget *_missionInfoWidget = nullptr;
    MissionAcceptedWidget *_missionAcceptedWidget = nullptr;
    MissionRejectedWidget *_missionRejectedWidget = nullptr;

    QPushButton    *_buttonNext = nullptr;
    QPushButton    *_buttonBack = nullptr;

    QTimer _popupTimer;

    SettingsContainer _settingsContainer;
};

#endif // MAINWINDOW_H
