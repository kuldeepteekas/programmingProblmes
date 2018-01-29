//
//  LiftClass.cpp
//  liftLogic


#include "LiftClass.hpp"
using namespace std;

LiftClass::LiftClass(){
    m_totalFloor = 0;
    m_currentFloor = 0;
    m_isStop = true;
    m_isGoingUp = true;
    m_isLiftPaused = true;
    m_liftSpeed = 0;
    m_lastTimeInterval = 0;
    m_timerInstance = TimerClass::getInstance();
}

LiftClass::~LiftClass(){
    cout << "Destructor of liftClass" << endl;
    m_lastTimeInterval = 0;
}

LiftClass::LiftClass(int numberOfFloor) {
    m_totalFloor = numberOfFloor;
}

void LiftClass::setTotalFloors(int totalFloor) {
    m_totalFloor = totalFloor;
}

int LiftClass::getTotalFloors() {
    return m_totalFloor;
}

void LiftClass::setCurrentFloor(int currentFloor) {
    m_currentFloor = currentFloor;
}

int LiftClass::getCurrentFloor() {
    return m_currentFloor;
}

bool LiftClass::getIsStop(){
    return m_isStop;
}

void LiftClass::setIsStop(bool isStop){
    m_isStop = isStop;
}

void LiftClass::setLiftSpeedToCrossSingleFloor(long timeInSec){
    m_liftSpeed = timeInSec;
}

long LiftClass::getLiftSpeed() {
    return m_liftSpeed;
}

bool LiftClass::isCurrentFloorDestinationFloor(int curFloor){
    
    bool result = false;
    for (int i=0; i < m_destinationFloors.size(); i++){
        if (curFloor == m_destinationFloors.at(i)) {
            result = true;
            break;
        }
    }
    return result;
}

void LiftClass::addFloorToGo(int floorToGo){
    m_destinationFloors.push_back(floorToGo);
}

void LiftClass::increaseFloor() {
    
    if (!getPauseStatus() && !getIsStop()){
        if (m_currentFloor != getTotalFloors() && !isCurrentFloorDestinationFloor(m_currentFloor)){
            m_currentFloor++;
            setCurrentFloor(m_currentFloor);
        }else{
            cout << "lift reaches your destination, floor count : " << m_currentFloor << endl;
            removeFloorFromDestinationFloor(m_currentFloor);
            pauseLift();
        }
    }
}

void LiftClass::decreaseFloor() {
    if (!getPauseStatus() && !getIsStop()){
        if (m_currentFloor != 0 && !isCurrentFloorDestinationFloor(m_currentFloor)){
            m_currentFloor--;
            setCurrentFloor(m_currentFloor);
        }else{
            cout << "lift reaches your destination, floor count : " << m_currentFloor << endl;
            removeFloorFromDestinationFloor(m_currentFloor);
            pauseLift();
        }
    }
}

bool LiftClass::isLiftGoingUp() {
    return m_isGoingUp;
}

void LiftClass::setLiftDirection(bool isGoingUp) {
    m_isGoingUp = isGoingUp;
}

void LiftClass::resumeLift() {
    m_isLiftPaused = false;
}

void LiftClass::pauseLift() {
    m_isLiftPaused = true;
}

bool LiftClass::getPauseStatus() {
    return m_isLiftPaused;
}

void LiftClass::removeFloorFromDestinationFloor(int floor) {
    auto it = std::find(m_destinationFloors.begin(), m_destinationFloors.end(), floor);
    if(it != m_destinationFloors.end())
        m_destinationFloors.erase(it);
    
    cout << "floor removed from destination floor " << floor << endl;
}

bool LiftClass::isAnyUpperFloor(int curFloor) {

    bool result = false;
    for (int i=0; i < m_destinationFloors.size(); i++) {
        if (curFloor <= m_destinationFloors.at(i)) {
            result = true;
            break;
        }
    }
    return result;
}

bool LiftClass::isAnyLowerFloor(int curFloor) {
    bool result = false;
    
    for (int i=0; i < m_destinationFloors.size(); i++) {
        if (curFloor >= m_destinationFloors.at(i)) {
            result = true;
            break;
        }
    }
    return result;
    
}

void LiftClass::setUpDownStatus() {

    if (isLiftGoingUp() && isAnyUpperFloor(m_currentFloor)) {
        setLiftDirection(true);
    }else {
        setLiftDirection(false);
    }
}

void LiftClass::startLift(){
    
    setIsStop(false);
    if (m_lastTimeInterval == 0) {
        m_lastTimeInterval = m_timerInstance->getCurrentTime();
    }
    
    while(!getIsStop()) {
    
        time_t timeElapsed = m_timerInstance->getCurrentTime() - m_lastTimeInterval;
        if (timeElapsed >= getLiftSpeed()){
            
            setUpDownStatus();
            
            if (m_destinationFloors.size() > 0 && getPauseStatus()) {
                resumeLift();
            }else {
                pauseLift();
            }
            
            if (isLiftGoingUp()){
                increaseFloor();
            }else{
                decreaseFloor();
            }
            cout << "current floor is " << getCurrentFloor() << endl;
            m_lastTimeInterval = m_timerInstance->getCurrentTime();
        }
    }
    
}
