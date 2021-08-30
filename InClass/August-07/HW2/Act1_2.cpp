/*

Nombre: Axel Amos Hernández Cárdenas - A00829837
Fecha de Creación: 30 de Agosto del 2021
Descripción: Este programa utiliza los algoritmos de ordenamiento y de busqueda para ofrecer al usuario el
numero de comparaciones y la posicion de el dato de un arreglo al ser ordenado
*/

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &vect)
{

    for (int i = 0; i < vect.size(); i++)
    {

        cout << vect[i] << " ";
    }
    cout << endl;
}

// ! Funciones de Busqueda

// * Funcion que busca un dato por medio de la busqueda secuencial y regresa el numero de comparaciones su posicion
// ? Complejidad: Mejor caso: O(1), Peor caso: O(n)
int busquedaSecuencial(vector<int> vect, int query)
{
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i] == query)
        {

            return i;
        }
    }
    return -1;
}

// * Funcion que busca un dato por medio de la busqueda binaria y regresa el numero de comparaciones su posicion
// ? Complejidad: Mejor caso: O(1), Peor caso: O(log(n))
int binarySearch(vector<int> vect, int query, int &comp)
{
    comp = 0;

    int inicio = 0, fin = vect.size() - 1, mitad;
    while (inicio <= fin)
    {
        mitad = (inicio + fin) / 2;
        comp++;
        if (vect[mitad] == query)
        {
            return mitad;
        }
        if (vect[mitad] > query)
        { // El dato que busco es menor al central
            fin = mitad - 1;
        }
        else
        { // El dato que busco es mayor al central
            inicio = mitad + 1;
        }
    }
    return -1;
}

// ! Funciones de Ordenamiento

// * Funcion que ordena un array / vector por el metodo de intercambio y regresa las comparaciones (mas el vector ordenado)
// ? Complejidad: O(n^2)
int sortIntercambio(vector<int> &vec)
{
    int comp = 0, temp;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            comp++; // Medir las comparaciones
            if (vec[i] > vec[j])
            {
                temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
    return comp;
}

// * Funcion que ordena un array / vector por el metodo burbuja y regresa las comparaciones (mas el vector ordenado)
// ? Complejidad: Mejor caso: O(n), Peor caso: O(n^2)
int bubbleSort(vector<int> &vec)
{
    bool interruptor = true;
    int temp, comp = 0;
    for (int pasada = 0; pasada < vec.size() && interruptor; pasada++)
    {
        interruptor = false;
        for (int j = 0; j < vec.size() - 1 - pasada; j++)
        {
            comp++;
            if (vec[j + 1] < vec[j])
            {
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
                interruptor = true;
            }
        }
    }
    return comp;
}

// * Funcion que ordena un array / vector por el metodo mergeSort y regresa las comparaciones (mas el vector ordenado)
// !!!!!!!!!! Complejidad: Posiblemente O(n)
int merge(vector<int> &vec, int inicio, int mitad, int fin, int &comp)
{
    vector<int> aux(vec.size());
    int i = inicio, j = mitad + 1, k = inicio;
    while (i <= mitad && j <= fin)
    {
        comp++;
        if (vec[i] < vec[j])
        {
            aux[k++] = vec[i++];
        }
        else
        {
            aux[k++] = vec[j++];
        }
    }
    if (i > mitad)
    {
        for (int a = j; a <= fin; a++)
        {
            aux[k++] = vec[a];
        }
    }
    else
    {
        for (int a = i; a <= mitad; a++)
        {
            aux[k++] = vec[a];
        }
    }
    for (int a = inicio; a <= fin; a++)
    {
        vec[a] = aux[a];
    }
    return comp;
}

// * Funcion que ordena y divide en subarrays por recursividad para llevar a cabo mergeSort
// ? Complejidad: Mejor caso: O(nlog(n)), Peor caso: O(nlog(n))
void mergeSort(vector<int> &vec, int inicio, int fin, int &comp)
{
    if (inicio < fin)
    {
        int mitad = (inicio + fin) / 2;
        mergeSort(vec, inicio, mitad, comp);
        mergeSort(vec, mitad + 1, fin, comp);
        merge(vec, inicio, mitad, fin, comp);
    }
}

int main()
{
    int nums, n, cont, queries, query;
    cin >> nums;

    // * vect1 == Ordenar con Intercambio
    // * vect2 == Ordenar con Búrbuja
    // * vect3 == Ordenar con Merge
    vector<int> vect1, vect2, vect3;

    for (int i = 0; i < nums; i++)
    {
        cin >> n;
        vect1.push_back(n);
        vect2.push_back(n);
        vect3.push_back(n);
    }

    
    // * sortIntercambio
    int compIntercambio = sortIntercambio(vect1);
    //print(vect1);

    // * bubbleSort
    int compBurbuja = bubbleSort(vect2);
    //print(vect2);

    // * mergeSort
    int compMerge = 0;
    mergeSort(vect3, 0, nums - 1, compMerge);
    //print(vect3);
    cout << compIntercambio << " " << compBurbuja << " " << compMerge << endl;

    cin >> queries;

    for (int j = 0; j < queries; j++)
    {
        cin >> query;
        int cantCompBB = 0;
        int posBusBinaria = binarySearch(vect1, query, cantCompBB);
        int posBusSecuencial = busquedaSecuencial(vect1, query);
        int cantCompBS = (posBusSecuencial == -1 ? vect1.size() : posBusSecuencial + 1);

        cout << posBusBinaria << " " << cantCompBS << " " << cantCompBB << endl;
    }
}
