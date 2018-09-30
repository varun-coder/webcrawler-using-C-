#include <stdio.h>

#include <string.h>

#include<stdlib.h>

#include <sys/types.h>

#include <sys/stat.h>

#define HASH_SIZE 100


#define URL_LENGTH 1000


#define SEED_URL "https://www.chitkara.edu.in"


#define MAX_URL_PER_PAGE 1000


#define INTERVAL_TIME 10


/*#define CHECK_MALLOC(s) if ((s) == NULL) { \

printf("memory allocation failed in %s: line%d", _FILE, __LINE_); \

perror(":"); \

exit(-1); \

} 
*/


#define SET_MEM(start,size) memset(start,0,size)



void getpage(char *url)
{
char urlbuffer[1000]={0};
strcat(urlbuffer,"wget -O ");
strcat(urlbuffer,"/home/anarchist/Desktop/Crawler/pages/temp.txt ");
strcat(urlbuffer,url);
system(urlbuffer);
}

char *get_html()
{
	int length=0,i=0;
	char ch;
	FILE *file1=fopen("/home/anarchist/Desktop/Crawler/pages/temp.txt ","r");

	while(!feof(file1))
	{
		ch=getc(file1);
		length++;
	}
	
	char *str=(char *)malloc(sizeof(char)*length);
	rewind(file1);
	while(!feof(file1))
	{
		ch=getc(file1);
		str[i]=ch;
		i++;
	}

	str[i-1]='\0';
	//printf("%s",str);
return str;
}


void validdir(char *dir)

{

    struct stat statbuf;

    if ( stat(dir, &statbuf) == -1 )

    {

        fprintf(stderr, "-----------------\n");

        fprintf(stderr, "Invalid directory\n");

        fprintf(stderr, "-----------------\n");

    }


    if ( !S_ISDIR(statbuf.st_mode) )

    {

        fprintf(stderr, "-----------------------------------------------------\n");

        fprintf(stderr, "Invalid directory entry. Your input isn't a directory\n");

        fprintf(stderr, "-----------------------------------------------------\n");

    }


    if ( (statbuf.st_mode & S_IWUSR) != S_IWUSR )

    {

        fprintf(stderr, "------------------------------------------\n");

        fprintf(stderr, "Invalid directory entry. It isn't writable\n");

        fprintf(stderr, "------------------------------------------\n");

    }

}

void validseedurl(char *url)
{
	if(strcmp(url,SEED_URL)!=0)
	{
		printf("URL NOT VALID\n");	
	}
	
	else

   	 {

        char ch[100] = "wget --spider ";

        strcat(ch,url);

        if(!system(ch))

        {

            printf("------------------------------------------\n");

            printf("%s is a Valid URL\n", url);

            printf("------------------------------------------\n\n");

        }

        else

        {

            printf("---------------------\n");

            printf("%s is a not Valid URL\n", url);

            printf("---------------------\n");

        }

    }
}

void validdepth(char *c)
{
	if(strcmp(c,"1")!=0)
	{
		printf("Depth is not valid\n");
	}

}

int validation_of_arguments(int argc, char *argv[])
{
	if(argc<4)
	{ 	printf("---------------------\n");
 		printf("Not Enough arguments");
		printf("---------------------\n");
		return 0;
	}
	
	validseedurl(argv[1]);	
 	validdepth(argv[2]);
	validdir(argv[3]);
	
	return 1;
}

char **get_url(char *html)
{	char url[MAX_URL_PER_PAGE][URL_LENGTH];
	char temp[]={"a href="};
	int i=0,j=0,k=0,f=0,count=0,row=0,column=0;
	while(html[i]!='\0')
	{
		j=0;
		
		while(html[i]==temp[j])
		{
			j++;
			i++;
		}	
		
		if(j==7)
		{
		
			if(html[i]=='"' && html[i+1]=='h')
			{	i++;
				while(html[i]!='"')
				{
					url[row][column]=html[i];
					column++;
					i++;
					k++;
				}
				url[row][column]='\0';
				row++;
				//count++;
				k++;
				
			}
			
			
		}	
		i++;
	}
	for(i=0;i<row;i++)
	{	
		
		
			printf("%s",*url[i]);
		
	}
	
	
return url;
}

int main(int argc, char *argv[])
{
	validation_of_arguments(argc,argv);

	getpage(argv[1]);
	
	char *html=get_html();
	
	char **url=get_url(html);
	return 0;
}
