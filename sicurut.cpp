#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class namaPem {
public:
    string nama;
    string kelas;
    int noAbsen;

    namaPem(string n, string k, int na) {
        nama = n;
        kelas = k;
        noAbsen = na;
    }

    void infoPem() {
        cout << "Nama     : " << nama << endl;
        cout << "No Absen : " << noAbsen << endl;
        cout << "Kelas    : " << kelas << endl;
    }
};

int main() {
    int pilihMenu;
    srand(time(0));

    while (true) {
        cout << "===================================================" << endl;
        cout << "===============[ MENCARI SI CURUT ]================" << endl;
        cout << "===================================================" << endl;
        cout << "                     MAIN    (1)                   " << "\n" << endl;
        cout << "                     PEMBUAT (2)                   " << "\n" << endl;
        cout << "                     KELUAR  (3)                   " << endl;
        cout << "===================================================" << endl;
        cout << "Pilih menu [1/2/3]: ";
        cin >> pilihMenu;

        switch (pilihMenu) {
        case 1: {
            system("cls");
            int level = 1;
            int poin = 0;
            int jumlahGoa = 2;

            while (true) {
                string bentukGoa = "|_|";
                int posisiCurut = rand() % jumlahGoa;

                vector<string> goaKosong(jumlahGoa, bentukGoa);
                vector<string> goaCurut(jumlahGoa, bentukGoa);

                goaCurut[posisiCurut] = "|>,<|";

                cout << "LEVEL: " << level << endl;
                cout << "POIN: " << poin << "\n" << endl;
                cout << "Coba kamu cari SI CURUT di salah satu goa ini:\n";
                for (int i = 0; i < jumlahGoa; i++) {
                    cout << goaKosong[i] << " ";
                }
                cout << endl;

                int pilihanTebakan;
                cout << "\nPilih goa nomer berapa yang ada SI CURUT nya! [1 sampai " << jumlahGoa << "]: ";
                cin >> pilihanTebakan;

                if (pilihanTebakan < 1 || pilihanTebakan > jumlahGoa) {
                    system("cls");
                    cout << "Masukkan angka antara 1 dan " << jumlahGoa << ".\n";
                    continue;
                }

                if (pilihanTebakan - 1 == posisiCurut) {
                    cout << "\n";
                    for (int i = 0; i < jumlahGoa; i++) {
                        cout << goaCurut[i] << " ";
                    }
                    cout << "\nSelamat, kamu menang! SI CURUT ada di goa nomer " << posisiCurut + 1 << "\n";
                    poin += 1;
                 
                    if (poin % 5 == 0) {
                        level += 1;
                        jumlahGoa++;
                    }
                } else {
                    cout << "\n";
                    for (int i = 0; i < jumlahGoa; i++) {
                        cout << goaCurut[i] << " ";
                    }
                    cout << "\nYahhh KALAH! SI CURUT ada di goa nomer " << posisiCurut + 1 << ", kamu malah milih " << pilihanTebakan << " :(\n";
                }

                char mainLagi;
                cout << "\n\nKamu mau bermain lagi? [y/n]: ";
                cin >> mainLagi;
                system("cls");
                if (mainLagi == 'n' || mainLagi == 'N') {
                    system("cls");
                    break;
                }
            }
            break;
        }
        case 2: {
            system("cls");
            namaPem pembuat1("Adinda Naswa R.", "X RPL 1", 1);
            namaPem pembuat2("Agung Ridho A.", "X RPL 1", 2);
            namaPem pembuat3("Ega Adyatma P.", "X RPL 1", 23);
            namaPem pembuat4("Esa Farellio", "X RPL 1", 26);

            pembuat1.infoPem();
            cout << "===========================" << endl;
            pembuat2.infoPem();
            cout << "===========================" << endl;
            pembuat3.infoPem();
            cout << "===========================" << endl;
            pembuat4.infoPem();
            cout << "===========================\n" << endl;
            break;
        }
        case 3: {
            system("cls");
            cout << "\nTERIMAKASIH SUDAH BERMAIN!\n";
            return 0;
        }
        default:
            system("cls");
            cout << "Pilihan tidak valid. Silakan pilih 1, 2, atau 3.\n";
        }
    }
    return 0;
}