#ifndef MARKINFOPAGE_H
#define MARKINFOPAGE_H

#include "missionwizard.h"

class MarkInfoPage : public QWizardPage
{
public:
    MarkInfoPage(QWidget *parent = 0);

    int nextId() const Q_DECL_OVERRIDE;
};

#endif // MARKINFOPAGE_H
