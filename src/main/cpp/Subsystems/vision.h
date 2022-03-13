#pragma once

#include "constants.h"

#include "frc/smartdashboard/Smartdashboard.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"
#include "wpi/span.h"

class limelight {

    
    
    public:
        limelight();
        ~limelight();
        
        // void createTable();

        double getAngleX();
        double getAngleY();
        double getArea();
        double getSkew();
        bool isTarget();
        void lightOn();
        void lightOff();

        bool inRange();

        std::shared_ptr<nt::NetworkTable> table;
};