#include "missioninfowidget.h"

#include <QLabel>
#include <QHBoxLayout>

QString MissionInfoWidget::missionDescription =
        "Твоя місія, якщо ти на неї погодишся, розвідати, що затіває \
        Кевін (він же Лекс Лютер) і затримати його. Почати варто з \
        проникнення у лігво Марка, яке потрібно знайти. Це має бути \
        неважко. Головний орієнтир - великі площі засаджені рослинами. \
        \
        Хай щастить.";


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

    const int textPixelSize = height() / 25;
    QString labelText = missionDescription;
    QString htmlText = QString("<p style='font-size:%0px; font-family:monospace'><b>%1</b></p>")
            .arg(textPixelSize)
            .arg(labelText);

    _messageLabel->setText(htmlText);
    _messageLabel->setWordWrap(true);

    QLayout *centralLayout = new QHBoxLayout;
    centralLayout->addWidget(_messageLabel);
    setLayout(centralLayout);
}
