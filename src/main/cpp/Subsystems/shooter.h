#pragma once

#include "rev/CANSparkMax.h"
#include "constants.h"
#include "ctre/Phoenix.h"
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/PneumaticHub.h>
#include <frc/PneumaticsModuleType.h>
#include <frc/PneumaticsControlModule.h>
#include <frc/PneumaticsBase.h>
#include <frc/DoubleSolenoid.h>
#include <frc/DigitalInput.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/controller/BangBangController.h>
#include <iostream>


class shooter {

    public:
        shooter();
        ~shooter();

        frc::PWMSparkMax m_sushiWheels{1};

        rev::CANSparkMax m_leftShooterMotor {Constants::shooterLeft, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANSparkMax m_rightShooterMotor {Constants::shooterRight, rev::CANSparkMax::MotorType::kBrushless};
        
        rev::SparkMaxRelativeEncoder m_leftShooterEncoder = m_leftShooterMotor.GetEncoder();
        rev::SparkMaxRelativeEncoder m_rightShooterEncoder = m_rightShooterMotor.GetEncoder(); 

        rev::SparkMaxPIDController m_leftShooterPID = m_leftShooterMotor.GetPIDController();
        rev::SparkMaxPIDController m_rightShooterPID = m_rightShooterMotor.GetPIDController();

        void jesusShootPlz();

        void shoot(double shooterSpeed);
        bool checkShooterSpeed();
        
        void upToSpeedShoot (double shooterSpeed);

        //OLD INTAKE STUFF *RIP*


        frc::PWMSparkMax m_bigWheel{0};

        TalonSRX m_intake{Constants::intakeMotor};
        frc::DoubleSolenoid m_rightIntakePneumatics{Constants::PH, frc::PneumaticsModuleType::REVPH,
                                                 Constants::intakeForwardRight, Constants::intakeBackwardRight};
        frc::DoubleSolenoid m_leftIntakePneumatics {Constants::PH, frc::PneumaticsModuleType::REVPH,
                                                    Constants::intakeForwardLeft, Constants::intakeBackwardLeft};



        frc::DigitalInput m_meterSwitch {0};

        // maybe need to be like CANTalonSRX or WPI_TalonSrx (need to be on CAN not PWM)

        VictorSPX m_meterRight{Constants::meterMotorRight};  // same as above
        VictorSPX m_meterLeft{Constants::meterMotorLeft};


        void bigWheel(double speeed);
        void intakePneumaticIn();
        void intakePneumaticOut();
        void intakeToggle();

        void intakeSpinBigWheel(double spinnySpeed, double bigSpeed);
        
        void intakeSpinny(double speed, double meterSpeed, bool shooting);

        void meterWheelsLeftRight(double leftspeed, double rightspeed);

        bool checkPressed(); 

};
