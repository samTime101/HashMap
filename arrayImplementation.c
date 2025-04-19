
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

char* keys[TABLE_SIZE];
char* values[TABLE_SIZE];

unsigned int hash(const char* key) {
    unsigned int hash = 0;
    for (int i = 0; key[i]; i++) {
        hash += key[i]; 
    }
    //simple hasing , returning only modulu
    return hash % TABLE_SIZE;
}

void insert(const char* key, const char* value) {
    unsigned int index = hash(key); //hash index find garne
    //if tyo index NULL xaina vane
    while (keys[index] != NULL) {
        //yedi tyo index ma exact key xa vane , update the value
        if (strcmp(keys[index], key) == 0) {
            values[index] = (char*)value;
            return;
        }
        //if tyo index ma exact key xaina vane , go 1 key forward 
        index = (index + 1) % TABLE_SIZE;
    }
    //if index NULL xa vane store key value;
    keys[index] = (char*)key;
    values[index] = (char*)value;
}

char* get(const char* key) {
    unsigned int index = hash(key);//index pauxa
    
    while (keys[index] != NULL) {
        if (strcmp(keys[index], key) == 0) {
            return values[index];
        }
        index = (index + 1) % TABLE_SIZE;
    }

    return NULL;
}

void printMap() {
    printf("\nHashMap Contents:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (keys[i] != NULL) {
            printf("[%d] %s => %s\n", i, keys[i], values[i]);
        } else {
            printf("[%d] (empty)\n", i);
        }
    }
}

int main() {
    insert("name", "Samip");
    insert("age", "18");
    insert("place", "Nepal");
    insert("name", "Samip Regmi"); 

    printf("Name: %s\n", get("name"));
    printf("Age: %s\n", get("age"));
    printf("Place: %s\n", get("place"));
    printf("Unknown: %s\n", get("unknown")); 

    printMap();

    return 0;
}
