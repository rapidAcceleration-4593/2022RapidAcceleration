#include "shooter.h"

shooter::shooter(){
m_leftShooterMotor.RestoreFactoryDefaults();
m_rightShooterMotor.RestoreFactoryDefaults();

// m_leftShooterMotor.SetInverted(true);
// m_rightShooterMotor.SetInverted(false);
// m_rightShooterMotor.Follow(m_leftShooterMotor, true);

m_leftShooterPID.SetP(Constants::shooterP);
m_leftShooterPID.SetI(Constants::shooterI);
m_leftShooterPID.SetD(Constants::shooterD);
m_leftShooterPID.SetFF(Constants::shooterFF);

m_rightShooterPID.SetP(Constants::shooterP);
m_rightShooterPID.SetI(Constants::shooterI);
m_rightShooterPID.SetD(Constants::shooterD);
m_rightShooterPID.SetFF(Constants::shooterFF);

}

shooter::~shooter(){

}

void shooter::shoot(double shooterSpeed){

std::cout << m_leftShooterEncoder.GetVelocity() << std::endl;
frc::SmartDashboard::PutNumber("shooter velocity", -m_leftShooterEncoder.GetVelocity());

if (shooterSpeed == 0){
    // m_sushiWheels.Set(0);
    m_leftShooterMotor.Set(0);
    m_rightShooterMotor.Set(0);
    // m_bigWheel.Set(0);
    // m_meterLeft.Set(ControlMode::PercentOutput, 0);
    // m_meterRight.Set(ControlMode::PercentOutput, 0);
}
else{
    m_rightShooterPID.SetReference(shooterSpeed, rev::ControlType::kVelocity);
    m_leftShooterPID.SetReference(-shooterSpeed, rev::ControlType::kVelocity);
    // m_sushiWheels.Set(-1);
    if(abs(m_leftShooterEncoder.GetVelocity()) > shooterSpeed - 100 && shooterSpeed > 1)
    {
        m_bigWheel.Set(-.75); 
        m_meterLeft.Set(ControlMode::PercentOutput, -.254);
        m_meterRight.Set(ControlMode::PercentOutput, -.254);
    }
}
//    if (checkShooterSpeed() == true){
//     m_sushiWheels.Set(-.876);
//     bigWheel(.254);
//     meterWheelsLeftRight(-.254, -.254);
//    }
//    else{
//        m_sushiWheels.Set(0);
//        bigWheel(0);
//        meterWheelsLeftRight(0,0);
//    }
   
}


void shooter::upToSpeedShoot(double shooterSpeed){
    m_leftShooterMotor.Set(-shooterSpeed);
    m_rightShooterMotor.Set(shooterSpeed);
    //m_sushiWheels.Set(shooterSpeed*2);

   if (checkShooterSpeed() == true){
    // m_sushiWheels.Set(-.876);
    bigWheel(.25);
    meterWheelsLeftRight(-.254, -.254);
   }
   else{
       // m_sushiWheels.Set(0);
       bigWheel(0);
       meterWheelsLeftRight(0,0);
   }
   
}



bool shooter::checkShooterSpeed(){
    //return m_shooterEncoder.GetVelocity();

    // if(abs(m_shooterEncoder.GetVelocity()) < 1323 ){
    //     return false;

    // }
    // else {
    //     return true;
    // }
    return true;
}

void shooter::intakePneumaticIn(){
    m_rightIntakePneumatics.Set(frc::DoubleSolenoid::Value::kForward);
    m_leftIntakePneumatics.Set(frc::DoubleSolenoid::Value::kForward);
}

void shooter::intakePneumaticOut(){
    m_rightIntakePneumatics.Set(frc::DoubleSolenoid::Value::kReverse);
    m_leftIntakePneumatics.Set(frc::DoubleSolenoid::Value::kReverse);
}

void shooter::intakeToggle(){
    m_rightIntakePneumatics.Toggle();
    m_leftIntakePneumatics.Toggle();
}

void shooter::intakeSpinny(double speed, double meterSpeed, bool shooting){
    m_intake.Set(ControlMode::PercentOutput, speed);



    if(checkPressed() == true && !shooting){
        m_bigWheel.Set(0);      
    }
    else{
        m_bigWheel.Set(-meterSpeed);
        m_meterLeft.Set(ControlMode::PercentOutput, -meterSpeed);
        m_meterRight.Set(ControlMode::PercentOutput, -meterSpeed);
    }
    // else if (!shooting){
    //     m_bigWheel.Set(0);
    //     m_meterLeft.Set(ControlMode::PercentOutput, 0);
    //     m_meterRight.Set(ControlMode::PercentOutput, 0);     
    // }
}

void shooter::bigWheel(double speed){
 m_bigWheel.Set(-speed);
}

bool shooter::checkPressed(){
    // std::cout << !m_meterSwitch.Get() << std::endl; 
    // return !m_meterSwitch.Get(); 
    return false;  
}

void shooter::meterWheelsLeftRight(double leftspeed,double rightspeed){
    m_meterLeft.Set(ControlMode::PercentOutput, leftspeed);
    m_meterRight.Set(ControlMode::PercentOutput, rightspeed);
}
