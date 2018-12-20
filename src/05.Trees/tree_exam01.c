#include "tree.h"
#include<stdio.h>
#include<stdlib.h>

enum {
    A,
    B, 
    C,
    D, 
    E,
    F, 
    G, 
    H, 
    I   
} names;

const char* node_names[]=
    {"A", "B", "C", "D", "E", "F", "G", "H", "I"};

tree_pointer create_node(void){
    tree_pointer temp;
    temp = (tree_pointer)malloc(sizeof(struct node));
    temp->left_child = NULL;
    temp->right_child = NULL;
    temp->data = 0;
    return temp;
}

void destroy_node(tree_pointer a){
    free(a); 
}

void inorder(tree_pointer ptr){
    if(ptr){
        inorder(ptr->left_child);
        printf("%s ", node_names[ptr->data]);
        inorder(ptr->right_child);
    }
}

void preorder(tree_pointer ptr){
    if(ptr){
        printf("%s ", node_names[ptr->data]);
        preorder(ptr->left_child);
        preorder(ptr->right_child);
    }
}

void postorder(tree_pointer ptr){
    if(ptr){
        postorder(ptr->left_child);
        postorder(ptr->right_child);
        printf("%s ", node_names[ptr->data]);
    }
}
int main()
{
    tree_pointer nodes[16]; 
    int i ; 
    for(i=0; i<16; i++){
        nodes[i] = create_node();
        nodes[i]->data = i;
    }
    nodes[A]->left_child = nodes[B];
    nodes[A]->right_child = nodes[C];
    nodes[B]->left_child = nodes[D];
    nodes[B]->right_child = nodes[E];
    nodes[D]->left_child = nodes[H];
    nodes[D]->right_child = nodes[I];
    nodes[C]->left_child = nodes[F];
    nodes[C]->right_child = nodes[G];

    inorder(nodes[A]);
    printf("\n");
    preorder(nodes[A]);
    printf("\n");
    postorder(nodes[A]);
    printf("\n");

    return 0;
}
