#include <stdio.h>
#include <stdlib.h>

typedef int Boolean;
#define TRUE 1
#define FALSE 0

struct list
{
    float* buffer;
    int size;
    int testa;
    int coda;
};

Boolean init(struct list* ptr, int size);
Boolean init(struct list* ptr, int size)
{
    ptr->buffer = (float*)malloc(sizeof(float) * size);
    ptr->size = size;
    ptr->testa = 0;
    ptr->coda = 0;
}

Boolean pre_insert(struct list* ptr, float value);
Boolean pre_insert(struct list* ptr, float value)
{
    if((((ptr->testa) + (ptr->size) - 1) % (ptr->size)) != (ptr->coda))
    {
        ptr->testa = ((ptr->testa) + (ptr->size) - 1) % (ptr->size);
        ptr->buffer[ptr->testa] = value;
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
    if(((ptr->coda + 1) % (ptr->size)) != (ptr->testa))
    {
        (ptr->buffer[ptr->coda]) = value;
        (ptr->coda) = ((ptr->coda + 1) % (ptr->size));
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void visit(struct list* ptr);
void visit(struct list* ptr)
{
    int count;
    printf("\nQuesta e' la lista...\n");

    for(count = (ptr->testa); count != (ptr->coda); count = ((count + 1) % (ptr->size)))
    {
        printf("%f\n", (ptr->buffer[count]));
    }
}

Boolean search(struct list* ptr, float target);
Boolean search(struct list* ptr, float target)
{
    int count;
    Boolean found;
    count = (ptr->testa);
    found = FALSE;

    while((count != (ptr->coda)) && (found == FALSE))
    {
        if((ptr->buffer[count]) == target)
        {
            found = TRUE;
        }
        else
        {
            count = (count + 1) % (ptr->size);
        }
    }

    return found;
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
        printf("Lista sequenziale\nInserire la dimensione del buffer\n>");
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
