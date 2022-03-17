// #pragma once

// #include "constants.h"
// #include <frc/PneumaticHub.h>
// #include <frc/PneumaticsModuleType.h>
// #include <frc/PneumaticsControlModule.h>
// #include <frc/PneumaticsBase.h>
// #include <frc/DoubleSolenoid.h>
// #include "ctre/Phoenix.h"
// #include <frc/motorcontrol/PWMSparkMax.h>
// #include <frc/DigitalInput.h>
// #include <iostream>

// class intake {

//     public:

//         intake();
//         ~intake();


//         frc::PWMSparkMax m_bigWheel{0};

//         TalonSRX m_intake{Constants::intakeMotor};
//         frc::DoubleSolenoid m_rightIntakePneumatics{Constants::PH, frc::PneumaticsModuleType::REVPH,
//                                                  Constants::intakeForwardRight, Constants::intakeBackwardRight};
//         frc::DoubleSolenoid m_leftIntakePneumatics {Constants::PH, frc::PneumaticsModuleType::REVPH,
//                                                     Constants::intakeForwardLeft, Constants::intakeBackwardLeft};

//         frc::DigitalInput m_meterSwitch {0};

//         // maybe need to be like CANTalonSRX or WPI_TalonSrx (need to be on CAN not PWM)

//         VictorSPX m_meterRight{Constants::meterMotorRight};  // same as above
//         VictorSPX m_meterLeft{Constants::meterMotorLeft};


//         void bigWheel(double speeed);
//         void intakePneumaticIn();
//         void intakePneumaticOut();
//         void intakeToggle();

//         void intakeSpinBigWheel(double spinnySpeed, double bigSpeed);
        
//         void intakeSpinny(double speed, double meterSpeed);

//         void meterWheelsLeftRight(double leftspeed, double rightspeed);

//         bool checkPressed();




// };