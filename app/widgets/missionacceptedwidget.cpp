#include "missionacceptedwidget.h"

#include <QtMath>
#include <QLabel>
#include <QMovie>
#include <QHBoxLayout>

MissionAcceptedWidget::MissionAcceptedWidget(QWidget *parent)
    : QWidget(parent)
    , _animationLabel(new QLabel)
    , _messageLabel(new QLabel)
    , _remainingTimeLabel(new QLabel)
    , _goodLuckLabel(new QLabel)
{
    setupUi();

    setupTimer();
}

void MissionAcceptedWidget::launch(int millisecondsToShutdown)
{
    _countdown.start(millisecondsToShutdown);
    updateTimeDisplay();
}

void MissionAcceptedWidget::blinkTimeDisplay()
{
    QPalette colorScheme(_remainingTimeLabel->palette());
    colorScheme.setBrush(QPalette::WindowText, Qt::transparent);
    _remainingTimeLabel->setPalette(colorScheme);
}

void MissionAcceptedWidget::updateTimeDisplay()
{
    static const int millisecondsPerSecond = 1000;

    int remainingTime = _countdown.remainingTime() / millisecondsPerSecond;
    QString secondsStr = "секунд";
    if ((remainingTime < 5) && (remainingTime > 1))
        secondsStr = "секунди";
    else if (remainingTime == 1)
        secondsStr = "секунду";

    QString timeString = QString("<p><b>%0</b> %1</p>").arg(remainingTime).arg(secondsStr);
    _remainingTimeLabel->setText(timeString);

    qreal nom = (qreal)millisecondsPerSecond * remainingTime;
    qreal den = _countdown.remainingTime();

    int greenChanel = 150 * qPow(nom / den, 3.0);  //[0-255]
    int blueChanel = 0;
    int redChanel = 255;
    QColor textColor = QColor(redChanel, greenChanel, blueChanel);

    QPalette colorScheme(_remainingTimeLabel->palette());
    colorScheme.setBrush(QPalette::WindowText, textColor);
    _remainingTimeLabel->setPalette(colorScheme);

    QTimer::singleShot(1000, this, SLOT(updateTimeDisplay()));
    if (remainingTime < 6)
        QTimer::singleShot(500, this, SLOT(blinkTimeDisplay()));
}

void MissionAcceptedWidget::setupUi()
{
    setupAnimationLabel();
    setupMessageLabel();
    setupTimeLabel();
    setupGoodLuckLabel();

    QLayout *centralLayout = new QVBoxLayout;
    centralLayout->addWidget(_animationLabel);
    centralLayout->addWidget(_messageLabel);
    centralLayout->addWidget(_remainingTimeLabel);
    centralLayout->addWidget(_goodLuckLabel);
    setLayout(centralLayout);
}

void MissionAcceptedWidget::setupAnimationLabel()
{
    _animationLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    _animationLabel->setAlignment(Qt::AlignHCenter);

    QMovie *movie = new QMovie("://animations/mission.gif");
    movie->setScaledSize(QSize(width(), 2 * width() / 5));
    _animationLabel->setMovie(movie);
    movie->start();
}

void MissionAcceptedWidget::setupMessageLabel()
{
    _messageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _messageLabel->setAlignment(Qt::AlignHCenter);

    QString labelText = "Це послання знищиться через";
    QString labelHtml = QString("<p style='color: orange; font-size: 24px; font-family:monospace'>%1</p>")
            .arg(labelText);

    _messageLabel->setText(labelHtml);
    _messageLabel->setWordWrap(true);
}

void MissionAcceptedWidget::setupTimeLabel()
{
    _remainingTimeLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _remainingTimeLabel->setAlignment(Qt::AlignHCenter);

    QFont labelFont = _remainingTimeLabel->font();
    labelFont.setPixelSize(height() / 7);
    labelFont.setFamily("Verdana");
    _remainingTimeLabel->setFont(labelFont);
}

void MissionAcceptedWidget::setupGoodLuckLabel()
{
    _goodLuckLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _goodLuckLabel->setAlignment(Qt::AlignHCenter);

    QString goodLuckText = "Щасти!";
    QString goodLuckHtml = QString("<p style='color: orange; font-size: 24px; font-family:monospace'>%1</p>")
            .arg(goodLuckText);

    _goodLuckLabel->setText(goodLuckHtml);
}

void MissionAcceptedWidget::setupTimer()
{
    _countdown.setSingleShot(true);

    connect(&_countdown, SIGNAL(timeout()), this, SIGNAL(countdownFinished()));
}
