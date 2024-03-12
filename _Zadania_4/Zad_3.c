#include <stdio.h>

int shouldSwap(int* array, int start, int curr) {
    for (int i = start; i < curr; i++) {
        if (array[i] == array[curr]) {
            return 0;
        }
    }
    return 1;
}

void permute(int* array, int start, int end){
    if(start == end){
        for(int i = 0; i <= end; i++){
            printf("%d ", array[i]);
        }
        printf("\n");
    } else {
        for(int i = start; i <= end; i++){
            int check = shouldSwap(array, start, i);
            if(check){
                int temp = array[start];
                array[start] = array[i];
                array[i] = temp;

                permute(array, start + 1, end);

                temp = array[start];
                array[start] = array[i];
                array[i] = temp;
            }
        }
    }
}

int main() {
    int array[] = {1,2, 2};
    permute(array, 0, 2);
    return 0;
}