#ifndef _TQUEUE_TAD_
#define _TQUEUE_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;
//-------------------------------------------
/* TAD Queue
Este TAD encapsula una cola. La implementaci�n,
que podr� ser sobre una lista enlazada con dos
punteros o una lista circular.
 */
template<typename T>struct Queue{

 //LISTA CIRCULAR
 Node<T>* q;
 int len;
};
//-------------------------------------------
template<typename T>void mLista(Queue<T> x){

 mListaCir<T>(x.q);
}

template<typename T>void mLista(
 Queue<T> x,void mostrarT(T)){

 mListaCir<T>(x.q, mostrarT);
}
//------------------------------------------

/*(1)
 */
template<typename T>Queue<T> queue(){

 Queue<T> x;
 x.q=NULL;
 x.len=0;
 return x;
}

/*(2)Descripci�n: Encola el elemento e.
Par�metros:
� Queue<T>& q - Cola.
� T e � Elemento que se encolar�.
Retorna: T* � Direcci�n de memoria del elemento
 que se encol�.
 */
template<typename T>T* queueEnqueue(
 Queue<T>& x,T e){

 x.len++;
 return &(enqueue<T>(x.q,e)->info);
}

/*(3)Descripci�n: Desencola un elemento.
Par�metro: Queue<T>& q - Cola.
Retorna: T � Elemento que se desencol�.
*/
template<typename T>T queueDequeue(Queue<T>& x){

 x.len--;
 return dequeue<T>(x.q);
}

/*(4)Descripci�n: Retorna true o false seg�n la
    cola tenga elementos o no.
Par�metro: Queue<T>& q - Cola.
Retorna: bool �true o false seg�n la cola tenga
  elementos o no.
*/
template<typename T>bool queueIsEmpty(Queue<T> x){

 return x.q!=NULL?true:false;
}

/*(5) no hay info en la documentacion

template<typename T>void queueUndequeue(Queue<T> q){

}*/

/*(6)
 */
template<typename T>int queueSize(Queue<T> x){

 return x.len;
}

#endif
