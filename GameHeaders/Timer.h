#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
public:
    Timer(int duration);

    void start();
    void update();
    bool isFinished() const;

    void changeDuration(int dur);

    bool isRunning() const;


private:
    int duration;
    bool running;
    bool flag;
    std::chrono::time_point<std::chrono::steady_clock> startTime;

    void restart();
};

#endif // TIMER_H
