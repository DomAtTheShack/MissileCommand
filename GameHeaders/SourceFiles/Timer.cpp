#include "../Timer.h"

Timer::Timer(int duration) : duration(duration), running(false), flag(false) {}

void Timer::start() {
    startTime = std::chrono::steady_clock::now();
    running = true;
    flag = false;
}

void Timer::update() {
    if (running) {
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
        if (elapsed >= duration) {
            flag = true;
            running = false;
        }
    }
}

bool Timer::isFinished() const {
    return flag;
}
