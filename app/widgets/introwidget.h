#ifndef INTROWIDGET_H
#define INTROWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

class IntroWidget : public QWidget
{
    Q_OBJECT
public:
    explicit IntroWidget(QWidget *parent = 0);


private:
    void setupUi();

    QLabel *_messageLabel;
};

#endif // INTROWIDGET_H
