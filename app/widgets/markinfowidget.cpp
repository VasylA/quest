#include "markinfowidget.h"

#include <QLabel>
#include <QHBoxLayout>

 QString MarkInfoWidget::markDescription =
        "<div> \
            <p><img src=\":/images/mark-620x365.jpg\" align=\"right\" width=\"300\"/></p> \
            <p style='padding-left: 50px; text-indent: 20px; text-align: left; \
                      color: orange; font-size: 20px; font-family: monospace'> \
                 Брат Кевіна - Марк - широковідомий у вузьких кругах наркобарон. \
                 Є інформація, що саме в нього у лігві тримають зниклих вчених \
                 для того щоб вивідати конфіденційну державну інформацію. \
            </p> \
            <p><img src=\":/images/mark2.jpg\" align=\"left\" width=\"300\"/></p> \
        </div>";

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

    _messageLabel->setText(markDescription);
    _messageLabel->setWordWrap(true);

    QLayout *centralLayout = new QHBoxLayout;
    centralLayout->addWidget(_messageLabel);
    setLayout(centralLayout);
}
