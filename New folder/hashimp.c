#include "hash.h"

int hash(HashTable *htable, int num)
{
    return (num % htable->size);
}

HashTable *create_table(int size)
{
    //TODO
    HashTable *newHashTable = (HashTable *)malloc(sizeof(HashTable));
    newHashTable->size = size;
    newHashTable->table = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        newHashTable->table[i] = -1;
    }

    return newHashTable;
}

void insert(HashTable *htable, int element)
{
    //TODO
    int key = hash(htable, element);

    if (htable->table[key] != -1) // if index is filled
    {
        int keycopy = key;
        do
        {
            key = (key + 1) % htable->size;
            if (key == keycopy)
                return;
        } while (htable->table[key] != -1);
    }
    htable->table[key] = element;
}

int search(HashTable *htable, int element)
{
    //TODO

    int key = hash(htable, element);
    if (htable->table[key] == element)
        return 1;
    else
    {
        int keycopy = key;
        keycopy += 1;
        while (keycopy != key)
        {
            if (htable->table[keycopy] == element)
                return 1;
            keycopy = (keycopy + 1) % htable->size;
        }
        return 0;
    }
}

void delete (HashTable *htable, int element)
{
    //TODO
    for (int i = 0; i < htable->size; i++)
    {
        if (htable->table[i] == element)
        {
            htable->table[i] = -1;
            return;
        }
    }
}

void destroy_table(HashTable *htable)
{
    //TODO
    free(htable->table);
    free(htable);
}
