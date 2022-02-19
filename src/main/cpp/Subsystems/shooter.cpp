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

void shooter::meterWheelsLeftRight(double leftspeed,double rightspeed){
    m_meterLeft.Set(ControlMode::PercentOutput, leftspeed);
    m_meterRight.Set(ControlMode::PercentOutput, rightspeed);
}