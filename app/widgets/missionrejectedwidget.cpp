#include "missionrejectedwidget.h"

#include <QLabel>
#include <QMovie>
#include <QHBoxLayout>

MissionRejectedWidget::MissionRejectedWidget(QWidget *parent)
    : QWidget(parent)
    , _animationLabel(new QLabel)
{
    setupUi();
}

void MissionRejectedWidget::setupUi()
{
    setupAnimationLabel();

    QLayout *centralLayout = new QHBoxLayout;
    centralLayout->addWidget(_animationLabel);
    setLayout(centralLayout);
}

void MissionRejectedWidget::setupAnimationLabel()
{
    _animationLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _animationLabel->setAlignment(Qt::AlignHCenter);

    QMovie *movie = new QMovie("://animations/mouse.gif");
    movie->setScaledSize(QSize(width(), 2 * width() / 3));
    _animationLabel->setMovie(movie);
    movie->start();
}
