#include <stdio.h>
#include <math.h>
int main()
{
    char d[10]="suaachsa";
    char s[100],S[100]="",c;
    int x=0,i,k=0,ch=0,chr=0,l=0;
    scanf("%s",s);
    l=strlen(s);
    for(i=0;i<l;i++)
    {
        if(x==8)
            x=0;
        k=(int)(d[x]);
        x++;
        ch=(int)s[i];
        while(k>26)
        {
            k-=26;
        }
        chr=ch-k;
        if(chr<97)
        {
            chr=122-(97-chr)+1;
        }
        c=(char)chr;
        S[i]=c;
    }
    printf("\nDecrypted string : %s",S);
    return 0;
}
