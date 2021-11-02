#include "../headers/pomodoro.hpp"
#include <chrono>
#include <ctime>  
#include <iostream> 
#include <fstream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include<unistd.h>

namespace pomodoro {

void version(){
    std::cout<<"Version 0.1 \n";
}

Pomodoro::Pomodoro()
{
    version();
}
    
void Pomodoro::fromFile(const std::string &path)
{
    std::cout << "Reading from:" << path << std::endl << std::endl;

    // Citesc fisierul de configurare
    std::ifstream configFile(path);
    std::string optiune;
    
    while (std::getline(configFile, optiune)) {
        const std::string delimitator = "="; 
        std::string token = optiune.substr(0, optiune.find(delimitator));
        optiune.erase(0, optiune.find(delimitator) + delimitator.length());
        
        if(token.compare("urgency") == 0) {
            this->urgency=optiune;
        }
        if(token.compare("summary") == 0) {
            this->summary=optiune;
        }
        if(token.compare("body") == 0) {
            this->body=optiune;
        }
        if(token.compare("title") == 0) {
            this->title=optiune;
        }
        if(token.compare("icon") == 0) {
            this->icon=optiune;
        }
        if(token.compare("time") == 0) {
            this->time=optiune;
            this->time.pop_back();
        }

    }
    configFile.close();
}

void Pomodoro::run()
{
    std::cout << this->time << std::endl;

    std::string cmd = 
        "notify-send --urgency " + 
        this->urgency + " " +
        "\"" + this->summary + "\"" + " " +
        "\"" + this->body + "\"" + " " +
        "-a " + "\"" + this->title + "\"" + " " +
        "-i " + "\"" + this->icon + "\"";

    std::cout << cmd << std::endl;

    const char *c = cmd.c_str();
    this->exec(c);
    sleep(2);
}

std::string Pomodoro::exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

void Pomodoro::stop()
{    
    std::cout << std::endl << "Byeee!" << std::endl;
}


} // namespace pomodoro
