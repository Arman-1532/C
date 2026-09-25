#include<stdio.h>

int printarray(int *arr,int size);
int selection_sort(int *arr, int size);

int main(){

    int arr[]={56,23,98,12,1,9,67};
    int size = (sizeof(arr)/sizeof(arr[0]));

    printarray(arr,size);
    selection_sort(arr,size);
    printarray(arr,size);

    return 0;
}

int printarray(int *arr,int size){

    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");

    return 0;
}

int selection_sort(int *arr,int size){

    int indexOfMin,i,j,temp;
    for(i=0;i<size-1;i++){
        indexOfMin = i;
        for(j=i+1;j<size;j++){
            if(arr[indexOfMin]>arr[j]){
                indexOfMin=j;
            }
        }
        temp=arr[indexOfMin];
        arr[indexOfMin]=arr[i];
        arr[i]=temp;
    }

    return 0;
}