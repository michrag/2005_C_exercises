#include <stdio.h>
#include <stdlib.h>

typedef int Boolean;

#define TRUE 1
#define FALSE 0

struct record
{
    float value;
    int next;
};
struct list
{
    struct record* buffer;
    int size;
    int first;
    int free;
};

Boolean init(struct list* ptr, int size);
Boolean init(struct list* ptr, int size)
{
    int count;

    ptr->buffer = (struct record*) malloc(size * sizeof(struct record));

    ptr->size = size;
    ptr->first = size;
    ptr->free = 0;

    for(count = 0; count < (ptr->size); count++)
    {
        (ptr->buffer[count]).next = count + 1;
    }
}

void visit(struct list* ptr);
void visit(struct list* ptr)
{
    int count;
    count = ptr->first;

    printf("\nQuesta e' la lista...\n\n");

    while(count != (ptr->size))
    {
        printf("%f\n", (ptr->buffer[count]).value);
        count = (ptr->buffer[count]).next;
    }
}

Boolean search(struct list* ptr, float target);
Boolean search(struct list* ptr, float target)
{
    int count;
    Boolean found;
    count = ptr->first;
    found = FALSE;

    while((count != ptr->size) && (found == FALSE))
    {
        if(((ptr->buffer[count]).value) == target)
        {
            found = TRUE;
        }

        else
        {
            count = (ptr->buffer[count]).next;
        }
    }

    return found;
}

Boolean pre_insert(struct list* ptr, float value);
Boolean pre_insert(struct list* ptr, float value)
{
    int tmp;

    if((ptr->free) != (ptr->size))
    {
        tmp = ptr->free;
        (ptr->free) = (ptr->buffer[ptr->free]).next;

        ptr->buffer[tmp].value = value;
        (ptr->buffer[tmp]).next = ptr->first;
        ptr->first = tmp;

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

Boolean suf_insert(struct list* ptr, float value);
Boolean suf_insert(struct list* ptr, float value)
{
    int tmp;
    int* index_ptr;

    if((ptr->free) != (ptr->size))
    {
        tmp = ptr->free;
        ptr->free = ((ptr->buffer[ptr->free]).next);

        index_ptr = &(ptr->first);

        while((*index_ptr) != (ptr->size))
        {
            index_ptr = &((ptr->buffer[*index_ptr]).next);
        }

        *index_ptr = tmp;
        (ptr->buffer[tmp]).value = value;
        (ptr->buffer[tmp]).next = ptr->size;

        return TRUE;
    }

    else
    {
        return FALSE;
    }
}


int main(int argc, char* argv[])
{
    int reply;
    int size;
    struct list* ptr;
    float value;
    float target;
    Boolean result;

    do
    {
        printf("Lista Collegata con Indici\nInserire la dimensione del buffer\n>");
        scanf("%d", &size);
    }
    while(size < 1);

    init(ptr, size);

    do
    {
        printf("\n\nCosa si desidera fare?\n1)inserimento in testa\n2)inserimento in coda\n3)cerca un valore\n4)stampa lista\n5)esci\n>");
        scanf("%d", &reply);

        switch(reply)
        {
            case 1:
            {
                printf("\nInserire il valore da inserire in testa\n>");
                scanf("%f", &value);
                result = pre_insert(ptr, value);

                if(result == TRUE)
                {
                    printf("Valore inserito in testa con successo");
                }
                else
                {
                    printf("Lista piena, inserimento impossibile!");
                }
            }
            break;

            case 2:
            {
                printf("\nInserire il valore da inserire in coda\n>");
                scanf("%f", &value);
                result = suf_insert(ptr, value);

                if(result == TRUE)
                {
                    printf("Valore inserito in coda con successo");
                }
                else
                {
                    printf("Lista piena, inserimento impossibile!");
                }
            }
            break;

            case 3:
            {
                printf("\nInserire il valore cercato\n>");
                scanf("%f", &target);
                result = search(ptr, target);

                if(result == TRUE)
                {
                    printf("\n%f e' presente nella lista", target);
                }
                else
                {
                    printf("\n%f NON e' presente nella lista", target);
                }
            }
            break;

            case 4:
            {
                visit(ptr);
            }
            break;

            case 5:
            {
                printf("\nUscita...\n");
                system("PAUSE");
                return 0;
            }

            default:
                printf("\nSelezione non valida!");
        }

    }
    while(reply != 5);

}


