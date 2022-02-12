#pragma once

#include "rev/CANSparkMax.h"
#include "constants.h"

class shooter {

    public:
        shooter();
        ~shooter();

        rev::CANSparkMax m_leftShooterMotor {Constants::shooterLeft, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANSparkMax m_rightShooterMotor {Constants::shooterRight, rev::CANSparkMax::MotorType::kBrushless};
        
        rev::SparkMaxRelativeEncoder m_shooterEncoder = m_leftShooterMotor.GetEncoder();

        void shoot(double speed);
        double getShooterSpeed();

};
