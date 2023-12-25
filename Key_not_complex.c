#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int n;

    printf("\n Algoritmo NON linearmente complesso! \n Immettere il numero di quanti addendi consecutivi devono avere \n somma uguale ad un certo valore \n >");

    scanf("%d", &n);

    int* V;
    int key;
    int next2read;
    int count;
    int sum;

    printf("\n Immettere il valore per cui quando la somma degli ultimi %d numeri \n immessi risulta uguale a tale valore, il programma esce \n >", n);

    scanf("%d", &key);
    sum = 0;

    V = (int*)malloc(n * sizeof(int));

    printf("\n Adesso immettere i numeri... \n");

    for(next2read = 0; next2read < n - 1; next2read++);
    {
        scanf("%d", &V[next2read]);
        sum = sum + V[next2read];
    }

    V[n - 1] = 0; /* perchè 0 è l'elemento neutro della somma*/

    do
    {
        sum = sum - V[next2read];
        scanf("%d", &V[next2read]);
        sum = sum + V[next2read];
        next2read = (next2read + 1) % n;
    }

    while(sum != key);

    printf("\n La somma degli ultimi %d numeri immessi e' uguale a %d \n", n, key);

    system("PAUSE");
    free(V);
    return 0;
}
