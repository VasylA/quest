#ifndef INTROPAGE_H
#define INTROPAGE_H

#include "missionwizard.h"

class IntroPage : public QWizardPage
{
public:
    IntroPage(QWidget *parent = 0);

    int nextId() const Q_DECL_OVERRIDE;
};

#endif // INTROPAGE_H
