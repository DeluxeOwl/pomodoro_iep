#include <iostream>
#include "../headers/pomodoro.hpp"
#include <cstdio>
#include <iostream>


int main() {
    pomodoro::Pomodoro pomodoro{};

    pomodoro.fromFile("./config.txt");
    
    pomodoro::Pomodoro copy{};
    copy = pomodoro;

    pomodoro = pomodoro;

    copy.run();
    
    copy.stop();
    return 0;
}