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
struct list1
{
    struct record* buffer1;
    int size1;
    int first1;
    int free1;
};
struct list2
{
    struct record* buffer2;
    int size2;
    int first2;
    int free2;
};
struct list3
{
    struct record* buffer3;
    int size3;
    int first3;
    int free3;
};

// funzioni lista sorgente 1
Boolean init1(struct list1* ptr, int size1);
Boolean init1(struct list1* ptr, int size1)
{
    int count;

    ptr->buffer1 = (struct record*) malloc(size1 * sizeof(struct record));

    ptr->size1 = size1;
    ptr->first1 = size1;
    ptr->free1 = 0;

    for(count = 0; count < (ptr->size1); count++)
    {
        (ptr->buffer1[count]).next = count + 1;
    }
}

void visit1(struct list1* ptr);
void visit1(struct list1* ptr)
{
    int count;
    count = ptr->first1;

    printf("\nQuesta e' la lista...\n\n");

    while(count != (ptr->size1))
    {
        printf("%f\n", (ptr->buffer1[count]).value);
        count = (ptr->buffer1[count]).next;
    }
}

Boolean search1(struct list1* ptr, float target);
Boolean search1(struct list1* ptr, float target)
{
    int count;
    Boolean found;
    count = ptr->first1;
    found = FALSE;

    while((count != ptr->size1) && (found == FALSE))
    {
        if(((ptr->buffer1[count]).value) == target)
        {
            found = TRUE;
        }

        else
        {
            count = (ptr->buffer1[count]).next;
        }
    }

    return found;
}

Boolean pre_insert1(struct list1* ptr, float value);
Boolean pre_insert1(struct list1* ptr, float value)
{
    int tmp;

    if((ptr->free1) != (ptr->size1))
    {
        tmp = ptr->free1;
        (ptr->free1) = (ptr->buffer1[ptr->free1]).next;

        ptr->buffer1[tmp].value = value;
        (ptr->buffer1[tmp]).next = ptr->first1;
        ptr->first1 = tmp;

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

Boolean suf_insert1(struct list1* ptr, float value);
Boolean suf_insert1(struct list1* ptr, float value)
{
    int tmp;
    int* index_ptr;

    if((ptr->free1) != (ptr->size1))
    {
        tmp = ptr->free1;
        ptr->free1 = ((ptr->buffer1[ptr->free1]).next);

        index_ptr = &(ptr->first1);

        while((*index_ptr) != (ptr->size1))
        {
            index_ptr = &((ptr->buffer1[*index_ptr]).next);
        }

        *index_ptr = tmp;
        (ptr->buffer1[tmp]).value = value;
        (ptr->buffer1[tmp]).next = ptr->size1;

        return TRUE;
    }

    else
    {
        return FALSE;
    }
}


// funzioni lista sorgente 2
Boolean init2(struct list2* ptr, int size2);
Boolean init2(struct list2* ptr, int size2)
{
    int count;

    ptr->buffer2 = (struct record*) malloc(size2 * sizeof(struct record));

    ptr->size2 = size2;
    ptr->first2 = size2;
    ptr->free2 = 0;

    for(count = 0; count < (ptr->size2); count++)
    {
        (ptr->buffer2[count]).next = count + 1;
    }
}

void visit2(struct list2* ptr);
void visit2(struct list2* ptr)
{
    int count;
    count = ptr->first2;

    printf("\nQuesta e' la lista...\n\n");

    while(count != (ptr->size2))
    {
        printf("%f\n", (ptr->buffer2[count]).value);
        count = (ptr->buffer2[count]).next;
    }
}

Boolean search2(struct list2* ptr, float target);
Boolean search2(struct list2* ptr, float target)
{
    int count;
    Boolean found;
    count = ptr->first2;
    found = FALSE;

    while((count != ptr->size2) && (found == FALSE))
    {
        if(((ptr->buffer2[count]).value) == target)
        {
            found = TRUE;
        }

        else
        {
            count = (ptr->buffer2[count]).next;
        }
    }

    return found;
}

Boolean pre_insert2(struct list2* ptr, float value);
Boolean pre_insert2(struct list2* ptr, float value)
{
    int tmp;

    if((ptr->free2) != (ptr->size2))
    {
        tmp = ptr->free2;
        (ptr->free2) = (ptr->buffer2[ptr->free2]).next;

        ptr->buffer2[tmp].value = value;
        (ptr->buffer2[tmp]).next = ptr->first2;
        ptr->first2 = tmp;

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

Boolean suf_insert2(struct list2* ptr, float value);
Boolean suf_insert2(struct list2* ptr, float value)
{
    int tmp;
    int* index_ptr;

    if((ptr->free2) != (ptr->size2))
    {
        tmp = ptr->free2;
        ptr->free2 = ((ptr->buffer2[ptr->free2]).next);

        index_ptr = &(ptr->first2);

        while((*index_ptr) != (ptr->size2))
        {
            index_ptr = &((ptr->buffer2[*index_ptr]).next);
        }

        *index_ptr = tmp;
        (ptr->buffer2[tmp]).value = value;
        (ptr->buffer2[tmp]).next = ptr->size2;

        return TRUE;
    }

    else
    {
        return FALSE;
    }
}

// funzioni lista destinazione (3)
Boolean pre_insert3(struct list3* ptr, float value);
Boolean pre_insert3(struct list3* ptr, float value)
{
    int tmp;

    if((ptr->free3) != (ptr->size3))
    {
        tmp = ptr->free3;
        (ptr->free3) = (ptr->buffer3[ptr->free3]).next;

        ptr->buffer3[tmp].value = value;
        (ptr->buffer3[tmp]).next = ptr->first3;
        ptr->first3 = tmp;

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


void visit3(struct list3* ptr);
void visit3(struct list3* ptr)
{
    int count;
    count = ptr->first3;

    printf("\nQuesta e' la lista...\n\n");

    while(count != (ptr->size3))
    {
        printf("%f\n", (ptr->buffer3[count]).value);
        count = (ptr->buffer3[count]).next;
    }
}

int main(int argc, char* argv[])
{
    int reply;
    int risp;
    int size1;
    int size2;
    int size3;
    struct list1* ptr1;
    struct list2* ptr2;
    struct list3* ptr3;
    float value;
    float target;
    Boolean result;
    Boolean back;
    Boolean exit;

    exit = FALSE;

    do
    {
        exit = FALSE;
        printf("\nUnione di due liste collegate don indici\nCosa si desidera fare?\n1)creare la prima lista\n2)creare la seconda lista\n3)unire le due liste\n4)uscire\n>");
        scanf("%d", &risp);

        switch(risp)
        {
            case 1: //prima lista
            {
                do
                {
                    printf("Prima Lista Collegata con Indici\nInserire la dimensione del buffer\n>");
                    scanf("%d", &size1);
                }
                while(size1 < 1);

                init1(ptr1, size1);

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
                            result = pre_insert1(ptr1, value);

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
                            result = suf_insert1(ptr1, value);

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
                            result = search1(ptr1, target);

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
                            visit1(ptr1);
                        }
                        break;

                        case 5:
                            back = TRUE;
                            break;


                        default:
                            printf("\nSelezione non valida!");
                    }

                }
                while(back != TRUE);

            }//chiuso il mega case 1
            break;

            case 2: //seconda lista
            {
                do
                {
                    printf("\nSeconda Lista Collegata con Indici\nInserire la dimensione del buffer\n>");
                    scanf("%d", &size2);
                }
                while(size2 < 1);

                init2(ptr2, size2);

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
                            result = pre_insert2(ptr2, value);

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
                            result = suf_insert2(ptr2, value);

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
                            result = search2(ptr2, target);

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
                            visit2(ptr2);
                        }
                        break;

                        case 5:
                            back = TRUE;
                            break;


                        default:
                            printf("\nSelezione non valida!");
                    }

                }
                while(back != TRUE);

            }//chiuso il mega case 2
            break;

            case 3:
            {
                size3 = size1 + size2;

                //unione
            }
            break;

            case 4:
                exit = TRUE;
                break;

            default:
                printf("\nSelezione non valida!");
        }//chiuso il mega switch
    }
    while(exit != TRUE); //chiuso il mega dowhile

    printf("\nUscita...\n");
    system("PAUSE");
    return 0;

}

