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
#include "Subsystems/DriveTrain.h"
#include "Subsystems/shooter.h"
#include "Subsystems/climber.h"
#include "Subsystems/intake.h"

#include <iostream>

frc::XboxController m_driverController{0};
frc::XboxController m_auxController{1};

DriveTrain m_driveTrain;
shooter m_shooter;
intake m_intake;
climber m_climber;

bool hasShot = false;
bool hasDroveBack = false;

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

m_driveTrain.resetEncoder();
  

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

  m_intake.intakePneumaticIn();
  

}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
    if (hasShot == false){
    m_shooter.shoot(.5172);
    }


    if(abs(m_shooter.getShooterSpeed()) > 2750 && hasShot == false)
    {
      m_shooter.meterWheelsLeft(-.4593);
      m_shooter.meterWheelsRigth(-.4593);
      m_intake.intakeSpinny(.930);
      m_shooter.shoot(.5172);
      hasShot = true;
    }

    if(abs(m_driveTrain.getAverageEncoder()) < 69 && hasShot == true)
    {
      m_driveTrain.drive(.25, 0);
     // m_leftShooterMotor.Set(0);
      //m_rightShooterMotor.Set(0);
      hasDroveBack = true;
    }
    else if(abs(m_driveTrain.getAverageEncoder() > 69))
    {
      m_driveTrain.drive(0, 0);
      m_shooter.shoot(0);
      m_shooter.meterWheelsLeft(0);
      m_shooter.meterWheelsRigth(0);
      m_intake.intakeSpinny(0);

      m_intake.intakePneumaticOut();
    }
    
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {

m_driveTrain.getRightEncoderValue();
m_driveTrain.getLeftEncoderValue();

// possible - on the drive train
// .75
  m_driveTrain.drive(.75 * m_driverController.GetLeftY(), -.75 * m_driverController.GetRightX());

  if (m_driverController.GetAButton()){
    m_climber.pneumaticArmIn();
  }
  else if(m_driverController.GetBButton()){
    m_climber.pneumaticArmOut();
  }
  else if(m_driverController.GetRightBumper()){
    m_climber.moveStaticDown(.254);
  }
  else if(m_driverController.GetLeftBumper()){
    m_climber.moveStaticUp(.254);
  }
  else if(m_driverController.GetBackButton()){
    m_climber.moveStaticDown(-.254);
  }
  else{
    m_climber.moveStaticUp(0);
    m_climber.moveStaticDown(0);
  }

  if (m_auxController.GetAButton()){

    m_shooter.shoot(.4593);

    //std::cout << m_shooterEncoder.GetVelocity() << std::endl;
  }
  else if (m_auxController.GetYButton()) {
   
    m_shooter.shoot(-.118);
  
  }
  else
  {
   m_shooter.shoot(0);
  }
  
  if (m_auxController.GetBButton()){

    m_intake.intakeSpinny(.930);
  
  }
  else if (m_auxController.GetXButton()){
    m_intake.intakeSpinny(-.876);
  }
  else
  {
    m_intake.intakeSpinny(0);
  }

  if (m_auxController.GetRightBumper()){

      //could use .toggle();
      //m_RLM.Set(1);
      //m_FLM.Set(1);
    m_intake.intakePneumaticOut();
    //m_intakePneumatics.Set(frc::DoubleSolenoid::Value::kForward);

    std::cout << "intake forward \n";
  }

  if (m_auxController.GetLeftBumper()){  
    m_intake.intakePneumaticIn();
    //m_intakePneumatics.Set(frc::DoubleSolenoid::Value::kReverse);

    std::cout << "intake reverse \n";
  }

  if (m_auxController.GetBackButton()){
   
   m_shooter.meterWheelsLeft(-.118);
   m_shooter.meterWheelsRigth(-.254);
   
   // m_meterLeft.Set(ControlMode::PercentOutput, -.254);
   // m_meterRight.Set(ControlMode::PercentOutput, -.148); 
  }
  else 
  {
    m_shooter.meterWheelsLeft(0);
    m_shooter.meterWheelsRigth(0);
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
