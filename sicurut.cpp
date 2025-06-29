#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <limits>
#include <fstream>

#ifdef _WIN32
    #define CLEAR "cls"
    #define PAUSE "pause"
#else
    #define CLEAR "clear"
    #define PAUSE "read -p 'Press Enter to continue...' var"
#endif

using namespace std;

string player;

class NamaPem {
public:
    string nama;
    string kelas;
    int noAbsen;

    NamaPem(string n, string k, int na) : nama(n), kelas(k), noAbsen(na) {}

    void infoPem() const {
        cout << "Nama     : " << nama << endl;
        cout << "No Absen : " << noAbsen << endl;
        cout << "Kelas    : " << kelas << endl;
    }
};

void tampilkanMenu() {
    system(CLEAR);
    cout << "===================================================\n";
    cout << "=================[ CARI SI CURUT ]=================\n";
    cout << "===================================================\n";
    cout << "                     MAIN    (1)                   \n\n";
    cout << "                     PEMBUAT (2)                   \n\n";
    cout << "                     KELUAR  (3)                   \n";
    cout << "===================================================\n";
    cout << "Pilih menu [1/2/3]: ";
}

int loadPoin() {
    ifstream file(player + ".txt");
    int poin = 0;
    if (file.is_open()) {
        file >> poin;
        file.close();
    }
    return poin;
}

void savePoin(int poin) {
    ofstream file(player + ".txt");
    if (file.is_open()) {
        file << poin;
        file.close();
    }
}

int loadLevel() {
    ifstream file(player + "_level.txt");
    int level = 1;
    if (file.is_open()) {
        file >> level;
        file.close();
    }
    return level;
}

void saveLevel(int level) {
    ofstream file(player + "_level.txt");
    if (file.is_open()) {
        file << level;
        file.close();
    }
}

void mainGame() {
    int level = loadLevel();
    int poin = loadPoin();
    int jumlahGoa = 2 + (level - 1);

    while (true) {
        int posisiCurut = rand() % jumlahGoa;
        vector<string> goaKosong(jumlahGoa, "|_|");
        vector<string> goaCurut(jumlahGoa, "|_|");

        goaCurut[posisiCurut] = "|>,<|";

        cout << "LEVEL: " << level << endl;
        cout << "POIN: " << poin << "\n\n";
        cout << "Hai " << player << ", Coba cari SI CURUT di salah satu goa ini:\n";
        for (const auto& goa : goaKosong) {
            cout << goa << " ";
        }
        cout << endl;

        int pilihanTebakan;
        cout << "\nPilih goa nomor berapa yang ada SI CURUT nya! [1 sampai " << jumlahGoa << "]: ";
        cin >> pilihanTebakan;

        if (cin.fail() || pilihanTebakan < 1 || pilihanTebakan > jumlahGoa) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system(CLEAR);
            cout << "Masukkan angka yang benar antara 1 dan " << jumlahGoa << ".\n";
            continue;
        }

        system(CLEAR);
        cout << "LEVEL: " << level << endl;
        cout << "POIN: " << poin << "\n\n\n";
        for (const auto& goa : goaCurut) {
            cout << goa << " ";
        }
        cout << endl;

        if (pilihanTebakan - 1 == posisiCurut) {
            cout << "\nSelamat, kamu menang! SI CURUT ada di goa nomor " << posisiCurut + 1 << "\n";
            poin++;
            savePoin(poin);

            if (poin % 5 == 0) {
                level++;
                jumlahGoa++;
                saveLevel(level);
            }
        } else {
            cout << "\nYahhh KALAH! SI CURUT ada di goa nomor " << posisiCurut + 1;
            cout << ", kamu malah milih " << pilihanTebakan << " :(\n";
        }

        char mainLagi;
        cout << "\n\nKamu mau bermain lagi? [y/n]: ";
        cin >> mainLagi;
        if (mainLagi == 'n' || mainLagi == 'N') {
            system(CLEAR);
            break;
        }
        system(CLEAR);
    }
}

void tampilkanPembuat() {
    system(CLEAR);
    vector<NamaPem> pembuat = {
        {"Adinda Naswa R.", "X RPL 1", 1},
        {"Agung Ridho A.", "X RPL 1", 2},
        {"Ega Adyatma P.", "X RPL 1", 23},
        {"Esa Farellio", "X RPL 1", 26}
    };

    for (const auto& p : pembuat) {
        p.infoPem();
        cout << "===========================\n";
    }
    system(PAUSE);
    system(CLEAR);
}

int main() {
    srand(time(0));
    cout << "Siapa namamu? ";
    getline(cin, player);

    int pilihMenu;

    while (true) {
        tampilkanMenu();
        cin >> pilihMenu;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system(CLEAR);
            cout << "Pilihan tidak valid. Masukkan angka 1, 2, atau 3.\n";
            continue;
        }

        switch (pilihMenu) {
            case 1:
                system(CLEAR);
                mainGame();
                break;
            case 2:
                tampilkanPembuat();
                break;
            case 3:
                system(CLEAR);
                cout << "\nTERIMAKASIH SUDAH BERMAIN!\n";
                system(PAUSE);
                return 0;
            default:
                system(CLEAR);
                cout << "Pilihan tidak valid. Silakan pilih 1, 2, atau 3.\n";
        }
    }
    return 0;
}
