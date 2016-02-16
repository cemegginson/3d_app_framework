#include "util/timer.h"
#include "util/definitions.h"

Timer* Timer::instance_ = nullptr;

Timer::Timer() {
    delta_time_ = (float32)0;
}

void Timer::Start() {
    start_ticks_ = std::chrono::high_resolution_clock::now();
}

void Timer::Reset() {
    start_ticks_ = std::chrono::high_resolution_clock::now();
}

void Timer::Update() {
    delta_time_ = static_cast<float32>(
                    std::chrono::duration_cast<std::chrono::duration<double>>(
                      std::chrono::high_resolution_clock::now() - start_ticks_
                    ).count()
                  );
    start_ticks_ = std::chrono::high_resolution_clock::now();
}

float32 Timer::delta_time() const {
    return delta_time_;
}

Timer* Timer::GetInstance() {
    if (instance_ == nullptr) {
        instance_ = new Timer();
        instance_->Start();
    }
    return instance_;
}
