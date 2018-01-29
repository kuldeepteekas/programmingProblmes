//
//  LiftClass.hpp
//  liftLogic

#ifndef LiftClass_hpp
#define LiftClass_hpp

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <vector>
#include "TimerClass.hpp"

class LiftClass {

private:
    int m_totalFloor;
    int m_currentFloor;
    bool m_isStop;
    bool m_isGoingUp;
    bool m_isLiftPaused;
    long m_liftSpeed;
    
public:
    LiftClass();
    ~LiftClass();
    LiftClass(int numberOfFloor);
    
    time_t m_lastTimeInterval;
    TimerClass* m_timerInstance;
    std::vector<int> m_destinationFloors;
    
    //Set total floors of lift
    void setTotalFloors(int totalFloor);
    int getTotalFloors();
    
    //set current floor on which lift is currently
    void setCurrentFloor(int currentFloor);
    int getCurrentFloor();
    
    //set and get the status of lift whether it is stopped or not
    bool getIsStop();
    void setIsStop(bool isStop);
    
    //time to cross single floor by lift
    void setLiftSpeedToCrossSingleFloor(long timeInSec);
    long getLiftSpeed();
    
    //set the floor which the person wants to go
    void addFloorToGo(int floorToGo);
    
    void increaseFloor();
    void decreaseFloor();
    bool isLiftGoingUp();
    void setLiftDirection(bool isGoingUp);
    bool isCurrentFloorDestinationFloor(int curFloor);
    void removeFloorFromDestinationFloor(int floor);
    
    bool isAnyUpperFloor(int curFloor);
    bool isAnyLowerFloor(int curFloor);
    
    void setCurrentDestinationFloor();
    void setUpDownStatus();
    
    void resumeLift();
    void pauseLift();
    bool getPauseStatus();
    
    void startLift();
};

#endif /* LiftClass_hpp */
