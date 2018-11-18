#include "markinfowidget.h"

#include <QLabel>
#include <QHBoxLayout>

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

    const int textPixelSize = height() / 10;
    QString labelText = "Mark";
    QString htmlText = QString("<p style='font-size:%0px; font-family:monospace'><b>%1</b></p>")
            .arg(textPixelSize)
            .arg(labelText);

    _messageLabel->setText(htmlText);
    _messageLabel->setWordWrap(true);

    QLayout *centralLayout = new QHBoxLayout;
    centralLayout->addWidget(_messageLabel);
    setLayout(centralLayout);
}
