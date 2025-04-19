#include <iostream>

using namespace std;

class Activity {
public:
    virtual double calculateCaloriesBurned() = 0;
    virtual ~Activity() {}
};

class Running : public Activity {
private:
    double distance;
    double time;
public:
    Running(double d, double t) {
        distance = d;
        time = t;
    }
    double calculateCaloriesBurned() {
        return distance * 60;
    }
};

class Cycling : public Activity {
private:
    double speed;
    double time;
public:
    Cycling(double s, double t) {
        speed = s;
        time = t;
    }
    double calculateCaloriesBurned() {
        return speed * time * 5;
    }
};

int main() {
    Running r(5, 30);
    Cycling c(20, 1);

    cout << "Running Calories Burned: " << r.calculateCaloriesBurned() << endl;
    cout << "Cycling Calories Burned: " << c.calculateCaloriesBurned() << endl;

    return 0;
}
