#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    float* M1;
    float* M2;
    float* M3;
    int R;
    int C;
    int C2;
    int r1;
    int c1;
    int r2;
    int c2;
    int r3;
    int c3;
    float valore;
    int reply;

    printf("Knock knock Neo...\n");

    do
    {
        printf("\nCosa desideri fare?\n1) Sommare due matrici\n2) Moltiplicare due matrici\n3) Uscire dal programma\n>");
        scanf("%d", &reply);

        switch(reply)
        {
            case 1:
            {
                do
                {
                    printf("\nInserire la dimensione delle matrici\nQuante righe?\n>");
                    scanf("%d", &R);
                    printf("\nQuante colonne?\n>");
                    scanf("%d", &C);
                }
                while(R < 1 || C < 1);


                M1 = (float*)malloc(R * C * sizeof(float));
                M2 = (float*)malloc(R * C * sizeof(float));
                M3 = (float*)malloc(R * C * sizeof(float));


                printf("\nAdesso inserire i valori della prima matrice (riga,colonna)\n");

                for(r1 = 0; r1 < R; r1++)
                    for(c1 = 0; c1 < C; c1++)
                    {
                        printf("valore %d,%d >", r1, c1);
                        scanf("%f", &valore);
                        M1[r1 * C + c1] = valore;
                    }

                printf("\n\nQuesta e' la prima matrice\n");

                for(r1 = 0; r1 < R; r1++)
                {
                    for(c1 = 0; c1 < C; c1++)
                    {
                        printf(" %f", M1[r1 * C + c1]);
                    }

                    printf("\n");
                }

                printf("\n\nAdesso inserire i valori della seconda matrice (riga,colonna)\n");

                for(r2 = 0; r2 < R; r2++)
                    for(c2 = 0; c2 < C; c2++)
                    {
                        printf("valore %d,%d >", r2, c2);
                        scanf("%f", &valore);
                        M2[r2 * C + c2] = valore;
                    }

                printf("\n\nQuesta e' la seconda matrice\n");

                for(r2 = 0; r2 < R; r2++)
                {
                    for(c2 = 0; c2 < C; c2++)
                    {
                        printf(" %f", M2[r2 * C + c2]);
                    }

                    printf("\n");
                }

                printf("\n\nQuesta e' la matrice risultante\n");

                for(r1 = 0, r2 = 0, r3 = 0; r1 < R, r2 < R, r2 < R; r1++, r2++, r3++)
                {
                    for(c1 = 0, c2 = 0, c3 = 0; c1 < C, c2 < C, c3 < C; c1++, c2++, c3++)
                    {
                        M3[r3 * C + c3] = M1[r1 * C + c1] + M2[r2 * C + c2];
                        printf(" %f", M3[r3 * C + c3]);
                    }

                    printf("\n");
                }

                free(M1);
                free(M2);
                free(M3);
            }
            break;

            case 2:
            {
                do
                {
                    printf("\nInserire la dimensione delle matrici\nQuante sono le righe della prima matrice?\n>");
                    scanf("%d", &R);
                    printf("\nQuante sono le colonne della prima matrice (e quindi le righe della seconda)?\n>");
                    scanf("%d", &C);
                    printf("\nQuante sono le colonne della seconda matrice?\n>");
                    scanf("%d", &C2);
                }
                while(R < 1 || C < 1 || C2 < 1);


                M1 = (float*)malloc(R * C * sizeof(float));
                M2 = (float*)malloc(C * C2 * sizeof(float));
                M3 = (float*)malloc(R * C2 * sizeof(float));

                printf("\nAdesso inserire i valori della prima matrice (riga,colonna)\n");

                for(r1 = 0; r1 < R; r1++)
                    for(c1 = 0; c1 < C; c1++)
                    {
                        printf("valore %d,%d >", r1, c1);
                        scanf("%f", &valore);
                        M1[r1 * C + c1] = valore;
                    }

                printf("\n\nQuesta e' la prima matrice\n");

                for(r1 = 0; r1 < R; r1++)
                {
                    for(c1 = 0; c1 < C; c1++)
                    {
                        printf(" %f", M1[r1 * C + c1]);
                    }

                    printf("\n");
                }

                printf("\n\nAdesso inserire i valori della seconda matrice (riga,colonna)\n");

                for(r2 = 0; r2 < C; r2++)
                    for(c2 = 0; c2 < C2; c2++)
                    {
                        printf("valore %d,%d >", r2, c2);
                        scanf("%f", &valore);
                        M2[r2 * C2 + c2] = valore;
                    }

                printf("\n\nQuesta e' la seconda matrice\n");

                for(r2 = 0; r2 < C; r2++)
                {
                    for(c2 = 0; c2 < C2; c2++)
                    {
                        printf(" %f", M2[r2 * C2 + c2]);
                    }

                    printf("\n");
                }

                for(r1 = 0; r1 < R; r1++)
                {
                    for(c2 = 0; c2 < C2; c2++)
                    {
                        M3[r1 * C2 + c2] = 0;

                        for(c1 = 0; c1 < C; c1++)
                        {
                            M3[r1 * C2 + c2] += M1[r1 * C + c1] * M2[c1 * C2 + c2];
                        }
                    }
                }


                printf("\nQuesta e' la matrice risultante\n");

                for(r1 = 0; r1 < R; r1++)
                {
                    for(c2 = 0; c2 < C2; c2++)
                    {
                        printf(" %f", M3[r1 * C2 + c2]);
                    }

                    printf("\n");
                }

                free(M1);
                free(M2);
                free(M3);
            }
            break;

            case 3:
            {
                printf("\nFollow the white rabbit...\n");
                system("PAUSE");
                return 0;
            }

            default:
                printf("\nSelezione non valida!");
        }
    }
    while(reply != 3);
}



