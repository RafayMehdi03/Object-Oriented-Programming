#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    void display() const {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    void addTime(const Time &t1, const Time &t2) {
        seconds = t1.seconds + t2.seconds;
        minutes = t1.minutes + t2.minutes + seconds / 60;
        hours = t1.hours + t2.hours + minutes / 60;

        seconds %= 60;
        minutes %= 60;
        hours %= 24;
    }
};

int main() {
    const Time time1(5, 30, 45);
    const Time time2(3, 45, 15);
    Time result;
    result.addTime(time1, time2);
    result.display();
    return 0;
}
