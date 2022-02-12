#include "climber.h"

climber::climber() {

}

climber::~climber(){

}

void climber::moveStaticUp(double speed){
    m_staticUp.Set(ControlMode::PercentOutput, speed);
}
void climber::moveStaticDown(double speed){
    m_staticDown.Set(ControlMode::PercentOutput, speed);
}
void climber::moveDynamicUp(double speed){
    m_dynamicUp.Set(ControlMode::PercentOutput, speed);
}
void climber::moveDynamicDown(double speed){
    m_dynamicDown.Set(ControlMode::PercentOutput, speed);
}
void climber::pneumaticArmOut(){
    m_climberPneumatic.Set(frc::DoubleSolenoid::Value::kForward);
}
void climber::pneumaticArmIn(){
    m_climberPneumatic.Set(frc::DoubleSolenoid::Value::kReverse);
}