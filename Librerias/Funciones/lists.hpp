#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T> struct Node{

 T info;
 Node<T>* sig;
};

//--------------------------------------------------
/* (0.1) Descripción: Muestra los elementos de una lista, hay que pasarle la funcion mostrarT.
*/
//////////////////////////////////////
template<typename T>void mLista(
 Node<T>* p, void mostrarT(T)){

 int j;

 cout<<endl<<"------------------------"<< endl<<" Elementos de la lista:"<<endl <<endl;

 if(p!=NULL){

  Node<T>* aux=p;

  for( j=0; aux!=NULL; j++){

   cout<<j<<"> ";
   T t=aux->info;
   mostrarT(t);
   cout<<endl;

   aux=aux->sig;
  }
 }
 else{

  cout<<" No hay elementos "<<endl;
 }

 cout<<"------------------------"<<endl<<endl;
}

/////////////////////////////////////////
template<typename T>void mListaSig(
  Node<T>* p, void mostrarT(T)){

 int j;

 cout<<endl<<"------------------------"<< endl<<" Elementos de la lista:"<<endl <<endl;

 if(p!=NULL){

  Node<T>* aux=p;

  for( j=0; aux!=NULL; j++){

   if(aux==p){cout<<"  p->";cout<<aux;cout<<endl;
   }
   else{
    cout<<"   ->";cout<<aux;cout<<endl;
   }
   cout<<j<<">";cout<<" info: ";
   T t=aux->info;
   mostrarT(t);
   cout<<" > ";cout<<"sig: ";cout<<aux->sig; cout<<endl<<endl;

   aux=aux->sig;
  }
 }
 else{

  cout<<" No hay elementos "<<endl;
 }

 cout<<"------------------------"<<endl<<endl;
}

////////////////////////////////////////
template<typename T>void mListaCir(
  Node<T>* q, void mostrarT(T)){

 int j;

 cout<<endl<<"------------------------"<< endl<<" Elementos de la lista:"<<endl <<endl;

 if(q!=NULL){

  Node<T>* aux=q->sig;
  Node<T>* p=NULL;

  if(aux==q){//un solo elemento

   cout<<0<<"> "; T t=aux->info;
   mostrarT(t); cout<<endl;
  }
  else{

   for( j=0; aux!=p; j++){
    p=q->sig;
    cout<<j<<"> "; T t=aux->info;
    mostrarT(t); cout<<endl;
    aux=aux->sig;
   }
  }
 }
 else{

  cout<<" No hay elementos "<<endl;
 }

 cout<<"------------------------"<<endl<<endl;
}



/* (0.2) Descripción: Muestra los elementos.
*/
//////////////////////////////////
template<typename T>void mostrarP(T t){

 cout<<t;
 cout<<endl;
}

//////////////////////////////////////
template<typename T>void mLista(Node<T>* p){

 mLista<T>(p,mostrarP);
}

/////////////////////////////////////////
template<typename T>void mListaSig(Node<T>* p){

 mListaSig<T>(p,mostrarP);
}

/////////////////////////////////////////
template<typename T>void mListaCir(Node<T>* q){

 mListaCir<T>(q,mostrarP);
}

//--------------------------------------------------

/* (1)Descripción: Agrega el elemento e al final
 *  de la lista direccionada por p.
 * Parámetro Node<T>*& p -Puntero al primer nodo
 *  de la lista.
 * Parámetro: T e -Elemento que vamos a agregar.
 * Retorna: Node<T>* -Puntero al nodo que contiene
 *  a t.
 */
////////////////////////////////////
template <typename T> Node<T>* add(
 Node<T>*& p, T e){

 Node<T>* nuevo=new Node<T>();
  nuevo->info=e;
  nuevo->sig=NULL;

 if(p==NULL){

   p=nuevo;
 }
 else{

  Node<T>* aux=p;

  while( aux->sig!= NULL){

   aux=aux->sig;
  }

  aux->sig=nuevo;
 }

 return nuevo;
}

/*(2)Descripción: Agrega el elemento e al inicio de
    la lista direccionada por p.
Parámetros:
• Node<T>*& p – Puntero al primer nodo de la lista.
• T e – Elemento que vamos a agregar al inicio de la
   lista.
Retorna: Node<T>* – Dirección del nodo que contiene
 al elemento que se agregó.
*/
///////////////////////////////////////
template <typename T>Node<T>* addFirst(
 Node<T>*& p, T e){// antes era insertFirst

 if(p!=NULL){

  Node<T>* nuevo=new Node<T>();
   nuevo->info=e;
   nuevo->sig=p;
   p=nuevo;
 }
 else{

  add<T>(p,e);
 }

 return p;
}

/* (3)Descripción: Remueve el primer elemento de la
 *  lista direccionada por p.
 * Parámetro: Node<T>*& p -Puntero al primer nodo
 *  de la lista.
 * Retorna: T -Valor que contenía el nodo removido.
 */
///////////////////////////////////
template <typename T>T removeFirst( //removeEnd
 Node<T>*& p){

 T e;

  e=p->info;
  Node<T>* aux=p;

  p=p->sig;
  delete aux;

 return e;
}

template <typename T>T* removeFirst2( //removeEnd
 Node<T>*& p){

  T* e;

  e=&(p->info);
  Node<T>* aux=p;

  p=p->sig;
  delete aux;

 return e;
}


/* (4)Descripción: Retorna un puntero al nodo
 *  que contiene la primer ocurrencia del
 *  valor k o NULL si ningún nodo lo contiene.
 * Parámetro: Node<T>*& p Puntero al primer nodo
 *  de la lista.
 * Parámetro: K k Elemento que se debe buscar.
 * Parámetro: int cmpTK(T,K) Función que compara
 *  un T con un K.
 * Retorna: Node<T>* Puntero al nodo buscado
 *  o NULL si la lista no contiene dicho elemento.
 */
////////////////////////////////////////////////
template <typename T, typename K>Node<T>* find(
 Node<T>* p, K v, int cmpTK(T,K) ){

 Node<T>* aux=p;

 while(aux!=NULL and cmpTK(aux->info,v)!=0 ){
  aux=aux->sig;
 }

 return aux;
}

/* (5)Descripción: Remueve la primera ocurrencia
 *  del elemento concordante con cmpTK.
Parámetros:
• Node<T>*& p – Puntero al primer nodo de la
   lista.
• K k – Elemento o clave de búsqueda del elemento
   que vamos a remover.
• int cmpTK(T,K)– Función de comparación.
Retorna: T – Valor del elemento que fue removido.
 */
//////////////////////////////////////////////
template <typename T, typename K>T remove(
 Node<T>*& p, K k, int cmpTK(T,K)){

 Node<T>* aux=p;
 Node<T>* aux2=find<T,K>(p,k,cmpTK);//usa(4)

  T t;

 if(aux2!=NULL){//existe el elemento

   t=aux2->info;

   if(p==aux2){

    p=p->sig;
   }
   else{

    while( aux->sig!=aux2){
     aux=aux->sig;
    }

    aux->sig=aux2->sig;
    aux=aux2;
   }

   delete aux;
 }
 else{//por las dudas...
  cout<<"ErroRemove: no existe el elemento para remover"<<endl;
 }

  return t;
}

/* (6)Descripción: Inserta en la lista direccionada por p
 * un nodo con el valor v respetando el criterio de
 * precedencia que establece cmpTT.
 * Parámetro: Node<T>*& p Puntero al primer nodo de la lista.
 * Parámetro: T t Elemento que se debe buscar.
 * Parámetro: int cmpTT(T,T) Función que compara un T con un T.
 * Retorna: Node<T>* Puntero al nodo insertado.
 */
////////////////////////////////////////////
template <typename T>Node<T>* orderedInsert(
 Node<T>*& p, T e, int cmpTT(T,T) ){

 Node<T>* aux=p; Node<T>* ant=aux; Node<T>* nuevo=new Node<T>();
 nuevo->info=e;
 nuevo->sig=NULL;

 if(p!=NULL){

  while(aux!=NULL){

   if(cmpTT(aux->info,e)>0){//si es menor,agregar

    if(p!=aux){//menor respecto a otro

     nuevo->sig=aux;
     ant->sig=nuevo;
     return nuevo;
    }
    else{
     //menor de todos
     return addFirst<T>(p,e);
    }
   }

   ant=aux;//direccion anterior
   aux=aux->sig;//direccion siguiente
  }
  //mayor de todos
  ant->sig=nuevo;
  return nuevo;
 }
 else{
  //si no hay elementos
  return add<T>(p,e);
 }
}

/* (7)Descripción: Busca en la lista direccionada por
 *   p la primera ocurrencia de e y retorna la
 *   dirección del nodo que lo contiene. Si e no
 *   existe en la lista entonces lo insertar en orden,
 *   según el criterio establecido por cmpTT, y
 *   retorna la dirección del nodo inserta-do.Asigna
 *   true o false a enc según e fue encontrado o insertado.
 * Parametros: Node<T>*& p – Puntero al primer nodo
 *   de la lista.
 * Parametros: T e – Elemento que vamos a insertar.
 * Parametros: bool& enc – Parámetro de salida que indica
 *   la acción que tomó la función.
 * Parametros: int cmpTT(T,T)– Función que establece el
 *   criterio de ordenamiento.
 * Retorna: Node<T>* – Dirección del nodo que acabamos de
 *   encontrar o insertar.
 */
//////////////////////////////////////////////
template <typename T> Node<T>* searchAndInsert(
  Node<T>*& p,T e,bool& enc,int cmpTT(T,T)){

 Node<T>* dir=find<T>(p,e,cmpTT);//busco e, en la lista

   if(dir!=NULL){//esta en la lista
    enc=true;
   }
   else{
    enc=false;
    sort<T>(p,cmpTT);//ordeno la lista
    dir=orderedInsert<T>(p,e,cmpTT);//insertar en orden
   }

 return dir;
}

/* (8)Descripción Ordena la lista direccionada por p según
 * el criterio de precedencia que establece cmpTT.
 * Parámetro: Node<T>*& p Puntero al primer nodo de la lista.
 * Parámetro: int cmpTK(T,T) Función que compara un T con un T.
 */
////////////////////////////////
template <typename T>void sort(
 Node<T>*& p, int cmpTT(T,T)){

 int ordenar=1;

 while( ordenar>0 ){
  ordenar=0;

  Node<T>* aux=p;
  Node<T>* ant=p;

  while(aux->sig!=NULL ){

    if( cmpTT(aux->info,(aux->sig)->info)>0){

     if(p==aux){//ok
      ant=aux->sig;
      p=ant;
      aux->sig=ant->sig;
      ant->sig=aux;
     }
     else{
      ant->sig=aux->sig;
      aux->sig=(ant->sig)->sig;
      (ant->sig)->sig=aux;
      ant=ant->sig;
     }

    ordenar++;
   }
   else{

    if(p!=aux){//ok
    aux=aux->sig;
    ant=ant->sig;
    }
    else{
     aux=aux->sig;
    }
   }
  }
 }
}


/* (9)Descripción: Indica si la lista está vacía.
 * Parámetro: Node<T>* p Puntero al primer nodo
 * de la lista.
 * Retorna: bool true si la lista está vacía o
 * false si tiene elementos.
 */
///////////////////////////////////
template <typename T> bool isEmpty(
 Node<T>* p){

 return p!=NULL?false:true;
}

/* (10)Descripción: Libera la memoria que ocupa la
 * lista.
 * Parámetro: Node<T>* p Puntero al primer nodo de la lista.
 */
////////////////////////////////
template <typename T> void free(
 Node<T>*& p){

 while(p!= NULL){

  Node<T>* aux=p->sig;
  delete p;
  p=aux;
 }
}


/*
//------- Pila --------

/*(11)Descripción: Apila o Inserta un nodo conteniendo
     a e al inicio de la lista direccionada por p.
Parámetros:
• Node<T>*& p – Puntero al primer nodo de la lista.
• T e – Elemento que vamos a agregar al inicio de la
   lista (apilar).
Retorna: Node<T>* – Dirección del nodo que contiene
 al elemento que se agregó.
*/
////////////////////////////////
template <typename T>Node<T>* push(
 Node<T>*& p, T e){

 return addFirst<T>(p,e);
}

/*(12)Descripción: Desapila o Remueve el primer nodo
   de la lista direccionada por p..
Parámetro: Node<T>*& p – Puntero al primer nodo de la
 lista.
Retorna: T – Elemento que contenía el nodo que fue
 removido.
*/
////////////////////////////
template <typename T> T pop(
 Node<T>*& p){

 return removeFirst<T>(p);
}

template <typename T> T* pop2(
 Node<T>*& p){

 return removeFirst2<T>(p);
}

//------- Cola --------

/* (13)Función enqueue
Descripción: Agrega el elemento e al final la
lista direccionada por q.
Parámetros:
• Node<T>*& p – Puntero al primer nodo de la lista.
• Node<T>*& q – Puntero al último nodo de la lista.
• T e – Elemento que vamos a agregar al final de
   la lista (q).
Retorna: Node<T>* – Dirección del nodo que
contiene al elemento que se agregó.
 */
//////////////////////////////////
template <typename T>Node<T>* enqueue(
 Node<T>*& p, Node<T>*& q, T e){

 if(p==NULL){
 q=add<T>(p,e);
 }
 else{
  Node<T>* nuevo=new Node<T>();
  nuevo->info=e;nuevo->sig=NULL;
  q->sig=nuevo;
  q=nuevo;
 }
 return q;
}
/* (14)Descripción: Remueve el primer nodo de la
 *   lista direccionada por p.
Parámetros:
• Node<T>*& p – Puntero al primer nodo de la lista.
• Node<T>*& q – Puntero al último nodo de la lista.
Retorna: T – Elemento que contenía el nodo que
 fue removido.
 */
///////////////////////////////
template <typename T>T dequeue(
 Node<T>*& p, Node<T>*& q){

 if(p!=q){
  removeFirst<T>(p);
 }
 else{
  p==NULL;q==NULL;
 }
}

// LISTA CIRCULAR

/* q->al ultimo elemento
 * q->sig al primer elemento
*/

/*  Función enqueue (sobrecarga)
Prototipo: Node<T>* enqueue(Node<T>*& q,T e);
Descripción: Agrega el elemento e al final la lista
 circular direccionada por q.
Parámetros:
• Node<T>*& q – Puntero al último nodo de la
   lista circular.
• T e – Elemento que vamos a agregar al final
   de la lista (q).
Retorna: Node<T>* – Dirección del nodo que
   contiene al elemento que se agregó.
 */
//////////////////////////////////
template <typename T>Node<T>* enqueue(
 Node<T>*& q, T e){

 Node<T>* nuevo=new Node<T>();
 nuevo->info=e;

 if(q!=NULL){

  nuevo->sig=q->sig;
  q->sig=nuevo;
 }
 else{

  nuevo->sig=nuevo;
 }

 q=nuevo;

 return q;
}

/* Función dequeue (sobrecarga)
 * Descripción: Remueve el primer nodo de la lista
 *  circular direccionada por q.
Parámetro: Node<T>*& q – Puntero al último nodo
 de la lista circular.
Retorna: T – Elemento que contenía el nodo que
 fue removido.
 */
///////////////////////////////
template <typename T>T dequeue(
 Node<T>*& q){


 Node<T>* aux=q->sig;
 T t=aux->info;

 if(aux!=q){
  q->sig=aux->sig;
  delete aux;
 }
 else{
  q=NULL;
 }

 return t;
}




#endif
