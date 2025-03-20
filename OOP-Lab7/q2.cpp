#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string color;
    int positionX, positionY;

public:
    Shape(string c, int x, int y) : color(c), positionX(x), positionY(y) {}

    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(string c, int x, int y, double r) : Shape(c, x, y), radius(r) {}

    void draw() override {
        cout << "Drawing a Circle at (" << positionX << ", " << positionY << ") with color " << color << endl;
    }

    double calculateArea() override {
        return 3.14 * radius * radius;
    }

    double calculatePerimeter() override {
        return 2 * 3.14 * radius;
    }
};

int main() {
    Shape* shape = new Circle("Red", 5, 5, 10);
    shape->draw();
    cout << "Area: " << shape->calculateArea() << endl;
    cout << "Perimeter: " << shape->calculatePerimeter() << endl;

    delete shape;
    return 0;
}
