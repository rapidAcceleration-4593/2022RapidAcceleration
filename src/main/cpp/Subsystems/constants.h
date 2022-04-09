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

        static const int bigMeteringWheel = 14;

        static const int intakeMotor = 7;

        static const int PH = 30;

        static const int intakeForwardRight = 0;
        static const int intakeBackwardRight = 1;

        static const int intakeForwardLeft = 2;
        static const int intakeBackwardLeft = 3;

        static const int meterMotorRight = 12;
        static const int meterMotorLeft = 9;

        //static const int staticUp = 11;
        static const int staticDown = 10;
       // static const int dynamicUp = 16;
        static const int dynamicDown = 11;

        static const int climberPneumaticUp = 4;
        static const int climberPneumaticDown = 5;

        static const int horizontalLimeMax = 6;
        static const int horizontalLimeMin = -6;
        static const int verticalLimeMax = 10;
        static const int verticalLimeMin = 0;

        static constexpr double shooterP = 15e-5;
        static constexpr double shooterI = 1e-6;
        static constexpr double shooterD = 10;
        static constexpr double shooterFF = .000015;

        // left p = .1058
        static const int leftP = (0.56937 + .1058)/2;
        static const int leftI = 0;
        static const int leftD = 0;
        static const int leftFF = .000015;
        
        // right p = .12146
        static const int rightP = (0.56172 + .12146)/2;
        static const int rightI = 0;
        static const int rightD = 0;
        static const int rightFF = .000015;
};