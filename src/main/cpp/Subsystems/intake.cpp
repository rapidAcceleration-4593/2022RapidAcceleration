#include "intake.h"

intake::intake(){

}

intake::~intake(){

}

void intake::intakePneumaticIn(){
    m_rightIntakePneumatics.Set(frc::DoubleSolenoid::Value::kForward);
    m_leftIntakePneumatics.Set(frc::DoubleSolenoid::Value::kForward);
}

void intake::intakePneumaticOut(){
    m_rightIntakePneumatics.Set(frc::DoubleSolenoid::Value::kReverse);
    m_leftIntakePneumatics.Set(frc::DoubleSolenoid::Value::kReverse);
}

void intake::intakeToggle(){
    m_rightIntakePneumatics.Toggle();
    m_leftIntakePneumatics.Toggle();
}

void intake::intakeSpinny(double speed){
    m_intake.Set(ControlMode::PercentOutput, speed);
}