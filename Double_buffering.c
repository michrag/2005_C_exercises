#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int niu;
    int old;

    printf("\n Il programma termina quando sono immessi consecutivamente due numeri uguali \n >");
    scanf("%d", &niu);

    do
    {
        old = niu;
        printf(">");
        scanf("%d", &niu);
    }

    while(old != niu);

    printf("\n Bravo! \n");

    system("PAUSE");
    return 0;
}
