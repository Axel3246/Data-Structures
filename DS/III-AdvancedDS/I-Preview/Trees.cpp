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

// *Creacion de nodo para arbol binario

Node *createNode(int n)
{
    Node *new_node = new Node();

    new_node->data = n;
    new_node->der = NULL;
    new_node->izq = NULL;

    return new_node;
}

// *Funcion para insertar un nodo al arbol
// *El arbol puede estar vacio o con nodos

void insert(Node *&arbol, int n)
{

    if (arbol == NULL)
    {
        Node *new_node = createNode(n);
        arbol = new_node;
    }
    else
    {
        int nodeVal = arbol->data; //!Obtenemos el valor de la raiz del arbol
        if (n < nodeVal)
        {
            insert(arbol->izq, n); // !Si n es menor a la raiz lo acomodamos a la izquierda
        }
        else
        {
            insert(arbol->der, n); // !Si n es mayor a la raiz lo acomodamos a la derecha
        }
    }
    
}

// *Funcion para mostrar un arbol binario

