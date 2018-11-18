#ifndef MISSIONACCEPTEDPAGE_H
#define MISSIONACCEPTEDPAGE_H

#include "missionwizard.h"

class MissionAcceptedPage : public QWizardPage
{
public:
    MissionAcceptedPage(QWidget *parent = 0);

    int nextId() const Q_DECL_OVERRIDE;
};

#endif // MISSIONACCEPTEDPAGE_H
