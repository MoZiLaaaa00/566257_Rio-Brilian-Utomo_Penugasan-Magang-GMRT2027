#include <iostream>
using namespace std;

long long ceilDiv(long long a, long long b) {
    return (a + b - 1) / b;
}

int main() {
    long long n, m, k;

    cin >> n >> m >> k;


    if (n % 3 != 0 || m % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }

    if (n == 0 && m == 0) {
        cout << 0 << endl;
        return 0;
    }


    if (n > 0 && k < 2) {
        cout << -1 << endl;
        return 0;
    }

    long long langkah = 0;



    if (n > 0) {
        long long kapasitas2 = k / 2;


        long long pindah2 = 2 * (n / 3);


        long long muat2 = ceilDiv(pindah2, kapasitas2);


        long long bongkar2 = 2;

        langkah += muat2 + bongkar2;
    }


    if (m > 0) {
        long long kapasitas1 = k;


        long long pindah1 = 2 * (m / 3);


        long long muat1 = ceilDiv(pindah1, kapasitas1);


        long long bongkar1 = 2;

        langkah += muat1 + bongkar1;
    }

    cout << langkah << endl;

    return 0;
}