#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

using namespace std;

/* (0.1) Descripci�n: Muestra los elementos del array, hay que pasarle la funcion mostrarT.
 */
/////////////////////////////////
template <typename T> void mArray(T arr[], int len, void mostrarT(T))
{

   int i,j = 0;

   cout<<endl<<"---------------------"<<endl<<" Elementos del Array:"<<endl
         <<endl;

   for( i = 0; i<len; i++ )
   {
      if( i<1 )
      {

         cout<<j<<"> ";
         mostrarT(arr[i]);
      }
      else
      {

         cout<<endl;
         cout<<j<<"> ";
         mostrarT(arr[i]);
      }
      j++;
   }

   if( i==0 )
   {

      cout<<" No hay elementos"<<endl;
   }

   cout<<"---------------------"<<endl<<endl;
}

/* (0.2) Descripci�n: Muestra los elementos(string, double, int, etc) del array.
 */
template <typename T>
void mostrarPT(T t){

   cout<<t;
   cout<<endl;
}

/////////////////////////////////
template <typename T>
void mArray(T arr[], int len){

 mArray<T>(arr,len,mostrarPT);
}

/* (1) Descripci�n: Agrega el elemento e al final de arr incrementando
 * su longitud len.  Retorna: int � Posici�n del array donde qued� ubicado
 * el elemento que agregamos.
 */
/////////////////////////////
template <typename T> int add(T arr[], int& len, T e){

//arr[]: Array donde agregaremos un elemento.

//len: Longitud actual del array.

   arr[len] = e;
   len++;
   return len-1;
}


/* (2) Descripci�n: Inserta el elemento e en la posici�n p del array arr.
 *Desplaza los elementos ubicados a partir de p+1 e incrementa la longitud len.
 */
/////////////////////////////////
template <typename T> void insert(T arr[], int& len, T e, int p)
{

//p: Posici�n donde se insertar� el nuevo elemento.

   for( int i = len-1; i>=p; i-- )
   {

      arr[i+1] = arr[i];
   }

   arr[p] = e;

   len++;
}


/* (3) Descripci�n: Remueve el elemento ubicado en la posici�n p del array arr.
 Desplaza ubicados a partir de p y decrementa la longitud len. Retorna: T � Elemento que fue removido del array.
 */
//////////////////////////////
template <typename T> T remove(T arr[], int& len, int p)
{

//p: Posici�n cuyo elemento ser� removido.
   T t = arr[p];

   for( int i = p; i<len; i++ )
   {

      arr[i] = arr[i+1];
   }

   len--;

   return t;
}

/* (4) Descripci�n: Retorna la posici�n de la primera ocurrencia de k
  dentro de arr o un valor negativo si arr no contiene a k.
 */
//////////////////////////////
template <typename T, typename K> int find(T arr[], int len, K k,int cmpTK(T, K)){

   int i;

   for( i = 0; i<len and cmpTK(arr[i],k); i++ ){}

   return i<len?i:-1;
}

/* (5) Descripci�n: Inserta e dentro de arr seg�n el criterio de precedencia que
establece cmpTT, y retorna la posici�n donde dicho elemento qued� insertado.
El array arr debe estar ordenado o vac�o. Retorna: La posici�n de la primera
ocurrencia de k dentro de arr o un valor negativo si arr no contiene a k.
 */
//////////////////////////////
template <typename T> int orderedInsert(T arr[], int& len, T e, int cmpTT(T, T))
{

   int i;

   if( len==0 )
   {

      add<T>(arr,len,e);
      i = len-1;
   }
   else
   {

      for( i = 0; i<len; i++ )
      {

         if( cmpTT(arr[i],e)>0 )
         {

            insert<T>(arr,len,e,i);

            return i;
         }
      }

      if( i==len )
      {

         add<T>(arr,len,e);
         i = len-1;
      }
   }

   return i;
}


/* (6) Descripci�n: Ordena arr seg�n el criterio de precedencia que establece cmpTT.
 */
//////////////////////////////
template <typename T> void sort(T arr[], int len, int cmpTT(T, T))
{

   T aux;
   int i,ordenar = 1;

   while( ordenar>0 )
   {

      ordenar = 0;

      for( i = 0; i<len-1; i++ )
      {

         if( cmpTT(arr[i],arr[i+1])>0 )
         {

            aux = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = aux;
            ordenar++;
         }
      }
   }
}
//template <typename T>
//void sort(T arr[], int len, int cmpTT(T,T))
//{
//   T rez;
//   for(int x = 0; x != len-1;x++)
//   {
//      if(cmpTT(arr[x],arr[x+1]) > 0)
//      {
//         rez = arr[x];
//         arr[x] = arr[x+1];
//         arr[x+1] = rez;
//         x = -1;
//      }
//   }
//}

#endif
