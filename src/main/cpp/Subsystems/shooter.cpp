#include "shooter.h"

shooter::shooter(){

}

shooter::~shooter(){

}

void shooter::shoot(double shooterSpeed){
    m_leftShooterMotor.Set(-shooterSpeed);
    m_rightShooterMotor.Set(shooterSpeed);
    m_sushiWheels.Set(.876);

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


bool shooter::checkShooterSpeed(){
    //return m_shooterEncoder.GetVelocity();

    if(abs(m_shooterEncoder.GetVelocity()) < 1000 ){
        return false;

    }
    else {
        return true;
    }
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

void shooter::intakeSpinny(double speed, double meterSpeed){
    m_intake.Set(ControlMode::PercentOutput, speed);
    m_meterLeft.Set(ControlMode::PercentOutput, -meterSpeed);
    m_meterRight.Set(ControlMode::PercentOutput, -meterSpeed); 

    if(checkPressed() == false){
        m_bigWheel.Set(-meterSpeed);      
    }
    else{
        m_bigWheel.Set(0);
        m_meterLeft.Set(ControlMode::PercentOutput, 0);
        m_meterRight.Set(ControlMode::PercentOutput, 0);     
    }
}

void shooter::bigWheel(double speed){
 m_bigWheel.Set(-speed);
}

bool shooter::checkPressed(){
    std::cout << !m_meterSwitch.Get() << std::endl; 
    return !m_meterSwitch.Get();    
}

void shooter::meterWheelsLeftRight(double leftspeed,double rightspeed){
    m_meterLeft.Set(ControlMode::PercentOutput, leftspeed);
    m_meterRight.Set(ControlMode::PercentOutput, rightspeed);
}



