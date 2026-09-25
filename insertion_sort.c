#include<stdio.h>

int printarray(int *arr,int size);
int insertion_sort(int *arr,int size);

int main(){
    int arr[6];
    for(int i=0;i<6;i++){
        scanf("%d",&arr[i]);
    }
    int size = (sizeof(arr)/sizeof(arr[0]));
    printarray(arr,size);
    insertion_sort(arr,size);
    printarray(arr,size);

    return 0;
}

int printarray(int *arr, int size){

    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");

    return 0;
}

int insertion_sort(int *arr,int size){

    int key,j;
    for(int i=1;i<size;i++){
        key = arr[i];
        j=i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

    return 0;
}