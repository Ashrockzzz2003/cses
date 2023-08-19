#include <iostream>
using namespace std;

void generateGrayCode(int n) {
    // Edge case
    if (n <= 0) {
        return;
    }

    string gray_code[1 << n];

    gray_code[0] = "0";
    gray_code[1] = "1";

    for (int i = 2; i < (1 << n); i = i << 1) {
        for (int j = i - 1; j >= 0; j--) {
            gray_code[2*i - j - 1] = gray_code[j];
        }

        for (int j = 0; j < i; j++) {
            gray_code[j] = "0" + gray_code[j];
        }

        for (int j = i; j < 2*i; j++) {
            gray_code[j] = "1" + gray_code[j];
        }
    }

    // Print contents of gray_code[]
    for (int i = 0; i < (1 << n); i++) {
        cout << gray_code[i] << endl;
    }

    return;
}

int main() {
    int n;
    cin >> n;

    generateGrayCode(n);
}