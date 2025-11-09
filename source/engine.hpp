#pragma once
#include <string>
#include "platform.hpp"
#include "utils/color.hpp"
#include "utils/math.hpp"
#include "utils/log.hpp"
#include "utils/rect.hpp"

class Engine {
public:
    Engine(int width, int height, const std::string& title);
    virtual ~Engine();

    bool init();
    void run();

protected:
    virtual void ready() {}
    virtual void update() {}
    virtual void render() {}
    virtual void handleInput();

    int width, height;
    std::string title;
    bool running;
};
