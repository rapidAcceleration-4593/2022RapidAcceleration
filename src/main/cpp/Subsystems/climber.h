#pragma once

#include "ctre/Phoenix.h"
#include "constants.h"
#include <frc/DoubleSolenoid.h>
#include <frc/PneumaticHub.h>
#include <frc/PneumaticsModuleType.h>
#include <frc/PneumaticsControlModule.h>
#include <frc/PneumaticsBase.h>

class climber {
    public:
        climber();
        ~climber();

        TalonSRX m_staticUp{Constants::staticUp};
        TalonSRX m_staticDown{Constants::staticDown};

        VictorSPX m_dynamicUp{Constants::dynamicUp};
        VictorSPX m_dynamicDown{Constants::dynamicDown};

        frc::DoubleSolenoid m_climberPneumatic{Constants::PH, frc::PneumaticsModuleType::REVPH, 
                                                Constants::climberPneumaticUp, Constants::climberPneumaticUp};

        void pneumaticArmOut();
        void pneumaticArmIn();
        
        void moveStaticUp(double speed);
        void moveStaticDown(double speed);
        void moveDynamicUp(double speed);
        void moveDynamicDown(double speed);

};