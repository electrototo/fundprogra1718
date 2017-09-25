#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t seed;

    printf("segundos: %ld\n", time(0));

    scanf("%ld", &seed);
    srand(seed);

    printf("numero: %d\n", rand() % 100 + 1);

    return 0;
}
