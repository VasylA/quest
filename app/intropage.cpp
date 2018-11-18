#include "intropage.h"

IntroPage::IntroPage(QWidget *parent)
    : QWizardPage(parent)
{
    setButtonText(QWizard::NextButton, tr("Прочитати"));
    setButtonText(QWizard::CancelButton, tr("Закрити"));
}

int IntroPage::nextId() const
{
    return MissionWizard::Page_KevinInfo;
}
