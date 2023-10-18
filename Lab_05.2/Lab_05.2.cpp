#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void S(const double x, const double eps, int& n, double& s);
void A(const double x, const int n, double& a);

int main() {
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = ";
    cin >> xp;
    cout << "xk = ";
    cin >> xk;
    cout << "dx = ";
    cin >> dx;
    cout << "eps = ";
    cin >> eps;

    cout << fixed;
    cout << "-----------------------------------------------------" << endl;
    cout << "|" << setw(10) << left << "x" << " |"
        << setw(15) << left << "arctan(x)" << " |"
        << setw(15) << left << "S" << " |"
        << setw(5) << right << "n" << " |"
        << endl;
    cout << "-----------------------------------------------------" << endl;

    x = xp;
    while (x <= xk) {
        S(x, eps, n, s);
        cout << "|" << setw(10) << left << setprecision(2) << x << " |"
            << setw(15) << left << setprecision(5) << atan(x) << " |"
            << setw(15) << left << setprecision(5) << s << " |"
            << setw(5) << right << n << " |"
            << endl;
        x += dx;
    }

    cout << "-----------------------------------------------------" << endl;
    return 0;
}

void S(const double x, const double eps, int& n, double& s) {
    n = 0;
    double a = x;
    s = a;
    do {
        n++;
        A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
}

void A(const double x, const int n, double& a) {
    double R = -x * x * (2 * n - 1) / (2 * n + 1);
    a *= R;
}
