#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    double a, b, h, n, x; 
    bool f;
    ofstream fout;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter h: ";
    cin >> h;
    cout << "Enter n: ";
    cin >> n;
    cout << "Do you want write to file? [1 - yes, 0 - no] ";
    cin >> f;
    
    if (h <= 0 || a > b || n < 2 || f != true && f != false) {
        cout << "Error. Wrong data";
        return 0;
    }
    x = a;
    fout.open("Text.txt");
    while (x < b)
    {
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
        cout << "y = " << y << endl;
        cout << "x = " << x << endl;
        if (f) {
            fout << "x = " << x << endl;
            fout << "y = " << y << endl;
        }
        x += h;
    }
    fout.close();
}