#include<iostream>
#include<stdio.h>


int main(int argc,char *argv[])
{
    printf("PROGRAMME NAME IS %s \n",argv[0]);
    if(argc <2)
    {
        printf("The arguments supplied are %s %s %s",argv[1]);
    }
    else{
        printf("TOO MANY ARGUMENTS");
    }
    return 0;
}
