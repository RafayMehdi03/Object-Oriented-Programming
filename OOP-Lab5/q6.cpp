#include <iostream>
using namespace std;

class GraphicsEngine {
    string graphicsType;
public:
    GraphicsEngine(string type) : graphicsType(type) {}
    void render() {
        cout << "Rendering " << graphicsType << " graphics..." << endl;
    }
};

class InputHandler {
    string inputMethod;
public:
    InputHandler(string method) : inputMethod(method) {}
    void handleInput() {
        cout << "Handling input via " << inputMethod << "..." << endl;
    }
};

class PhysicsEngine {
    string physicsType;
public:
    PhysicsEngine(string type) : physicsType(type) {}
    void simulate() {
        cout << "Simulating " << physicsType << " physics..." << endl;
    }
};

class GameEngine {
    GraphicsEngine graphics;
    InputHandler input;
    PhysicsEngine physics;
public:
    GameEngine(GraphicsEngine g, InputHandler i, PhysicsEngine p)
        : graphics(g), input(i), physics(p) {}
    
    void start() {
        graphics.render();
        input.handleInput();
        physics.simulate();
    }
};

int main() {
    GraphicsEngine graphics("3D");
    InputHandler input("Keyboard");
    PhysicsEngine physics("Realistic");

    GameEngine game(graphics, input, physics);
    game.start();
    
    return 0;
}

