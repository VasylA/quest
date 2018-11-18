#include "missionrejectedpage.h"

MissionRejectedPage::MissionRejectedPage(QWidget *parent)
    : QWizardPage(parent)
{

}

int MissionRejectedPage::nextId() const
{
    return MissionWizard::Page_None;
}
