#include <iostream>
using namespace std;

int main() {
    float rainfall[3][4];
    float total, average;
    string city[3] = {"City1", "City2", "City3"};
    for (int i = 0; i < 3; i++) {
        cout << "Enter rainfall data for " << city[i] << ":" << endl;
        for (int j = 0; j < 4; j++) {
            cout << "Month " << j + 1 << ": ";
            cin >> rainfall[i][j];
        }
        cout << endl;
    }

    cout << endl;
    cout << "Rainfall Tracking:" << endl;
    cout << "Sr No" << endl;
    cout << "City Name" << endl;
    cout << "Month1" << endl;
    cout << "Month2" << endl;
    cout << "Month3" << endl;
    cout << "Month4" << endl;
    cout << "Average Rainfall" << endl << endl;
    cout << "Sr No\tCity Name\tMonth1\tMonth2\tMonth3\tMonth4\tAverage Rainfall\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << "\t" << city[i] << "\t\t";
        total = 0;
        for (int j = 0; j < 4; j++) {
            cout << rainfall[i][j] << "\t";
            total += rainfall[i][j];
        }
        average = total / 4;
        cout << average << endl;
    }

    return 0;
}
