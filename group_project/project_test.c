#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project_functions.h"

int main(void)
{
    char c, *ref, *password = (char *)malloc(13 * sizeof(char)), *entered_password = (char *)malloc(13 * sizeof(char)),
                  *word = (char *)malloc(45 * sizeof(char)), keyword[256] = {'\0'};
    while (1)
    {
        printf("\nEnter the keyword. It should only consist of alphabets : ");
        scanf("%s", keyword);
        int klen = strlen(keyword), count = 0;
        for (int i = 0; i < klen; i++)
        {
            if (isalpha(*(keyword + i)))
                count++;
            else
            {
                printf("Keyword must consist of letters only. Please try again\n");
                keyword[256] = '\0';
                break;
            }
        }
        if (count == klen)
        {
            int choice = 0;
            printf("\nTo proceed with this keyword press 0. To re-enter the keyword press 1 : ");
            scanf("%d", &choice);
            if (!choice)
                break;
            else
            {
                keyword[256] = '\0';
                continue;
            }
        }
    }
    int entered_password_length, count = 0, breaking_point = 0, i = 0;
    FILE *file_to_be_read = fopen("file_to_be_read.txt", "r"),
         *encrypted_form_of_file = fopen("encrypted_form.txt", "w"), *file_to_be_shown = fopen("file_to_be_shown.txt", "w");
    if (file_to_be_read)
    {
        while ((c = fgetc(file_to_be_read)) + 1) //The ASCII value of EOF is -1
        {
            if (c == ' ' || c == '\n')
            {
                word = vigenere(word, keyword);
                int ref = 0;
                *(word + i) = 0;
                while (*(word + ref))
                {
                    fputc(*(word + ref), encrypted_form_of_file);
                    ref++;
                }
                fputc(c, encrypted_form_of_file);
                i = -1;
                free(word);
                word = (char *)malloc(45 * sizeof(char));
            }
            else
                *(word + i) = c;
            i++;
        }
    }
    else
        printf("\nThe file is empty.");
    free(ref);
    fclose(file_to_be_read);
    fclose(encrypted_form_of_file);
    printf("\n\nThe encrypted form of your file is : \n\n");
    file_to_be_read = fopen("encrypted_form.txt", "r");
    while ((c = fgetc(file_to_be_read)) + 1)
        printf("%c", c);
    int choice;
    printf("\n\nPress 0 to generate password or press 1 to classify your password : ");
    scanf("%d", &choice);
    if (choice)
    {
        int choice_password = 1;
        while (choice_password)
        {
            printf("\nEnter your length of your password. The length should be minimum 8 and maximum 12 : ");
            int length;
            scanf("%d", &length);
            entered_password_length = length;
            if (length >= 8 && length <= 12)
            {
                printf("\nEnter your password : ");
                fflush(stdin);
                fgets(password, length + 1, stdin);
                choice_password = password_classification(password, entered_password_length);
            }
            else
            {
                printf("\nInvalid input. Try again.");
            }
        }
    }
    else
    {
        int choice_password = 1;
        while (choice_password)
        {
            int length = password_generation(password);
            entered_password_length = length;
            printf("\nThe generated password is : ");
            for (int i = 0; i < length; i++)
                printf("%c", *(password + i));
            printf("\nTo proceed with this password press 0 and to re-enter password press 1 : ");
            scanf("%d", &choice_password);
        }
    }
    fclose(encrypted_form_of_file);
    fclose(file_to_be_read);
    file_to_be_read = fopen("encrypted_form.txt", "r");
    while (breaking_point < 4)
    {
        count = 0;
        printf("\nTo decrypt the file enter the password : ");
        fflush(stdin);
        fgets(entered_password, entered_password_length + 1, stdin);
        for (int i = 0; i < entered_password_length; i++)
            if (*(password + i) == *(entered_password + i))
                count++;
        if (count == entered_password_length)
        {
            printf("\nThe decrypted form of your file is : \n\n");
            while ((c = (char)fgetc(file_to_be_read)) + 1)
            {
                if (c == ' ' || c == '\n')
                {
                    word = decryption(word, keyword);
                    int ref = 0;
                    *(word + i) = 0;
                    while (*(word + ref))
                    {
                        fputc(*(word + ref), file_to_be_shown);
                        ref++;
                    }
                    fputc(c, file_to_be_shown);
                    i = -1;
                    free(word);
                    word = (char *)malloc(45 * sizeof(char));
                }
                else
                    *(word + i) = c;
                i++;
            }
            fclose(file_to_be_shown);
            file_to_be_shown = fopen("file_to_be_shown.txt ", "r");
            while ((c = fgetc(file_to_be_shown)) != EOF)
                printf("%c", c);
            break;
        }
        else
        {
            printf("\nWrong password. Try again.");
            breaking_point++;
        }
    }
    if (breaking_point == 3)
        printf("\nYou entered wrong password three times. You have been blocked !!!");
    fclose(encrypted_form_of_file);
    fclose(file_to_be_read);
    fclose(file_to_be_shown);
    free(password);
    free(entered_password);
    printf("\n");
    return 0;
}
