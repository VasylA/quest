#include "missioninfopage.h"

#include <QtWidgets>

MissionInfoPage::MissionInfoPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(tr("Complete Your Registration"));
    setPixmap(QWizard::WatermarkPixmap, QPixmap(":/images/watermark.png"));

    bottomLabel = new QLabel;
    bottomLabel->setWordWrap(true);

    agreeCheckBox = new QCheckBox(tr("I agree to the terms of the license"));

    registerField("conclusion.agree*", agreeCheckBox);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(bottomLabel);
    layout->addWidget(agreeCheckBox);
    setLayout(layout);
}

int MissionInfoPage::nextId() const
{
    if (agreeCheckBox->isChecked())
        return MissionWizard::Page_MissionAccepted;
    else
        return MissionWizard::Page_MissionRejected;
}
