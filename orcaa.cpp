#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Parent class
class KomponenROV {
protected:
    string nama;
    string status;

public:
    KomponenROV(string nama, string status) {
        this->nama = nama;
        this->status = status;
    }

    virtual void info() {
        cout << nama << " " << status << endl;
    }

    virtual ~KomponenROV() {}
};

// Child class Thruster
class Thruster : public KomponenROV {
private:
    int power;

public:
    Thruster(string nama, string status, int power)
        : KomponenROV(nama, status) {
        this->power = power;
    }

    void info() override {
        cout << nama << " " << status << " " << power << endl;
    }
};

// Child class Sensor
class Sensor : public KomponenROV {
private:
    int nilai;

public:
    Sensor(string nama, string status, int nilai)
        : KomponenROV(nama, status) {
        this->nilai = nilai;
    }

    void info() override {
        cout << nama << " " << status << " " << nilai << endl;
    }
};

int main() {
    int n;
    cin >> n;

    vector<KomponenROV*> komponen;

    for (int i = 0; i < n; i++) {
        string jenis, nama, status;
        int nilai;

        cin >> jenis >> nama >> status >> nilai;

        if (jenis == "Thruster") {
            komponen.push_back(new Thruster(nama, status, nilai));
        }
        else if (jenis == "Sensor") {
            komponen.push_back(new Sensor(nama, status, nilai));
        }
    }

    cout << n << endl;

    for (KomponenROV* k : komponen) {
        k->info();
    }

    // Menghapus objek yang dibuat dengan new
    for (KomponenROV* k : komponen) {
        delete k;
    }

    return 0;
}