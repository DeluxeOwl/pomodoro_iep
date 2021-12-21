#include <iostream>
#include "../headers/pomodoro.hpp"
#include <cstdio>
#include <iostream>
#include <memory>

using namespace pomodoro;

Pomodoro* createPomodoro() {
    return new Pomodoro();
}

void lock(Pomodoro &pomLock) {
    std::cout << "Locking Pomodoro 🔒";
    pomLock.setIsLocked(true);
}
void unlock(Pomodoro &pomLock) {
    std::cout << "Unlocking Pomodoro 🔓";
    pomLock.setIsLocked(false);
}

class LockManager{
    private:
        Pomodoro &pomLock;
    public:
        LockManager(Pomodoro &p) : pomLock(p) {
            lock(pomLock);
        }
        ~LockManager() {
            unlock(pomLock);
        }
};

int main() {
    // std::cout<<"Memory leak inc ... 🚰"
    // Pomodoro *pPom1 = createPomodoro();

    // pPom1->fromFile("./config.txt");
    // pPom1->run();
    // pPom1->stop();
    // return 0;

    // delete(pPom1);

    // std::auto_ptr<Pomodoro> pPom2(createPomodoro());
    // std::auto_ptr<Pomodoro> pPom3(pPom2); // pPom3 pointeaza spre obiect, pPom2 e null
    // pPom2 = pPome3 // acum invers ???
    // pPom2->run();
    // pPom2->stop();

    // std::cout<<"Unique pointer 🚱"
    // std::unique_ptr<Pomodoro> pPomUnique(createPomodoro());
    // pPomUnique->fromFile("./config.txt");
    // // std::unique_ptr<Pomodoro> pPomUnique2(pPomUnique); // eroare, nu permite copiere
    // std::unique_ptr<Pomodoro> pPomUnique2 = move(pPomUnique);
    // pPomUnique2->run();

    // Pomodoro pom{};
    // pom.fromFile("./config.txt");

    // LockManager *lockPom = new LockManager(pom);
    // pom.checkLock();
    // delete lockPom;
    // pom.checkLock();
    
    
}