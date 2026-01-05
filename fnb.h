#ifndef FNB_H
#define FNB_H
#include <iostream>
#include <string>

using namespace std;

struct fnb
{
    string idMakanan; // Baru diubah jangan lupa tambah di cpp
    string namaMakanan;
    int hargaMakanan;
    int jumlahMakanan;
    int subtotal;
};

typedef fnb listMakanan;
typedef struct node *address;

struct node
{
    listMakanan isiList;
    address next;
    address prev;
};

struct linkedlist
{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void CreateList(linkedlist &List);
address alokasi(string idMakanan, string namaMakanan, int hargaMakanan, int jumlahMakanan);
void dealokasi(address &node);

void insertLast(linkedlist &List, address nodeBaru);

void PrintList(linkedlist List);
void deleteMakanan(linkedlist &List, address &node);
void deleteListMakanan(linkedlist &List);
address searchMakananById(linkedlist &List, string idMakanan);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address next);

#endif