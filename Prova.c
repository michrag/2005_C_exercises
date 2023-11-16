#include <stdio.h>
#include <stdlib.h>


struct record
{
    int codice;
};

int main(int argc, char* argv[])
{
    int count;
    struct record** V;
    //alloca(&V);


    *V = (struct record*)malloc(5 * sizeof(struct record));
    (*V[0]).codice = 1;

    system("PAUSE");
    return 0;
}
