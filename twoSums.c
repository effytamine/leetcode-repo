#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key; 
    int indice;
} Seen;

int *twoSum(int *nums, int numsSize, int target) {
    int *result = malloc(2 * sizeof(int)); // allocate memory for 2 ints;
    if (result == NULL) {
        return NULL;
    }
    
    Seen keys[numsSize];    // create a dictionary
    int records = 0;

    for(int i = 0; i < numsSize; i++) {
        int diff = target - nums[i]; // find out difference of current number; it's solution essentially

        if(records > 0) {
            for(int j = 0; j < records; j++) {
                if(keys[j].key == diff) {
                    result[0] = keys[j].indice;
                    result[1] = i;
                    return result;
                }
            }
        }

        keys[i].key = nums[i]; // record number and its indice to dictionary
        keys[i].indice = i;
        records++;
    }
    free(result);
    return NULL;
}
int main() {
    
    int nums[] = {3, 3};
    int Size = 2;
    int target = 6;
    int *result = twoSum(nums, Size, target);

    printf("Numbers: ");
        for(int i = 0; i < Size; i++) {
            printf("%i, ", nums[i]);
        }
    printf("\nTarget: %i\n", target);
    printf("Indices\n{\n  ");

    if(result != NULL) {
        for(int i = 0; i < 2; i++) {
            printf("%i, ", result[i]);
        }
    }
    else {
        printf("None");
    }

    printf("\n}");
    free(result);
}