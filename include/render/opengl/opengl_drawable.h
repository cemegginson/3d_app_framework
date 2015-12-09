#pragma once

#include "virtual/component.h"

Class OpenGlDrawable : Component {
protected:
    OpenGlModel* model_;

public:
    OpenGlDrawable();
    ~OpenGlDrawable();
    
    void Draw();
}
