#include "fnb.h"
#include "tiket.h"
#include <iostream>

using namespace std;

bool isEmpty(linkedlist List)
{
    if (List.first == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CreateList(linkedlist &List)
{
    List.first = NULL;
    List.last = NULL;
}

address alokasi(string idMakanan, string namaMakanan, int hargaMakanan, int jumlahMakanan, NodeTiket tiket)
{
    address Nodebaru = new node;
    Nodebaru->isiList.idMakanan = idMakanan;
    Nodebaru->isiList.namaMakanan = namaMakanan;
    Nodebaru->isiList.hargaMakanan = hargaMakanan;
    Nodebaru->isiList.jumlahMakanan = jumlahMakanan;
    Nodebaru->isiList.subtotal = hargaMakanan * jumlahMakanan;
    Nodebaru->next = NULL;
    Nodebaru->prev = NULL;
    Nodebaru->tiket = tiket;
    return Nodebaru;
}

void dealokasi(address &node)
{
    node->next = NULL;
    node->prev = NULL;
    node->tiket = NULL;
    delete node;
}

void insertLast(linkedlist &List, address nodeBaru)
{
    if (isEmpty(List))
    {
        List.first = List.last = nodeBaru;
        nodeBaru->tiket->infoTiket.totalBiaya += nodeBaru->isiList.subtotal;
    }
    else
    {
        {
            nodeBaru->prev = List.last;
            List.last->next = nodeBaru;
            List.last = nodeBaru;
            nodeBaru->tiket->infoTiket.totalBiaya += nodeBaru->isiList.subtotal;
        }
    }
}

void PrintList(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "Data kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != NULL)
        {
            cout << "ID Makanan         : " << nodeBantu->isiList.idMakanan << endl;
            cout << "Nama Makanan       : " << nodeBantu->isiList.namaMakanan << endl;
            cout << "Harga Makanan      : " << nodeBantu->isiList.hargaMakanan << endl;
            cout << "Jumlah Makanan     : " << nodeBantu->isiList.jumlahMakanan << endl;
            cout << "Total              : " << nodeBantu->isiList.subtotal << endl;
            cout << "------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void deleteMakanan(linkedlist &List, address &node)
{
    string idTerhapus = node->isiList.idMakanan;
    node->tiket->infoTiket.totalBiaya -= node->isiList.subtotal;

    if (List.first == node)
    {
        List.first = List.first->next;
    }
    else
    {
        address prev = List.first;

        while (prev != nullptr && prev->next != node)
        {
            prev = prev->next;
        }

        if (prev != nullptr)
        {
            prev->next = node->next;

            if (node == List.last)
            {
                List.last = prev;
            }

            node->next = nullptr;
        }
    }
    delete node;
    node = nullptr;
    cout << "Menghapus makanan dengan ID: " << idTerhapus << endl;
}

void deleteListMakanan(linkedlist &List)
{
    cout << "Menghapus semua makanan..." << endl;
    while (List.first != NULL)
    {
        deleteMakanan(List, List.first);
    }
    cout << "Semua makanan telah dihapus." << endl;
}

address searchMakananById(linkedlist &List, string idMakanan)
{
    address temp = List.first;
    while (temp != NULL)
    {
        if (temp->isiList.idMakanan == idMakanan)
        {
            return temp;
        }
        temp = temp->next;
    }
    cout << "Makanan dengan id " << idMakanan << " belum tersedia pada menu" << endl;
    return NULL;
}

void updateFirst(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        cout << "Masukkan list makanan pertama yang ingin diubah : " << endl;
        cout << "Nama Makanan       : ";
        getline(cin, List.first->isiList.namaMakanan);
        cout << "Harga Makanan           : ";
        cin >> List.first->isiList.hargaMakanan;
        cout << "Jumlah Makanan     : ";
        cin >> List.first->isiList.jumlahMakanan;
        cin.ignore();
        cout << "Data berhasil ditambahkan" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        cout << "Masukkan list makanan terakhir yang ingin diubah : " << endl;
        cout << "Nama Makanan       : ";
        getline(cin, List.last->isiList.namaMakanan);
        cout << "Harga Makanan           : ";
        cin >> List.last->isiList.hargaMakanan;
        cout << "Jumlah Makanan     : ";
        cin >> List.last->isiList.jumlahMakanan;
        cin.ignore();
        cout << "Data berhasil ditambahkan" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address prev)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (prev != NULL && prev->next != NULL)
        {
            address nodeBantu = prev->next;
            cout << "Masukkan list makanan yang ingin diubah : " << endl;
            cin.ignore();
            cout << "Nama Makanan       : ";
            getline(cin, nodeBantu->isiList.namaMakanan);
            cout << "Harga Makanan           : ";
            cin >> nodeBantu->isiList.hargaMakanan;
            cout << "Jumlah Makanan     : ";
            cin >> nodeBantu->isiList.jumlahMakanan;
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
        }
    }
}

void updateBefore(linkedlist List, address next)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (next != NULL && next->prev != NULL)
        {
            address nodeBantu = next->prev;
            cout << "Masukkan list makanan yang ingin diubah : " << endl;
            cout << "Nama Makanan       : ";
            getline(cin, nodeBantu->isiList.namaMakanan);
            cout << "Harga Makanan           : ";
            cin >> nodeBantu->isiList.hargaMakanan;
            cout << "Jumlah Makanan     : ";
            cin >> nodeBantu->isiList.jumlahMakanan;
            cin.ignore();
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
        }
    }
}