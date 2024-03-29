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

    // m_FLM.SetOpenLoopRampRate(5);
    // m_FRM.SetOpenLoopRampRate(5);
    // m_RRM.SetOpenLoopRampRate(5);
    // m_RLM.SetOpenLoopRampRate(5);

    m_diffDrive.SetDeadband(.15);
}

DriveTrain::~DriveTrain()
{

}

void DriveTrain::drive(double a1, double a2)
{
    // std::cout << m_FLMEncoder.GetVelocity() << std::endl;
    frc::SmartDashboard::PutNumber("left side position derivative", m_FLMEncoder.GetVelocity());
    frc::SmartDashboard::PutNumber("right side position derivative", m_FRMEncoder.GetVelocity());

   // std::cout << "ramprate" + m_FLM.GetClosedLoopRampRate(); << std::endl;

    //a2 = (a2 + .25)* -1;
    //a1 = double(m_FRMPID.SetReference(a1, rev::CANSparkMax::ControlType::kVelocity));

    m_diffDrive.ArcadeDrive(a1, a2);
}

void DriveTrain::tankDrive(double leftSpeed, double rightSpeed){
    m_diffDrive.TankDrive(leftSpeed, rightSpeed);
}

double DriveTrain::getLeftEncoderValue(){
    //std::cout << m_FLMEncoder.GetPosition() << std::endl;
    return m_FLMEncoder.GetPosition();
}

double DriveTrain::getRightEncoderValue(){
   // std::cout << m_FRMEncoder.GetPosition() << std::endl;
    return m_FRMEncoder.GetPosition();
}

void DriveTrain::resetEncoder(){
    m_FLMEncoder.SetPosition(0);
    m_FRMEncoder.SetPosition(0);
    m_RLMEncoder.SetPosition(0);
    m_RRMEncoder.SetPosition(0);
}

double DriveTrain::getAverageEncoder()
{
    return (m_FLMEncoder.GetPosition() + m_FRMEncoder.GetPosition()) / 2;
}

void DriveTrain::coastMode()
{
    // set coast mode somehow
    m_FRM.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_FLM.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_RRM.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_RLM.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}

void DriveTrain::brakeMode()
{
    // set brake mode somehow
   m_FRM.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
   m_FLM.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
   m_RRM.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
   m_RLM.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
}
