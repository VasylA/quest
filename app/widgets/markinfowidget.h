#ifndef MARKINFOWIDGET_H
#define MARKINFOWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

class MarkInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MarkInfoWidget(QWidget *parent = 0);


private:
    void setupUi();

    static QString markDescription;

    QLabel *_messageLabel;
};
#endif // MARKINFOWIDGET_H
