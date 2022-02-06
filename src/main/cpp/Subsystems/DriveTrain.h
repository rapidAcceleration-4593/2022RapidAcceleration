#pragma once

#include <frc/drive/DifferentialDrive.h>
#include "rev/CANSparkMax.h"
#include "constants.h"

class DriveTrain {

    public:
        DriveTrain();
        ~DriveTrain();

        rev::CANSparkMax m_FLM{Constants::FLM, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANSparkMax m_FRM{Constants::FRM, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANSparkMax m_RLM{Constants::RLM, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANSparkMax m_RRM{Constants::RRM, rev::CANSparkMax::MotorType::kBrushless};

        frc::DifferentialDrive m_diffDrive{m_FLM, m_FRM};


        void drive(double a1, double a2);








};