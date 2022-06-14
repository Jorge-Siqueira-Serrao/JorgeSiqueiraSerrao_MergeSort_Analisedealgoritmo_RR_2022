#include<stdio.h>

void quickSort(int arr[], int start, int end){
    if(start < end){
        int pIndex = partition(arr, start, end);
        quickSort(arr, start, pIndex-1);
        quickSort(arr, pIndex+1, end);
    }
}

int partition(int arr[], int start, int end){
    int pIndex = start;
    int pivot = arr[end];
    int i;
    for(i = start; i < end; i++){
        if(arr[i] < pivot){
            swap(&arr[i], &arr[pIndex]);
            pIndex++;
        }
    }
    swap(&arr[end], &arr[pIndex]);
    return pIndex;
}

void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

void printArray(int A[], int size){
    int i;
    for (i=0; i < size; i++)
    printf("%d ", A[i]);
    printf("\n");
}

int main(){

    int arr[] = {75, 29, 57, 12, 39, 89, 65, 41};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    quickSort(arr,0,arr_size-1);

    printf("After the QuickSort\n");
    printArray(arr, arr_size);

    return 0;
}
