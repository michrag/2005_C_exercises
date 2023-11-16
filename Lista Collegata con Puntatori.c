#include <stdio.h>
#include <stdlib.h>

typedef int Boolean;

#define TRUE 1
#define FALSE 0



struct list
{
    float value;
    struct list* next_ptr;
};

void init(struct list** ptr_ptr);
void init(struct list** ptr_ptr)
{
    *ptr_ptr = NULL;
}

void pre_insert(struct list** ptr_ptr, float value);
void pre_insert(struct list** ptr_ptr, float value)
{
    struct list* tmp_ptr;
    tmp_ptr = *ptr_ptr;

    *ptr_ptr = (struct list*) malloc(sizeof(struct list));
    (*ptr_ptr)->value = value;
    (*ptr_ptr)->next_ptr = tmp_ptr;
}

void suf_insert(struct list** ptr_ptr, float value);
void suf_insert(struct list** ptr_ptr, float value)
{
    while((*ptr_ptr) != NULL)
    {
        ptr_ptr = &((*ptr_ptr)->next_ptr);
    }

    pre_insert(ptr_ptr, value);
}

void ord_insert(struct list** ptr_ptr, float value);
void ord_insert(struct list** ptr_ptr, float value)
{
    while((*ptr_ptr) != NULL && ((*ptr_ptr)->value) < value)
    {
        ptr_ptr = &((*ptr_ptr)->next_ptr);
    }

    pre_insert(ptr_ptr, value);
}

void visit(struct list* ptr);
void visit(struct list* ptr)
{
    printf("\nQuesta e' la lista...\n");

    while(ptr != NULL)
    {
        printf("%f\n", ptr->value);
        ptr = ptr->next_ptr;
    }
}

void reverse_visit(struct list* ptr);
void reverse_visit(struct list* ptr)
{
    if(ptr != NULL)
    {
        reverse_visit(ptr->next_ptr);
        printf("%f\n", ptr->value);
    }
}

Boolean search(struct list* ptr, float target);
Boolean search(struct list* ptr, float target)
{
    Boolean found;
    found = FALSE;

    while(ptr != NULL && found == FALSE)
    {
        if(ptr->value == target)
        {
            found = TRUE;
        }

        else
        {
            ptr = ptr->next_ptr;
        }
    }

    return found;
}

void sum(struct list* ptr);
void sum(struct list* ptr)
{
    float somma;
    somma = 0;

    while(ptr != NULL)
    {
        somma += (ptr->value);
        ptr = ptr->next_ptr;
    }

    printf("\nLa somma di tutti gli elementi della lista e' %f\n", somma);
}

Boolean pre_cancel(struct list** ptr_ptr);
Boolean pre_cancel(struct list** ptr_ptr)
{
    if(*ptr_ptr != NULL)
    {
        struct list* tmp_ptr;
        tmp_ptr = *ptr_ptr;
        *ptr_ptr = (*ptr_ptr)->next_ptr;
        free(tmp_ptr);
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
    struct list* ptr;
    float value;
    float target;
    Boolean result;

    printf("Lista Collegata con Puntatori\n");

    init(&ptr);

    do
    {
        printf("\nCosa si desidera fare?\n1)inserimento in testa\n2)inserimento in coda\n3)inserimento in ordine\n4)cerca un valore\n5)stampa lista\n6)stampa la lista in ordine inverso\n7)somma tra loro tutti gli elementi della lista\n8)cancellazione in testa\n9)esci\n>");
        scanf("%d", &reply);

        switch(reply)
        {
            case 1:
            {
                printf("\nInserire il valore da inserire in testa\n>");
                scanf("%f", &value);
                pre_insert(&ptr, value);
            }
            break;

            case 2:
            {
                printf("\nInserire il valore da inserire in coda\n>");
                scanf("%f", &value);
                suf_insert(&ptr, value);
            }
            break;

            case 3:
            {
                printf("\nInserire il valore da inserire in ordine\n>");
                scanf("%f", &value);
                ord_insert(&ptr, value);
            }
            break;

            case 4:
            {
                printf("\nInserire il valore cercato\n>");
                scanf("%f", &target);
                result = search(ptr, target);

                if(result == TRUE)
                {
                    printf("\n%f e' presente nella lista\n", target);
                }
                else
                {
                    printf("\n%f NON e' presente nella lista\n", target);
                }
            }
            break;

            case 5:
            {
                visit(ptr);
            }
            break;

            case 6:
            {
                printf("\nQuesta e' la lista in ordine inverso...\n");
                reverse_visit(ptr);
            }
            break;

            case 7:
            {
                sum(ptr);
            }
            break;

            case 8:
            {
                if(pre_cancel(&ptr) == TRUE)
                {
                    printf("\nValore in testa cancellato con successo!\n");
                }

                else
                {
                    printf("\nLista vuota!\n");
                }
            }
            break;

            case 9:
            {
                printf("\nUscita...\n");
                system("PAUSE");
                return 0;
            }

            default:
                printf("\nSelezione non valida!");
        }

    }
    while(reply != 9);

}


