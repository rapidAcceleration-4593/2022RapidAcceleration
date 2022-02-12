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
        frc::DoubleSolenoid m_intakePneumatics{Constants::PH, frc::PneumaticsModuleType::REVPH,
                                                 Constants::intakeForward, Constants::intakeBackward};

        void intakePneumaticIn();
        void intakePneumaticOut();

        void intakeSpinny(double speed);




};