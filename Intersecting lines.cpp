#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;
};

struct Line {
    double a, b, c;
};

Line modelLine(Point p1, Point p2) {
    Line linea;
    if (fabs(p1.x - p2.x) < EPS) {
        linea.a = 1.0; linea.b = 0.0; linea.c = -p1.x;
    } else {
        linea.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        linea.b = 1.0;
        linea.c = -(double)(linea.a * p1.x) - p1.y;
    }
    return linea;
}

bool verfParalelismo(Line l1, Line l2) {
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

bool verfIguales(Line l1, Line l2) {
    return verfParalelismo(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

bool verfIntersect(Line l1, Line l2, Point &p) {
    if (verfParalelismo(l1, l2)){
        return false;
    }
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS){
        p.y = -(l1.a * p.x + l1.c);
    }else{
        p.y = -(l2.a * p.x + l2.c);
    }
    return true;
}

int main() {
    int tc;
    cin >> tc;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    while(tc--) {
        Point p1, p2, p3, p4;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
        Line l1 = modelLine(p1, p2);
        Line l2 = modelLine(p3, p4);
        Point intersectPoint;
        if (verfIguales(l1, l2)) {
            cout << "LINE";
        } else if (verfIntersect(l1, l2, intersectPoint)) {
            cout << fixed << setprecision(2) << "POINT " << intersectPoint.x << " " << intersectPoint.y;
        } else {
            cout << "NONE";
        }
        cout << endl;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}