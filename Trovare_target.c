#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int V[8];
    int target;
    int count;
    int found;
    printf("\n Introdurre il valore da cercare \n >");
    scanf("\%d", &target);

    count = 0;
    found = 0; /* variabile "booleana"*/

    while(count < 8 && found == 0)
    {
        if(V[count] == target)
        {
            found = 1;
        }
        else
        {
            count = count + 1;
        }
    }

    if(found = 1)
    {
        printf("\n Il valore cercato e' stato trovato \n");
    }
    else
    {
        printf("\n Il valore cercato non e' stato trovato \n");
    }

    system("PAUSE");
    return 0;
}
