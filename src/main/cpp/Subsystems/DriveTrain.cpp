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

    m_FLMPID.SetP(Constants::leftP);        
    m_FLMPID.SetI(Constants::leftI);
    m_FLMPID.SetD(Constants::leftD);        
    m_FLMPID.SetFF(Constants::leftFF);

    m_RLMPID.SetP(Constants::leftP);        
    m_RLMPID.SetI(Constants::leftI);
    m_RLMPID.SetD(Constants::leftD);        
    m_RLMPID.SetFF(Constants::leftFF);

    m_FRMPID.SetP(Constants::rightP);        
    m_FRMPID.SetI(Constants::rightI);
    m_FRMPID.SetD(Constants::rightD);        
    m_FRMPID.SetFF(Constants::rightFF);

    m_RRMPID.SetP(Constants::rightP);        
    m_RRMPID.SetI(Constants::rightI);
    m_RRMPID.SetD(Constants::rightD);        
    m_RRMPID.SetFF(Constants::rightFF);

}

DriveTrain::~DriveTrain()
{

}

void DriveTrain::drive(double a1, double a2)
{
    m_diffDrive.ArcadeDrive(a1, a2);
}