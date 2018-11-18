#ifndef MISSIONREJECTEDWIDGET_H
#define MISSIONREJECTEDWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

class MissionRejectedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MissionRejectedWidget(QWidget *parent = 0);


private:
    void setupUi();

    QLabel *_messageLabel;
};
#endif // MISSIONREJECTEDWIDGET_H
