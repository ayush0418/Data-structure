#include<stdio.h>

int linaerSeaching(int arr[], int size, int element){
    for(int i=0;i<=size;i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}

int main(){
    int element;

    // Unsorted array for linear search
    int arr[] = {18, 9, 23, 17, 67}; 
    int size = sizeof(arr)/sizeof(int);

    printf("Enter the number to be searched: ");
    scanf("%d",&element);

    int searchIndex = linaerSeaching(arr,size,element);
    printf("The element %d was found at index %d \n", element, searchIndex);
}