#ifndef KEVININFOWIDGET_H
#define KEVININFOWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

class KevinInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KevinInfoWidget(QWidget *parent = 0);


private:
    void setupUi();

    QLabel *_messageLabel;
};

#endif // KEVININFOWIDGET_H
