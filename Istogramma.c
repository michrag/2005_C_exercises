#include <stdio.h>
#include <stdlib.h>

typedef short unsigned int Boolean;

#define TRUE 1
#define FALSE 0

struct list
{
    float value;
    int instances;
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
    (*ptr_ptr)->instances = 1;
    (*ptr_ptr)->next_ptr = tmp_ptr;
}

void add_value(struct list** ptr_ptr, float value);
void add_value(struct list** ptr_ptr, float value)
{
    while((*ptr_ptr) != NULL && ((*ptr_ptr)->value) < value)
    {
        ptr_ptr = &((*ptr_ptr)->next_ptr);
    }

    if((*ptr_ptr) != NULL && ((*ptr_ptr)->value == value))
    {
        ((*ptr_ptr)->instances)++;
    }
    else
    {
        pre_insert(ptr_ptr, value);
    }
}

void create_histo(float* V, int size, struct list** ptr_ptr);
void create_histo(float* V, int size, struct list** ptr_ptr)
{
    int count;
    init(ptr_ptr);

    for(count = 0; count < size; count++)
    {
        add_value(ptr_ptr, V[count]);
    }
}

void visit(struct list* ptr);
void visit(struct list* ptr)
{
    while(ptr != NULL)
    {
        printf("|%f|   |%d|\n", ptr->value, ptr->instances);
        ptr = ptr->next_ptr;
    }
}

int main(int argc, char* argv[])
{
    float* A;
    struct list* ptr;
    int n;
    int count;
    int reply;
    int risp;
    Boolean back;
    Boolean exit;

    exit = FALSE;


    printf("\nIstogramma\n");

    do
    {
        printf("\nCosa desideri fare?\n1)Creare un vettore\n2)Uscire\n>");
        scanf("%d", &reply);

        switch(reply)
        {
            case 1:
            {
                do
                {
                    printf("Inserire la dimensione del vettore\n>");
                    scanf("%d", &n);
                }
                while(n < 1);

                A = (float*)malloc(n * sizeof(float));

                printf("\nInserire i valori...\n");

                for(count = 0; count < n; count++)
                {
                    printf("Valore in posizione %d >", count);
                    scanf("%f", &A[count]);
                }

                do
                {
                    printf("\nCosa desideri fare?\n1)stampare il vettore\n2)creare e stampare l'istogramma\n3)tornare al menu precedente\n>");
                    scanf("%d", &risp);

                    back = FALSE;

                    switch(risp)
                    {
                        case 1:
                        {
                            printf("\nQuesto e' il vettore...\n");

                            for(count = 0; count < n; count++)
                            {
                                printf("|%f|\n", A[count]);
                            }
                        }
                        break;

                        case 2:
                        {
                            create_histo(A, n, &ptr);
                            printf("\nQuesto e' l'istogramma\n|valore|     |presenze nel vettore|\n\n");
                            visit(ptr);
                        }
                        break;

                        case 3:
                        {
                            back = TRUE;
                            free(A);
                        }
                        break;

                        default:
                            printf("Selezione non valida\n");

                    }
                }
                while(back != TRUE);


            }
            break;

            case 2:
                exit = TRUE;
                break;

            default:
                printf("Selezione non valida\n");

        }
    }
    while(exit != TRUE);

    system("PAUSE");
    return 0;
}
