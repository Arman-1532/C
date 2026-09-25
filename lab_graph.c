#include<stdio.h>
#include<string.h>

struct cities{
    char city[100];
};
int main(){
    int size,i=0,j,incount,outcount;
    printf("enter the number of cities\n");
    scanf("%d",&size);
    struct cities cities[100];

    FILE *fp = fopen("input.txt","r");
    for(i = 0; i < size && fscanf(fp,"%s",cities[i].city) != EOF; i++){
        i++;
    }
    
    char source[100], destination[100];
    printf("enter the name of those cities you want to search\n");
    scanf("%s",source);
    scanf("%s",destination);
    int flag1 = 1;
    for(j = 0; j<i; j++){
        if(strcmp(cities[j].city,source)){
            flag1 = 0;
        }
    }

    int flag = i;
    int arr[size][size];
    printf("enter the matrix\n");
    for(i = 0; i<size; i++){
        for(j = 0; j<size; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int in[size],out[size];
    for(i = 0; i<size; i++){
        incount = 0;
        outcount = 0;
        for(j = 0; j<size; j++){
            if(arr[i][j] != 0){
                outcount++;
            }
            if(arr[j][i] != 0){
                incount++;
            }
            out[i] = outcount;
            in[i] = incount;
        }
    }
    printf("\t\tin\tout\n");
    for(i = 0; i<flag; i++){
        printf("%s\t%d\t%d\n",cities[i].city,in[i],out[i]);
    }

    for(i = 0; i<flag; i++){
        printf("%s -> ",cities[i].city);
        for(j = 0; j<flag; j++){
            if(arr[i][j] != 0){
                printf("%s ",cities[j].city);
            }
        }
        printf("\n");
    }

    return 0;

}