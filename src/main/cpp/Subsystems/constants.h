#pragma once

class Constants
{
    public:
        static const int FLM = 2;   
        static const int RLM = 1;
        static const int FRM = 4;
        static const int RRM = 3;

        static const int shooterLeft = 5;
        static const int shooterRight = 6;

        static const int intakeMotor = 7;

        static const int PH = 30;

        static const int intakeForward = 0;
        static const int intakeBackward = 1;

        static const int meterMotorRight = 12;
        static const int meterMotorLeft = 9;

        //static const int staticUp = 11;
        static const int staticDown = 10;
       // static const int dynamicUp = 16;
        static const int dynamicDown = 11;

        static const int climberPneumaticUp = 4;
        static const int climberPneumaticDown = 5;

        static const int leftP = 0.1058;
        static const int leftI = 0;
        static const int leftD = 0;
        static const int leftFF = .000015;
        
        static const int rightP = 0.12146;
        static const int rightI = 0;
        static const int rightD = 0;
        static const int rightFF = .000015;
};