#ifndef POMODORO_HPP
#define POMODORO_HPP

#include <string>
namespace pomodoro {

class Pomodoro
{
public:
    Pomodoro();
    
    ~Pomodoro() = default;
    std::string timeMesage;
    
public:
    void start();
    
    void run();
    
    void stop();
};

} 

#endif