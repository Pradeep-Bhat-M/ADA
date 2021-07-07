#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX 100
int t[MAX];

void shifttable(char p[]){
    int i,j,m;
    m = strlen(p);

    for( i=0; i<126; i++)
        t[i] = m;
    for( i=0; i<m-2; i++)
        t[p[i]] = m-1-i;
}

int horspool(char src[],char p[]){

    int i,j,k,m,n;
    m = strlen(p);
    n= strlen(src);


    i = m-1;

    while(i<n){
        k=0;
        while(k<m && p[m-1-k]==src[i-k])
            k++;


        if(k==m)
            return i-m-1; else
        i += t[src[i]];

    }

    return -1;

}

int main()
{
    char src[100],p[100];
	int pos;

	printf("Enter the text in which pattern is to be searched:\n");
	gets(src);
	printf("Enter the pattern to be searched:\n");
	gets(p);
	shifttable(p);
	pos=horspool(src,p);
	if(pos>=0)
	  printf("\n The desired pattern was found starting from position %d",pos+1); else
	  printf("\n The pattern was not found in the given text\n");
	getch();
}