#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

using namespace std;

/* (0.1) Descripción: Muestra los elementos del array, hay que pasarle la funcion mostrarT.
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

/* (0.2) Descripción: Muestra los elementos(string, double, int, etc) del array.
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

/* (1) Descripción: Agrega el elemento e al final de arr incrementando
 * su longitud len.  Retorna: int – Posición del array donde quedó ubicado
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


/* (2) Descripción: Inserta el elemento e en la posición p del array arr.
 *Desplaza los elementos ubicados a partir de p+1 e incrementa la longitud len.
 */
/////////////////////////////////
template <typename T> void insert(T arr[], int& len, T e, int p)
{

//p: Posición donde se insertará el nuevo elemento.

   for( int i = len-1; i>=p; i-- )
   {

      arr[i+1] = arr[i];
   }

   arr[p] = e;

   len++;
}


/* (3) Descripción: Remueve el elemento ubicado en la posición p del array arr.
 Desplaza ubicados a partir de p y decrementa la longitud len. Retorna: T – Elemento que fue removido del array.
 */
//////////////////////////////
template <typename T> T remove(T arr[], int& len, int p)
{

//p: Posición cuyo elemento será removido.
   T t = arr[p];

   for( int i = p; i<len; i++ )
   {

      arr[i] = arr[i+1];
   }

   len--;

   return t;
}

/* (4) Descripción: Retorna la posición de la primera ocurrencia de k
  dentro de arr o un valor negativo si arr no contiene a k.
 */
//////////////////////////////
template <typename T, typename K> int find(T arr[], int len, K k,int cmpTK(T, K)){

   int i;

   for( i = 0; i<len and cmpTK(arr[i],k); i++ ){}

   return i<len?i:-1;
}

/* (5) Descripción: Inserta e dentro de arr según el criterio de precedencia que
establece cmpTT, y retorna la posición donde dicho elemento quedó insertado.
El array arr debe estar ordenado o vacío. Retorna: La posición de la primera
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


/* (6) Descripción: Ordena arr según el criterio de precedencia que establece cmpTT.
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
