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
    void setupWindow();
    void setupWidgets();
    void setupStackedWidget();

    void switchToKevinInfo();
    void switchToMarkInfo();
    void switchToMissionInfo();
    void switchToMissionAccepted();
    void switchToMissionRejected();

private slots:
    void reactOnNextPressed();
    void reactOnBackPressed();

private:
    MissionStatus _missionStatus;

    QStackedWidget *_stackedWidget;

    IntroWidget    *_introWidget;
    KevinInfoWidget *_kevinInfoWidget;
    MarkInfoWidget *_markInfoWidget;
    MissionInfoWidget *_missionInfoWidget;
    MissionAcceptedWidget *_missionAcceptedWidget;
    MissionRejectedWidget *_missionRejectedWidget;

    QPushButton    *_buttonNext;
    QPushButton    *_buttonBack;
};

#endif // MAINWINDOW_H
