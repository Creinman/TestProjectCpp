#include <iostream>

using namespace std;

template <typename T>
bool is2pow_1(T num) {
    bool single = false;
    for (int i = 0; i < sizeof(T) * 8; ++i) {
        if (num & (1 << i)) {
            if (single) {
                return false;
            }
            else {
                single = true;
            }
        }
    }
    return single;
}

template <typename T>
bool is2pow_2(T num) {
    while (num > 1) {
        if (num & 1)
            return false;
        num >>= 1;
    }
    return true;
}

template <typename T>
bool is2pow_3(T num) {
    while (num > 1) {
        if (num % 2 != 0)
            return false;
        num /= 2;
    }
    return true;
}

template <typename T>
bool is2pow_4(T num) {
    if (num > 1) {
        if (num & 1)
            return false;
        return is2pow_4(num >> 1);
    }
    return true;
}


int main() {

    unsigned int n;

    cin >> n;

    cout << (is2pow_1(n) ? "YES" : "NOPE") << endl;
    cout << (is2pow_2(n) ? "YES" : "NOPE") << endl;
    cout << (is2pow_3(n) ? "YES" : "NOPE") << endl;
    cout << (is2pow_4(n) ? "YES" : "NOPE") << endl;

    system("pause");
    return 0;
}