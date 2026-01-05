#include "film.h"
#include "tiket.h"

bool isFilmEmpty(listFilm L)
{
    if (L.head == Nil && L.tail == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createListFilm(listFilm &L)
{
    L.head = L.tail = Nil;
}

adrFilm alokasiNodeFilm(string idFilm, string judul, string studio, int durasi, int tahunTerbit, int kapasitasPenonton, int hargaTiket)
{
    adrFilm filmBaru = new nodeFilm;
    filmBaru->infoFilm.idFilm = idFilm;
    filmBaru->infoFilm.judul = judul;
    filmBaru->infoFilm.studio = studio;
    filmBaru->infoFilm.durasi = durasi;
    filmBaru->infoFilm.tahunTerbit = tahunTerbit;
    filmBaru->infoFilm.kapasitasPenonton = kapasitasPenonton;
    filmBaru->infoFilm.hargaTiket = hargaTiket;
    createListTiket(filmBaru->daftarTiket);
    filmBaru->next = filmBaru->prev = Nil;
    return filmBaru;
}

void dealokasiNodeFilm(adrFilm &N)
{
    N->next = N->prev = Nil;
    delete N;
}

void tambahFilm(listFilm &L, adrFilm &N)
{
    if (isFilmEmpty(L))
    {
        L.head = L.tail = N;
        cout << "Film " << N->infoFilm.judul << " telah berhasil ditambahkan ke jadwal" << endl;
    }
    else
    {
        N->next = L.head;
        L.head->prev = N;
        L.head = N;
        cout << "Film " << N->infoFilm.judul << " telah berhasil ditambahkan ke jadwal" << endl;
    }
}

void editFilm(listFilm &L, string idFilm, string judul, string studio, int durasi, int tahunTerbit, int kapasitasPenonton, int hargaTiket)
{
    adrFilm N = cariIdFilm(L, idFilm);
    if (N != Nil)
    {
        N->infoFilm.judul = judul;
        N->infoFilm.studio = studio;
        N->infoFilm.durasi = durasi;
        N->infoFilm.tahunTerbit = tahunTerbit;
        N->infoFilm.kapasitasPenonton = kapasitasPenonton;
        N->infoFilm.hargaTiket = hargaTiket;
        cout << "Data film dengan id " << idFilm << " telah berhasil di update" << endl;
    }
    else
    {
        cout << "Film dengan id " << idFilm << " belum tayang di bioskop ini" << endl;
    }
}

void hapusFilm(listFilm &L, adrFilm &N)
{
    if (N->prev == Nil)
    {
        N->next->prev = Nil;
        L.head = N->next;
    }
    else if (N->next == Nil)
    {
        N->prev->next = Nil;
        L.tail = N->prev;
    }
    else
    {
        N->prev->next = N->next;
        N->next->prev = N->prev;
    }

    dealokasiNodeFilm(N);
}

void cekJumlahPenonton(listFilm L, string idFilm)
{
    adrFilm searchFilm = cariIdFilm(L, idFilm);
    int countPenonton = 0;

    if (searchFilm != Nil)
    {
        NodeTiket temp = searchFilm->daftarTiket.first;
        while (temp != nullptr)
        {
            countPenonton++;
            temp = temp->next;
        }
        cout << "Film dipesan oleh " << countPenonton << " orang" << endl;
    }
    else
    {
        cout << "Film dengan id " << idFilm << " belum tayang di bioskop ini" << endl;
    }
}

adrFilm cariIdFilm(listFilm L, string idFilm)
{
    if (isFilmEmpty(L))
    {
        cout << "Mohon maaf, belum ada film yang tayang saat ini" << endl;
        return Nil;
    }
    else
    {
        adrFilm temp = L.head;
        while (temp != Nil)
        {
            if (temp->infoFilm.idFilm == idFilm)
            {
                return temp;
            }
            temp = temp->next;
        }
        return Nil;
    }
}

void tampilkanInfoSeluruhFilm(listFilm L)
{
    if (isFilmEmpty(L))
    {
        cout << "Mohon maaf, belum ada film yang tayang saat ini" << endl;
    }
    else
    {
        cout << "Film yang sedang tayang hari ini : " << endl;

        adrFilm temp = L.head;
        while (temp != Nil)
        {
            cout << "ID Film : " << temp->infoFilm.idFilm << endl
                 << "Judul : " << temp->infoFilm.judul << endl
                 << "Studio : " << temp->infoFilm.studio << endl
                 << "Durasi : " << temp->infoFilm.durasi << endl
                 << "Tahun Terbit : " << temp->infoFilm.tahunTerbit << endl
                 << "Kapasitas Penonton : " << temp->infoFilm.kapasitasPenonton << endl
                 << "Harga Tiket : " << temp->infoFilm.hargaTiket << endl
                 << endl;
            temp = temp->next;
        }
    }
}

void tampilkanInfoFilm(adrFilm N)
{
    cout << "ID Film : " << N->infoFilm.idFilm << endl
         << "Judul : " << N->infoFilm.judul << endl
         << "Studio : " << N->infoFilm.studio << endl
         << "Durasi : " << N->infoFilm.durasi << endl
         << "Tahun Terbit : " << N->infoFilm.tahunTerbit << endl
         << "Kapasitas Penonton : " << N->infoFilm.kapasitasPenonton << endl
         << "Harga Tiket : " << N->infoFilm.hargaTiket << endl
         << endl;
}
