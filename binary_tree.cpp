// Created by Crystin Rodrick on 1/30/17.
#include<stdlib.h>
#include<stdio.h>

struct bin_tree {
    int word;
    struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node ** tree, int val) {
    node *temp = NULL;
    if(!(*tree)) {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->word = val;
        *tree = temp;
        return;
    }
    if(val < (*tree)->word) {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->word) {
        insert(&(*tree)->right, val);
    }
}



void print_inorder(node * tree) {
    if (tree) {
        print_inorder(tree->left);
        printf("%d\n",tree->word);
        print_inorder(tree->right);
    }
}




node* search(node ** tree, int val) {
    if(!(*tree)) {
        return NULL;
    }
    if(val < (*tree)->word) {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->word) {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->word) {
        return *tree;
    }
}

void main() {
    node *root;
    node *tmp;
    //int i;
    root = NULL;
    /* Inserting nodes into tree */
    insert(&root, ge);
    insert(&root, we);
    insert(&root, are);
    insert(&root, team);
    insert(&root, violet);
    insert(&root, boo);
    insert(&root, yea);

    /* Printing nodes of tree */
    print_inorder(root);


    /* Search node into tree */
    tmp = search(&root, hey);
    if (tmp) {
        printf("Searched node=%d\n", tmp->word);
    }
    else {
        printf("word Not found in tree.\n");
    }

}
