#include<stdio.h>

void display(int arr[], int size){           // Traversal
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indexDeletion(int arr[], int size, int index, int capacity){     //Deletion
    if(size<0 || index>= capacity){
        return -1;
    }
    else{
        for(int i=index; i<= size-1; i++){
            arr[i] = arr[i+1];
        }
        return 1;
    }
}

int main(){
    int arr[10] = {7,8,12,27,88};
    int index, size = 5;
    printf("Enter the Deletion index: ");
    scanf("%d", &index);
    
    display(arr,size);

    int x = indexDeletion(arr,size,index,10);
    size = size - 1;

    if(x == 1){
        display(arr,size);
        printf("Deletion Sucessfull \n");
    }
    else{
        printf("Deletion Failed \n");
    }
}