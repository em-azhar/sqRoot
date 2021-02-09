//
//  main.cpp
//  sqRoot
//
//  Created by Azhar on 2/9/21.
//

#include <iostream>
using namespace std;

int checkRange(int x) {
    int fTempA, fTempB;
    int tempA = 1;
    int tempB = tempA + 2;
    fTempA = pow(tempA, 2) - x;
    fTempB = pow(tempB, 2) - x;
    
    bool check3 = !((fTempA <= 0 && fTempB >= 0) || (fTempB <= 0 && fTempA >= 0));
    
    while (check3) {
        tempA++;
        tempB++;
        fTempA = pow(tempA, 2) - x;
        fTempB = pow(tempB, 2) - x;
        check3 = !((fTempA < 0 && fTempB > 0) || (fTempB < 0 && fTempA > 0));
    }
    return tempA;
}

int main() {
    double a, b, temp, midValue;
    double fa, fb, fc;
    int x;
    cout << "Enter any number: ";
    cin >> x;
    a = checkRange(x);
    b = a + 2;
    temp = b - a;
    midValue = (a + b) / 2;
    fc = pow(midValue, 2) - x;
    if (fc == 0) {
        cout << midValue;
    } else {
        while (temp >= 0.00001) {
            temp = b - a;
            midValue = (a + b) / 2;
            fa = pow(a, 2) - x;
            fb = pow(b, 2) - x;
            fc = pow(midValue, 2) - x;
            if (fc * fa < 0) {
                b = midValue;
            } else if (fc * fb < 0) {
                a = midValue;
            }
        }
        cout << a;
    }
    return 0;
}
