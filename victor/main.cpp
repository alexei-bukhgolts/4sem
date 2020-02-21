#include<iostream>

#include "vec2.h"
using namespace std;

int main(int argc, char const *argv[]) {
    vec2 a = vec2(0.1, 1), b = vec2(1, 0.1);
    cout << "a = (" << a.x << ", " << a.y << "), b = (" << b.x << ", " << b.y << ")" << endl;

    cout << "Enter c..." << endl;
    vec2 c;
    cin >> c;
    cout << "c is " << c << endl;

    cout << "a + b == " << a + b << endl;
    cout << "a += b" << endl;
    a += b;
    cout << "a == " << a << endl;

    cout << "a - b == " << a - b << endl;
    cout << "a -= b" << endl;
    a -= b;
    cout << "a == " << a << endl;

    cout << "a = (1, 2)" << endl;
    a = vec2(1, 1);

    cout << "(1, 5) . (5, 2) == " << vec2(1, 5) * vec2(5, 2) << endl;

    cout << "a * b == " << a * b << endl;

    cout << "a * 3 == " << a * 3 << ", which is also  3 * a == " << 3 * a << endl;

    cout << "a / 3 == " << a / 3 << endl;

    cout << "a normalized is " << a.getNormalized() << endl;

    cout << "Perpendicular to a is " << a.getPerp() << endl;

    cout << "-a == " << -a << endl;

    cout << "a rotated by 2pi/3 and normalized is " << a.getRotated(2. / 3 * 3.14159265358979).getNormalized() << endl;

    cout << "rotating a..." << endl;
    a = a.rotate(2. / 3 * 3.14159265358979);
    cout << "a == " << a << endl;

    cout << "a ** 2  == " << a.lenSquared() << endl;

    return 0;
}
