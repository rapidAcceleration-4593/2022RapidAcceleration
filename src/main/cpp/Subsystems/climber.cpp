#include "climber.h"

climber::climber() {
    m_static.SetNeutralMode(Brake);
}

climber::~climber(){

}

void climber::moveStatic(double speed){
    m_static.Set(ControlMode::PercentOutput, speed);
    //m_staticDown.Set(speed);
}

void climber::moveDynamic(double speed){
    m_dynamic.Set(ControlMode::PercentOutput, speed);
}
void climber::pneumaticArmOut(){
    m_climberPneumatic.Set(frc::DoubleSolenoid::Value::kForward);
}
void climber::pneumaticArmIn(){
    m_climberPneumatic.Set(frc::DoubleSolenoid::Value::kReverse);
}
