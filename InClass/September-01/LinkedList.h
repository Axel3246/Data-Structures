
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
    void deleteFirst();
    void deleteLast();
    bool isEmpty();
    int getSize();

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
// ? Complejidad: O(1)
void LinkedList<T>::addFirst()
{
    // * Se crea un nuevo nodo, tomando en cuenta que
    // * head es de tipo nodo
    head = new Node(data, head);
    size++;
}

template <class T>
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
        while (curr->getNext != nullptr)
        {
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data));
        size++;
    }
}

template <class T>
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
        size--; // * Reduce el contador del tamaño del linked list
    }
}

template <class T>
// ? Complejidad: O(1)
bool LinkedList<T>::isEmpty()
{
    return (size == 0); // ? return (head == nullptr);
}

template <class T>
// ? Complejidad: O(1)
int LinkedList<T>::getSize()
{
    return size;
}