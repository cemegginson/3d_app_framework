#pragma once

#include <chrono>
#include <memory>

#include "util/definitions.h"

class Timer {
private:
    static Timer* instance_;

    // The clock time when the timer started
    std::chrono::high_resolution_clock::time_point start_ticks_;

    float32 delta_time_;

    Timer();
    ~Timer();
    void Start();


public:
    static Timer* GetInstance();
    void Reset();
    void Update();

    Timer(Timer const&) = delete;
    void operator=(Timer const&) = delete;

    float32 delta_time() const;
};

typedef std::shared_ptr<Timer> TimerPtr;
typedef std::weak_ptr<Timer> TimerWeakPtr;
