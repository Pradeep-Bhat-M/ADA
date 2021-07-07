#include <stdio.h>
int main()
{   
    FILE *fp;
    fp = fopen("BMSCE.txt","w");
    char c, text[1000];
    printf("Enter the contents into the file\n");    
    fgets(text, 1000, stdin);
    fputs(text, fp);
    fclose(fp);
    
    fp = fopen("BMSCE.txt","r");
    printf("The contents of the file are\n");
    while((c = getc(fp)) != EOF)
    {
        printf("%c",c);
    }
    fclose(fp);
    return 0;
}