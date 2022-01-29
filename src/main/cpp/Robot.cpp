// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <fmt/core.h>

#include <frc/smartdashboard/SmartDashboard.h>

#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/XboxController.h>
#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include "rev/CANSparkMax.h"
#include <frc/PneumaticHub.h>
#include <frc/PneumaticsModuleType.h>
#include <frc/PneumaticsControlModule.h>
#include <frc/PneumaticsBase.h>
#include <frc/DoubleSolenoid.h>
#include "ctre/Phoenix.h"

#include "Subsystems/constants.h"

// static const int FLM = 1;   
// static const int RLM = 2;
// static const int FRM = 3;
// static const int RRM = 4;

// static const int shooterLeft = 5;
// static const int shooterRight = 6;

// static const int intakeMotor = 7;

// static const int intakeRight = 8;

// static const int intakeLeft = 9;

// static const int meterMotorRight = 12;
// static const int meterMotorLeft = 9;

rev::CANSparkMax m_FLM{Constants::FLM, rev::CANSparkMax::MotorType::kBrushless};
rev::CANSparkMax m_FRM{Constants::FRM, rev::CANSparkMax::MotorType::kBrushless};
rev::CANSparkMax m_RLM{Constants::RLM, rev::CANSparkMax::MotorType::kBrushless};
rev::CANSparkMax m_RRM{Constants::RRM, rev::CANSparkMax::MotorType::kBrushless};

TalonSRX m_intake{Constants::intakeMotor};  // maybe need to be like CANTalonSRX or WPI_TalonSrx (need to be on CAN not PWM)

VictorSPX m_meterRight{Constants::meterMotorRight};  // same as above
VictorSPX m_meterLeft{Constants::meterMotorLeft};

rev::CANSparkMax m_leftShooterMotor {Constants::shooterLeft, rev::CANSparkMax::MotorType::kBrushless};
rev::CANSparkMax m_rightShooterMotor {Constants::shooterRight, rev::CANSparkMax::MotorType::kBrushless};

frc::DoubleSolenoid m_intakeRight{Constants::intakeRight, frc::PneumaticsModuleType::REVPH, 1,2};
frc::DoubleSolenoid m_intakeLeft{Constants::intakeLeft, frc::PneumaticsModuleType::REVPH, 3, 4};

frc::DifferentialDrive m_driveTrain{m_FLM, m_FRM};

frc::XboxController m_driverController{0};

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  m_FLM.RestoreFactoryDefaults();
  m_FRM.RestoreFactoryDefaults();
  m_RLM.RestoreFactoryDefaults();
  m_RRM.RestoreFactoryDefaults();

  m_RRM.Follow(m_FRM);
  m_RLM.Follow(m_FLM);

}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnoszzztics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {

  m_driveTrain.ArcadeDrive(m_driverController.GetRightX(),m_driverController.GetRightY());

  if (m_driverController.GetAButton()){

    m_leftShooterMotor.Set(-.4593);
    m_rightShooterMotor.Set(.4593);

  }
  else
  {
    m_leftShooterMotor.Set(0);
    m_rightShooterMotor.Set(0);
  }

  if (m_driverController.GetBButton()){

    m_intake.Set(ControlMode::PercentOutput, .5);
  
  }
  else
  {
    m_intake.Set(ControlMode::PercentOutput, 0);
  }

  if (m_driverController.GetYButton()){

      //could use .toggle();

    m_intakeRight.Set(frc::DoubleSolenoid::Value::kForward);
    m_intakeLeft.Set(frc::DoubleSolenoid::Value::kForward);

  }
  if (m_driverController.GetXButton()){  
    m_intakeRight.Set(frc::DoubleSolenoid::Value::kReverse);
    m_intakeLeft.Set(frc::DoubleSolenoid::Value::kReverse);

  }

  if (m_driverController.GetBackButton()){
    m_meterLeft.Set(ControlMode::PercentOutput, -.118);
    m_meterRight.Set(ControlMode::PercentOutput, -.118); 
  }
  else 
  {
    m_meterLeft.Set(ControlMode::PercentOutput, 0);
    m_meterRight.Set(ControlMode::PercentOutput, 0); 
  }

}



void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
