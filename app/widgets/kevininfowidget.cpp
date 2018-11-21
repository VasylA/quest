#include "kevininfowidget.h"

#include <QLabel>
#include <QHBoxLayout>

QString KevinInfoWidget::kevinDescription =
        "<div> \
            <p><img src=\"://images/kevin.jpg\" align=\"right\" width=\"180\"/></p> \
             <p style='padding-left: 50px; text-indent: 20px; text-align: left; \
                       color: green; font-size: 20px; font-family: monospace'> \
               Ваш об'єкт - Кевін Спейсі - успішний бізнесмен та плейбой. \
               Мало кому відомо, але він веде подвійне життя. Ходять чутки, \
               що ось уже 10 років він очолює злочинне угрупування під назвою \
               Ліга Несправедливості. Ліга займається грабежем, залякуванням \
               та контрабандою. У кримінальному світі Кевін відомий як Лекс \
               Лютер. Стало відомо, що останням часом він почав активно \
               скуповувати акції Boing та інших відомих компаній. Також його \
               пов'язують з викраденням кількох вчених - працівників SpaceX, \
               що трацюють у тактичному відділі компанії \
            </p> \
            <p><img src=\"://images/kevin-team.jpg\" align=\"left\" width=\"250\"/></p> \
        </div>";

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

    _messageLabel->setText(kevinDescription);
    _messageLabel->setWordWrap(true);

    QLayout *centralLayout = new QHBoxLayout;
    centralLayout->addWidget(_messageLabel);
    setLayout(centralLayout);
}
