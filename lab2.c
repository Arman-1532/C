#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct {
    char name[100];
} City;

City cities[100];
int numofcities = 0;

int Index(char *name) {
    for (int i = 0; i < numofcities; i++) {
        if (strcmp(name, cities[i].name) == 0) {
            return i; 
        }
    }
    strcpy(cities[numofcities].name, name);
    return numofcities++; 
}

int main() {
    int matrix[100][100] = {0};
    int connections, cost;
    char city1[100], city2[100];

    FILE *fp = fopen("input.txt","r");
    fscanf(fp,"%d", &connections);

    for (int i = 0; i < connections; i++) {
        fscanf(fp,"%s %s %d", city1, city2, &cost);
        int index1 = Index(city1);
        int index2 = Index(city2);
        matrix[index1][index2] = cost;
    }

    printf("Matrix:\n");
    for (int i = 0; i < numofcities; i++)
    {
        for (int j = 0; j < numofcities; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
 
    printf("cities:\n");
    for (int i = 0; i < numofcities; i++) {
        printf("%s\n", cities[i].name);
    }

    printf("Enter the source city: ");
    scanf("%s", city1);
    printf("Enter the destination city: ");
    scanf("%s", city2);

    int index1 = Index(city1);
    int index2 = Index(city2);

    
    if (matrix[index1][index2] > 0) {
        printf("\nIt is possible to go from %s to %s and cost is %d.\n", city1, city2, cost);
    } else {
        printf("\nIt is not possible to go from %s to %s directly.\n", city1, city2);
    }

    fclose(fp);
    return 0;
}


