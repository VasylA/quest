#include "mainwindow.h"

#include "settingsmanager.h"
#include "widgets/introwidget.h"
#include "widgets/kevininfowidget.h"
#include "widgets/markinfowidget.h"
#include "widgets/missioninfowidget.h"
#include "widgets/missionacceptedwidget.h"
#include "widgets/missionrejectedwidget.h"

#include <QPalette>
#include <QtWidgets>
#include <QApplication>
#include <QLinearGradient>

#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>


QString MainWindow::settingsFilePath = "";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _missionStatus(MS_Intro)
    , _stackedWidget(nullptr)
    , _introWidget(new IntroWidget)
    , _kevinInfoWidget(new KevinInfoWidget)
    , _markInfoWidget(new MarkInfoWidget)
    , _missionInfoWidget(new MissionInfoWidget)
    , _missionAcceptedWidget(new MissionAcceptedWidget)
    , _missionRejectedWidget(new MissionRejectedWidget)
    , _soundPlayer(new QMediaPlayer(this))
{
    settingsFilePath = QApplication::applicationDirPath() + "/config.xml";

    loadSettingsFromFile();

    setupWindow();
    setupWidgets();

    initSoundPlayer();
    initTimer();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initTimer()
{
    _popupTimer.setInterval(_settingsContainer.windowPopupPeriod);
    _popupTimer.setSingleShot(true);

    connect(&_popupTimer, QTimer::timeout, this, &MainWindow::popup);

    _popupTimer.start(_settingsContainer.windowPopupPeriod);
}

void MainWindow::initSoundPlayer()
{
    _soundPlayer->setVolume(80);
}

void MainWindow::setupWindow()
{
    QLinearGradient bgGradient;
    bgGradient.setStart(0, 0);
    bgGradient.setFinalStop(0, 1);
    bgGradient.setColorAt(0.0, QColor(30, 30, 30));
    bgGradient.setColorAt(0.7, QColor(30, 30, 30));
    bgGradient.setColorAt(1.0, QColor(250, 150, 0));
    bgGradient.setCoordinateMode(QGradient::StretchToDeviceMode);

    QPalette colorScheme(palette());
    colorScheme.setBrush(QPalette::Background, bgGradient);

    setAutoFillBackground(true);
    setPalette(colorScheme);

    QRect availableScreenRect = qApp->primaryScreen()->availableGeometry();
    auto width = 750;
    auto height = 550;
    auto x = (availableScreenRect.width() - width) / 2;
    auto y = (availableScreenRect.height() - height) / 2;

    setGeometry(x, y, width, height);
    setFixedSize(width, height);

    setWindowTitle(tr("Захищений канал"));
}

void MainWindow::setupWidgets()
{
    _buttonNext = new QPushButton(tr("Прочитати"));
    _buttonNext->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 100, 0); font-weight: bold;"));
    _buttonNext->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    _buttonNext->setMinimumSize(QSize(150, 50));
    _buttonNext->setGeometry(this->rect().center().x() - 200, _buttonNext->y(), 150, 50);
    connect(_buttonNext, &QPushButton::clicked, this, &MainWindow::reactOnNextPressed);

    _buttonBack = new QPushButton(tr("Закрити"));
    _buttonBack->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 100, 0); font-weight: bold;"));
    _buttonBack->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    _buttonBack->setMinimumSize(QSize(150, 50));
    _buttonBack->setGeometry(this->rect().center().x() + 200, _buttonNext->y(), 150, 50);
    connect(_buttonBack, &QPushButton::clicked, this, &MainWindow::reactOnBackPressed);

    QHBoxLayout *controlLayout = new QHBoxLayout;
    controlLayout->setSpacing(50);
    controlLayout->setContentsMargins(0, 0, 0, 0);
    controlLayout->addItem(new QSpacerItem(175, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    controlLayout->addWidget(_buttonBack);
    controlLayout->addItem(new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    controlLayout->addWidget(_buttonNext);
    controlLayout->addItem(new QSpacerItem(175, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));

    QWidget *controlWidget = new QWidget;
    controlWidget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
    controlWidget->setLayout(controlLayout);

    setupStackedWidget();

    QVBoxLayout *centralFrameLayout = new QVBoxLayout();
    centralFrameLayout->setSpacing(0);
    centralFrameLayout->setContentsMargins(0, 0, 0, 0);

    /* Setup central widget */
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(centralFrameLayout);

    centralWidget->layout()->addWidget(_stackedWidget);
    centralWidget->layout()->addWidget(controlWidget);

    setCentralWidget(centralWidget);
}

void MainWindow::setupStackedWidget()
{
    _stackedWidget = new QStackedWidget;

    _introWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _stackedWidget->addWidget(_introWidget);

    _kevinInfoWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _stackedWidget->addWidget(_kevinInfoWidget);

    _markInfoWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _stackedWidget->addWidget(_markInfoWidget);

    _missionInfoWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _stackedWidget->addWidget(_missionInfoWidget);

    _missionAcceptedWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _stackedWidget->addWidget(_missionAcceptedWidget);
    connect(_missionAcceptedWidget, &MissionAcceptedWidget::countdownFinished, this, &MainWindow::close);

    _missionRejectedWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _stackedWidget->addWidget(_missionRejectedWidget);
    connect(_missionRejectedWidget, &MissionRejectedWidget::countdownFinished, this, &MainWindow::close);

    _stackedWidget->setCurrentWidget(_introWidget);
}

void MainWindow::switchToKevinInfo()
{
    _missionStatus = MS_KevinInfo;

    _stackedWidget->setCurrentWidget(_kevinInfoWidget);

    _buttonNext->setText(tr("Далі >"));
    _buttonNext->show();

    _buttonBack->setText(tr("Закрити"));
    _buttonBack->show();


    bool isMediaPlaying = (_soundPlayer->state() == QMediaPlayer::PlayingState);
    if (!isMediaPlaying)
    {
        _soundPlayer->setMedia(QUrl("qrc:/sounds/main_theme.mp3"));
        _soundPlayer->play();
    }
}

void MainWindow::switchToMarkInfo()
{
    _missionStatus = MS_MarkInfo;

    _stackedWidget->setCurrentWidget(_markInfoWidget);

    _buttonNext->setText(tr("Далі >"));
    _buttonNext->show();

    _buttonBack->setText(tr("< Назад"));
    _buttonBack->show();
}

void MainWindow::switchToMissionInfo()
{
    _missionStatus = MS_MissionInfo;

    _stackedWidget->setCurrentWidget(_missionInfoWidget);

    _buttonNext->setText(tr("Погодитися"));
    _buttonNext->show();

    _buttonBack->setText(tr("Відхилити"));
    _buttonBack->show();
}

void MainWindow::switchToMissionAccepted()
{
    _soundPlayer->stop();

    _missionStatus = MS_MissionAccepted;

    _stackedWidget->setCurrentWidget(_missionAcceptedWidget);
    _missionAcceptedWidget->launch(_settingsContainer.shutdownPeriod);

    _buttonBack->hide();
    _buttonNext->hide();

    _soundPlayer->setMedia(QUrl("qrc:/sounds/clock.mp3"));
    _soundPlayer->play();
}

void MainWindow::switchToMissionRejected()
{
    _soundPlayer->stop();

    _missionStatus = MS_MissionRejected;

    _stackedWidget->setCurrentWidget(_missionRejectedWidget);
    _missionRejectedWidget->launch(_settingsContainer.shutdownPeriod);

    _buttonBack->hide();
    _buttonNext->hide();

    _soundPlayer->setMedia(QUrl("qrc:/sounds/reject_sound.mp3"));
    _soundPlayer->play();
}

void MainWindow::reactOnNextPressed()
{
    switch (_missionStatus)
    {
    case MS_Intro:
        switchToKevinInfo();
        return;

    case MS_KevinInfo:
        switchToMarkInfo();
        return;

    case MS_MarkInfo:
        switchToMissionInfo();
        return;

    case MS_MissionInfo:
        switchToMissionAccepted();
        return;

    default:
        return;
    }
}

void MainWindow::reactOnBackPressed()
{
    switch (_missionStatus)
    {
    case MS_Intro:
        close();
        return;

    case MS_MarkInfo:
        switchToKevinInfo();
        return;

    case MS_KevinInfo:
    case MS_MissionInfo:
        switchToMissionRejected();
        break;

    default:
        break;
    }
}

void MainWindow::loadSettingsFromFile()
{
    SettingsManager missionSettingsManager;
    if (missionSettingsManager.loadSettings(settingsFilePath))
        _settingsContainer = missionSettingsManager.settings();
}

void MainWindow::popup()
{
    show();

    setWindowState(Qt::WindowMinimized);
}

