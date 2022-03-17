#include "climber.h"

climber::climber() {
    m_staticDown.SetNeutralMode(Brake);
    
}

climber::~climber(){

}

// void climber::moveStaticUp(double speed){
//     //m_staticUp.Set(ControlMode::PercentOutput, speed);
//   // m_staticUp.Set(speed);
// }
void climber::moveStaticDown(double speed){
    m_staticDown.Set(ControlMode::PercentOutput, speed);
    //m_staticDown.Set(speed);
}
// void climber::moveDynamicUp(double speed){
//     //m_dynamicUp.Set(ControlMode::PercentOutput, speed);
//     //m_dynamicUp.Set(speed);
// }
void climber::moveDynamicDown(double speed){
    m_dynamicDown.Set(ControlMode::PercentOutput, speed);
}
void climber::pneumaticArmOut(){
    m_climberPneumatic.Set(frc::DoubleSolenoid::Value::kForward);
}
void climber::pneumaticArmIn(){
    m_climberPneumatic.Set(frc::DoubleSolenoid::Value::kReverse);
}