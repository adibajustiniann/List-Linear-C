/* Program   : mainprimitifList.c */
/* Deskripsi : file DRIVER modul primitif list linear */
/* NIM/Nama  : 24060120130080/Adiba Justinian */
/* Tanggal   : 26 Oktober 2021 */
/***********************************/

#include <stdio.h>
#include "primitifList.h"

int main()
{
    //Kamus Global
    List L;
    List Z;
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


    printf("\n\nFSearch address B pada list L : ");
    if (FSearch(L, B))
    {
        printf ("True");
    }
    else
    {
        printf ("False");
    }

    printf("\n\nFSearch address A pada list L : ");
    if (FSearch(L, A))
    {
        printf ("True");
    }
    else
    {
        printf ("False");
    }

    printf("\n\nFSearch address B pada list Z : ");
    if (FSearch(Z, B))
    {
        printf ("True");
    }
    else
    {
        printf ("False");
    }

    printf("\n\nSearch Prec pada list L : %d\n");
    SearchPrec (L, 3, &Prec);

    return 0;
}
