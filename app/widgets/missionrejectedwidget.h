#ifndef MISSIONREJECTEDWIDGET_H
#define MISSIONREJECTEDWIDGET_H

#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

class MissionRejectedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MissionRejectedWidget(QWidget *parent = 0);
    void launch(int millisecondsToShutdown);

signals:
    void countdownFinished();

private:
    void setupUi();
    void setupAnimationLabel();

    void setupTimer();

    QTimer _countdown;

    QLabel *_animationLabel = nullptr;
};
#endif // MISSIONREJECTEDWIDGET_H
