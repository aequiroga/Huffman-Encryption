#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

//---------------------------------------
/*TAD Stack
Este TAD encapsula una pila.
 */
template<typename T>struct Stack{

 Node<T>* p;
 int len;
};
//---------------------------------------
template<typename T>void mLista(Stack<T> x){

 mLista<T>(x.p);
}

template<typename T>void mLista(
 Stack<T> x,void mostrarT(T)){

 mLista<T>(x.p,mostrarT);
}
//---------------------------------------

/*(1)Descripcion: Inicializa una Pila.
 */
template<typename T>Stack<T> stack(){

 Stack<T> x;
 x.p=NULL;
 x.len=0;
 return x;
}

/*(2)Descripci�n: Apila el elemento e.
Par�metros:
� Stack<T>& st - Pila.
� T e � Elemento que se apilar�.
Retorna: T* � Direcci�n de memoria del elemento
 que se apil�.
 */
template<typename T>T* stackPush(
 Stack<T>& st,T e){

 st.len++;
 return &(push<T>(st.p,e)->info);
}

/*(3)Descripci�n: Desapila un elemento.
Par�metro: Stack<T>& st - Pila.
Retorna: T � Elemento que se desapil�.
 */
template<typename T>T stackPop(Stack<T>& st){

 st.len--;
 return pop<T>(st.p);
}

template<typename T>T* stackPop2(Stack<T>& st){

 st.len--;
 return pop2<T>(st.p);
}

/*(4)Descripci�n: Retorna true o false seg�n la
    pila tenga elementos o no.
Par�metro: Stack<T>& st - Pila.
Retorna: bool �true o false seg�n la pila tenga
 elementos o no.
 */
//template<typename T>
//bool stackIsEmpty(Stack<T> st){ while( !stack)
//
// return st.p!=NULL? true: false;
//}

template<typename T>
bool stackIsEmpty(Stack<T> st)
{
   return isEmpty<T>(st.p);
}

/*(5)Descripci�n: Retorna la cantidad de elementos
    que tiene la pila.
Par�metro: Stack<T>& st - Pila.
Retorna: int � Cu�ntos elementos tiene la pila.
 */
template<typename T>int stackSize(Stack<T> st){

 return st.len;
}

#endif
