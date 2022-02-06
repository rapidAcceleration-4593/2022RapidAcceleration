#include "DriveTrain.h"

DriveTrain::DriveTrain()
{
    m_FLM.RestoreFactoryDefaults();
    m_FRM.RestoreFactoryDefaults();
    m_RLM.RestoreFactoryDefaults();
    m_RRM.RestoreFactoryDefaults();

    m_FLM.SetInverted(true);

    m_RRM.Follow(m_FRM);
    m_RLM.Follow(m_FLM);
}

DriveTrain::~DriveTrain()
{

}

void DriveTrain::drive(double a1, double a2)
{
    m_diffDrive.ArcadeDrive(a1, a2);
}