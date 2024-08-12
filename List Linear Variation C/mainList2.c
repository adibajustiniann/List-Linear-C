/* Program   : mainList2.c */
/* Deskripsi : file DRIVER modul List 2 */
/* NIM/Nama  : 24060120130080/Adiba Justinian */
/* Tanggal   : 2 November 2021 */
/***********************************/

#include <stdio.h>
#include "List2.h"

int main()
{

    //Kamus Global
    List L, Z, P, P1, P2, Q, Q1, R, S, T, U, M, N, H, I, J, O;
    address A, B, C, D, E;
    int X;
    address Prec;

    //Algoritma
    printf("====================List L====================\n\n");
    printf("-------Create List-----\n");
    CreateList(&L);


    printf("\n-------List Empty-----\n");
    if (ListEmpty(L))
    {
        printf ("List kosong");
    }
    else
    {
        printf ("List tidak kosong");
    }


    A = Alokasi(9);
    printf("\n\n-------Insert First-----\n");
    InsertFirst(&L, A);
    PrintInfo(L);


    B = Alokasi(7);
    printf("\n\n-------Insert After-----\n");
    InsertAfter(&L, B, A);
    PrintInfo(L);

    C = Alokasi(5);
    printf("\n\n-------Insert After-----\n");
    InsertAfter(&L, C, B);
    PrintInfo(L);

    D = Alokasi(3);
    printf("\n\n-------Insert After-----\n");
    InsertAfter(&L, D, C);
    PrintInfo(L);


    E = Alokasi(1);
    printf("\n\n-------Insert Last-----\n");
    InsertLast(&L, E);
    PrintInfo(L);


    printf("\n\n-------List Empty-----\n");
    if (ListEmpty(L))
    {
        printf ("List kosong");
    }
    else
    {
        printf ("List tidak kosong");
    }


    printf("\n\n-------Delete First-----\n");
    DelFirst(&L, A);
    PrintInfo(L);


    printf("\n\n-------Delete Last-----\n");
    DelLast(&L, &E);
    PrintInfo(L);


    printf("\n\n-------Delete After-----\n");
    DelAfter(&L, &C, B);
    PrintInfo(L);


    printf("\n\n====================List Z====================\n\n");
    printf("-------Create List-----\n");
    CreateList(&Z);


    printf("\n\n-------InsVFirst-----\n");
    InsVFirst(&Z, 27);
    PrintInfo(Z);


    printf("\n\n-------InsVLast-----\n");
    InsVLast(&Z, 5);
    PrintInfo(Z);


    printf("\n\n-------InsVAfter-----\n");
    InsVAfter(&Z, 19, 27);
    PrintInfo(Z);

    printf("\n\n-------InsVAfter-----\n");
    InsVAfter(&Z, 13, 19);
    PrintInfo(Z);


    printf("\n\n-------DelVFirst-----\n");
    DelVFirst(&Z, &X);
    PrintInfo(Z);


    printf("\n\n-------DelVLast-----\n");
    DelVLast(&Z, &X);
    PrintInfo(Z);


    printf("\n\n-------DelVAfter-----\n");
    DelVAfter(&Z, &X, 19);
    PrintInfo(Z);


    printf("\n\n-------DelVFirst-----\n");
    DelVFirst(&Z, &X);
    PrintInfo(Z);


    printf("\n\nNb Elmt List Z : %d", NbElmt(Z));

    printf("\n\nNb Elmt List L : %d", NbElmt(L));


    printf("\n\nNilai rata-rata list = %f", Average(L));


    printf("\n\nAlamat elemen 7 pada list L : %d");
    Search(L, 7);

    printf("\n\nAlamat elemen 3 pada list L : %d");
    Search(L, 3);


    printf("\n\nFSearch address -794822096 pada list L : ");
    if (FSearch(L, B))
    {
        printf ("True");
    }
    else
    {
        printf ("False");
    }

    printf("\n\nFSearch address 7 pada list L : ");
    if (FSearch(L, D))
    {
        printf ("True");
    }
    else
    {
        printf ("False");
    }

    printf("\n\nFSearch address -794822096 pada list Z : ");
    if (FSearch(Z, B))
    {
        printf ("True");
    }
    else
    {
        printf ("False");
    }


    printf("\n\nSearch Prec elemen 3 pada list L : %d\n");
    SearchPrec (L, 3, &Prec);


    printf("\nDel All List L = ");
    DelAll(&L);
    PrintInfo(L);


    printf("\n\nCreate List P = ");
    CreateList(&P);
    InsVFirst(&P, 5);
    InsVLast(&P, 25);
    InsVAfter(&P, 10, 5);
    InsVAfter(&P, 15, 10);
    InsVAfter(&P, 20, 15);
    PrintInfo(P);


    printf("\n\nCreate List Q = ");
    CreateList(&Q);
    InsVFirst(&Q, 1);
    InsVLast(&Q, 5);
    InsVAfter(&Q, 2, 1);
    InsVAfter(&Q, 3, 2);
    InsVAfter(&Q, 4, 3);
    PrintInfo(Q);


    printf("\n\n-------Invers List P-----\n");
    InversList(&P);
    PrintInfo(P);

    printf("\n\n-------Invers List Q-----\n");
    InversList(&Q);
    PrintInfo(Q);


    printf("\n\n-------FInvers List P-----\n");
    printf("List P = ");
    PrintInfo(P);
    P1 = FInversList(P);
    printf("\nList P1 = ");
    PrintInfo(P1);


    printf("\n\n-------Copy List Q-----\n");
    CopyList(&Q, &Q);
    PrintInfo(Q);


    printf("\n\n-------FCopy List P1-----\n");
    printf("List P1 = ");
    PrintInfo(P1);
    P2 = FCopyList(P1);
    printf("\nList P2 = ");
    PrintInfo(P2);

    printf("\n\n-------FCopy List Q-----\n");
    printf("List Q = ");
    PrintInfo(Q);
    Q1 = FCopyList(Q);
    printf("\nList Q1 = ");
    PrintInfo(Q1);


    printf("\n\n-------CpAlok List P-----\n");
    printf("Lout = ");
    CpAlokList(P, &R);
    PrintInfo(R);


    printf("\n\nCreate List M = ");
    CreateList(&M);
    InsVFirst(&M, 3);
    InsVLast(&M, 17);
    InsVAfter(&M, 7, 3);
    InsVAfter(&M, 11, 7);
    InsVAfter(&M, 13, 11);
    PrintInfo(M);

    printf("\nCreate List N = ");
    CreateList(&N);
    InsVFirst(&N, 5);
    InsVLast(&N, 9);
    InsVAfter(&N, 6, 5);
    InsVAfter(&N, 7, 6);
    InsVAfter(&N, 8, 7);
    PrintInfo(N);

    printf("\nCreate List O = ");
    CreateList(&O);
    InsVFirst(&O, 2);
    InsVLast(&O, 10);
    InsVAfter(&O, 4, 2);
    InsVAfter(&O, 6, 4);
    InsVAfter(&O, 8, 6);
    PrintInfo(O);

    printf("\n\n-------Konkat List P dan List O-----\n");
    printf("List P = "), PrintInfo(P);
    printf("\nList O = "), PrintInfo(O);
    Konkat(P, O, &T);
    printf("\nL3 = ");
    PrintInfo(T);


    printf("\n\n-------Konkat1 List M dan List N-----\n");
    printf("List M = ");
    PrintInfo(M);
    printf("\nList N = ");
    PrintInfo(N);
    Konkat1(&M, &N, &U);
    printf("\nList 3 = ");
    PrintInfo(U);
    printf("\nList 1 = ");
    PrintInfo(M);
    printf("\nList 2 = ");
    PrintInfo(N);


    printf("\n\nCreate List J = ");
    CreateList(&J);
    InsVFirst(&J, 1);
    InsVLast(&J, 7);
    InsVAfter(&J, 2, 1);
    InsVAfter(&J, 3, 2);
    InsVAfter(&J, 4, 3);
    InsVAfter(&J, 5, 4);
    InsVAfter(&J, 6, 5);
    PrintInfo(J);

    printf("\n\n-------Pecah List L3-----\n");
    printf("L3 = ");
    PrintInfo(J);
    printf("\n");
    PecahList(&H, &I, J);
    printf("L1 = ");
    PrintInfo(H);
    printf("\nL2 = ");
    PrintInfo(I);
    printf("\n");


    return 0;



}

