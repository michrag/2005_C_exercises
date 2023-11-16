// inclusioni per l'uso di funzioni di libreria
#include <stdio.h>
#include <stdlib.h>

// definizioni per l'uso dei Booleani
typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

//dimensione del buffer: N è una variabile globale
int N;

// prototipi
void init(int* TOS_ptr);
boolean push(float* buffer, int* TOS_ptr, float value);
boolean pop(float* buffer, int* TOS_ptr, float* value_ptr);
void getvalue(float* value_ptr);
void putvalue(float value);
void notify_push_failure(void);
void notify_pop_failure(void);
void notify_selection_failure(char selection);


// definizioni secondo lo schema buttom-up

void init(int* TOS_ptr)
// inizializza a zero il TOS
{
    *TOS_ptr = 0;
}

boolean push(float* buffer, int* TOS_ptr, float value)
/* se il buffer non è pieno inserisce value e restituisce TRUE, altrimenti
restituisce FALSE */
{
    if(*TOS_ptr < N)
    {
        buffer[*TOS_ptr] = value;
        (*TOS_ptr)++;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

boolean pop(float* buffer, int* TOS_ptr, float* value_ptr)
/* se il buffer non è vuoto estrae un valore in *value_ptr e restituisce TRUE,
altrimenti restituisce FALSE */
{
    if(*TOS_ptr > 0)
    {
        (*TOS_ptr)--; /* *TOS_ptr si deve abbassare di una
                         posizione per estrarre l'ultima variabile, altrimenti
                         colpirebbe a vuoto! */
        *value_ptr = buffer[*TOS_ptr];
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void getvalue(float* value_ptr)
// acquisisce un float da tastiera
{
    printf("\n Inserire un valore \n>");
    scanf("%f", value_ptr);
}

void putvalue(float value)
// stampa a video un float
{
    printf("\n Valore estratto: %f\n", value);
}

void notify_push_failure(void)
// notifica il fallimento dell'operazione di inserimento
{
    printf("\nBuffer pieno! Inserimento impossibile.\n");
}

void notify_pop_failure(void)
// notifica il fallimento dell'operazione di estrazione
{
    printf("\nBuffer vuoto! Estrazione impossibile.\n");
}

void notify_selection_failure(char selection)
// notifica il fallimento dell'operazione di selezione
{
    printf("\n%c non e' una selezione valida.\n", selection);
}

main()
/* dialogo transazionale nel quale l'utente può ripetutamente inserire ed
estrarre numeri finchè non richiede la terminazione */
{
    int TOS;
    float* buffer;
    char selection;
    float value;
    boolean result;
    boolean exit_required;

    printf("STACK: segmento di memoria con politica Last In First Out\n");

    do
    {
        printf("Inserire la dimensione dello stack (un intero maggiore di zero)\n>");
        scanf("%d", &N);
    }
    while(N < 1);

    init(&TOS);
    buffer = (float*) malloc(N * sizeof(float));

    do
    {
        fflush(stdin); // funzione di libreria che impedisce che l'invio sia considerato un carattere
        exit_required = FALSE;

        printf("Cosa si desidera fare?\nI: inserire un valore\nO: estrarre un valore\nX: uscire dal programma\n>");

        selection = getchar(); /* è una funzione di libreria inclusa
                    in stdio.h che riceve un carattere da tastiera */


        switch(selection)
        {
            case 'i':
            case 'I': // sia minuscolo che maiuscolo
                getvalue(&value);

                result = push(buffer, &TOS, value);

                if(result == FALSE)
                {
                    notify_push_failure();
                }

                break;

            case 'o':
            case 'O':
                result = pop(buffer, &TOS, &value);

                if(result == TRUE)
                {
                    putvalue(value);
                }
                else
                {
                    notify_pop_failure();
                }

                break;

            case 'x':
            case 'X':
                exit_required = TRUE;
                break;

            default:
                notify_selection_failure(selection);
        }
    }

    while(exit_required == FALSE);

    printf("\nUscita...\n");
    system("PAUSE");
    return 0;
}
