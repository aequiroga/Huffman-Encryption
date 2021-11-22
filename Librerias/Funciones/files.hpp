#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include<strings.h>
#include <stdio.h>
#include "../TAD/Arr.hpp"



template<typename T> T read(FILE* f)
{
   T buff;
   fread(&buff, sizeof(T), 1, f);
   return buff;
}
template<typename T> void write(FILE* f, T v){

   fwrite(&v, sizeof(T), 1, f);
}
/////////////////////////////////////////////////////////////////////////
template<typename T>void read(FILE* f,Arr<T>& array, unsigned int n){

   fread(array.arr,sizeof(T),n,f);
}
//
template<typename T>void write(FILE* f,Arr<T>& array,unsigned int n){

   fwrite(array.arr,sizeof(T),n,f);
}
//////////////////////////////////////////////////////////////////////////

template<typename T> void seek(FILE* f, int n)
{
   fseek(f,n*sizeof(T),SEEK_SET);
}

template<typename T> long fileSize(FILE* f)
{
   // tomo la posicion actual
   long curr=ftell(f);
   // muevo el puntero al final del archivo

	fseek(f,0,SEEK_END);  // SEEK_END hace referencia al final del archivo

	// tomo la posicion actual (ubicado al final)
   long ultimo=ftell(f);

   // vuelvo a donde estaba al principio
 	fseek(f,curr,SEEK_SET);

   return ultimo/sizeof(T);
}

template<typename T> long filePos(FILE* f)
{
   return ftell(f)/sizeof(T);
}


//(7) Muestra un archivo existente, segun la funcion tToString.
template<typename T>
void mFile(string nom,void tToString(T)){


 char nomArray[50];//char array.
 strcpy(nomArray,nom.c_str());

//leer el archivo
FILE* f=fopen(nomArray,"r+b");

   int j=0;
   cout<<"-----------"<<endl;cout<<" Registros:  "<<endl<<endl;

   T a=read<T>(f);

   while(!feof(f)){

    cout<<j<<"> "; tToString(a); cout<<endl;
    a=read<T>(f);
    j++;
   }

 cout<<endl<<"total registros:  "<<fileSize<T>(f); cout<<endl;cout<<"-------------------------"<<endl;

 fclose(f);
}

template<typename T>void pToString(T a){

 cout<<a; cout<<endl;
}

template<typename T>
void mFile(string nom){

 mFile<T>(nom,pToString);

}




#endif
