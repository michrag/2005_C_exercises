#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int niu;
    int middle;
    int old;

    printf("\n Il programma esce quando la somma degli ultimi tre numeri immessi risulta \n uguale a 30 \n >");

    scanf("%d", &niu);

    middle = niu;

    printf(">");

    scanf("%d", &niu);

    do
    {
        old = middle;
        middle = niu;
        printf(">");
        scanf("%d", &niu);
    }
    while(old + middle + niu != 30);

    printf("Bravo! \n");

    system("PAUSE");
    return 0;
}
