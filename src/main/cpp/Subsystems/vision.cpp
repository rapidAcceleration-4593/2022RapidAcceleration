#include "vision.h"

limelight::limelight(){
    table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
}

limelight::~limelight(){

}

// void limelight::createTable(){
//     auto table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
// }

double limelight::getAngleX(){
   double targetOffsetAngle_Horizontal = table->GetNumber("tx",0.0);

   return targetOffsetAngle_Horizontal;
}

double limelight::getAngleY(){
    double targetOffsetAngle_Vertical = table->GetNumber("ty",0.0);

    return targetOffsetAngle_Vertical;
}

double limelight::getArea(){
    double targetArea = table->GetNumber("ta",0.0);

    return targetArea;
}

double limelight::getSkew(){
    double targetSkew = table->GetNumber("ts",0.0);

    return targetSkew;
}

bool limelight::isTarget(){
    double isTarget = table->GetNumber("tv",0.0);

    if(isTarget == 1){
        return true;
    }
    else{
        return false;
    }
}

void limelight::lightOn(){
    table->PutNumber("<ledMode>",3);
}

void limelight::lightOff(){
    table->PutNumber("<ledMode>",1);
}

bool limelight::inRange(){
    if (isTarget() == 0){
        return false;
    }

    if (Constants::verticalLimeMin > getAngleY() || Constants::verticalLimeMax < getAngleY()){
        return false;
    }

    if (Constants::horizontalLimeMin > getAngleX() || Constants::horizontalLimeMax < getAngleX()){
        return false;
    }

    return true;
}
