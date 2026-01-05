#ifndef FILM_H
#define FILM_H
#define Nil NULL
#include <iostream>
#include "tiket.h"
using namespace std;

typedef struct nodeFilm *adrFilm;

struct Film
{
    string idFilm, judul, studio;
    int durasi, tahunTerbit, kapasitasPenonton, hargaTiket;
};

struct nodeFilm
{
    Film infoFilm;
    listTiket daftarTiket;
    adrFilm next, prev;
};

struct listFilm
{
    adrFilm head, tail;
};

bool isFilmEmpty(listFilm L);
void createListFilm(listFilm &L);
adrFilm alokasiNodeFilm(string idFilm, string judul, string studio, int durasi, int tahunTerbit, int kapasitasPenonton, int hargaTiket);
void dealokasiNodeFilm(adrFilm &N);
void tambahFilm(listFilm &L, adrFilm &N);
void editFilm(listFilm &L, string idFilm, string judul, string studio, int durasi, int tahunTerbit, int kapasitasPenonton, int hargaTiket);
void hapusFilm(listFilm &L, adrFilm &N);
void cekJumlahPenonton(listFilm L, string idFilm);
adrFilm cariIdFilm(listFilm L, string idFilm);
void tampilkanInfoSeluruhFilm(listFilm L);
void tampilkanInfoFilm(adrFilm N);

#endif