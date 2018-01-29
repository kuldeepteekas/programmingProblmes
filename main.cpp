//
//  main.cpp
//  liftLogic


#include <iostream>
#include "TimerClass.hpp"
#include "LiftClass.hpp"


int main() {

    LiftClass* myLift = new LiftClass();
    myLift->setTotalFloors(10);
    myLift->setLiftSpeedToCrossSingleFloor(2);
    myLift->setLiftDirection(true);
    myLift->setCurrentFloor(2);
    myLift->addFloorToGo(3);
    myLift->addFloorToGo(5);
    myLift->addFloorToGo(1);
    myLift->startLift();
    return 0;
}
