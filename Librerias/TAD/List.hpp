#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct List{

 Node<T>* p;//direccion del primer nodo

 Node<T>* curr;//direccion del proximo elemento

 int len;//cantidad de elementos de la lista
};
//---------------------------------------------
//funciones para mostrar listas
template<typename T>void mLista(List<T> lst){

 mLista<T>(lst.p);
}
template<typename T>void mLista(
  List<T> lst,void mostrarT(T)){

 mLista<T>(lst.p,mostrarT);
}

template<typename T>void mListaSig(List<T> lst){

 mListaSig<T>(lst.p);
}
template<typename T>void mListaSig(
  List<T> lst,void mostrarT(T)){

 mListaSig<T>(lst.p,mostrarT);
}
//---------------------------------------------

/*(1)Descripción: Función de inicialización.
Retorna: List<T> – La lista.
 */
template<typename T>List<T> list(){//CreateList

 List<T> lst;
  lst.p=NULL;
  lst.curr=lst.p;
  lst.len=0;

 return lst;
}

/*(2)Descripción: Agrega un elemento al final de
    la lista.
Parámetros:
• List<T>& lst - Lista.
• T e – Elemento que se agregará al final de la lista.
Retorna: T* – Dirección de memoria del elemento
 que se agregó.
 */
template<typename T>T* listAdd(
 List<T>& lst,T v){

 Node<T>* e=add<T>(lst.p,v);
 lst.len++;
 return &(e->info);
}

/*(3)Descripción: Remueve el elemento que concuerde
    con k según la función cmpTK.
Parámetros:
• List<T>& lst - Lista.
• K k – Elemento que será removido de la lista.
Retorna: T – Elemento que fue removido.
 */
template<typename T,typename K>T listRemove(
 List<T>& lst,K k, int cmpTK(T,K)){

 lst.len--;
 return remove(lst.p,k,cmpTK);
}

/*(4)Descripción: Retorna la dirección del primer
    elemento concordante con k según cmpTK.
Parámetros:
• List<T>& lst - Lista.
• K k – Clave o elemento a buscar.
• int cmpTK(T,K) – Función de comparación.
Retorna: T* – Dirección del elemento encontrado
 o NULL si hubo concordancia.
*/
template<typename T,typename K>T* listFind(
 List<T> lst,K k, int cmpTK(T,K)){

 Node<T>* e=find<T>(lst.p,k,cmpTK);
 return e==NULL? NULL: &(e->info);
}

/*(5)Descripción: Inserta un elemento según
    el orden que establece cmpTT. La lista debe
    estar ordenada (según cmpTT) o vacía.
Parámetros:
• List<T>& lst - Lista.
• T t – Elemento a insertar.
• int cmpTT(T,T) – Función de comparación.
Retorna: T* – Dirección del elemento insertado.
 */
template<typename T>T* listOrderedInsert(
 List<T>& lst,T t,int cmpTT(T,T)){

 Node<T>* e=orderedInsert<T>(lst.p,t,cmpTT);
 lst.len++;
 return &(e->info);
}

/*(6)Descripción: Ordena la lista según el
    criterio que establece cmpTT.
Parámetros:
• List<T>& lst – Lista.
• int cmpTT(T,T) – Función de comparación.
Retorna: void.
 */
template<typename T>void listSort(
 List<T>& lst,int cmpTT(T,T)){

 sort<T>(lst.p,cmpTT);
}

/* (7)Descripción: Indica si la lista está vacía
 *  o tiene elementos.
Parámetro: List<T>& lst – Lista.
Retorna: bool – true si la lista está vacía,
 false si tiene elementos.
 */
template<typename T>bool listIsEmpty(
 List<T>& lst){

 return isEmpty<T>(lst.p);
}

/*(8)Descripción: Indica cuántos elementos tiene
    la lista.
Parámetro: List<T>& lst – Lista.
Retorna: int – Cantidad de elementos que tiene
 la lista.
*/
template<typename T>int listSize(List<T> lst){

 return lst.len;
}

/*(9)Descripción: Libera la memoria que ocupa la lista.
Parámetro: List<T>& lst – Lista.
Retorna: void.
 */
template<typename T>void listFree(
 List<T>& lst){

 free<T>(lst.p);
}

/*(10)Descripcion: reinicia o prepara la lista para
    iterarla(asigna p a curr).
Parámetro: List<T>& lst – Lista.
Retorna: void.
*/
template<typename T>void listReset(
 List<T>& lst){

 lst.curr=lst.p;//curr apunta al primer nodo
}

/*(11)Descripción: Indica si quedan más elementos
    para seguir iterando la lista.
Parámetro: List<T>& lst – Lista.
Retorna: bool – true si es posible seguir iterando
 la lista.
*/
template<typename T>bool listHasNext(
 List<T>& lst){

 return lst.curr!=NULL? true:false;
}

/*(12)Descripción: Retorna la dirección del siguiente
    elemento de la lista en la iteración.
Parámetro: List<T>& lst – Lista.
Retorna: T* – Dirección del siguiente elemento en
 la iteración.
*/
template<typename T>T* listNext(
 List<T>& lst){

 T* e=&(lst.curr->info);
 lst.curr=lst.curr->sig;
 return e;
}

#endif
