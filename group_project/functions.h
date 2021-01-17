#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

void shuffle(char *array, size_t n);
void password_generation(void);
void password_classification(void);
int shift(char c);
int check(int k);
void vigenere (void);
int message (int a);
void decryption (void);

int klen;

//Password functions
void shuffle(char *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void password_generation(void)
{
    srand(time(0));
    char password[12];
    const char *small_alpha = "abcdefghijklmnopqrstuvwxyz";
    const char *caps_alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *num = "0123456789";
    const char *special_char = "!@#$^&*()_+-=[]{}|<>/?\"\\";
    int password_len = rand() % 8 + 7;
    for (int i = 0; i < 4; i++)
    {
        int j;
        switch (i)
        {
        case 0:
            j = rand() % 26;
            password[i] = small_alpha[j];
            break;
        case 1:
            j = rand() % 26;
            password[i] = caps_alpha[j];
            break;
        case 2:
            j = rand() % 10;
            password[i] = num[j];
            break;
        case 3:
            j = rand() % 24;
            password[i] = special_char[j];
            break;
        }
    }
    for (int i = 4; i < password_len; i++)
    {
        int selection = rand() % 4, j;
        switch (selection)
        {
        case 0:
            j = rand() % 26;
            password[i] = small_alpha[j];
            break;
        case 1:
            j = rand() % 26;
            password[i] = caps_alpha[j];
            break;
        case 2:
            j = rand() % 10;
            password[i] = num[j];
            break;
        case 3:
            j = rand() % 28;
            password[i] = special_char[j];
            break;
        }
    }
    shuffle(password, password_len);
    printf("Generated Password is: %s\n", password);
}

void password_classification(void)
{
    int count_small_alpha = 0, count_caps_alpha = 0, count_num = 0, count_special_char = 0;
    char str[14];
    const char *small_alpha = "abcdefghijklmnopqrstuvwxyz";
    const char *caps_alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *num = "0123456789";
    const char *special_char = "!@#$^&*()_+-=[]{}|;:,.<>/?\"\\";
    printf("\nEnter a password of minimum 8 and maximum 14 characters : ");
    scanf("%s", str);
    int password_len = strlen(str), small_alpha_len = strlen(small_alpha), caps_alpha_len = strlen(caps_alpha), num_len = strlen(num), special_char_len = strlen(special_char);
    for (int i = 0; i < password_len; i++)
    {
        for (int j = 0; j < small_alpha_len; j++)
            if (str[i] == small_alpha[j])
                count_small_alpha++;
        for (int j = 0; j < caps_alpha_len; j++)
            if (str[i] == caps_alpha[j])
                count_caps_alpha++;
        for (int j = 0; j < num_len; j++)
            if (str[i] == num[j])
                count_num++;
        for (int j = 0; j < special_char_len; j++)
            if (str[i] == special_char[j])
                count_special_char++;
    }
    printf("%s", str);
    if (count_small_alpha >= 1 && count_caps_alpha >= 1 && count_num >= 1 && count_special_char >= 1)
        printf(" is strong password\n");
    else if ((count_small_alpha < 1 && count_caps_alpha >= 1 && count_num >= 1 && count_special_char >= 1) || (count_small_alpha >= 1 && count_caps_alpha < 1 && count_num >= 1 && count_special_char >= 1) || (count_small_alpha >= 1 && count_caps_alpha >= 1 && count_num < 1 && count_special_char >= 1) || (count_small_alpha >= 1 && count_caps_alpha >= 1 && count_num >= 1 && count_special_char < 1))
        printf(" is partially strong password\n");
    else if ((count_small_alpha < 1 && count_caps_alpha < 1 && count_num >= 1 && count_special_char >= 1) || (count_small_alpha < 1 && count_caps_alpha >= 1 && count_num < 1 && count_special_char >= 1) || (count_small_alpha < 1 && count_caps_alpha >= 1 && count_num >= 1 && count_special_char < 1) || (count_small_alpha >= 1 && count_caps_alpha < 1 && count_num < 1 && count_special_char >= 1) || (count_small_alpha >= 1 && count_caps_alpha < 1 && count_num >= 1 && count_special_char < 1) || (count_small_alpha >= 1 && count_caps_alpha >= 1 && count_num < 1 && count_special_char < 1))
        printf(" is partially weak password\n");
    else
        printf(" is weak");
}

//Encryption Functions
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

void vigenere (void)
{
    char *word = (char *)malloc(256*sizeof(char));
    char *keyword = (char *)malloc(256*sizeof(char));

    int key, length, j;

    printf("keyword: \n");
    scanf("%s", keyword);
    klen = strlen(keyword);
    for (int i = 0; i < klen; i++)
    {
        if (isalpha(*(keyword + i)) == 0)
        {
            printf("Keyword must consist of letters only. Please try again\n");
            return;
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

int message (int a)
{
    printf("Available options: \n");
    printf("1. Password Generation\n");
    printf("2. Password Classification\n");
    printf("3. Encryption\n");
    printf("4. Decryption\n");
    printf("5. Exit\n");
    printf("Enter your choice: \n");
    scanf(" %d", &a);
    return a;
}

void decryption (void)
{
    char *word = (char *)malloc(256*sizeof(char));
    char *keyword = (char *)malloc(256*sizeof(char));

    int key, length, j;

    printf("keyword: \n");
    scanf("%s", keyword);
    klen = strlen(keyword);
    for (int i = 0; i < klen; i++)
    {
        if (isalpha(*(keyword + i)) == 0)
        {
            printf("Keyword must consist of letters only. Please try again\n");
            return;
        }
    }
    printf("ciphertext: \n");
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
            if (key > word[i] - 'a')
            {
                int tkey = key;
                int gap = *(word + i) + 1 - 'a';
                *(word + i) = 'z';
                tkey = tkey - gap;
                *(word + i) -= tkey;
                j = check(j);
            }
            else
            {
                *(word + i) -= key;
                j = check(j);
            }
        }
        else if (*(word + i) <= 'Z' && *(word + i) >= 'A')
        {
            if (key > word[i] - 'A')
            {
                int tkey = key;
                int gap = *(word + i) + 1 - 'A';
                *(word + i) = 'Z';
                tkey = tkey - gap;
                *(word + i) -= tkey;
                j = check(j);
            }
            else
            {
                *(word + i) -= key;
                j = check(j);
            }
        }
    }
    printf("plaintext: %s\n", word);
    free(word);
    free(keyword);
}