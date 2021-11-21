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

Pomodoro& Pomodoro::operator=(const Pomodoro &other) {

    if(this == &other) {
        std::cout << "Uh-oh, tried to do a self-assignment 😢" << std::endl;
        return *this;
    }
    std::cout << "Called assignment operator 🤙" << std::endl;

    body = other.body;
    title = other.title;
    icon = other.icon;
    time = other.time;
    urgency = other.urgency;
    summary = other.summary;

    return *this;
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
        if(token.compare("stop_after") == 0) {
            this->stop_after=stoi(optiune);
        }

    }
    configFile.close();
}

void Pomodoro::run()
{
    std::cout << "Running every " << this->time << " seconds" << std::endl;

    std::string cmd = 
        "notify-send --urgency " + 
        this->urgency + " " +
        "\"" + this->summary + "\"" + " " +
        "\"" + this->body + "\"" + " " +
        "-a " + "\"" + this->title + "\"" + " " +
        "-i " + "\"" + this->icon + "\"";

    const char *c = cmd.c_str();
    for(int i=0; i < this->stop_after; i++) {
        this->exec(c);
        sleep(stoi(this->time));
    }
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
    std::cout << std::endl << "Done, stopped after " << this-> stop_after << " runs!" << std::endl;
}


} // namespace pomodoro
