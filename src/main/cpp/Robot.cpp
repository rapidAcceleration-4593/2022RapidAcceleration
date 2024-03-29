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
#include <cameraserver/CameraServer.h>
#include "frc/smartdashboard/Smartdashboard.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"
#include "wpi/span.h"

#include "Subsystems/constants.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/shooter.h"
#include "Subsystems/climber.h"
#include "Subsystems/vision.h"

#include <iostream>
#include <ctime>


frc::XboxController m_driverController{0};
frc::XboxController m_auxController{1}; 

DriveTrain m_driveTrain;
shooter m_shooter;
climber m_climber;
limelight m_limelight;

bool hasShot = false;
bool hasDroveBack = false;

bool sendThatBall = false;

bool slurpedBall = false;

bool shooting = false; // probably unneeded

bool manualOverride = false;

time_t startAutoTime;

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  //m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  m_chooser.AddOption(kAutoNameNoDrive, kAutoNameNoDrive);
  m_chooser.AddOption(kAutoNameTwoBall, kAutoNameTwoBall);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  m_driveTrain.resetEncoder();

//frc::CameraServer::StartAutomaticCapture();

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

  m_driveTrain.resetEncoder();
  m_shooter.intakePneumaticIn();
  startAutoTime = time(0);
  m_driveTrain.brakeMode();
}

void Robot::AutonomousPeriodic() {

  // when shoot is called, can remove all of the other intake feeding things

  if (m_autoSelected == kAutoNameCustom) {

    // THIS IS THE KINDA BAD / TURNING AUTO

    if (time(0) - startAutoTime < 4){
    m_shooter.shoot(1750);
    }

    if(abs(m_driveTrain.getAverageEncoder()) < 55 && time(0) - startAutoTime > 4)
    {
      m_driveTrain.drive(.4593,0);
      m_shooter.shoot(0);
      hasDroveBack = true;
    }
    else if(abs(m_driveTrain.getAverageEncoder() > 55))
    {
      m_driveTrain.drive(0, 0);
      m_shooter.shoot(0);
      m_shooter.intakeSpinny(0, 0);
      m_shooter.intakePneumaticOut();
    }
  }

    // SIMPLE AUTO STUFF/ NO DRIVE


  else if (m_autoSelected == kAutoNameNoDrive){

    if (time(0) - startAutoTime < 5){
      m_shooter.shoot(2000);
    }
    else {
      m_shooter.intakeSpinny(0, 0);
      m_shooter.shoot(0);
    }

  }

  // TWO BALL

  else if(m_autoSelected == kAutoNameTwoBall){

    m_shooter.intakePneumaticOut();

   if(abs(m_driveTrain.getAverageEncoder()) < 35 && !slurpedBall){
    m_shooter.intakeSpinny(.6, .254);
    m_driveTrain.drive(-.4593,-.01);
   }
    else if (abs(m_driveTrain.getRightEncoderValue()) < 59.5){
        m_driveTrain.drive(0, .5);
        slurpedBall = true;
        //m_shooter.intakePneumaticIn();
    }
    else if (!m_limelight.inRange() && slurpedBall){
        m_driveTrain.drive(-.45,0);
        m_shooter.intakePneumaticIn();
        m_shooter.intakeSpinny(0,0);
    }
    // else if (m_limelight.inRange()){
    //     //m_shooter.shoot(.45);
    //     m_driveTrain.drive(0,0);

    // else if (time(0) - startAutoTime < 12.5){
    //       //m_shooter.shoot(1750);
    //       m_shooter.intakePneumaticIn();
    //       //m_driveTrain.drive(0,0);

    //     // else if (time(0) - startAutoTime < 15 && time(0) - startAutoTime > 7)
    //     // {
    //     //   m_shooter.meterWheelsLeftRight(-.4593,-.4539);
    //     //   // m_shooter.intakeSpinny(.930, .254);
    //     //   m_shooter.bigWheel(.3);
    //     //   m_shooter.shoot(.5);
    //     //   m_driveTrain.drive(0,0);

    //     // }
    if (time(0) - startAutoTime < 12.5 && time(0) - startAutoTime > 11){
      m_driveTrain.tankDrive(0,-.4);
    }
    // }
    if (time(0) - startAutoTime < 20 && time(0) - startAutoTime > 12.5){
      //m_driveTrain.tankDrive(0,-.4);
      //m_shooter.bigWheel(.3);
      m_shooter.shoot(1750);
      //m_shooter.intakeSpinny(.9,0);
     // m_shooter.intakePneumaticIn();
    }
    // else if (sendThatBall = true){
    //   m_driveTrain.drive(0,0);
    // }
    // else if(sendThatBall && m_shooter.) {
    //   m_shooter.shoot(.45);
    //   m_driveTrain.drive(0,0);
    //   m_shooter.meterWheelsLeftRight(-.254,-.254);
    //   m_shooter.bigWheel(.4);
    // }


    // else if(m_limelight.getAngleX() < 4 && m_limelight.getAngleX() > -8 && !m_limelight.isTarget()){
    //   m_limelight.lightOn();
    //   m_shooter.intakeSpinny(0);
    //   m_driveTrain.drive(0,.5);
    //   slurpedBall = true;
    // }

  else {
    //m_driveTrain.drive(0,0);
    m_limelight.lightOff();
    m_shooter.shoot(0);
  }

}
  else {
    // THIS IS A GOOD ONE

    if (time(0) - startAutoTime < 4){
      m_shooter.shoot(1750);
    }

    if(abs(m_driveTrain.getAverageEncoder()) < 60 && time(0) - startAutoTime > 4)
    {
      m_driveTrain.drive(.5172, 0);
      m_shooter.shoot(1750);
      hasDroveBack = true;
    }
    else if(abs(m_driveTrain.getAverageEncoder() > 60))
    {
      m_driveTrain.drive(0, 0);
      m_shooter.shoot(0);
      m_shooter.intakePneumaticOut();
    }
  }
}

void Robot::TeleopInit() {
  m_driveTrain.coastMode();
  
}

void Robot::TeleopPeriodic() {

  // limelight stuff
  frc::SmartDashboard::PutBoolean("lined up", m_limelight.inRange());

  m_driveTrain.drive(m_driverController.GetLeftY(), - m_driverController.GetRightX());

  if(m_driverController.GetRightBumper()){
    m_climber.moveStatic(.973);
  }
  // else if(m_driverController.GetRightBumper()){
  // m_climber.moveStatic(.254);
  // } 
  // should that else if be there?
  else if(m_driverController.GetLeftBumper()){
    m_climber.moveStatic(-.973);
  }
  else {
    m_climber.moveStatic(0);
  }

    // this is dynamic arm

  if (m_driverController.GetAButton()){
    m_climber.pneumaticArmIn();
  }
  else if(m_driverController.GetBButton()){
    m_climber.pneumaticArmOut();
  }
  // else if (m_driverController.GetRightTriggerAxis()){
  //   m_climber.moveDynamicUp(.5172);
  //  }
  // same with this else if
  else if (m_driverController.GetRightTriggerAxis()){
  m_climber.moveDynamic(1);
   }
  else if (m_driverController.GetLeftTriggerAxis()){
  m_climber.moveDynamic(-1);
  }
  else{
    m_climber.moveDynamic(0);
  }



  // AUX CONTROLLER STUFFS
   if (m_auxController.GetBButton()){
    m_shooter.meterWheelsLeftRight(-.118,-.254);
    m_shooter.bigWheel(.35);
    manualOverride = true;
  }


  if (m_auxController.GetAButton()){
    m_shooter.shoot(1778);
    shooting = true;
    // m_driveTrain.brakeMode();
  }
  else if (m_auxController.GetYButton()) {
    m_shooter.shoot(-100);
  }
  else if (m_auxController.GetLeftTriggerAxis()){
    m_shooter.intakeSpinny(.65, .5);
  }
  else if (m_auxController.GetXButton()){
    m_shooter.intakeSpinny(-.876, -.254);
  }
  else if(!manualOverride)
  {
   m_shooter.shoot(0);
   m_shooter.intakeSpinny(0, 0);
   shooting = false;
   // m_driveTrain.coastMode();
  }

  if (m_auxController.GetRightBumper()){
    m_shooter.intakePneumaticOut();
  }

  if (m_auxController.GetLeftBumper()){
    m_shooter.intakePneumaticIn();
  }

  manualOverride = false;
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
