
#include <iostream>
#include <string.h>

using namespace std;

//* Para eliminar un Nodo,  es recomendable que cada nodo recuerde quien es su padre, para esto, debemos modificar el programa

// *Node Structure for a Binary Tree

struct Node
{
    int data;
    Node *der;
    Node *izq;
    Node *padre; //! Esta linea nos guardara el nodo padre de cada nodo
};

//*Prototipos

void menu();
Node *createNode(int n, Node *padre);          //! A esta funcion le pasaremos ahora, como extra, el nodo padre
void insert(Node *&arbol, int n, Node *padre); //!A esta funcion tambien se debe de pasarle el nodo padre
void showTree(Node *arbol, int contador);
bool searchNode(Node *arbol, int n);
void preOrden(Node *arbol);
void eliminate(Node *arbol, int n); // !funcion para recorrer el arbol y encontrar el nodo
void eliminateNode(Node *eliminar); // !Funcion para eliminar el nodo
Node *arbol = NULL; //! Variabe

int main()
{
    menu();
}

void menu()
{
    int opcion, dato, contador = 0;
    do
    {
        cout << endl;
        cout << "\t.:Menu:." << endl;
        cout << "1. Agregar Nodo" << endl;
        cout << "2. Mostrar Arbol" << endl;
        cout << "3. Buscar Elemento" << endl;
        cout << "4. Recorrer en PreOrden" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion -> ";
        cin >> opcion;

        switch (opcion)
        {

        case 1:

            int dato;
            cout << "Numero: ";
            cin >> dato;
            insert(arbol, dato, NULL); // ?Como no sabemos quien es el padre, simplemente ponemos NULL
            break;

        case 2:
            cout << endl;
            showTree(arbol, contador);
            break;

        case 3:

            cout << "Elemento a buscar: ";
            cin >> dato;
            if (searchNode(arbol, dato) == true)
            {
                cout << "El elemento " << dato << " ha sido encontrado." << endl;
            }
            else
            {
                cout << "El elemento " << dato << " no ha sido encontrado." << endl;
            }
            break;

        case 4:

            cout << endl;
            preOrden(arbol);
            break;
        }

    } while (opcion != 5);
}

Node *createNode(int n, Node *padre) //! Asi quedaria la funcion para crear un nuevo nodo
{
    Node *new_node = new Node();

    new_node->data = n;
    new_node->der = NULL;
    new_node->izq = NULL;
    new_node->padre = padre; //!Le asignamos el padre al nuevo nodo creado

    return new_node;
}

// !Funcion para insertar un nodo al arbol
// ! El arbol puede estar vacio o con nodos

void insert(Node *&arbol, int n, Node *padre)
{

    if (arbol == NULL)
    {
        Node *new_node = createNode(n, padre); //! Indicamos quien es el padre del nuevo nodo creado
        arbol = new_node;
    }
    else
    {
        int nodeVal = arbol->data; //!Obtenemos el valor de la raiz del arbol
        if (n < nodeVal)
        {
            insert(arbol->izq, n, padre); // !Si n es menor a la raiz lo acomodamos a la izquierda, indicamos quien es el padre
        }
        else
        {
            insert(arbol->der, n, padre); // !Si n es mayor a la raiz lo acomodamos a la derecha, indicamos quien es el padre
        }
    }
}

// !Funcion para mostrar el arbol

void showTree(Node *arbol, int contador)
{

    //!Si el arbol esta vacio

    if (arbol == NULL)
    {
        return;
    }
    else
    {
        showTree(arbol->der, contador + 1); //*Se empieza con el lado derecho del arbol
        for (int i = 0; i < contador; i++)  //*Separacion de caracteres
            cout << "   ";
    }
    cout << arbol->data << endl;        // *Impresion del dato del nodo
    showTree(arbol->izq, contador + 1); //*Ahora es el turno de imprimir el lado izquierdo del arbol
}

// !Funcion para buscar un nodo en el arbol

bool searchNode(Node *arbol, int n)
{

    //!Si el arbol esta vacio (Caso 1)
    if (arbol == NULL)
    {
        return false; // *El elemento no ha sido encontrado
    }
    else if (arbol->data == n)
    { //*Si encontramos el elemento (en la raiz)
        return true;
    }
    else if (n < arbol->data)
    {
        return searchNode(arbol->izq, n); //*Dependiendo del numero a buscar, nos inclinaremos hacia ese lado del arbol
    }
    else
    {
        return searchNode(arbol->der, n); //*Dependiendo del numero a buscar, nos inclinaremos hacia ese lado del arbol
    }
}

//! Funcion para recorrido pre orden (por direccion y subraices)

void preOrden(Node *arbol)
{

    //*Se debe conoer si el arbol esta vacio, para eso sirve este primer condicional
    if (arbol == NULL)
    {
        return;
    }
    else
    { //*Este else indica que el arbol no esta vacio
        cout << arbol->data;
        preOrden(arbol->izq); //?RECORRE EL LADO IZQUIERDO
        preOrden(arbol->der); //?RECORRE EL LADO DERECHO
    }
}

//! Funcion para iterar el arbol y encontrar un nodo para eliminar

/* --PARTE 1-- */

void eliminate(Node *arbol, int n)
{
    if(arbol == NULL){ //*Si el arbol esta vacio no tengo nada que eliminar, entonces solo retorno
        return;
    }
    else if(n < arbol ->data){ // *Si el valor es menor, buscar por la izquierda
        eliminate(arbol->izq,n);
    }
    else if(n > arbol ->data){ // *Si el valor es mayor, buscar por la derecha
        eliminate(arbol->der,n);
    }
    else{ //* Si se encuentra el valor se llama a la funcion
        eliminateNode(arbol);
    }
}

//! Funcion para eliminar un nodo

/* --PARTE 2-- */


