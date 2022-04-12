#pragma once

#include "ctre/Phoenix.h"
#include "constants.h"
#include <frc/DoubleSolenoid.h>
#include <frc/PneumaticHub.h>
#include <frc/PneumaticsModuleType.h>
#include <frc/PneumaticsControlModule.h>
#include <frc/PneumaticsBase.h>
#include "rev/CANSparkMax.h"
#include <frc/motorcontrol/PWMSparkMax.h>

class climber {
    public:
        climber();
        ~climber();

        TalonSRX m_static{Constants::staticPort};

        TalonSRX m_dynamic{Constants::dynamicPort};

        frc::DoubleSolenoid m_climberPneumatic{Constants::PH, frc::PneumaticsModuleType::REVPH, 
                                                Constants::climberPneumaticUp, Constants::climberPneumaticDown};

        void pneumaticArmOut();
        void pneumaticArmIn();
        
        void moveStatic(double speed);
        void moveDynamic(double speed);
};
