#ifndef TIMER_H
#define TIMER_H

#include <thread>
#include <chrono>
#include <functional>

class Timer {

    std::thread Thread;
    bool Alive = false;
    long CallNumer = -1L;
    long repeat_count = -1L;
    std::chrono::milliseconds interval = std::chrono::milliseconds(0);
    std::function<void(void)> funct = nullptr;

    void SleepAndRun() {
        std::this_thread::sleep_for(interval);
        if (Alive)
            Function()();
    }

    void ThreadFunc() {
        if (CallNumer==Infinite)
            while (Alive) {
                SleepAndRun();
            }
        else
            while(repeat_count--){
                SleepAndRun();
            }
    }

public:
    static const long Infinite = -1L;

    // constructors
    Timer () {}
    Timer (const std::function<void(void)> &f) : funct (f) {}
    Timer (const std::function<void(void)> &f, const unsigned long &i, const long repeat = Timer::Infinite) : funct (f),
                                                                                                              interval(std::chrono::milliseconds(i)),
                                                                                                              CallNumer(repeat) {}
    void Start(bool Async=true) {
        if(IsAlive())
            return;

        Alive=true;
        repeat_count = CallNumer;

        if(Async)
            Thread = std::thread(ThreadFunc, this);
        else
            this->ThreadFunc();
    }

    void Stop(){
        Alive = false;
        Thread.join();
    }

    // Setters

    void SetFunction(const std::function<void(void)> &f) {
        funct = f;
    }

    void RepeatCount (const long r) {
        if(Alive)
            return;
        else
            CallNumer = r;
    }

    void SetInterval(const unsigned long &i) {
        if (Alive) {
            return;
        }
        interval = std::chrono::milliseconds(i);
    }

    // Getters

    bool IsAlive () const {
        return Alive;
    }

    long GetLeftCount() const {
        return repeat_count;
    }

    long RepeatCount () const {
        return CallNumer;
    }

    unsigned long Interval() const {
        return interval.count();
    }

    const std::function<void(void)>& Function() const {
        return funct;
    }

};

#endif // TIMER_H
