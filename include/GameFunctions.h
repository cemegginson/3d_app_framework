#pragma once

#include "Definitions.h"

const float32 fPRV = 10.0f;

inline float32 PW2RW(float32 x){return x*fPRV;}

inline float32 RW2PW(float32 x){return x/fPRV;}

inline float32 RW2PW(int x){return (float32)x/fPRV;}

//degrees to radians
inline float32 RW2PWAngle(float32 x){return((float32)x*(2.0f*3.14159f)/360.0f);}

//radians to degrees
inline float32 PW2RWAngle(float32 x){return((float32)x*360.0f/(2.0f*3.14159f));}
