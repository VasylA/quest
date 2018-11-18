#ifndef MISSIONREJECTEDPAGE_H
#define MISSIONREJECTEDPAGE_H

#include "missionwizard.h"

class MissionRejectedPage : public QWizardPage
{
public:
    MissionRejectedPage(QWidget *parent = 0);

    int nextId() const Q_DECL_OVERRIDE;
};

#endif // MISSIONREJECTEDPAGE_H
