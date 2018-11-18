#ifndef MISSIONACCEPTEDWIDGET_H
#define MISSIONACCEPTEDWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

class MissionAcceptedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MissionAcceptedWidget(QWidget *parent = 0);


private:
    void setupUi();

    QLabel *_messageLabel;
};
#endif // MISSIONACCEPTEDWIDGET_H
