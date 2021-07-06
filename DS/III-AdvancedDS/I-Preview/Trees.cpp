//!Concepto de Arbol Binario

#include <iostream>
#include <string.h>


// *Node Structure for a Binary Tree

struct Node 
{
    int data;   // !Un dato
    Node *der; // !Un apuntador al hijo der (si hay)
    Node *izq; // !Un apuntador al hijo izq (si hay)
};
