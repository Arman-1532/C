#include<stdio.h>
int b[100];

int printarray(int *array,int n){
    for(int i=0;i<n;i++){
        printf("%d\t",array[i]);
    }
    printf("\n");

    return 0;
}

int merge(int *arr, int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;

    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            b[k]=arr[i];
            k++;
            i++;
        }
        else{
            b[k]=arr[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        b[k]=arr[i];
        k++;
        i++;
    }
    while(j<=high){
        b[k]=arr[j];
        k++;
        j++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=b[i];
    }
        return 0;
    
}

void mergesort(int *arr, int low,int high){
    if(low<high){
        int mid = (low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
    int array[]={8,56,76,23,87,1,9,12,67,23};
    int n = (sizeof(array)/sizeof(array[0]));
    printarray(array,n);
    mergesort(array,0,n-1);
    printarray(array,n);

    return 0;
}