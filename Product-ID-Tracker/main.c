#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myHashTable.h"
#include "myBST.h"

#define K 5

// Checks if an ID was produced (exists in hash table)
bool wasProducedHere(int id, HashTable* hash_table) {
    if (search(hash_table, id)) {
        printf("Y\n");
        return true;
    } else {
        printf("N\n");
        return false;
    }
}

// Finds up to K predecessors and K successors of a given ID in BST
void findNeighbors(int id, TreeNode* bst_root) {
    TreeNode* node = find_key(bst_root, id);
    if (node == NULL) {
        return;  // No neighbors to find if node doesn't exist
    }

    int neighbors[2 * K];
    int neighbor_count = 0;

    // Find K predecessors
    TreeNode* predecessor = node;
    for (int i = 0; i < K; i++) {
        predecessor = find_predecessor(bst_root, predecessor);
        if (predecessor != NULL) {
            neighbors[neighbor_count++] = predecessor->key;
        } else {
            break;  // Stop if no more predecessors are found
        }
    }

    // Find K successors
    TreeNode* successor = node;
    for (int i = 0; i < K; i++) {
        successor = find_successor(bst_root, successor);
        if (successor != NULL) {
            neighbors[neighbor_count++] = successor->key;
        } else {
            break;  // Stop if no more successors are found
        }
    }

    // Print the neighbors if any were found
    if (neighbor_count > 0) {
        for (int i = 0; i < neighbor_count; i++) {
            printf("%d", neighbors[i]);
            if (i < neighbor_count - 1) {
                printf(",");
            }
        }
        printf("\n");
    }
}

int main() {
    int id;
    char operation;
    int max_capacity = 10000;
    HashTable* hash_table = create_table(max_capacity);
    TreeNode* bst_root = NULL;

    // Read operations from input
    while (scanf("%d,%c", &id, &operation) != EOF) {
        switch (operation) {
            case 'I': {
                if (insert_key(hash_table, id)) {
                    TreeNode* new_node=create_node(id);
                    if(bst_root ==  NULL){
                        bst_root= new_node;
                    }
                    else{
                    
                    insert(bst_root, new_node);
                    }  // Update bst_root

                }
                break;
            }

            case 'D': {
                if (delete_key(hash_table, id)) {
                    TreeNode* node_to_delete = find_key(bst_root, id);
                    if (node_to_delete != NULL) {
                        bst_root = delete_node(bst_root, node_to_delete);  // Update bst_root
                    }
                }
                break;
            }

            case 'C': {
                if(wasProducedHere(id, hash_table)) {  // Check existence in hash_table
                    findNeighbors(id, bst_root);  // Call findNeighbors if ID exists
                }
                break;
                
            }
        }
    }

    return 0;
    //clean up
    clear_table(hash_table);
}
