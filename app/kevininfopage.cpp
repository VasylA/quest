#include "kevininfopage.h"

KevinInfoPage::KevinInfoPage(QWidget *parent)
    : QWizardPage(parent)
{
    setButtonText(QWizard::NextButton, tr("Далі"));
}

int KevinInfoPage::nextId() const
{
    return MissionWizard::Page_MarkInfo;
}
