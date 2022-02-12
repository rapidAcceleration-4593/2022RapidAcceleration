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