#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
#define n 8

    int V[n];
    int key;
    int next2read;
    int count;
    int sum;

    scanf("%d", &key);
    sum = 0;

    for(next2read = 0; next2read < n - 1; next2read++);

    {
        scanf("%d", &V[next2read]);
        sum = sum + V[next2read];
    }

    V[n - 1] = 0; /* perchè 0 è l'elemento neutro della somma*/

    do
    {
        sum = sum - V[next2read];
        scanf("%d", &V[next2read]);
        sum = sum + V[next2read];
        next2read = (next2read + 1) % n;
    }

    while(sum != key);

    system("PAUSE");
    return 0;
}
