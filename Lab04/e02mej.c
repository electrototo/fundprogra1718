#include <stdio.h>

int main() {
    int nums[3];
    int index[3] = {-1, -1, -1};

    printf("Ingrese tres numeros: ");
    scanf("%d %d %d", &nums[0], &nums[1], &nums[2]);

    int max, ii;
    ii = 0;

    int in = 0;

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            if (nums[i] > max) {

                for (int k = 0; k < 3; k++) {
                    in = (index[k] == i) ? 1 : 0;
                    
                    if (in)
                        break;
                }

                if (!in) {
                    max = nums[i];
                    index[ii] = i;
                }
            }
        }

        printf("max: %d\n", max);

        max = in = 0;
        ii++;
    }


    return 0;
}
