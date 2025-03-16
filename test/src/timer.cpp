#include "timer.h"

void timerr::await(float seconds,  Callable function){
    Timer *time = memnew(Timer);
    add_child(time);

    time->connect("timeout", function);
    
    time->set_wait_time(seconds);
    time->start();
}
