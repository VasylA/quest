#ifndef MISSIONINFOWIDGET_H
#define MISSIONINFOWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

class MissionInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MissionInfoWidget(QWidget *parent = 0);


private:
    void setupUi();

    static QString missionDescription;

    QLabel *_messageLabel;
};
#endif // MISSIONINFOWIDGET_H
