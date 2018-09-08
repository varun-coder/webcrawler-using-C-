#include<iostream>
#include<stdio.h>


int main(int argc,char *argv[])
{
    printf("PROGRAMME NAME IS %s \n",argv[0]);
    if(argc >2)
    {
	for(int i = 0 ;i<argc;i++)
	{
        	printf("\nThe arguments supplied are %s\n",argv[i]);
	}
    }
	
    else 
    {
		printf("THE PROGRAMME CONTAINS NO ARGUMENTS");
    }
    return 0;
}
