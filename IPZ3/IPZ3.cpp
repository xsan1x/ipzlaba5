#include <iostream>
#include <fstream>

using namespace std;

void checkValidInput() {
    if (cin.fail()) { throw "Incorrect input"; }
}

void check_Valid_Params(double& a, double& b, double& h, double& n) {
    if (h <= 0 || a > b || n < 2 ) {
        throw  "Error. Wrong data";
    }
}

double calculate(double& x, double& n) {
    double y;
    if (x >= 0) {
        y = 0;
        for (int i = 1; i < n; ++i) {
            y += x / i;
        }
    }
    else {
        y = 1;
        for (int i = 1; i < n; ++i) {
            double s = 0;

            for (int j = 1; j <= n; ++j) {
                s += (x - i + j);
            }
            y *= s;
        }
    }
    return y;
}
void calculate_In_A_Loop(double& x, double& b, double& h, double& n, bool& stream) {
    ofstream fout("file.txt");
    while (x < b) {
        if (stream) {
            fout << "x = " << x << endl;
            fout << "y = " << calculate(x, n) << endl;
        }
        cout << "x = " << x << endl;
        cout << "y = " << calculate(x, n) << endl;
        x += h;
    }
    fout.close();
    }   

int main()
{
    double a, b, h, n;
    bool stream;
    ofstream fout;
    try {
        cout << "Enter a: ";
        cin >> a;
        cout << "Enter b: ";
        cin >> b;
        cout << "Enter h: ";
        cin >> h;
        cout << "Enter n: ";
        cin >> n;
        cout << "Do you want write to file? [1 - yes, 0 - no] ";
        cin >> stream;
        checkValidInput();
        calculate_In_A_Loop(a, b, h, n, stream);
    }
    catch (const char* ch) {
        cout << ch << endl;
        return -1;
    }
    catch (...) {
        cout << "Error" << endl;
        return -2;
    }
}