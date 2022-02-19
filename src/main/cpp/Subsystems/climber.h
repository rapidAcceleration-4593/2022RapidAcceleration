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

        frc::PWMSparkMax m_staticUp{0};
        frc::PWMSparkMax m_dynamicUp{1};

        // m_staticUp{Constants::staticUp};
        TalonSRX m_staticDown{Constants::staticDown};

        //VictorSPX m_dynamicUp{Constants::dynamicUp};
        TalonSRX m_dynamicDown{Constants::dynamicDown};

        frc::DoubleSolenoid m_climberPneumatic{Constants::PH, frc::PneumaticsModuleType::REVPH, 
                                                Constants::climberPneumaticUp, Constants::climberPneumaticDown};

        void pneumaticArmOut();
        void pneumaticArmIn();
        
        void moveStaticUp(double speed);
        void moveStaticDown(double speed);
        void moveDynamicUp(double speed);
        void moveDynamicDown(double speed);

};