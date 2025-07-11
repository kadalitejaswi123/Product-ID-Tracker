#include "myBST.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
TreeNode* create_node(int key){
    TreeNode* new_node=(TreeNode*)malloc(sizeof(TreeNode));
                    new_node->key = key;
                    new_node->left = NULL;
                    new_node->right = NULL;
                    new_node->parent = NULL;
                    }

void insert(TreeNode* root, TreeNode* node) {
    if (root == NULL) {
        root = node;  // This won't update the caller's root.
        return;
    }

    TreeNode* y = NULL;
    TreeNode* x = root;

    while (x != NULL) {
        y = x;
        if (node->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    node->parent = y;

    if (node->key < y->key) {
        y->left = node;
    } else {
        y->right = node;
    }
}


/*Transplant function */
TreeNode* Transplant(TreeNode *root,TreeNode *u, TreeNode *v){
    
 if(u->parent == NULL){
    root = v;
 }
 else if( u == u->parent->left){
    u->parent->left = v;
 }
 else{
    u->parent->right = v;
 }
 if( v != NULL){
   v->parent = u->parent;
 }
 return root;
}

/*Tree-Minimum function*/
TreeNode* Tree_Min(TreeNode *root){
while(root->left != NULL){
    root = root->left;
}
return root;
}

/*Tree-Maximum function*/
TreeNode* Tree_Max(TreeNode *root){
while(root->right != NULL){
    root = root->right;
}
return root;
}

/* Delete the node pointed to by node, return a pointer to the (possibly new) root
node of the tree */
/*TreeNode* delete_node(TreeNode *root, TreeNode *node){
    
    TreeNode *y;

    if(node->left==NULL && node->right==NULL){

         if(node->key < node->parent->key){
            node->parent->right = NULL;
         }
         else{
            node->parent->left = NULL;
         }
        free(node);
    }
    else if(node->left==NULL || node->right==NULL){

        if(node->left==NULL){
          Transplant(root,node,node->right);
        }
        else if(node->right==NULL){
          Transplant(root,node,node->left);
        }
    }
    else{
      y = Tree_Min(node->right);
      if(y->parent != node){
        Transplant(root,y,y->right);
        y->right = node->right;
        y->right->parent = y;
        Transplant(root,node,y);
        y->left = node->left;
        y->left->parent = y;
      }
    }
    return root;
}*/
TreeNode* delete_node(TreeNode *root, TreeNode *node) {
    TreeNode *y;

    if (node->left == NULL && node->right == NULL) {
        if (node->parent == NULL) {
            // The node to delete is the root and has no children
            free(node);
            return NULL;  // New root will be NULL
        }

        if (node->key < node->parent->key) {
            node->parent->left = NULL;
        } else {
            node->parent->right = NULL;
        }
        free(node);
    } else if (node->left == NULL || node->right == NULL) {
        TreeNode* child = (node->left != NULL) ? node->left : node->right;
        root = Transplant(root, node, child);
        free(node);
    } else {
        y = Tree_Min(node->right);
        if (y->parent != node) {
            Transplant(root, y, y->right);
            y->right = node->right;
            y->right->parent = y;
        }
        root = Transplant(root, node, y);
        y->left = node->left;
        y->left->parent = y;
        free(node);
    }
    return root;
}

/* Return a pointer to the successor of a given node in the tree */
TreeNode* find_successor(TreeNode *root, TreeNode *node){

if(node->right != NULL){
    return Tree_Min(node->right);
}
else{
    TreeNode *y;
    y = node->parent;
    while( y != NULL && node == y->right){
        node = y;
        y = y->parent;
    }
    return y;
}
}
/* Return a pointer to the predecessor of a given node in the tree */
TreeNode* find_predecessor(TreeNode *root, TreeNode *node){

if(node->left != NULL){
    return Tree_Max(node->left);
}
else{
   TreeNode *y;
   y = node->parent; 
   while( y != NULL && node == y->left){
       node = y;
       y = y->parent;
   }
   return y;
}
}
/* Return a pointer to the Node containing key in the subtree rooted at *root */
TreeNode* find_key(TreeNode *root, int key){
    if( root == NULL || root->key == key){
        return root;
    }
    else if( key < root->key){
       return find_key(root->left,key);
    }
    else{
       return find_key(root->right,key);
    }
}