#include "BeloveEngine.hpp" 
#include <string>

class sprite_loading : public Engine {
public:
    sprite_loading(int w, int h, const std::string& t) : Engine(w, h, t) {}
    
protected:
    void ready() override {}

    void update() override {}
    
    void render() override {
        // Clearing the screen with a white color
        Draw::clear({255, 255, 255, 255});
    }
};

int main(int argc, char* argv[]) {
    // we will use 800x600 resolution
    sprite_loading game(800, 600, "basic window");
    if (!game.init()) return 1;
    game.run();
    return 0;
}