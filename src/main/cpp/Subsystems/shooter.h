#pragma once

#include "rev/CANSparkMax.h"
#include "constants.h"
#include "ctre/Phoenix.h"

class shooter {

    public:
        shooter();
        ~shooter();

        // maybe need to be like CANTalonSRX or WPI_TalonSrx (need to be on CAN not PWM)

        VictorSPX m_meterRight{Constants::meterMotorRight};  // same as above
        VictorSPX m_meterLeft{Constants::meterMotorLeft};


        rev::CANSparkMax m_leftShooterMotor {Constants::shooterLeft, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANSparkMax m_rightShooterMotor {Constants::shooterRight, rev::CANSparkMax::MotorType::kBrushless};
        
        rev::SparkMaxRelativeEncoder m_shooterEncoder = m_leftShooterMotor.GetEncoder();

        void shoot(double speed);
        double getShooterSpeed();
        void meterWheelsLeftRight(double leftspeed, double rightspeed);

};
