#include "../headers/pomodoro.hpp"
#include <chrono>
#include <ctime>  
#include <iostream> 

namespace pomodoro {

void version(){
std::cout<<"Version 03 \n";
}

Pomodoro::Pomodoro()
{
    this->timeMesage = "Data si ora de azi: ";
    version();
}
    
void Pomodoro::start()
{
    std::cout << "Salut!" << std::endl << std::endl;
}

void Pomodoro::run()
{
    std::time_t crttime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::cout << timeMesage << std::ctime(&crttime) << std::endl;        
}


void Pomodoro::stop()
{    
    std::cout << "Pa Pa!" << std::endl;
}


} // namespace pomodoro
