#include<stdio.h>

int printarray(int *array,int n){
    for(int i=0;i<n;i++){
        printf("%d\t",array[i]);
    }
    printf("\n");

    return 0;
}

int partition(int *array,int low,int high){

    int pivot = array[low];
    int i=low+1,j=high;
    do{
        while(i<=j && pivot>=array[i]){
            i++;
        }
        while(i<=j && pivot<array[j]){
            j--;
        }
        if(i<=j){
            int temp=array[i];
            array[i]=array[j];
            array[j]=temp;
        }
    }while(i<=j);

    int temp = array[low];
    array[low] = array[j];
    array[j] = temp;

    return j;
}
void quicksort(int *array,int low,int high){

    int partitionIndex; //index of pivot after partition
    if(low<high){
        partitionIndex = partition(array,low,high);
        quicksort(array,low,partitionIndex-1);  //sort left sub-array
        quicksort(array,partitionIndex+1,high);  //sory right sub-array
    }
}
int main(){
    int array[]={56,76,23,87,1,9,12,67,23};
    int n = (sizeof(array)/sizeof(array[0]));
    printarray(array,n);
    quicksort(array,0,n-1);
    printarray(array,n);

    return 0;
}