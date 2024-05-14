#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct dataMahasiswa
{
    long long Nim_2311102033;
    int nilai;
};

class HashTable
{
private:
    static const int hashGroup = 10;
    vector<list<dataMahasiswa>> table;

public:
    HashTable() : table(hashGroup) {}
    int hashFunction(long long Nim_2311102033)
    {
        return Nim_2311102033 % hashGroup;
    }

    void tambahData(long long Nim_2311102033, int nilai)
    {
        dataMahasiswa mhs;
        mhs.Nim_2311102033 = Nim_2311102033;
        mhs.nilai = nilai;
        int hashKey = hashFunction(Nim_2311102033);
        table[hashKey].push_back(mhs);
    }
    void hapusData(long long Nim_2311102033)
    {
        int hashKey = hashFunction(Nim_2311102033);
        for (auto it = table[hashKey].begin(); it != table[hashKey].end(); ++it)
        {

            if ((*it).Nim_2311102033 == Nim_2311102033)
            {
                table[hashKey].erase(it);
                cout << "Nim " << it->Nim_2311102033 << " telah di hapus" << endl;
                break;
            }
        }
    }
    void cariNIM(long long Nim_2311102033)
    {
        int hashKey = hashFunction(Nim_2311102033);
        for (auto mhs : table[hashKey])
        {
            if (mhs.Nim_2311102033 == Nim_2311102033)
            {
                cout << "Nim: " << mhs.Nim_2311102033 << ", Nilai: " << mhs.nilai << endl;
                return;
            }
        }
        cout << "Data mahasiswa dengan Nim " << Nim_2311102033 << " tidak." << endl;
    }
    void cariRentang()
    {
        for (const auto &group : table)
        {
            for (const auto &mhs : group)
            {
                if (mhs.nilai >= 80 && mhs.nilai <= 90)
                {
                    cout << "Nim: " << mhs.Nim_2311102033 << ", Nilai: " << mhs.nilai << endl;
                }
            }
        }
    }
};
int main()
{
    int Pilihanmu, nilai;
    long long Nim_2311102033;
    HashTable hashTable;

    cout << "\n\t\t     PROGRAM UNTUK MENYIMPAN DATA MAHASISWA\n\n";
    cout << "+--------------------------------------------------------------------------+\n";
    cout << "| Menu | Pilihan |                     Keterangan                          |\n";
    cout << "+------+---------+---------------------------------------------------------+\n";
    cout << "|  1   | Tambah  | Tambah data mahasiswa                                   |\n";
    cout << "|  2   | Hapus   | Hapus data mahasiswa                                    |\n";
    cout << "|  3   | Cari    | Cari data mahasiswa berdasarkan Nim                     |\n";
    cout << "|  4   | Rentang | Cari data mahasiswa berdasarkan rentang nilai (80-90)   |\n";
    cout << "|  5   | Keluar  | Keluar dari program                                     |\n";
    cout << "+------+---------+---------------------------------------------------------+\n";

    do
    {
        cout << "Pilih menu (1-5): ";
        cin >> Pilihanmu;
        switch (Pilihanmu)
        {
        case 1:
            cout << "Masukkan Nim mahasiswa: ";
            cin >> Nim_2311102033;
            cout << "Masukkan nilai mahasiswa: ";
            cin >> nilai;
            hashTable.tambahData(Nim_2311102033, nilai);
            break;
        case 2:
            cout << "Masukkan Nim mahasiswa yang ingin dihapus: ";
            cin >> Nim_2311102033;
            hashTable.hapusData(Nim_2311102033);
            break;
        case 3:
            cout << "Masukkan Nim mahasiswa yang ingin dicari: ";
            cin >> Nim_2311102033;
            hashTable.cariNIM(Nim_2311102033);
            break;
        case 4:
            cout << "Mahasiswa dengan nilai antara 80 dan 90:" << endl;
            hashTable.cariRentang();
            break;
        case 5:
            cout << "Terimakasih Telah Memakai program ini " << endl;
            break;
        default:
            cout << "NOT FOUND." << endl;
        }
    } while (Pilihanmu != 5);
    return 0;
}
