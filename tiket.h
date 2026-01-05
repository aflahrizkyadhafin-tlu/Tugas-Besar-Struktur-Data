#ifndef TIKET_H
#define TIKET_H

#include <iostream>
#include "fnb.h"
using namespace std;

struct nodeFilm;
typedef struct nodeFilm *adrFilm;

struct Tiket
{
    string idTiket;
    string namaPembeli;
    int jumlahTiket;
    linkedlist makanan;
    int totalBiaya;
    adrFilm film;
};

typedef struct nodeTiket *NodeTiket;

struct nodeTiket
{
    Tiket infoTiket;
    NodeTiket next;
};

struct listTiket
{
    NodeTiket first;
    NodeTiket last;
};

void createListTiket(listTiket &LTiket);
NodeTiket allocNodeTiket(string idTiket, string namaPembeli, int jumlahTiket, adrFilm film);
void insertFirstTiket(listTiket &LTiket, NodeTiket newTiket);
void deleteFirstTiket(listTiket &LTiket);
void deleteTiket(listTiket &LTiket, NodeTiket &NTiket);
void updateTiket(NodeTiket tiket, string namaPembeliBaru, int totalBiayaBaru);
void printListTiket(listTiket &LTiket);
void printTiket(NodeTiket &NTiket);
void deleteListTiket(listTiket &LTiket);
NodeTiket searchByIdTiket(listTiket &LTiket, string idTiket);

#endif