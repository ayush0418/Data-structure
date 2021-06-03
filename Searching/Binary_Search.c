#include<stdio.h>

int binarySearching(int arr[], int size, int element){
    int low = 0;
    int mid;
    int high = size-1;

    while(low<=high){
        mid = (high + low)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid] < element){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int element;

    // Sorted array for binary search
    int arr[] = {1,3,5,56,64,73,123,225,444};
    int size = sizeof(arr)/sizeof(int);

    printf("Enter the number to be searched: ");
    scanf("%d",&element);

    int searchIndex = binarySearching(arr, size, element);
    printf("The element %d was found at index %d \n", element, searchIndex);
}