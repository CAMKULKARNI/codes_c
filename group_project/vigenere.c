#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int shift(char c);
int klen;
int key;
char* word;
int length;
int j;
int check(int k);
char* keyword;

int main(void)
{   
    word = (char *)malloc(256*sizeof(char));
    keyword = (char *)malloc(256*sizeof(char));
    printf("keyword: \n");
    scanf("%s", keyword);
    klen = strlen(keyword);
    for (int i = 0; i < klen; i++)
    {
        if (isalpha(*(keyword + i)) == 0)
        {
            printf("Usage: ./vigenere keyword\n");
            exit(1);
        }
    }
    printf("plaintext: \n");
    scanf(" %s", word);
    length = strlen(word);
    j = 0;
    for (int i = 0; i < length; i++)
    {
        if (j <= klen - 1)
        {    
            key = shift(*(keyword + j));
        }
        while (key > 25)
        {
            key -= 26;
        }
        if (*(word + i) <= 'z' && *(word + i) >= 'a')
        {
            if (key > 'z' - word[i])
            {
                int tkey = key;
                int gap = 'z' - *(word + i) + 1;
                *(word + i) = 'a';
                tkey = tkey - gap;
                *(word + i) += tkey;
                j = check(j);
            }
            else
            {
                *(word + i) += key;
                j = check(j);
            }
        }
        else if (*(word + i) <= 'Z' && *(word + i) >= 'A')
        {
            if (key > 'Z' - word[i])
            {
                int tkey = key;
                int gap = 'Z' - *(word + i) + 1;
                *(word + i) = 'A';
                tkey = tkey - gap;
                *(word + i) += tkey;
                j = check(j);
            }
            else
            {
                *(word + i) += key;
                j = check(j);
            }
        }
    }
    printf("ciphertext: %s\n", word);
    free(word);
    free(keyword);
}

int shift(char c)
{
    int newpos = c;
    if (c <= 'z' && c >= 'a')
    {
        newpos -= 97;
    }
    else if (c <= 'Z' && c >= 'A')
    {
        newpos -= 65;
    }
    return newpos;
}

int check(int k)
{
    if (k == klen - 1)
    {
        k = 0;
    }
    else
    {
        k++;
    }    
    return k; 
}