#include "util/timer.h"
#include "util/definitions.h"

Timer* Timer::instance_ = nullptr;

Timer::Timer() {
    delta_time_ = (float64)0;
}

void Timer::Start() {
    current_time_ = std::chrono::high_resolution_clock::now();
}

void Timer::Reset() {
    current_time_ = std::chrono::high_resolution_clock::now();
}

void Timer::Update() {
    previous_time_ = current_time_;
    current_time_ = std::chrono::high_resolution_clock::now();
    delta_time_ = static_cast<float64>(
            std::chrono::duration_cast<std::chrono::duration<float64>>(
            current_time_ - previous_time_).count());
}

float64 Timer::delta_time() const {
    return delta_time_;
}

Timer* Timer::GetInstance() {
    if (instance_ == nullptr) {
        instance_ = new Timer();
        instance_->Start();
    }
    return instance_;
}
