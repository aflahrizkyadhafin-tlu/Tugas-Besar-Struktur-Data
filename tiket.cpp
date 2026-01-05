#include "tiket.h"
#include "film.h"
#include "fnb.h"
#include <iostream>
using namespace std;

void createListTiket(listTiket &LTiket)
{
    LTiket.first = LTiket.last = nullptr;
}

NodeTiket allocNodeTiket(string idTiket, string namaPembeli, int jumlahTiket, adrFilm film)
{
    NodeTiket newNode = new nodeTiket;
    newNode->infoTiket.idTiket = idTiket;
    newNode->infoTiket.namaPembeli = namaPembeli;
    newNode->infoTiket.jumlahTiket = jumlahTiket;
    newNode->infoTiket.film = film;
    newNode->infoTiket.totalBiaya = jumlahTiket * film->infoFilm.hargaTiket;
    CreateList(newNode->infoTiket.makanan);
    newNode->next = nullptr;
    return newNode;
}

void insertFirstTiket(listTiket &LTiket, NodeTiket newTiket)
{
    // cek duplikat ID Tiket
    if (searchByIdTiket(LTiket, newTiket->infoTiket.idTiket) != nullptr)
    {
        cout << "Tiket dengan ID '" << newTiket->infoTiket.idTiket
             << "' sudah ada!" << endl;
        delete newTiket;
        return;
    }

    if (LTiket.first == nullptr)
    {
        LTiket.first = newTiket;
        LTiket.last = newTiket;
    }
    else
    {
        newTiket->next = LTiket.first;
        LTiket.first = newTiket;
    }
}

void deleteFirstTiket(listTiket &LTiket)
{
    if (LTiket.first == nullptr)
    {
        cout << "List tiket kosong!" << endl;
        return;
    }

    NodeTiket temp = LTiket.first;

    if (LTiket.first == LTiket.last)
    {
        LTiket.first = nullptr;
        LTiket.last = nullptr;
    }
    else
    {
        LTiket.first = LTiket.first->next;
    }

    cout << "Menghapus tiket dengan ID: " << temp->infoTiket.idTiket << endl;
    delete temp;
}

void deleteTiket(listTiket &LTiket, NodeTiket &NTiket)
{
    string idTerhapus = NTiket->infoTiket.idTiket;

    if (LTiket.first == NTiket)
    {
        deleteFirstTiket(LTiket);
    }
    else
    {
        NodeTiket prev = LTiket.first;

        while (prev != nullptr && prev->next != NTiket)
        {
            prev = prev->next;
        }

        if (prev != nullptr)
        {
            prev->next = NTiket->next;

            if (NTiket == LTiket.last)
            {
                LTiket.last = prev;
            }

            NTiket->next = nullptr;
            delete NTiket;
            NTiket = nullptr;
        }
        cout << "Menghapus tiket dengan ID: " << idTerhapus << endl;
    }
}

void printListTiket(listTiket &LTiket)
{
    if (LTiket.first == nullptr)
    {
        cout << "Tidak ada tiket yang tercatat." << endl;
        return;
    }

    NodeTiket current = LTiket.first;
    int count = 1;

    cout << "\n=== DAFTAR TIKET ===" << endl;
    cout << "====================" << endl;
    while (current != nullptr)
    {
        cout << "Tiket #" << count << endl;
        cout << "ID Tiket     : " << current->infoTiket.idTiket << endl;
        cout << "Nama Pembeli : " << current->infoTiket.namaPembeli << endl;
        cout << "Judul Film   : " << current->infoTiket.film->infoFilm.judul << endl;
        cout << "Jumlah Tiket : " << current->infoTiket.jumlahTiket << endl;
        cout << "Total Biaya  : Rp " << current->infoTiket.totalBiaya << endl;
        cout << "--------------------" << endl;
        current = current->next;
        count++;
    }
    cout << "Total Tiket: " << (count - 1) << " buah" << "\n"
         << endl;
}

void printTiket(NodeTiket &NTiket)
{

    cout << "\n===   TIKET    ===" << endl;
    cout << "====================" << endl;
    cout << "ID Tiket     : " << NTiket->infoTiket.idTiket << endl;
    cout << "Nama Pembeli : " << NTiket->infoTiket.namaPembeli << endl;
    cout << "Judul Film   : " << NTiket->infoTiket.film->infoFilm.judul << endl;
    cout << "Jumlah Tiket : " << NTiket->infoTiket.jumlahTiket << endl;
    cout << "Total Biaya  : Rp " << NTiket->infoTiket.totalBiaya << endl;
    cout << "--------------------" << endl;
}

void deleteListTiket(listTiket &LTiket)
{
    cout << "Menghapus semua tiket..." << endl;
    while (LTiket.first != nullptr)
    {
        deleteListMakanan(LTiket.first->infoTiket.makanan);
        deleteFirstTiket(LTiket);
    }
    cout << "Semua tiket telah dihapus." << endl;
}

NodeTiket searchByIdTiket(listTiket &LTiket, string idTiket)
{
    NodeTiket current = LTiket.first;

    while (current != nullptr)
    {
        if (current->infoTiket.idTiket == idTiket)
        {
            return current;
        }
        current = current->next;
    }

    return nullptr;
}

int countTiket(listTiket &LTiket)
{
    int count = 0;
    NodeTiket current = LTiket.first;

    while (current != nullptr)
    {
        count++;
        current = current->next;
    }

    return count;
}

void updateTiket(NodeTiket tiket, string namaPembeliBaru, int jumlahTiketBaru, int hargaTiket)
{
    tiket->infoTiket.namaPembeli = namaPembeliBaru;
    tiket->infoTiket.jumlahTiket = jumlahTiketBaru;
    tiket->infoTiket.totalBiaya = jumlahTiketBaru * hargaTiket;
}