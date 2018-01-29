//
//  TimerClass.cpp
//
#include "TimerClass.hpp"


static TimerClass* instance = nullptr;

TimerClass::TimerClass() {
}

TimerClass* TimerClass::getInstance() {
    if(instance == nullptr) {
        instance = new TimerClass();
    }
    return instance;
}


time_t TimerClass::getCurrentTime() {
    time_t tE;
    tE = time(0);
    return tE;
}

long TimerClass::getTimeDifferenceInMs(time_t startTime) {
    time_t tv = getCurrentTime();
    long returnVal = tv - startTime;
    return returnVal;
}
