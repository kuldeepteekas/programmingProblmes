//
//  TimerClass.hpp
//


#ifndef TimerClass_hpp
#define TimerClass_hpp

#include <time.h>

class TimerClass {
    
private:
    TimerClass();
    
public:
    static TimerClass* getInstance();
    
    long getLastTimeFromSeconds(long seconds);
    time_t getCurrentTime();
    long getTimeDifferenceInMs(time_t time);
    
};
#endif /* TimerClass_hpp */
