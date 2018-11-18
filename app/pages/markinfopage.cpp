#include "markinfopage.h"

MarkInfoPage::MarkInfoPage(QWidget *parent)
    : QWizardPage(parent)
{

}

int MarkInfoPage::nextId() const
{
    return MissionWizard::Page_MissionInfo;
}
