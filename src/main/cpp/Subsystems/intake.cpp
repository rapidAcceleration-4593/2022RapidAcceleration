#include "intake.h"

intake::intake(){

}

intake::~intake(){

}

void intake::intakePneumaticIn(){
    m_intakePneumatics.Set(frc::DoubleSolenoid::Value::kForward);
}

void intake::intakePneumaticOut(){
     m_intakePneumatics.Set(frc::DoubleSolenoid::Value::kReverse);
}

void intake::intakeToggle(){
     m_intakePneumatics.Toggle();
}

void intake::intakeSpinny(double speed){
    m_intake.Set(ControlMode::PercentOutput, speed);
}