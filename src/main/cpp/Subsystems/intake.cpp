// #include "intake.h"

// intake::intake(){

// }

// intake::~intake(){

// }

// void intake::intakePneumaticIn(){
//     m_rightIntakePneumatics.Set(frc::DoubleSolenoid::Value::kForward);
//     m_leftIntakePneumatics.Set(frc::DoubleSolenoid::Value::kForward);
// }

// void intake::intakePneumaticOut(){
//     m_rightIntakePneumatics.Set(frc::DoubleSolenoid::Value::kReverse);
//     m_leftIntakePneumatics.Set(frc::DoubleSolenoid::Value::kReverse);
// }

// void intake::intakeToggle(){
//     m_rightIntakePneumatics.Toggle();
//     m_leftIntakePneumatics.Toggle();
// }

// void intake::intakeSpinny(double speed, double meterSpeed){
//     m_intake.Set(ControlMode::PercentOutput, speed);

//     if(checkPressed() == false){
//         bigWheel(meterSpeed);
//         meterWheelsLeftRight(-meterSpeed, -meterSpeed);
//     }
//     else{
//         bigWheel(0);
//         meterWheelsLeftRight(0,0);
//     }
// }

// void intake::bigWheel(double speed){
//  m_bigWheel.Set(-speed);
// }

// bool intake::checkPressed(){
//     std::cout << m_meterSwitch.Get() << std::endl; 
//     return m_meterSwitch.Get();    
// }

// void intake::meterWheelsLeftRight(double leftspeed,double rightspeed){
//     m_meterLeft.Set(ControlMode::PercentOutput, leftspeed);
//     m_meterRight.Set(ControlMode::PercentOutput, rightspeed);
// }