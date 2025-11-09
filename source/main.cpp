#include "engine.hpp" 
#include "utils/math.hpp"
#include <algorithm>
#include <string>

vector2 player_pos = {15, 15};
vector2 player_vel = {0, 0};

float acceleration = 100.0f;
float max_speed = 50.0f;
int delta_time = 0;
s_texture test_texture;
class MyGame : public Engine {
public:
    MyGame(int w, int h, const std::string& t) : Engine(w, h, t) {}
    
protected:
    void ready() override {
        //player = load_image("assets/TBOI/player_idle.png");
        test_texture = load_image("player_idle.png");
    }

    void update() override {
        delta_time += 1;
        player_vel = {0, 0};
        if (Input::is_down(key_W)) {
            player_vel.y -= acceleration * delta_time;
        }
        if (Input::is_down(key_S)) {
            player_vel.y += acceleration * delta_time;
        }
        if (Input::is_down(key_A)) {
            player_vel.x -= acceleration * delta_time;
        }
        if (Input::is_down(key_D)) {
            player_vel.x += acceleration * delta_time;
        }

        player_pos.x += player_vel.x;
        player_pos.y += player_vel.y;

        player_pos.x = std::clamp(player_pos.x, 0.0f, static_cast<float>(480 - 16));
        player_pos.y = std::clamp(player_pos.y, 0.0f, static_cast<float>(272 - 16));
    }
    
    void render() override {
        Draw::clear({255, 255, 255, 255});
        Draw::draw_texture(test_texture, 15, 15);
    }
};

int main() {
    MyGame game(480, 272, "My game!");
    if (!game.init()) return 1;
    game.run();
    return 0;
}