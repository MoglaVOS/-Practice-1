#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    do {
        int hello;
        cout << "Run the program?\n" << "1 - yes\n" << "0 - no\n";
        cin >> hello;
        if (hello == 0) {
            break;
        }
        unsigned x;
        cout << "Enter task number\n";
        cin >> x;
        switch (x) {
            case 1: {
                cout << "How much memory is allocated for different data types: " << "\n";
                cout << "Under int: " << sizeof(int) << "\n";
                cout << "Under short inf: " << sizeof(short) << "\n";
                cout << "Under long int: " << sizeof(long) << "\n";
                cout << "Under float: " << sizeof(float) << "\n";
                cout << "Under double: " << sizeof(double) << "\n";
                cout << "Under long double: " << sizeof(long double) << "\n";
                cout << "Under char: " << sizeof(char) << "\n";
                cout << "Under bool: " << sizeof(bool) << "\n";
                break;
            }

            case 2: {
                int value;
                unsigned order = sizeof(int) * 8, mask = pow(2, 31);
                cout << "\n" << "Enter an integer: " << "\n";
                cin >> value;
                for (int i = 1; i <= order; ++i) {
                    putchar(value & mask ? '1' : '0');
                    mask >>= 1;
                    if (i % 8 == 0) {
                        cout << (' ');
                    }
                    if (i % order - 1 == 0) {
                        cout << (' ');
                    }
                }
                cout << endl;
                break;
            }

            case 3: {
                union{float numb_f;int value;};
                unsigned order = sizeof(float) * 8, mask = 1 << (order - 1);
                cout << "\nEnter a float number: \n";
                cin >> numb_f;
                for (int i = 1; i <= order; ++i) {
                    if (i == 2 || i == 10) {  //отделяем знак и мантиссу
                        cout << (' ');
                    }
                    putchar(value & mask ? '1' : '0');
                    mask >>= 1;
                }
                cout << endl;
                break;
            }

            case 4: {
                union {double numb_d;int values[2];};
                unsigned order = sizeof(double) * 8, mask = 1 << (order - 1);
                cout << "\nEnter a floating point number: \n";
                cin >> numb_d;
                for (int j = 1; j >= 0; j--) {
                    for (int i = 1; i <= order / 2; i++) {
                        putchar(values[j] & mask ? '1' : '0');
                        values[j] <<= 1;
                        if ((i == 1 || i == 12) && j == 1) {
                            cout << (' ');
                        }
                    }
                }
                cout << endl;
                break;
            }
            default: {
                cout << "Unknown command\n";
            }
        }
    } while (true);
}