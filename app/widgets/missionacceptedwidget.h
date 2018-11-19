#ifndef MISSIONACCEPTEDWIDGET_H
#define MISSIONACCEPTEDWIDGET_H

#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

class MissionAcceptedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MissionAcceptedWidget(QWidget *parent = 0);
    void launch(int secondsToShutdown);

signals:
    void countdownFinished();


private slots:
    void blinkTimeDisplay();
    void updateTimeDisplay();

private:
    void setupUi();
    void setupAnimationLabel();
    void setupMessageLabel();
    void setupTimeLabel();
    void setupGoodLuckLabel();

    void setupTimer();

    QTimer _countdown;

    QLabel *_animationLabel = nullptr;
    QLabel *_messageLabel = nullptr;
    QLabel *_remainingTimeLabel = nullptr;
    QLabel *_goodLuckLabel = nullptr;
};
#endif // MISSIONACCEPTEDWIDGET_H
