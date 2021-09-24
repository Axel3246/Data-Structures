
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
// ? Complejidad: O(1)
void LinkedList<T>::addFirst(T data)
{
    // * Se crea un nuevo nodo, tomando en cuenta que
    // * head es de tipo nodo
    head = new Node<T>(data, head);
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
        while (curr->getNext() != nullptr)
        {
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data));
        size++;
    }
}

template <class T>
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
        size--;                 // * Reduce el contador del tamaño del linked list
    }
}

template <class T>
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

template <class T>
// ? Complejidad: O(n)
T LinkedList<T>::get(int pos)
{
    Node<T> *curr = head;

    for (int i = 1; i <= pos; i++)
    {
        curr = curr->getNext();
    }
    return curr->getData();
}

template <class T>
// ? Complejidad: O(n)
T LinkedList<T>::set(T data, int pos)
{

    Node<T> *curr = head;
    for (int i = 1; i <= pos; i++)
    {
        curr = curr->getNext();
    }
    T dataAux = curr->getData();
    curr->setData(data);
    return dataAux;
}

template <class T>
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