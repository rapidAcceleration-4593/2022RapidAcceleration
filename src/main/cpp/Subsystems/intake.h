#pragma once

#include "constants.h"
#include <frc/PneumaticHub.h>
#include <frc/PneumaticsModuleType.h>
#include <frc/PneumaticsControlModule.h>
#include <frc/PneumaticsBase.h>
#include <frc/DoubleSolenoid.h>
#include "ctre/Phoenix.h"

class intake {

    public:

        intake();
        ~intake();

        TalonSRX m_intake{Constants::intakeMotor};
        frc::DoubleSolenoid m_rightIntakePneumatics{Constants::PH, frc::PneumaticsModuleType::REVPH,
                                                 Constants::intakeForwardRight, Constants::intakeBackwardRight};
        frc::DoubleSolenoid m_leftIntakePneumatics {Constants::PH, frc::PneumaticsModuleType::REVPH,
                                                    Constants::intakeForwardLeft, Constants::intakeBackwardLeft};


        void intakePneumaticIn();
        void intakePneumaticOut();
        void intakeToggle();

        void intakeSpinny(double speed);




};