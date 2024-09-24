#include <bits/stdc++.h>

using namespace std;

double calcRadio(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    double r = area / s;
    return r;
}

int main() {
    double a, b, c;
    while (cin >> a >> b >> c) {
        cout << "The radius of the round table is: ";
        if(a == 0 || b == 0 || c == 0){
            cout << "0.000" << endl;
        }else{
            double radio = calcRadio(a, b, c);
            cout << fixed << setprecision(3) << radio << endl;
        }
    }
    return 0;
}