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

        rev::SparkMaxPIDController m_FLMPID = m_FLM.GetPIDController();
        rev::SparkMaxPIDController m_RLMPID = m_RLM.GetPIDController();
        rev::SparkMaxPIDController m_FRMPID = m_FRM.GetPIDController();
        rev::SparkMaxPIDController m_RRMPID = m_RRM.GetPIDController();

        rev::SparkMaxRelativeEncoder m_FLMEncoder = m_FLM.GetEncoder();
        rev::SparkMaxRelativeEncoder m_RLMEncoder = m_RLM.GetEncoder();
        rev::SparkMaxRelativeEncoder m_FRMEncoder = m_FRM.GetEncoder();
        rev::SparkMaxRelativeEncoder m_RRMEncoder = m_RRM.GetEncoder();

        


};