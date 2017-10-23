/*
 * autor: cristobal liendo i
 * fecha: 23/10/17
 * descripcion: algortimo bubble sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 20

void bubble_sort(int *, int);
void swap(int *, int *);

int main() {
    srand(time(0));

    int nums[LENGTH];

    printf("Numeros aleatorios:\n");
    for (int i = 0; i < LENGTH; i++) {
        nums[i] = (rand() % LENGTH) + 1;
        printf("%d%s", nums[i], (i == LENGTH - 1) ? "\n" : ", ");
    }

    bubble_sort(nums, LENGTH);

    printf("Despues de haber sido ordenado:\n");
    for (int i = 0; i < LENGTH; i++)
        printf("%d%s", nums[i], (i == LENGTH - 1) ? "\n" : ", ");

    return 0;
}

void bubble_sort(int *nums, int length) {
    int change = 1;

    while (change == 1) {
        change = 0;

        for (int i = 1; i < length; i++) {
            if (nums[i] < nums[i - 1]) {
                swap(&nums[i], &nums[i - 1]);
                change = 1;
            }
        }
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
