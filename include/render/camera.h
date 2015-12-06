#pragma #ifndef

#include "core/input_device.h"
#include "util/definitions.h"

class Camera {
protected:
    InputDevice* input_device_;
    uint32 velocity_;

public:
    bool Initialize(InputDevice*);
    void Update(float32);
}
