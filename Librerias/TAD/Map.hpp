
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Arr.hpp"
#include "../funciones/files.hpp"

using namespace std;

//##### TAD MAP #########

///////////////////////////////////
template<typename K,typename V>
struct Map{

 Arr<K> keys;

 Arr<V> values;

 int curr;
};

/////////////////////////////////
template<typename K,typename V>
struct Aux{

 K k;

 V v;
};


//////////////////////////////
template<typename K>
int cmpKK(K a,K b){

 return (a>b?1:b>a?-1:0);
}

/* (0.1) Descripción: Muestra los elementos del array, hay que pasarle la funcion mostrarT.
*/
/////////////////////////////////
template<typename K,typename V>
void mMap( Map<K,V> m, void mostrarKV(K,V)){

 int i,j=0;

 cout<<endl<<"---------------------"<< endl<<" Elementos del Map:"<<endl <<endl;

 for( i=0; i<m.keys.len; i++){
  if(i<1){

   cout<<j<<"> ";
   mostrarKV(m.keys.arr[i],m.values.arr[i]);
  }
  else{

  cout<<endl;
  cout<<j<<"> ";
   mostrarKV(m.keys.arr[i],m.values.arr[i]);
  }
  j++;
 }

 if(i==0){

  cout<<" No hay elementos"<<endl;
 }

 cout<<"---------------------"<<endl<<endl;
}

/* (0.1) Descripción: Muestra los elementos(string, double, int, etc) del array.
*/
template<typename K,typename V>
void mostrarPKV(K k,V v){

 cout<<"key= "<<k;
 cout<<endl;
 cout<<" > value= "<<v;
 cout<<endl;


/*cout<<"key= ";
  cout<<k<<endl;
  cout<<" > value= ";
  cout<<v.nom<<", "<<v.dni<<endl;
 */
}

/////////////////////////////////
template<typename K,typename V>
void mMap(Map<K,V> m){

 mMap<K,V>(m,mostrarPKV);
}

/* (1) Descripción: Inicializa un map.Retorna: Map<K,V> – El map.
*/
////////////////////////////////
template<typename K,typename V> Map<K,V> map(){

 Map<K,V> m;

 m.keys=arr<K>();

 m.values=arr<V>();

 return m;
}

/* (2) Descripción: Retorna la dirección de memoria del valor asociado a
 * la clave k o NULL si map no contiene ningún valor asociado a dicha clave.
*/
////////////////////////////////////
template<typename K,typename V>
V* mapGet(Map<K,V>& m,K k){

 int pos=arrFind<K,K>(m.keys,k,cmpKK);

 return (pos<0? NULL: arrGet<V>(m.values,pos));
}


/* (3) Descripción: Agrega al map map el elemento v asociado a la clave k.
 * Si existía una entrada vinculada a k se debe reemplazar el valor anterior por v.
 * Retorna: V* - Dirección de memoria del elemento vinculado con la clave k.
*/
///////////////////////////////////
template<typename K,typename V>
V* mapPut(Map<K,V>& m,K k,V v){

 int pos=arrFind<K,K>(m.keys,k,cmpKK);
 if(pos<0){

  pos=arrAdd<K>(m.keys,k);
  arrAdd<V>(m.values,v);
 }
 else{

  m.values.arr[pos]=v;
 }

 return arrGet<V>(m.values,pos);
}


/* (4) Descripción: Verifica si map contiene a k. Retorna: bool - true o false según map contenga,
 * o no, una entrada vinculada a k.
*/
///////////////////////////////////
template<typename K,typename V>
bool mapContains(Map<K,V>& m,K k){

int pos=arrFind<K,K>(m.keys,k,cmpKK);

 return (pos<0? false: true);
}


/* (5) Descripción: Elimina de m la entrada identificada con la clave k.
 Retorna: V – Valor que contenía la entrada asociada a la clave k.
*/
///////////////////////////////////
template<typename K,typename V>
V mapRemove(Map<K,V>& m,K k){

 int pos = arrFind<K,K>(m.keys,k,cmpKK);

 return arrRemove<V>(m.values,pos);
}

/* (6) Descripción: Retorna la cantidad actual de entradas que tiene m.
 Retorna: int – Cantidad de entradas que tiene el map m.
*/
//////////////////////////////////
template<typename K,typename V>
int mapSize(Map<K,V> m){

 return arrSize(m.keys);
}

/* (7) Descripción: Indica si quedan más elementos para continuar iterando el map.
 Retorna: bool – true o false según queden elementos para continuar iterando.
*/
///////////////////////////////////
template<typename K,typename T> bool mapHasNext(Map<K,T>& m){

 return m.curr < arrSize(m.keys);
}

/* (8) Descripción: Permite iterar sobre las claves del map. Esta función es mutuamente
excluyente respecto de mapNextValue.
 Retorna: K – La siguiente clave dentro de una iteración.
*/
//////////////////////////////////
template<typename K,typename T> K mapNextKey(Map<K,T>& m){

 return m.keys.arr[m.curr++];
}


/* (9) Descripción: Permite iterar sobre los valores que contiene el map. Esta función es mu-
tuamente excluyente despecto de mapNextKey.
  Retorna: V* – Dirección de memoria del siguiente valor dentro de una iteración.
*/
//////////////////////////////////
template<typename K,typename T> T* mapNextValue(Map<K,T>& m){

 return &(m.values.arr[m.curr++]);
}


/* (10) Descripción: Prepara el map para comenzar una nueva iteración.
*/
//////////////////////////////////
template<typename K,typename T> void mapReset(Map<K,T>& m){

 m.curr=0;
}


/* (11) Descripción: Ordena el map aplicando sobre sus claves el criterio que establece cmpKK.
*/
//////////////////////////////////
template<typename K,typename V> void mapSortByKeys( Map<K,V>& m,int cmpKK(K,K)){

 K auxK;
 V auxV;

 int i,ordenar=1;

 while( ordenar>0){

  ordenar=0;

  for(i=0;i<mapSize<K,V>(m)-1;i++){

   if(cmpKK(m.keys.arr[i],m.keys.arr[i+1])>0){

    auxK=m.keys.arr[i+1];
    auxV=m.values.arr[i+1];

    m.keys.arr[i+1]=m.keys.arr[i];
  m.values.arr[i+1]=m.values.arr[i];

    m.keys.arr[i]=auxK;
    m.values.arr[i]=auxV;

    ordenar++;
   }
  }
 }
}

/*(11.b) Descripción: otra version q Ordena el map aplicando sobre sus claves el criterio que establece cmpKK.

//////////////////////////////////
template<typename K,typename V> void mapSortByKeys( Map<K,V>& m,int cmpKK(K,K)){

 int i,j=mapSize<K,V>(m);

 Arr<Aux<K,V>> aux=arr<Aux<K,V>>(j);

 for(int i=0;i<j;i++){

  arrAdd<Aux<K,V>>(aux,{m.keys.arr[i],m.values.arr[i]});
 }

 arrSort<K>(m.keys,cmpKK);

 for(int i=0;i<j;i++){

Aux<K,V> b=*arrGet<Aux<K,V>>(aux,i);

  mapPut<K,V>(m,b.k,b.v);
 }
}
*/

/* (12) Descripción: Ordena el map aplicando sobre sus values el criterio que establece cmpVV.
*/
//////////////////////////////////
template<typename K,typename V> void mapSortByValues(Map<K,V>& m,int cmpVV(V,V)){

 K auxK;
 V auxV;

 int i,ordenar=1;

 while( ordenar>0){

  ordenar=0;

  for(i=0;i<mapSize<K,V>(m)-1;i++){

   if(cmpVV(m.values.arr[i],m.values.arr[i+1])>0){

    auxV=m.values.arr[i+1];
    auxK=m.keys.arr[i+1];

    m.values.arr[i+1]=m.values.arr[i];
    m.keys.arr[i+1]=m.keys.arr[i];

    m.values.arr[i]=auxV;
    m.keys.arr[i]=auxK;

    ordenar++;
   }
  }
 }
}

//()Descripción: Libera la memoria que ocupa la lista.
template<typename K,typename V> void mapFree(Map<K,V>& m){

 arrFree<K>(m.keys);
 arrFree<V>(m.values);
 m.curr=0;
}


/*()Descripcion: Recibe el nombre del archivo de CONSULTA y retorna un Map.
Parametro: string s- Nombre del archivo
Parametro: K campos(T,V&)- Retorna el valor de la Key. Tambien le
asigna valores a "ALGUNOS" de los campos de V v.
*/
template<typename K,typename V,typename T>
Map<K,V> fileToMap(string s,K campoV(T,V&)){

 char arr[30]; strcpy(arr,s.c_str());

 Map<K,V> m=map<K,V>();//Map donde guardamos los elementos del Archivo

 FILE* f=fopen(arr,"r+b");

  V v;//de tipo RAlgo
  T t=read<T>(f);//de tipo Algo( tipo de dato del archivo)
  K k=campoV(t,v);//le asigna valor a la Key

 while(!feof(f)){

  mapPut<K,V>(m,k,v);
  t=read<T>(f);
  k=campoV(t,v);//k,v(& : por referencia)
 }
 fclose(f);

 return m;
}
//
template<typename K,typename V,typename T>
Map<K,V> fileToMap(string s,void procesarNovedad(Map<K,V>&,T)){

 char arr[30]; strcpy(arr,s.c_str());

 Map<K,V> m=map<K,V>();

 FILE* f=fopen(arr,"r+b");

  T t=read<T>(f);

 while(!feof(f)){

  procesarNovedad(m,t);//logica
  t=read<T>(f);
 }
 fclose(f);

 return m;
}

// ME SIRVE PARA GENERAR UN INDICE(entre otras cosas)
template<typename K,typename V,typename T,typename W>
Map<T,W> mapIndex(Map<K,V> m,T newKeyValue(K,V,W&)){

  Map<T,W> aux=map<T,W>();

  mapReset<K,V>(m);
  while( mapHasNext<K,V>(m) ){

     K k=mapNextKey<K,V>(m);//anterior key
     V v=*mapGet<K,V>(m,k);//anterior value

     W w;//nueva value
     T t=newKeyValue(k,v,w);//nueva o anterior key
     mapPut<T,W>(aux,t,w);//agrego al nuevo map
  }
 return aux;
}

template<typename K,typename V,typename T,typename W>
 W valueIndex(Map<K,V> m,T newKeyValue(K,V,W&),T k){

 Map<T,W> aux=mapIndex<K,V,T,W>(m,newKeyValue);

  W w=*mapGet<T,W>(aux,k);

 return w;
}

//uso un indice, retorna un nuevo map, con la misma value y diferente key
template<typename K,typename V,typename T,typename W>
Map<W,V> newMap(Map<K,V> m,Map<T,W> indice){

  Map<W,V> aux=map<W,V>();//NUEVO MAP

  mapReset<K,V>(m);
  while( mapHasNext<K,V>(m) ){

     K k=mapNextKey<K,V>(m);//anterior key
     V v=*mapGet<K,V>(m,k);//anterior value

     W w=*mapGet<T,W>(indice,k);//nueva key
     mapPut<W,V>(aux,w,v);//agrego al nuevo map
  }
 return aux;
}

// a partir de alguna de la value de map2, incializa uno de los campos del map1
template<typename K,typename V,typename T,typename W>
void newMap(Map<K,V> m1,Map<T,W> map2,void newSubValue(K,V&,Map<T,W>)){

  mapReset<K,V>(m1);
  while( mapHasNext<K,V>(m1) ){

   K k=mapNextKey<K,V>(m1);//anterior key
   V v=*mapGet<K,V>(m1,k);//anterior value

   newSubValue(k,v,map2);//inicializa uno de sus campos
  }
}

/*
template<typename K,typename V,typename T,typename W>
void newMapArr(Map<K,Arr<V>>& m1,Map<T,W> map2,void newSubValue(K,V&,Map<T,W>)){

  mapReset<K,Arr<V>>(m1);
  while( mapHasNext<K,Arr<V>>(m1) ){

   K k=mapNextKey<K,Arr<V>>(m1);//anterior key
   Arr<V> v=*mapGet<K,Arr<V>>(m1,k);//anterior value

   W w=*mapGet<T,W>(m2,k);//nueva key
   for(int i=0;arrSize<V>(v);i++){

      V* x=arrGet<V>(v,i);
    }

   newSubValue(k,v,map2);//inicializa uno de sus campos
  }
}*/
/*
template<typename K,typename V>
void arrAsignar(Arr<V> a){

  for(int i=0;arrSize<V>(a);i++){

    V* v=arrGet<V>(a,i);
  }
}
*/
/*
template<typename K,typename V>
Map<K,V> fileToMap(FILE* f,K getKey(V)){


 Map<K,V> m=map<K,V>();


  V v=read<V>(f);

 while(!feof(f)){

  K k=getKey(v);//k,v(& : por referencia)
  mapPut<K,V>(m,k,v);
  v=read<V>(f);
 }

 return m;
}*/
/*
template<typename K,typename V,typename T>
Map<K,V> fileToMapX(FILE* f,K getKey(T),V tToV(T)){


 Map<K,V> m=map<K,V>();

  T t=read<T>(f);

 while(!feof(f)){

  K k=getKey(t);
  V v=tToV(t);
  mapPut<K,V>(m,k,v);
  t=read<T>(f);
 }

 return m;
}*/
/*
template<typename K,typename V,typename T>
Map<K,V> fileToMapX(FILE* f,K toMapEntry(T,V&)){


 Map<K,V> m=map<K,V>();

  T t=read<T>(f);

 while(!feof(f)){

  V v;
  K k=toMapEntry(t,v);

  mapPut<K,V>(m,k,v);
  t=read<T>(f);
 }

 return m;
}*/


/*
template<typename K,typename T>
struct Map
{
};

template<typename K,typename T>
Map<K,T> map()
{
   //return {};
}

template<typename K,typename T>
T* mapGet(Map<K,T>& m,K k)
{
   return NULL;
}

template<typename K,typename T>
T* mapPut(Map<K,T>& m,K k,T v)
{
   return NULL;
}

template<typename K,typename T>
bool mapContains(Map<K,T>& m,K k)
{
   return false;
}

template<typename K,typename T>
T mapRemove(Map<K,T>& m,K k)
{
   T t;
   return t;
}

template<typename K,typename T>
void mapRemoveAll(Map<K,T>& m)
{
}

template<typename K,typename T>
int mapSize(Map<K,T> m)
{
   return arrSize(m.keys);
}

template<typename K,typename T> bool mapHasNext(Map<K,T>& m)
{
   return m.curr<arrSize(m.keys);
}

template<typename K,typename T> K mapNextKey(Map<K,T>& m)
{
   return NULL;
}

template<typename K,typename T> T* mapNextValue(Map<K,T>& m)
{
   return NULL;
}


template<typename K,typename T> void mapReset(Map<K,T>& m)
{
}

template<typename K,typename T> void mapSortByKeys(Map<K,T>& m,int cmpKK(K,K))
{
}

template<typename K,typename T> void mapSortByValues(Map<K,T>& m,int cmpTT(T,T))
{
}*/




#endif
