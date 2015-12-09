#pragma #ifndef

#include "core/input_device.h"
#include "util/definitions.h"

class Camera {
protected:
    InputDevice* input_device_;

public:
    virtual bool Initialize(InputDevice*) = 0;
    virtual void Update(float32) = 0;
}
