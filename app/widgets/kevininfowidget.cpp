#include "kevininfowidget.h"

#include <QLabel>
#include <QHBoxLayout>

QString KevinInfoWidget::kevinDescription =
        "Ваш об'єкт - Кевін Спейсі - успішний бізнесмен та плейбой. \
        Мало кому відомо, але він веде подвійне життя. Ходять чутки, \
        що ось уже 10 років він очолює злочинне угрупування під назвою \
        Ліга Несправедливості. Ліга займається грабежем, залякуванням \
        та контрабандою. У кримінальному світі Кевін відомий як Лекс \
        Лютер. Стало відомо, що останням часом він почав активно \
        скуповувати акції Boing та інших відомих компаній. Також його \
        пов'язують з викраденням кількох вчених - працівників SpaceX, \
        що трацюють у тактичному відділі компанії";

KevinInfoWidget::KevinInfoWidget(QWidget *parent)
    : QWidget(parent)
    , _messageLabel(new QLabel)
{
    setupUi();
}

void KevinInfoWidget::setupUi()
{
    _messageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _messageLabel->setAlignment(Qt::AlignCenter);

    const int textPixelSize = height() / 25;
    QString labelText = kevinDescription;;
    QString htmlText = QString("<p style='font-size:%0px; font-family:monospace'><b>%1</b></p>")
            .arg(textPixelSize)
            .arg(labelText);

    _messageLabel->setText(htmlText);
    _messageLabel->setWordWrap(true);

    QLayout *centralLayout = new QHBoxLayout;
    centralLayout->addWidget(_messageLabel);
    setLayout(centralLayout);
}
