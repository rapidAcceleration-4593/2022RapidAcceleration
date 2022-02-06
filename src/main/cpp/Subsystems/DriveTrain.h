#include <frc/drive/DifferentialDrive.h>
#include "rev/CANSparkMax.h"
// #include "constants.h"

class DriveTrain {

    public:
        DriveTrain();
        ~DriveTrain();

        rev::CANSparkMax m_FLM{2, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANSparkMax m_FRM{4, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANSparkMax m_RLM{1, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANSparkMax m_RRM{3, rev::CANSparkMax::MotorType::kBrushless};

        frc::DifferentialDrive m_diffDrive{m_FLM, m_FRM};


        void drive(double a1, double a2);








};