#include <stdio.h>
#include <stdlib.h>

typedef int Boolean;

#define TRUE 1
#define FALSE 0

struct struttura
{
    int code;
    struct prestazione* ptr;
};
struct elenco
{
    int size;
    int testa;
    int coda;
    int* buffer;
};
struct prestazione
{
    int codice;
    struct elenco elenco;
    struct prestazione* next_ptr;
};

Boolean search(struct prestazione* ptr, int target);
void stampa_data(struct elenco* ptr);
void dove_quando(struct struttura* V, int size, int target);

void dove_quando(struct struttura* V, int size, int target)
{
    int count;

    for(count = 0; count < size; count++)
    {
        if(search(V[count].ptr, target) == TRUE)
        {
            printf(" struttura %d", V[count].code);
        }
    }
}


Boolean search(struct prestazione* ptr, int target)
{
    Boolean found;
    found = FALSE;

    while(ptr != NULL && found == FALSE)
    {
        if(ptr->codice == target)
        {
            found = TRUE;
            stampa_data(&(ptr->elenco));
        }

        else
        {
            ptr = ptr->next_ptr;
        }
    }

    return found;
}


void stampa_data(struct elenco* ptr)
{
    int data;

    if(ptr->testa != ptr->coda)
    {
        data = ptr->buffer[ptr->testa];
        printf("\nLa prestazione richiesta e' disponibile il giorno %d nella", data);
    }

    else
    {
        printf("\nLa prestazione richiesta e' offerta ma al amomento non disponibile nella");
    }
}

int main(int argc, char* argv[])
{

    system("PAUSE");
    return 0;
}
