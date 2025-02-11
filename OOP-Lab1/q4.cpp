#include <iostream>
using namespace std;

int main() {
    int i, count, j, k, maxArea = 0;

    cout << "how many heights do you want to enter: ";
    cin >> count;

    int height[count];
    for(i = 0; i < count; i++) {
        cout << "enter height: ";
        cin >> height[i];
    }

    for(j = 0; j < count - 1; j++) {
        for(k = j + 1; k < count; k++) {
            if(height[j] <= height[k]) {
                if(height[j] * (k - j) >= maxArea) {
                    maxArea = height[j] * (k - j);
                }
            } else {
                if(height[k] * (k - j) >= maxArea) {
                    maxArea = height[k] * (k - j);
                }
            }
        }
    }

    cout << "The max area which container can contain is " << maxArea << endl;
    return 0;
}