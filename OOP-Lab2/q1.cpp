#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    float* arr = new float[n];

    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> *(arr + i);
    }

    float sum = 0.0f;
    for (int i = 0; i < n; ++i) {
        sum += *(arr + i);
    }
    float average = sum / n;

    float* closest = arr;
    float min_diff = *(arr + 0) - average;

    if (min_diff < 0) min_diff = -min_diff;

    for (int i = 1; i < n; ++i) {
        float diff = *(arr + i) - average;
        if (diff < 0) diff = -diff;
        if (diff < min_diff) {
            min_diff = diff;
            closest = arr + i;
        }
    }

    cout << "Average: " << average << endl;
    cout << "Number closest to the average: " << *closest << endl;

    delete[] arr;

    return 0;
}
