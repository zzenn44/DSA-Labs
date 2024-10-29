#include <stdio.h>
#define MAXSIZE 5

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            for (int j = i; j >= gap && arr[j - gap] > arr[j]; j -= gap) {
                int temp = arr[j];
                arr[j] = arr[j - gap];
                arr[j - gap] = temp;
            }
        }
    }
}

int main() {
     int arr[MAXSIZE] ;

    printf("Original array:\n enter the elements ");
    for (int i = 0; i < MAXSIZE; i++) 
    {
        scanf("%d ", &arr[i]);
    }
   
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    shellSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}


