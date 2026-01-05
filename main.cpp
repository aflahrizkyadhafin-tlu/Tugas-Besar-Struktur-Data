#include "film.h"
#include "tiket.h"
#include "fnb.h"
#include <string>
#include <iostream>
using namespace std;

void tampilanHome(listFilm &L);
void tampilanReservasiTiket(listFilm &LFilm);
void tampilanKelolaFilm(listFilm &L);
void tampilanBeliMakanan(NodeTiket &NTiket);

void dataDummy(listFilm &LFilm)
{
    // Data Dummy Film
    adrFilm film1 = alokasiNodeFilm(
        "FLM001",
        "Avengers Endgame",
        "Studio A",
        181,
        2019,
        150,
        50000);
    tambahFilm(LFilm, film1);

    adrFilm film2 = alokasiNodeFilm(
        "FLM002",
        "Spider-Man No Way Home",
        "Studio B",
        148,
        2021,
        120,
        55000);
    tambahFilm(LFilm, film2);

    adrFilm film3 = alokasiNodeFilm(
        "FLM003",
        "The Batman",
        "Studio C",
        176,
        2022,
        100,
        60000);
    tambahFilm(LFilm, film3);

    adrFilm film4 = alokasiNodeFilm(
        "ANM002",
        "Koe No Katachi",
        "Studio 8",
        145,
        2019,
        120,
        55000);
    tambahFilm(LFilm, film4);

    adrFilm film5 = alokasiNodeFilm(
        "ANM001",
        "Kimi no Na wa",
        "Studio 1",
        106,
        2016,
        200,
        45000);
    tambahFilm(LFilm, film5);

    // Data Dummy Tiket
    NodeTiket tiket1 = allocNodeTiket("T001", "Aflah", 2, film5);
    insertFirstTiket(film5->daftarTiket, tiket1);
    NodeTiket tiket2 = allocNodeTiket("T002", "Nadhif", 5, film5);
    insertFirstTiket(film5->daftarTiket, tiket2);
    NodeTiket tiket3 = allocNodeTiket("Q001", "Gilar", 3, film1);
    insertFirstTiket(film1->daftarTiket, tiket3);

    // Data Dummy Makanan
    address makanan1 = alokasi("SNK001", "Popcorn", 15000, 15, tiket1);
    insertLast(tiket1->infoTiket.makanan, makanan1);
    address makanan2 = alokasi("SNK002", "T Bone Steak", 250000, 2, tiket1);
    insertLast(tiket1->infoTiket.makanan, makanan2);
    address makanan3 = alokasi("SNK001", "Popcorn", 15000, 12, tiket2);
    insertLast(tiket2->infoTiket.makanan, makanan3);
}

void tampilanBeliMakanan(NodeTiket &NTiket)
{
    int pilihanBeliMakanan = -1;
    PrintList(NTiket->infoTiket.makanan);

    while (pilihanBeliMakanan != 0)
    {
        cout << "\n==== Beli Makanan ====" << endl;
        cout << "1. Tambah makanan" << endl
             << "2. Lihat Pesanan makanan" << endl
             << "3. Edit makanan" << endl
             << "4. Hapus makanan" << endl
             << "0. Kembali" << endl;
        cout << "Pilih menu : ";
        cin >> pilihanBeliMakanan;
        cout << endl;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            pilihanBeliMakanan = -1;
            continue;
        }

        switch (pilihanBeliMakanan)
        {
        case 1:
        {
            string idMakanan, namaMakanan;
            int hargaMakanan, jumlahMakanan;

            cout << "ID Makanan : ";
            cin >> idMakanan;
            cin.ignore();

            address checkId = searchMakananById(NTiket->infoTiket.makanan, idMakanan);

            if (checkId != NULL)
            {
                cout << "ID makanan sudah digunakan!" << endl;
            }
            else
            {
                cout << "Nama Makanan : ";
                getline(cin, namaMakanan);
                cout << "Harga Makanan : ";
                cin >> hargaMakanan;
                cout << "Jumlah Makanan : ";
                cin >> jumlahMakanan;

                address makananBaru = alokasi(idMakanan, namaMakanan, hargaMakanan, jumlahMakanan, NTiket);
                insertLast(NTiket->infoTiket.makanan, makananBaru);
                cout << "Makanan berhasil ditambahkan!" << endl;
            }
            break;
        }
        case 2:
            cout << "\n=== DAFTAR PESANAN MAKANAN ===" << endl;
            PrintList(NTiket->infoTiket.makanan);
            break;

        case 3:
        {
            string idMakanan;

            cout << "==== Edit menu ====" << endl;
            cout << "ID Makanan : ";
            cin >> idMakanan;

            address cariMakanan = searchMakananById(NTiket->infoTiket.makanan, idMakanan);
            if (cariMakanan != NULL)
            {
                string namaMakanan;
                int hargaMakanan, jumlahMakanan;

                cin.ignore();
                cout << "Nama Makanan : ";
                getline(cin, namaMakanan);
                cout << "Harga Makanan : ";
                cin >> hargaMakanan;
                cout << "Jumlah Makanan : ";
                cin >> jumlahMakanan;

                deleteMakanan(NTiket->infoTiket.makanan, cariMakanan);

                address makananBaru = alokasi(idMakanan, namaMakanan, hargaMakanan, jumlahMakanan, NTiket);
                insertLast(NTiket->infoTiket.makanan, makananBaru);
                cout << "Makanan berhasil diupdate!" << endl;
            }
            else
            {
                cout << "Makanan tidak ditemukan!" << endl;
            }
            break;
        }

        case 4:
        {
            string idMakanan;
            cout << "==== Hapus menu ====" << endl;
            cout << "ID Makanan : ";
            cin >> idMakanan;

            address cariMakanan = searchMakananById(NTiket->infoTiket.makanan, idMakanan);
            if (cariMakanan != NULL)
            {
                deleteMakanan(NTiket->infoTiket.makanan, cariMakanan);
                cout << "Makanan berhasil dihapus!" << endl;
            }
            else
            {
                cout << "Makanan tidak ditemukan!" << endl;
            }
            break;
        }
        case 0:
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }
    }
}

void tampilanReservasiTiket(listFilm &LFilm)
{
    int pilihanMenuReservasi = -1;
    adrFilm aFilm = LFilm.head;

    tampilkanInfoFilm(aFilm);
    while (pilihanMenuReservasi != 0)
    {
        cout << endl;
        cout << "=== MENU RESERVASI TIKET ===" << endl;
        cout << "1. Film selanjutnya" << endl
             << "2. Film sebelumnya" << endl
             << "3. Beli tiket" << endl
             << "4. Cari tiket" << endl
             << "5. Tampilkan seluruh tiket" << endl
             << "6. Pembatalan tiket" << endl
             << "0. Home" << endl;
        cout << "Pilih menu : ";
        cin >> pilihanMenuReservasi;
        cout << endl;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            pilihanMenuReservasi = -1;
            continue;
        }

        switch (pilihanMenuReservasi)
        {
        case 1:
            if (aFilm->next != Nil)
            {
                aFilm = aFilm->next;
            }
            tampilkanInfoFilm(aFilm);
            break;

        case 2:
            if (aFilm->prev != Nil)
            {
                aFilm = aFilm->prev;
            }
            tampilkanInfoFilm(aFilm);
            break;

        case 3:
        {
            string idTiket, namaPembeli;
            int jumlahTiket;
            cout << "==== Masukan Data pembeli ====" << endl;
            cout << "Id Tiket : ";
            cin >> idTiket;

            // Cek Duplikat ID Tiket
            if (searchByIdTiket(aFilm->daftarTiket, idTiket) != nullptr)
            {
                cout << "Tiket dengan ID '" << idTiket << "' sudah terdaftar" << endl;
                cout << "Gunakan ID Tiket yang berbeda!" << endl;
                break;
            }

            cout << "Nama pembeli : ";
            cin.ignore();
            getline(cin, namaPembeli);

            cout << "Jumlah : ";
            cin >> jumlahTiket;

            if (jumlahTiket <= 0)
            {
                cout << "Jumlah tiket harus lebih dari 0!" << endl;
                break;
            }

            NodeTiket tiketBaru = allocNodeTiket(idTiket, namaPembeli, jumlahTiket, aFilm);
            bool berhasilTerkirim = insertFirstTiket(aFilm->daftarTiket, tiketBaru);

            if (berhasilTerkirim)
            {
                cout << "\nTiket berhasil ditambahkan!" << endl;
                cout << "Total Harga: Rp " << (jumlahTiket * aFilm->infoFilm.hargaTiket) << endl;

                cout << endl;
                string beliMakanan = "tidak";
                cout << "Beli makanan (ya/tidak) : ";
                cin >> beliMakanan;

                if (beliMakanan == "ya" || beliMakanan == "Ya" || beliMakanan == "YA")
                {
                    tampilanBeliMakanan(tiketBaru);
                }
            }

            break;
        }

        case 4:
        {
            string idTiket;
            cout << "==== Cari tiket Berdasarkan ID Tiket ====" << endl;
            cout << "Masukan id tiket : ";
            cin >> idTiket;

            NodeTiket cariTiket = searchByIdTiket(aFilm->daftarTiket, idTiket);

            if (cariTiket != Nil)
            {
                cout << "\nTiket ditemukan!" << endl;
                printTiket(cariTiket);
                if (!isEmpty(cariTiket->infoTiket.makanan))
                {
                    cout << "\n=== MAKANAN YANG DIPESAN ===" << endl;
                    PrintList(cariTiket->infoTiket.makanan);
                }

                string editMakanan;
                cout << "Edit makanan? (ya/tidak) : ";
                cin >> editMakanan;
                if (editMakanan == "ya" || editMakanan == "Ya" || editMakanan == "YA")
                {
                    tampilanBeliMakanan(cariTiket);
                }
            }
            else
            {
                cout << "Tiket dengan id " << idTiket << " tidak ditemukan" << endl;
            }
            break;
        }

        case 5:
            printListTiket(aFilm->daftarTiket);
            break;

        case 6:
        {
            string idTiket;
            cout << "==== Batalkan Pemesanan tiket ====" << endl;
            cout << "Masukan id tiket : ";
            cin >> idTiket;

            NodeTiket cariTiket = searchByIdTiket(aFilm->daftarTiket, idTiket);
            if (cariTiket != nullptr)
            {
                deleteListMakanan(cariTiket->infoTiket.makanan);
                deleteTiket(aFilm->daftarTiket, cariTiket);
                cout << "Tiket berhasil dibatalkan!" << endl;
            }
            else
            {
                cout << "Tiket tidak ditemukan!" << endl;
            }
            break;
        }

        case 0:
            return;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }
    }
}

void tampilanKelolaFilm(listFilm &L)
{
    int pilihanKelolaFilm = -1;
    while (pilihanKelolaFilm != 0)
    {
        cout << "====== BIOSKOP H. TOHIRIN ======" << endl
             << "1. Tampilkan seluruh jadwal bioskop" << endl
             << "2. Tambah jadwal film" << endl
             << "3. Ganti informasi film" << endl
             << "4. Hapus jadwal film" << endl
             << "0. Home" << endl;
        cout << "Pilihan menu : ";
        cin >> pilihanKelolaFilm;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            pilihanKelolaFilm = -1;
            continue;
        }

        switch (pilihanKelolaFilm)
        {
        case 1:
            tampilkanInfoSeluruhFilm(L);
            break;
        case 2:
        {
            string idFilm, judul, studio;
            int durasi, tahunTerbit, kapasitasPenonton, hargaTiket;

            cout << "==== Input Data Film ====" << endl;
            cout << "ID Film : ";
            cin >> idFilm;

            adrFilm checkFilm = cariIdFilm(L, idFilm);
            if (checkFilm == Nil)
            {
                cin.ignore();
                cout << "Judul Film : ";
                getline(cin, judul);
                cout << "Nama Studio : ";
                getline(cin, studio);
                cout << "Durasi (menit) : ";
                cin >> durasi;
                cout << "Tahun Terbit : ";
                cin >> tahunTerbit;
                cout << "Kapasitas Kursi : ";
                cin >> kapasitasPenonton;
                cout << "Harga Tiket : ";
                cin >> hargaTiket;

                adrFilm filmBaru = alokasiNodeFilm(idFilm, judul, studio, durasi, tahunTerbit, kapasitasPenonton, hargaTiket);
                tambahFilm(L, filmBaru);
            }
            else
            {
                cout << "❌ ID " << idFilm << " sudah digunakan dalam list" << endl;
            }
            break;
        }
        case 3:
        {
            string idFilm, judul, studio;
            int durasi, tahunTerbit, kapasitasPenonton, hargaTiket;

            cout << "==== Ganti Data Film ====" << endl;
            cout << "ID Film : ";
            cin >> idFilm;
            cin.ignore();
            cout << "Judul Film : ";
            getline(cin, judul);
            cout << "Nama Studio : ";
            getline(cin, studio);
            cout << "Durasi (menit) : ";
            cin >> durasi;
            cout << "Tahun Terbit : ";
            cin >> tahunTerbit;
            cout << "Kapasitas Kursi : ";
            cin >> kapasitasPenonton;
            cout << "Harga Tiket : ";
            cin >> hargaTiket;

            adrFilm filmPilihan = cariIdFilm(L, idFilm);

            if (filmPilihan != Nil)
            {
                editFilm(L, idFilm, judul, studio, durasi, tahunTerbit, kapasitasPenonton, hargaTiket);
            }
            else
            {
                cout << "❌ Film dengan ID " << idFilm << " tidak ditemukan!" << endl;
            }
            break;
        }
        case 4:
        {
            string idFilm;
            cout << "==== Hapus Data Film ====" << endl;
            cout << "Id Film : ";
            cin >> idFilm;

            adrFilm filmDihapus = cariIdFilm(L, idFilm);
            if (filmDihapus != Nil)
            {
                deleteListTiket(filmDihapus->daftarTiket);
                hapusFilm(L, filmDihapus);
                cout << "✅ Film berhasil dihapus!" << endl;
            }
            else
            {
                cout << "❌ Film tidak ditemukan!" << endl;
            }
            break;
        }
        case 0:
            return;
        default:
            cout << "❌ Pilihan tidak valid!" << endl;
            break;
        }
    }
}

void tampilanHome(listFilm &L)
{
    int pilihanHome = -1;
    while (pilihanHome != 0)
    {
        cout << "\n==== Bioskop H. Tohirin ====" << endl
             << "1. Tampilkan seluruh jadwal bioskop" << endl
             << "2. Reservasi Tiket" << endl
             << "3. Kelola Film" << endl
             << "0. Exit" << endl;
        cout << "Pilihan menu : ";
        cin >> pilihanHome;
        cout << endl;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            pilihanHome = -1;
            continue;
        }

        switch (pilihanHome)
        {
        case 1:
            tampilkanInfoSeluruhFilm(L);
            break;
        case 2:
            tampilanReservasiTiket(L);
            break;
        case 3:
            tampilanKelolaFilm(L);
            break;
        case 0:
            cout << "Terima kasih telah menggunakan aplikasi kami !!!" << endl;
            break;
        default:
            cout << "❌ Pilihan tidak valid!" << endl;
            break;
        }
    }
}

int main()
{
    listFilm jadwalTayang;
    createListFilm(jadwalTayang);
    dataDummy(jadwalTayang);
    tampilanHome(jadwalTayang);
    return 0;
}