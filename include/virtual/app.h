#pragma once

class App {
protected:

public:
    // virtual App() = 0;
    // virtual ~App() = 0;
    virtual bool Initialize(Renderer*, InputDevice*) = 0;
    virtual void Reset() = 0;
    virtual bool LoadLevel(std::string) = 0;
    virtual void Run() = 0;
    virtual void Update() = 0;
};
