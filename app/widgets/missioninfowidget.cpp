#include "missioninfowidget.h"

#include <QLabel>
#include <QHBoxLayout>

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

    const int textPixelSize = height() / 10;
    QString labelText = "Mission info";
    QString htmlText = QString("<p style='font-size:%0px; font-family:monospace'><b>%1</b></p>")
            .arg(textPixelSize)
            .arg(labelText);

    _messageLabel->setText(htmlText);
    _messageLabel->setWordWrap(true);

    QLayout *centralLayout = new QHBoxLayout;
    centralLayout->addWidget(_messageLabel);
    setLayout(centralLayout);
}
