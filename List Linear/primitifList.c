/* Program   : primitifList.c */
/* Deskripsi : file BODY modul primitif list linear */
/* NIM/Nama  : 24060120130080/Adiba Justinian */
/* Tanggal   : 26 Oktober 2021 */
/***********************************/

#ifndef primitifList_C
#define primitifList_C
#include "primitifList.h"
#include <stdio.h>
#include <stdlib.h>


/* ----- Test List Kosong ----- */
/* Mengirim true jika list kosong */
boolean ListEmpty (List L)
{
    //Kamus Lokal


    //Algoritma
    if(First(L) == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }

}

/* ----- Pembuatan List Kosong ----- */
/* I.S.		: sembarang
   F.S.		: Terbentuk list kosong */
void CreateList (List *L)
{
    //Kamus Lokal


    //Algoritma
    First(*L) = Nil;

}

/* ----- Manajemen Memori ----- */
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil,
   dan misalnya menghasilkan P, maka
   Info(P) = X, Next(P) = Nil
   Jika alokasi gagal, mengirimkan Nil */
address Alokasi (infotype X)
{
    //Kamus Lokal
    address P;

    //Algooritma
    P = (address) malloc(sizeof(ElmtList));
    if(P != Nil )
    {
        info(P) = X;
        next(P) = Nil;
        return P;
    }
    else
    {
        return Nil;
    }

}

/* I.S.		: P terdefinisi
   F.S.		: P dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address P */
void Dealokasi (address *P)
{
    //Kamus Lokal


    //Algoritma
    free(*P);

}

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertFirst (List *L, address P)
{
    //Kamus Lokal


    //Algoritma
    next(P) = First(*L);
    First(*L) = P;

}

/* I.S.		: Prec pastilah elemen list dan bukan elemen terakhir,
			  P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertAfter (List *L, address P, address Prec)
{
    //Kamus Lokal


    //Algoritma
    next(P) = next(Prec);
    next(Prec) = P;

}

/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */
void InsertLast (List *L, address P)
{
    //Kamus Lokal
    address Last;

    //Algoritma
    if(First(*L) == Nil)
    {
        InsertFirst(L, P);
    }
    else
    {
        Last = First(*L);
        while(next(Last) != Nil)
        {
            Last = next(Last);
        }
        InsertAfter(L, P, Last);
    }

}

/* Penghapusan Sebuah Elemen */
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen pertama list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              First element yang baru adalah suksesor elemen pertama yang
              lama */
void DelFirst (List *L, address *P)
{
    //Kamus Lokal


    //Algoritma
    P = First(*L);
    First(*L) = next(First(*L));

}

/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */
void DelLast (List *L, address *P)
{
    //Kamus Lokal
    address Last;
    address PrecLast;

    //Algoritma
    Last = First(*L);
    PrecLast = Nil;
    while(next(Last) != Nil)
    {
        PrecLast = Last;
        Last = next(Last);
    }
    (*P) = Last;
    if(PrecLast == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        next(PrecLast) = Nil;
    }

}

/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec) :
              Pdel adalah alamat elemen list yang dihapus */
void DelAfter (List *L, address * Pdel, address Prec)
{
    //Kamus Lokal


    //Algoritma
    (*Pdel) = next(Prec);
    next(Prec) = next(next(Prec));
    next(*Pdel) = Nil;

}

/* ----- Primitif Berdasarkan Nilai ----- */
/* Penambahan Elemen */
/* I.S.		: L mungkin kosong
   F.S. 	: X ditambahkan sebagai elemen pertama L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen
   			  pertama dengan nilai X jika alokasi berhasil.
   			  Jika alokasi gagal, maka I.S.= F.S. */
void InsVFirst (List *L, infotype X)
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = Alokasi(X);
    if(P != Nil)
    {
        InsertFirst(L, P);
    }

}

/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen terakhir L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  di akhir yaitu
   			  jika alokasi berhasil, elemen terakhir yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */
void InsVLast (List *L, infotype X)
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = Alokasi(X);
    if(P != Nil)
    {
        InsertLast(L, P);
    }
}

/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen setelah Prec
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  setelah Prec yaitu
   			  jika alokasi berhasil, elemen setelah Prec yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */
void InsVAfter (List *L, infotype X, infotype Xprec)
{
    //Kamus Lokal
    address P;
    address Prec;

    //Algoritma
    P = Alokasi(X);
    Prec = First(*L);
    if(info(Prec) == Xprec)
    {
        InsertAfter(L, P, Prec);
    }
    else
    {
        while(info(Prec) != Xprec && next(Prec) != Nil)
        {
            Prec = next(Prec);
            if(info(Prec) == Xprec)
            {
                InsertAfter(L, P, Prec);
            }
        }
    }

}

/*mencari alamat elemen terakhir dan sebelumnya*/
void AdrLast(List *L, address *Prec, address *Last)
{
    //Kamus Lokal


    //Algoritma
    if(!ListEmpty(*L))
    {
        (*Last) = First(*L);
        (*Prec) = Nil;
        while(next(*Last) != Nil)
        {
            (*Prec) = (*Last);
            (*Last) = next(*Last);
        }
    }
    else
    {
        printf("List kosong");
    }

}

/* Penghapusan ELemen */
/* I.S.		: List L tidak kosong
   F.S.		: Elemen pertama list dihapus den nilai info disimpan pada X
   			 dan alamat elemen pertama di-dealokasi */
void DelVFirst (List *L, infotype *X)
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = First(*L);
    (*X) = info(P);
    First(*L) = next(First(*L));
    next(P) = Nil;
    Dealokasi(&P);

}

/* I.S.		: List L tidak kosong
   F.S.		: Elemen terakhir list dihapus : nilai info disimpan pada X
   			  dan alamat elemen terakhir di-dealokasi */
void DelVLast (List *L, infotype *X)
{
    //Kamus Lokal
    address Last;
    address Prec;

    //Algoritma
    AdrLast(&(*L), &Prec, &Last);
    (*X) = info(Last);
    if(Prec == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        next(Prec) = Nil;
    }
    Dealokasi(&Last);

}

/* I.S.		: List L tidak kosong
   F.S.		: Elemen list setelah Prec dihapus : nilai info disimpan pada X
   			  dan alamat elemen setelah Prec di-dealokasi */
void DelVAfter (List *L, infotype *X, infotype Y)
{
    //Kamus Lokal
    address P;
    address Prec;

    //Algoritma
    (*X) = -999;
    if(P != Nil)
    {
        Prec = Search((*L), Y);
        if((Prec != Nil) && (next(Prec) != Nil))
        {
            DelAfter(&(*L), &P, Prec);
            (*X) = info(P);
            Dealokasi(&P);
        }
    }

}

/* ----- Proses Semua Elemen List ----- */
/* I.S.     : List mungkin kosong
   F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint
              Jika list kosong, hanya menuliskan "list kosong" */
void PrintInfo (List L)
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = First(L);
    if (ListEmpty(L))
    {
        printf("List kosong");
    }
    else
    {
        while(P != Nil)
        {
            printf("%d; ", info(P));
            P = next(P);
        }
    }

}

/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
int NbElmt (List L)
{
    //Kamus Lokal
    address P;
    int i;

    //Algoritma
    i = 0;
    P = First(L);
    while(P != Nil)
    {
        i++;
        P = next(P);
    }
    return i;

}

/*----- Pencarian Sebuah Elemen List ------*/
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
address Search (List L, infotype X)
{
    //Kamus Lokal
    address P;
    boolean found;

    //Algoritma
    P = First(L);
    found = false;
    while((P != Nil) && (!found))
    {
        if(X == info(P))
        {
            found = true;
        }
        else
        {
            P = next(P);
        }
    }
    return P;

}

/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
boolean FSearch (List L, address P)
{
    //Kamus lokal
    address Ps;
    boolean found;

    //Algoritma
    Ps = First(L);
    found = false;
    while((Ps != Nil) && (!found))
    {
        if(P == Ps)
        {
            found = true;
        }
        else
        {
            Ps = next(Ps);
        }
    }
    return found;
}

/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P */
/* dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain*/
address SearchPrec (List L, infotype X, address *Prec)
{
    //Kamus Lokal
    address P;
    boolean found;

    //Algoritma
    P = Search(L, X);
    (*Prec) = Nil;
    if(P != Nil && next(First(L)) != Nil)
    {
        (*Prec) = First(L);
        while(next(*Prec) != P)
        {
            (*Prec) = next(*Prec);
        }
    }

}

#endif
