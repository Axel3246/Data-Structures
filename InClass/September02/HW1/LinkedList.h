
#include "Node.h"

template <class T>
class LinkedList
{
    // * Atributos publicos
public:
    LinkedList();
    ~LinkedList();
    void addFirst(T data);
    void addLast(T data);
    bool add(T data, int pos);
    void deleteFirst();
    void deleteLast();
    void del(int pos);
    int deleteAll();
    bool isEmpty();
    int getSize();
    T get(int pos);
    T set(T data, int pos);
    void reverse();
    void shift(int n);
    bool operator==(LinkedList<T> *list);
    void print();

    // * Atributos privados
private:
    Node<T> *head;
    int size;
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    // ! TBD
}

template <class T>
// * Método que agrega un nodo al inicio de la lista
// ? Complejidad: O(1)
void LinkedList<T>::addFirst(T data)
{
    // * Se crea un nuevo nodo, tomando en cuenta que
    // * head es de tipo nodo
    head = new Node<T>(data, head);
    size++;
}

template <class T>
// * Método que agrega un nodo al final de la lista
// ? Complejidad: O(n)
void LinkedList<T>::addLast(T data)
{
    // * Si no hay nada, llama a addFirtst
    if (size == 0)
    {
        addFirst(data);
    }
    else
    {
        Node<T> *curr = head;
        while (curr->getNext() != nullptr)
        {
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data));
        size++;
    }
}

template <class T>
// * Método que agrega un nodo dada una posicion de la lista
// ? Complejidad: O(n)
bool LinkedList<T>::add(T data, int pos)
{

    if (pos > size)
    {
        return false;
    }
    if (pos == 0)
    {
        addFirst(data);
    }
    else if (pos == size)
    {
        addLast(data);
    }
    else
    {
        Node<T> *curr = head;
        for (int i = 1; i < pos; i++) // * Garantizar que entre pos - 1 veces
        {
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data, curr->getNext()));
        size++;
    }
    return true;
}

template <class T>
// * Método que elimina el primer nodo de la lista
// ? Complejidad: O(1)
void LinkedList<T>::deleteFirst()
{
    // * Si hay algo lo elimina, y si no, no hace nada
    if (size != 0)
    {
        Node<T> *curr = head;
        head = head->getNext();
        delete curr;
        size--;
    }
}

template <class T>
// * Método que elimina el ultimo nodo de la lista
// ? Complejidad: O(n)
void LinkedList<T>::deleteLast()
{
    // * Sio solo hay un elemento llama a deleteFirst
    if (size <= 1)
    {
        deleteFirst();
    }
    else
    {
        // * Nodo "auxiliar"
        Node<T> *curr = head;
        while (curr->getNext()->getNext() != nullptr) // * Estara viendo a que apunta dos posiciones de enfrente
        {
            curr = curr->getNext();
        }
        delete curr->getNext(); // * Elimina la lista siguiente
        curr->setNext(nullptr); // * Establece NULL a la lista actual
        size--;                 // * Reduce el contador del tamaño del linked list
    }
}

template <class T>
// * Método que elimina un nodo dada una posicion de la lista
// ? Complejidad: O(n)
void LinkedList<T>::del(int pos)
{

    if (pos == 0)
    {
        deleteFirst();
    }
    else if (pos == size - 1)
    {
        deleteLast();
    }
    else
    {
        Node<T> *curr = head;
        for (int i = 1; i < pos; i++)
        {

            curr = curr->getNext();
        }
        Node<T> *aux = curr->getNext();
        curr->setNext(aux->getNext()); // curr->setNext(curr->getNext->getNext())
        delete aux;
        size--;
    }
}

template <class T>
// * Método que elimina todos los nodos de la lista
// ? Complejidad: O(n)
int LinkedList<T>::deleteAll()
{
    Node<T> *curr = head;
    while (head != nullptr)
    {
        head = head->getNext();
        delete curr;
        curr = head;
    }
    int cant = size;
    size = 0;
    return cant;
}

template <class T>
// * Método que regresa verifica si la lista esta vacía
// ? Complejidad: O(1)
bool LinkedList<T>::isEmpty()
{
    return (size == 0); // ? return (head == nullptr);
}

template <class T>
// * Método que regresa el tamaño de la lista
// ? Complejidad: O(1)
int LinkedList<T>::getSize()
{
    return size;
}

template <class T>
// * Método que obtiene el dato contenido en el nodo de la posición dada
// ? Complejidad: O(n)
T LinkedList<T>::get(int pos)
{
    Node<T> *curr = head;

    // * Se recorren pos - 1 veces
    for (int i = 1; i <= pos; i++)
    {
        curr = curr->getNext();
    }
    return curr->getData(); // * se regresa el datol
}

template <class T>
// * Metodo que cambia el dato contenido en el nodo de la posicion dada y
// * regresa el valor del dato anterior
// ? Complejidad: O(n)
T LinkedList<T>::set(T data, int pos)
{

    Node<T> *curr = head;
    // * Se recorren pos - 1 posiciones (i empieza en 1)
    for (int i = 1; i <= pos; i++)
    {
        curr = curr->getNext();
    }
    T dataAux = curr->getData(); // *obtenemos el dato que se desea cambiar
    curr->setData(data);         // * se cambia
    return dataAux;              // * se regresa el dato anterior
}

template <class T>
// * Método que regresa la lista de forma inversa
// ? Complejidad: O(n)
void LinkedList<T>::reverse()
{
    if (size != 0)
    {
        // * curr apuntara a head como comienzo
        // * siguiente sera el sustituto de head->getNext()
        // * aux sera el que ayudara a reversear los nodos
        Node<T> *curr = head, *siguiente = nullptr, *aux = nullptr;
        while (curr != nullptr)
        {
            // * Siguiente de head (curr)
            siguiente = curr->getNext();
            // * Se establece que el nodo de head ahora apunta a null
            // * (y ahora cada nodo apuntara a su anterior)
            curr->setNext(aux);
            // * movemos una posicion a aux
            aux = curr;
            // * movemos una posicion a curr
            curr = siguiente;
        }
        // * al estar linkeado al reves, se iguala head a aux
        head = aux;
    }
}


template <class T>
// * Método intercambia nodos n posiciones
// ? Complejidad: O(n)
void LinkedList<T>::shift(int n)
{
    if (size != 0)
    {
        Node<T> *curr = head, *siguiente = nullptr, *aux = head;

        // * Enlazamos la lista en una (sin null)
        while (aux != nullptr)
        {
            curr->getNext();
        }
        curr->setNext(head);

        for(int i = 0; i < (size-n); i++){
            aux = aux->getNext();
        }
        head = curr->getNext();
        
    }
}


template <class T>
// * Método que verifica si dos listas son iguales
// ? Complejidad: O(n)
bool LinkedList<T>::operator==(LinkedList<T> *list){
    Node<T> *curr1 = head;

}




template <class T>
// * Método que imprime la lista
// ? Complejidad: O(1)
void LinkedList<T>::print()
{

    Node<T> *curr = head;
    while (curr != nullptr)
    {
        cout << curr->getData() << endl;
        curr = curr->getNext();
    }
}