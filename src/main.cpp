#include <iostream>
#include "../headers/pomodoro.hpp"
#include <cstdio>
#include <iostream>


int main() {
    pomodoro::Pomodoro pomodoro{};

    pomodoro.fromFile("./config.txt");
    
    pomodoro.run();
    
    pomodoro.stop();
    return 0;
}