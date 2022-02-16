#include "shooter.h"

shooter::shooter(){

}

shooter::~shooter(){

}

void shooter::shoot(double speed){
    m_leftShooterMotor.Set(-speed);
    m_rightShooterMotor.Set(speed);
}


double shooter::getShooterSpeed(){
    return m_shooterEncoder.GetVelocity();
}

void shooter::meterWheelsLeft(double speed){
    m_meterLeft.Set(ControlMode::PercentOutput, speed);
}

void shooter::meterWheelsRigth(double speed){
    m_meterRight.Set(ControlMode::PercentOutput, speed);
}