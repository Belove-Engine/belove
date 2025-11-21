#include "BeloveEngine.hpp" 
#include <string>

s_texture bird;

class sprite_loading : public Engine {
public:
    sprite_loading(int w, int h, const std::string& t) : Engine(w, h, t) {}
    
protected:
    void ready() override {
        bird = load_image("../assets/bird.png");
    }

    void update() override {}
    
    void render() override {
        // Clearing the screen with a white color
        Draw::clear({255, 255, 255, 255});

        // Drawing the loaded texture at 100, 100
        Draw::draw_texture(bird, 100, 100);
    }
};

int main() {
    // we will use 800x600 resolution
    sprite_loading game(800, 600, "basic window");
    if (!game.init()) return 1;
    game.run();
    return 0;
}