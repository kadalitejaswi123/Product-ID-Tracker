#include "myHashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include<stdbool.h>

/* creates a hash table that can hold max_capacity elements */
HashTable* create_table(int max_capacity){
    HashTable *htable = (HashTable *)malloc(sizeof(HashTable));
    htable->size = max_capacity;
    htable->count = 0;
    htable->table = (Node **)malloc(max_capacity * sizeof(Node *));
    
    for (int i = 0; i < max_capacity; i++) {
        htable->table[i] = NULL;
    }
    
    return htable;
}

/* Hash function to determine index */
int hash(int key, int size){
    return key % size;
}

/* Insert a key into the Hashtable. Return TRUE if element not already present,
else FALSE */
bool insert_key(HashTable *htable, int key){

    int index = hash(key, htable->size);
    Node *current = htable->table[index];
    
    while (current != NULL) {
        if (current->key == key) {
            return false;  
        }
        current = current->next;
    }
    
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->key = key;
    new_node->next = htable->table[index];
    htable->table[index] = new_node;
    htable->count++;
    return true;
}

/* Deletes a key from the HashTable, given a pointer to it */
bool delete_key(HashTable *htable, int key){

    int index = hash(key, htable->size);
    Node *current = htable->table[index];
    Node *prev = NULL;
    
    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                htable->table[index] = current->next;  
            } else {
                prev->next = current->next;  
            }
            free(current);
            htable->count--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;  
}

/* Returns a boolean value if the table contains the key, if it exists, 0 otherwise
*/
bool search(HashTable *htable, int key){

    int index = hash(key, htable->size);
    Node *current = htable->table[index];
    
    while (current != NULL) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

/* Clear the Hash Table and release any memory allocated to it*/
void clear_table(HashTable *htable){

    for (int i = 0; i < htable->size; i++) {
        Node *current = htable->table[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
        htable->table[i] = NULL;
    }
    htable->count = 0;
    free(htable->table);
    free(htable);
}