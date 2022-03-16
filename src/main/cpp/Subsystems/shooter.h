#pragma once

#include "rev/CANSparkMax.h"
#include "constants.h"
#include "ctre/Phoenix.h"
#include <frc/motorcontrol/PWMSparkMax.h>

class shooter {

    public:
        shooter();
        ~shooter();

        // maybe need to be like CANTalonSRX or WPI_TalonSrx (need to be on CAN not PWM)

        VictorSPX m_meterRight{Constants::meterMotorRight};  // same as above
        VictorSPX m_meterLeft{Constants::meterMotorLeft};

        frc::PWMSparkMax m_bigWheel{0};

        frc::PWMSparkMax m_sushiWheels{1};

        rev::CANSparkMax m_leftShooterMotor {Constants::shooterLeft, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANSparkMax m_rightShooterMotor {Constants::shooterRight, rev::CANSparkMax::MotorType::kBrushless};
        
        rev::SparkMaxRelativeEncoder m_shooterEncoder = m_leftShooterMotor.GetEncoder();

        void shoot(double shooterSpeed, double sushiSpeed);
        double getShooterSpeed();
        void meterWheelsLeftRight(double leftspeed, double rightspeed);
        void bigWheel(double speeed);

};
