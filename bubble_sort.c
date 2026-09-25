#include<stdio.h>
int printarray(int *arr,int size);
int bubblesort(int *arr,int size);

int main(){
    int arr[6]= {56,322,89,3,90,2};
    int size = (sizeof(arr)/sizeof(arr[0]));
    printarray(arr,size);
    bubblesort(arr,size);
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
int bubblesort(int *arr,int size){
    int temp;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return 0;
}
