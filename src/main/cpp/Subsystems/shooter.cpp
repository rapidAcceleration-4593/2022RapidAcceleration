#include "shooter.h"

shooter::shooter(){

}

shooter::~shooter(){

}

void shooter::shoot(double shooterSpeed, double sushiSpeed){
    m_leftShooterMotor.Set(-shooterSpeed);
    m_rightShooterMotor.Set(shooterSpeed);

   m_sushiWheels.Set(-sushiSpeed);
}


double shooter::getShooterSpeed(){
    return m_shooterEncoder.GetVelocity();
}

void shooter::meterWheelsLeftRight(double leftspeed,double rightspeed){
    m_meterLeft.Set(ControlMode::PercentOutput, leftspeed);
    m_meterRight.Set(ControlMode::PercentOutput, rightspeed);
}

void shooter::bigWheel(double speed){
 m_bigWheel.Set(-speed);
}