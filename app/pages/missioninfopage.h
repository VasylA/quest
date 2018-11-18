#ifndef MISSIONINFOPAGE_H
#define MISSIONINFOPAGE_H

#include "missionwizard.h"

QT_BEGIN_NAMESPACE
class QCheckBox;
class QLabel;
QT_END_NAMESPACE

class MissionInfoPage : public QWizardPage
{
public:
    MissionInfoPage(QWidget *parent = 0);

    int nextId() const Q_DECL_OVERRIDE;

private:
    QLabel *bottomLabel;
    QCheckBox *agreeCheckBox;
};

#endif // MISSIONINFOPAGE_H
