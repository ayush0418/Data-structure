#include<stdio.h>

void display(int arr[], int size){           // Traversal
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indexInsertion(int arr[], int size, int element, int index, int capacity){    // Insertion
    if(size >= capacity || index >= capacity){
       return -1;
    }
    else{
        for(int i=size-1; i>=index; i--){
            arr[i+1] = arr[i];
        }
        arr[index] = element;
        return 1;
    }
}

int main(){
    int arr[10] = {7,8,12,27,88};
    int element, index, size = 5;

    printf("Enter the insertion element: ");
    scanf("%d", &element);

    printf("Enter the insertion index: ");
    scanf("%d", &index);
    
    display(arr,size);

    int x = indexInsertion(arr,size,element,index,10);
    size = size + 1;

    if(x == 1){
        display(arr,size);
        printf("Insertion Sucessfull \n");
    }
    else{
        printf("Insterion Failed \n");
    }
}