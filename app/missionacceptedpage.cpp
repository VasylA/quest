#include "missionacceptedpage.h"

MissionAcceptedPage::MissionAcceptedPage(QWidget *parent)
    : QWizardPage(parent)
{

}

int MissionAcceptedPage::nextId() const
{
    return MissionWizard::Page_None;
}
