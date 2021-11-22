#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

//##### TAD de arrays #########


/* Descripcion: El TAD Arr representa un array tipo T cuya capacidad f�sica se incrementar� auto-
m�ticamente cuando su longitud (cantidad de elementos que contiene) se aproxime
a la capacidad; d�ndole al usuario la �ilusi�n� de estar trabajando con una estructura
 de datos din�mica.
*/
///////////////////////////////
template<typename T>struct Arr{

 int cap;

 T* arr; //new T[cap];

 int len;
};

/*(0.1) Descripcion: muestra los elementos de tipo Arr<T>, donde el tipo T no es primitivo, puede ser de tipo Persona, Fecha, etc.
*/
////////////////////
template<typename T> void mArr(Arr<T> a, void mostrarT(T)){

 mArray<T>(a.arr,a.len,mostrarT);
}

/*(0.2) Descripcion: muestra los elementos de tipo Arr<T>, donde el tipo T es primitivo, puede ser de tipo int, double, char, "string"(no es primitivo pero lo muestra)
*/
////////////////////
template<typename T> void mArr(Arr<T> a){

 mArray<T>(a.arr,a.len);
}

/* (1) Descripci�n: Inicializa un array con capacidad cap y longitud inicial vac�a.Retorna: Arr<T> � El array.
*/
////////////////////////////////
template<typename T>Arr<T>  arr(int size ){

 Arr<T> a;

 a.len=0;

 a.cap=size;

 a.arr=new T[a.cap];

 return a;
}

/* (2) Descripci�n: Inicializa un array cuya capacidad inicial se establece por defecto.Retorna: Arr<T> � El array.
*/
//////////////////////////////////
template<typename T> Arr<T>  arr(){

 Arr<T> a;

 a=arr<T>(50);

 return a;
}

/* (3) Descripci�n: Agrega t al final de arr incrementando, de ser necesario, su capacidad. Retorna la posici�n del arr donde qued� ubicado el elemento t.Retorna: int � Posici�n de arr donde se agreg� el elemento t.*/
///////////////////////////////
template<typename T>int arrAdd( Arr<T>& a,T v){

 if(a.len < a.cap){

  add<T>(a.arr,a.len,v);
 }
 else{

  int n=(a.cap)*2;
  T* aux=new T[n];

  for(int i=0;i<a.len;i++){

   aux[i]=a.arr[i];
  }

  add<T>(aux,a.len,v);

  delete a.arr;
  a.arr=aux;
  a.cap=n;
 }

 return (a.len)-1;
}

/* (4) Descripci�n: Retorna la direcci�n del elemento de arr ubicado en la posici�n p. Retorna: T* � Direcci�n del elemento ubicado en la posici�n p del array arr.
*/
////////////////////////
template<typename T>T* arrGet( Arr<T> a,int p){

 return &(a.arr[p]);
}

/* (9) Descripci�n: Descripci�n: Asigna el elemento t en la posici�n p del array a.
*/
/////////////////////////////////
template<typename T>void arrSet( Arr<T>& a,T v,int p){

 (a.len==0? add<T>(a.arr,a.len,v): a.arr[p]=v );
}


/* (5) Descripci�n: Inserta t en la posici�n p del array arr.
*/
//////////////////////////////////
template<typename T>void arrInsert( Arr<T>& a,T t,int p){

 insert<T>(a.arr,a.len,t,p);
}

/* (6) Descripci�n: Retorna la longitud actual del array arr. Retorna: int � Longitud del array arr.
*/
///////////////////////////////////
template<typename T>
int arrSize(Arr<T> a){

 return a.len;
}

/* (7) Descripci�n: Remove el elemento de arr ubicado en la posici�n p. Retorna: T � Elemento que ocupaba la posici�n p dentro de arr.
*/
/////////////////////////////////
template<typename T>T arrRemove( Arr<T>& a,int p){

 return remove<T>(a.arr,a.len,p);
}

/* (8) Descripci�n: Remueve todos los elemento de arr
 * dej�ndolo vaci�.Descripci�n: Remueve todos los
 * elemento de arr dej�ndolo vaci�.
*/
/////////////////////////////////
template<typename T>void arrRemoveAll (Arr<T>& a){

 a.len=0;
}




/* (10) Descripci�n: Retorna la posici�n que k ocupa dentro de arr, seg�n la funci�n de comparaci�n cmpTK, o un valor negativo si arr no contiene a k.  Retorna: int � Posici�n de la primera ocurrencia de k dentro de arr o un valor negativo si arr no contiene a k.
*/
///////////////////////////////////
template<typename T,typename K>
int arrFind(Arr<T>& a,K k,int cmpTK(T,K)){

 return find<T,K>(a.arr,a.len,k,cmpTK);
}

/* (11) Descripci�n: Inserta t en arr seg�n el criterio de precedencia que establece cmpTT.
*/
//////////////////////////////////
template<typename T>
int arrOrderedInsert(Arr<T>& a,T t,int cmpTT(T,T)){

 return orderedInsert<T>(a.arr,a.len, t,cmpTT);
}


/* (12) Descripci�n: Ordena el array arr seg�n establece cmpTT.
*/
template<typename T>void arrSort( Arr<T>& a,int cmpTT(T,T)){

 sort<T>(a.arr,a.len,cmpTT);
}

template<typename T>void arrFree(Arr<T>& a){

 delete a.arr;
 a.arr=NULL;
 a.len=0;
 a.cap=0;
}




/*template<typename T>
struct Arr
{
};

template<typename T>
Arr<T> arr(int size)
{
   return {};
}

template<typename T>
Arr<T> arr()
{
   return {};
}

template<typename T>
int arrAdd(Arr<T>& a,T v)
{
   return 0;
}

template<typename T>
T* arrGet(Arr<T> a,int p)
{
   return NULL;
}

template<typename T>
void arrSet(Arr<T>& a,int p,T t)
{
}

template<typename T>
void arrInsert(Arr<T>& a,T v,int p)
{
}

template<typename T>
int arrSize(Arr<T> a)
{
   return 0;
}

template<typename T>
T arrRemove(Arr<T>& a,int p)
{
   T t;
   return t;
}

template<typename T>
void arrRemoveAll(Arr<T>& a)
{
}

template<typename T,typename K>
int arrFind(Arr<T>& a,K k, int cmpTK(T,K))
{
   return 0;
}

template<typename T>
int arrOrderedInsert(Arr<T>& a,T t,int cmpTT(T,T))
{
   return 0;
}

template<typename T>
void arrSort(Arr<T>& a,int cmpTT(T,T))
{
}*/

#endif
