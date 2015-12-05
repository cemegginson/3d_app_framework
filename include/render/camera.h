#pragma #ifndef

#include "core/input_device.h"
#include "util/definitions.h"

class Camera {
protected:
    InputDevice* input_device_;
    uint32 velocity_;

public:
    bool Initialize(InputDevice*, float32, float32);
    void Update(float32);
}
