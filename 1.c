#include<stdio.h>
#include<string.h>
#define max  999;
int arr[] = {23,34,645,76,87};
int main()
{
    FILE *fp;
    fp = fopen("userfile.txt","r");

    char e_id[100];
    char pass[7];
    char collecte_id[100];
    int com;

    do{
        fscanf(fp,"%s",collecte_id);

        printf("enter your email id\n");
        gets(e_id);

        com= strcmp(collecte_id,e_id);
        if(com==0)
        {
            printf("the email id already exists. Try a new id\n");
        }

    }while(!com);

    printf("enter your password\n");
    gets(pass);

    fclose(fp);

    fp= fopen("userfile.txt","a");

    fputs(e_id,fp);
    fprintf(fp,"\n");
    
    for(int i=0;pass[i];i++)
    {
        fputc(pass[i]+1,fp);
    }
    fprintf(fp,"\n");

    fclose(fp);
    //puts(collecte_id);

    return 0;
}