#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>
#include <Windows.h>
using namespace std;

void displayGroupInfo() {
    const HANDLE oh = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(oh, 4);
    cout << "\tNAMA KELOMPOK\n";
    cout << "+----+------------------------------+--------------+\n";
    SetConsoleTextAttribute(oh, 1);
    cout << "| NO |" << setw(30) << left << "      Nama" << "|" << setw(14) << left << "     NIM" << "|" << endl;
    cout << "+----+------------------------------+--------------+\n";
    SetConsoleTextAttribute(oh, 13);
    cout << "| 1. |" << setw(30) << left << "   Muhammad Ariel EkaPutra" << "|" << setw(14) << left << "  23.11.5754" << "|" << endl;
    cout << "+----+------------------------------+--------------+\n";
    SetConsoleTextAttribute(oh, 12);
    cout << "| 2. |" << setw(30) << left << "   Erhansa Pratama Aryana" << "|" << setw(14) << left << "  23.11.5761" << "|" << endl;
    cout << "+----+------------------------------+--------------+\n";
    SetConsoleTextAttribute(oh, 10);
    cout << "| 3. |" << setw(30) << left << "   Muhammad" << "|" << setw(14) << left << "  23.11.5786" << "|" << endl;
    cout << "+----+------------------------------+--------------+\n";
    SetConsoleTextAttribute(oh, 6);
    cout << "| 4. |" << setw(30) << left << "   Akmal Harizulhaq" << "|" << setw(14) << left << "  23.11.5783" << "|" << endl;
    cout << "+----+------------------------------+--------------+\n";
    SetConsoleTextAttribute(oh, 7);
    cout << "\n";

    system("pause");
    system("cls");
}

int main() {
    string input;

    displayGroupInfo();  // Pemanggilan hanya dilakukan satu kali

    do {
        cout << "Masukkan bilangan yang ingin anda konversi: ";
        cin >> input;

        int choice;

        cout << "Pilihan tipe bilangan yang anda masukkan:" << endl;
        cout << "1. Desimal" << endl;
        cout << "2. Biner" << endl;
        cout << "3. Oktal" << endl;
        cout << "4. Heksadesimal" << endl;
        cout << "Pilihlah tipe bilangan (1-4): ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (isdigit(input[0])) {
                int num = stoi(input);
                cout << "Biner: " << bitset<32>(num) << endl;
                cout << "Oktal: " << oct << num << endl;
                cout << "Heksadesimal: " << hex << num << endl;
            }
            else {
                cout << "Format input tidak valid." << endl;
            }
            break;

        case 2:
            if (input.find_first_not_of("01") == string::npos) {
                cout << "Desimal: " << stoi(input, 0, 2) << endl;
                cout << "Oktal: " << oct << stoi(input, 0, 2) << endl;
                cout << "Heksadesimal: " << hex << stoi(input, 0, 2) << endl;
            }
            else {
                cout << "Format input tidak valid." << endl;
            }
            break;

        case 3:
            if (input.find_first_not_of("01234567") == string::npos) {
                cout << "Desimal: " << stoi(input, 0, 8) << endl;
                cout << "Biner: " << bitset<32>(stoi(input, 0, 8)) << endl;
                cout << "Heksadesimal: " << hex << stoi(input, 0, 8) << endl;
            }
            else {
                cout << "Format input tidak valid." << endl;
            }
            break;

        case 4:
            if (input.find_first_not_of("0123456789ABCDEFabcdef") == string::npos) {
                cout << "Desimal: " << stoi(input, 0, 16) << endl;
                cout << "Biner: " << bitset<32>(stoi(input, 0, 16)) << endl;
                cout << "Oktal: " << oct << stoi(input, 0, 16) << endl;
            }
            else {
                cout << "Format input tidak valid." << endl;
            }
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
        }

        int pilihan;
        cout << "Apakah ingin mengkonversi lagi?\n" << "1. Iya\n2. Tidak\n";
        cin >> pilihan;

        if (pilihan != 1) {
            break; // Keluar dari loop jika tidak ingin mengkonversi lagi
        }
        system("cls");
    } while (true);

    return 0;
}