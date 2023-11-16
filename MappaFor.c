#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

    int count;

    for(count = 0; count < 256; count++)
    {
        (char) count;
        printf("%c e' il carattere ", count);
        (int) count;
        printf("numero %d \n", count);
    }

    system("PAUSE");
    return 0;
}
