#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T> struct Node{

 T info;
 Node<T>* sig;
};

//--------------------------------------------------
/* (0.1) Descripci�n: Muestra los elementos de una lista, hay que pasarle la funcion mostrarT.
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



/* (0.2) Descripci�n: Muestra los elementos.
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

/* (1)Descripci�n: Agrega el elemento e al final
 *  de la lista direccionada por p.
 * Par�metro Node<T>*& p -Puntero al primer nodo
 *  de la lista.
 * Par�metro: T e -Elemento que vamos a agregar.
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

/*(2)Descripci�n: Agrega el elemento e al inicio de
    la lista direccionada por p.
Par�metros:
� Node<T>*& p � Puntero al primer nodo de la lista.
� T e � Elemento que vamos a agregar al inicio de la
   lista.
Retorna: Node<T>* � Direcci�n del nodo que contiene
 al elemento que se agreg�.
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

/* (3)Descripci�n: Remueve el primer elemento de la
 *  lista direccionada por p.
 * Par�metro: Node<T>*& p -Puntero al primer nodo
 *  de la lista.
 * Retorna: T -Valor que conten�a el nodo removido.
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


/* (4)Descripci�n: Retorna un puntero al nodo
 *  que contiene la primer ocurrencia del
 *  valor k o NULL si ning�n nodo lo contiene.
 * Par�metro: Node<T>*& p Puntero al primer nodo
 *  de la lista.
 * Par�metro: K k Elemento que se debe buscar.
 * Par�metro: int cmpTK(T,K) Funci�n que compara
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

/* (5)Descripci�n: Remueve la primera ocurrencia
 *  del elemento concordante con cmpTK.
Par�metros:
� Node<T>*& p � Puntero al primer nodo de la
   lista.
� K k � Elemento o clave de b�squeda del elemento
   que vamos a remover.
� int cmpTK(T,K)� Funci�n de comparaci�n.
Retorna: T � Valor del elemento que fue removido.
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

/* (6)Descripci�n: Inserta en la lista direccionada por p
 * un nodo con el valor v respetando el criterio de
 * precedencia que establece cmpTT.
 * Par�metro: Node<T>*& p Puntero al primer nodo de la lista.
 * Par�metro: T t Elemento que se debe buscar.
 * Par�metro: int cmpTT(T,T) Funci�n que compara un T con un T.
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

/* (7)Descripci�n: Busca en la lista direccionada por
 *   p la primera ocurrencia de e y retorna la
 *   direcci�n del nodo que lo contiene. Si e no
 *   existe en la lista entonces lo insertar en orden,
 *   seg�n el criterio establecido por cmpTT, y
 *   retorna la direcci�n del nodo inserta-do.Asigna
 *   true o false a enc seg�n e fue encontrado o insertado.
 * Parametros: Node<T>*& p � Puntero al primer nodo
 *   de la lista.
 * Parametros: T e � Elemento que vamos a insertar.
 * Parametros: bool& enc � Par�metro de salida que indica
 *   la acci�n que tom� la funci�n.
 * Parametros: int cmpTT(T,T)� Funci�n que establece el
 *   criterio de ordenamiento.
 * Retorna: Node<T>* � Direcci�n del nodo que acabamos de
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

/* (8)Descripci�n Ordena la lista direccionada por p seg�n
 * el criterio de precedencia que establece cmpTT.
 * Par�metro: Node<T>*& p Puntero al primer nodo de la lista.
 * Par�metro: int cmpTK(T,T) Funci�n que compara un T con un T.
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


/* (9)Descripci�n: Indica si la lista est� vac�a.
 * Par�metro: Node<T>* p Puntero al primer nodo
 * de la lista.
 * Retorna: bool true si la lista est� vac�a o
 * false si tiene elementos.
 */
///////////////////////////////////
template <typename T> bool isEmpty(
 Node<T>* p){

 return p!=NULL?false:true;
}

/* (10)Descripci�n: Libera la memoria que ocupa la
 * lista.
 * Par�metro: Node<T>* p Puntero al primer nodo de la lista.
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

/*(11)Descripci�n: Apila o Inserta un nodo conteniendo
     a e al inicio de la lista direccionada por p.
Par�metros:
� Node<T>*& p � Puntero al primer nodo de la lista.
� T e � Elemento que vamos a agregar al inicio de la
   lista (apilar).
Retorna: Node<T>* � Direcci�n del nodo que contiene
 al elemento que se agreg�.
*/
////////////////////////////////
template <typename T>Node<T>* push(
 Node<T>*& p, T e){

 return addFirst<T>(p,e);
}

/*(12)Descripci�n: Desapila o Remueve el primer nodo
   de la lista direccionada por p..
Par�metro: Node<T>*& p � Puntero al primer nodo de la
 lista.
Retorna: T � Elemento que conten�a el nodo que fue
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

/* (13)Funci�n enqueue
Descripci�n: Agrega el elemento e al final la
lista direccionada por q.
Par�metros:
� Node<T>*& p � Puntero al primer nodo de la lista.
� Node<T>*& q � Puntero al �ltimo nodo de la lista.
� T e � Elemento que vamos a agregar al final de
   la lista (q).
Retorna: Node<T>* � Direcci�n del nodo que
contiene al elemento que se agreg�.
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
/* (14)Descripci�n: Remueve el primer nodo de la
 *   lista direccionada por p.
Par�metros:
� Node<T>*& p � Puntero al primer nodo de la lista.
� Node<T>*& q � Puntero al �ltimo nodo de la lista.
Retorna: T � Elemento que conten�a el nodo que
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

/*  Funci�n enqueue (sobrecarga)
Prototipo: Node<T>* enqueue(Node<T>*& q,T e);
Descripci�n: Agrega el elemento e al final la lista
 circular direccionada por q.
Par�metros:
� Node<T>*& q � Puntero al �ltimo nodo de la
   lista circular.
� T e � Elemento que vamos a agregar al final
   de la lista (q).
Retorna: Node<T>* � Direcci�n del nodo que
   contiene al elemento que se agreg�.
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

/* Funci�n dequeue (sobrecarga)
 * Descripci�n: Remueve el primer nodo de la lista
 *  circular direccionada por q.
Par�metro: Node<T>*& q � Puntero al �ltimo nodo
 de la lista circular.
Retorna: T � Elemento que conten�a el nodo que
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
