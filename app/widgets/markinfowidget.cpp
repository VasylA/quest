#include "markinfowidget.h"

#include <QLabel>
#include <QHBoxLayout>

 QString MarkInfoWidget::markDescription =
        "Брат Кевіна - Марк - широковідомий у вузьких кругах наркобарон. \
        Є інформація, що саме в нього у лігві тримають зниклих вчених \
        для того щоб вивідати конфіденційну державну інформацію.";

MarkInfoWidget::MarkInfoWidget(QWidget *parent)
    : QWidget(parent)
    , _messageLabel(new QLabel)
{
    setupUi();
}

void MarkInfoWidget::setupUi()
{
    _messageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _messageLabel->setAlignment(Qt::AlignCenter);

    const int textPixelSize = height() / 25;
    QString labelText = markDescription;
    QString htmlText = QString("<p style='font-size:%0px; font-family:monospace'><b>%1</b></p>")
            .arg(textPixelSize)
            .arg(labelText);

    _messageLabel->setText(htmlText);
    _messageLabel->setWordWrap(true);

    QLayout *centralLayout = new QHBoxLayout;
    centralLayout->addWidget(_messageLabel);
    setLayout(centralLayout);
}
