#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#define HASH_SIZE 100
#define URL_LENGTH 1000
#define SEED_URL "http://www.chitkara.edu.in"
#define MAX_URL_PER_PAGE 1000
#define INTERVAL_TIME 10
/* FUNCTION TO INSERT INTO FILES */
using namespace std;
void insertIntoFILE()
{
    FILE *inputFile;
    inputFile =fopen("temp.txt","w");

    if (inputFile==NULL)
    {
        fprintf(stderr," ERROR OPENING FILE ");
    }
    else
    {
        fprintf(inputFile,"FILE OPENED %s",system("curl https://www.chitkara.edu.in > temp.txt"));
    }
}

/* ********************************************************* */

/* FUNCTION TO EXTRACT URLS FROM THE FILE */
void extractURLS()
{
    FILE *extractData;
    extractData = fopen("temp.txt","r");
    char ch;

    if(extractData == NULL)
    {
        printf("INSERT A HTML PAGE");
        exit(0);
    }
    else
    {
        ch = fgetc(extractData);

        while(ch!= EOF)
        {
            if(ch!='<' && ch!='>')
            {
                cout<<ch<<endl;
            }
            ch = fgetc(extractData);
        }
    }

}
/* END OF EXTRACT FUNCTION */
int main(int argc,char *argv[]) // command line arguments
{
    printf("PROGRAMME NAME IS %s \n",argv[0]);
    if(argc >2)
    {
        for(int i = 0 ; i<argc; i++)
        {
            printf("\nThe arguments supplied are %s\n",argv[i]);
        }
    }

    else
    {
        printf("THE PROGRAMME CONTAINS NO ARGUMENTS");
    }


    insertIntoFILE();
    extractURLS();
    return 0;
}
