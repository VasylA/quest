#include "missioninfowidget.h"

#include <QLabel>
#include <QHBoxLayout>

QString MissionInfoWidget::missionDescription =
        "<div> \
            <p style='padding-left: 50px; text-indent: 20px; text-align: left; \
                      color: green; font-size: 20px; font-family: monospace'> \
                  Твоя місія, якщо ти на неї погодишся, розвідати, що затіває \
                  Кевін (він же Лекс Лютер) і затримати його. Почати варто з \
                  проникнення у лігво Марка, яке потрібно знайти. Це має бути \
                  неважко. Головний орієнтир - великі площі засаджені рослинами. \
            </p> \
            <p><img src=\":/images/drugs.jpg\" align=\"ridht\" width=\"350\"/></p> \
            <p style='padding-left: 50px; text-indent: 20px; text-align: center; \
                      color: green; font-size: 25px; font-family: monospace'> \
                  Хай щастить! \
            </p> \
        </div>";

MissionInfoWidget::MissionInfoWidget(QWidget *parent)
    : QWidget(parent)
    , _messageLabel(new QLabel)
{
    setupUi();
}

void MissionInfoWidget::setupUi()
{
    _messageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _messageLabel->setAlignment(Qt::AlignCenter);

    _messageLabel->setText(missionDescription);
    _messageLabel->setWordWrap(true);

    QLayout *centralLayout = new QHBoxLayout;
    centralLayout->addWidget(_messageLabel);
    setLayout(centralLayout);
}
