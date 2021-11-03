#ifndef POMODORO_HPP
#define POMODORO_HPP

#include <string>
namespace pomodoro {

class Pomodoro
{
public:
    Pomodoro();
    
    ~Pomodoro() = default;
    
public:
    void fromFile(const std::string &path);
    
    void run();
    
    void stop();
private:
    // initializare
    std::string urgency = "low";
    std::string summary = "sample summary";
    std::string body = "sample body";
    std::string title = "sample title";
    std::string icon = "";
    std::string time = "30";
    int stop_after = 3;

    std::string exec(const char* cmd);

    Pomodoro(const Pomodoro&);
    Pomodoro& operator=(const Pomodoro&);

};

} 

#endif