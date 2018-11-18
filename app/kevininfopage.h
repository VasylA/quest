#ifndef KEVININFOPAGE_H
#define KEVININFOPAGE_H

#include "missionwizard.h"

class KevinInfoPage : public QWizardPage
{
public:
    KevinInfoPage(QWidget *parent = 0);

    int nextId() const Q_DECL_OVERRIDE;
};

#endif // KEVININFOPAGE_H
