#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

//=======[Tokens]=======

// 1) Cuenta la cantidad tokens que el separador sep genera en s.
int tokenCount(string s, char sep){
 int i=charCount(s,sep);

 return  s==""? 0: i+1;
}


// 2) Retorna el i-ésimo token de la cadena tokenizada s.
string getTokenAt(string s, char sep, int i){

 return i==0 and tokenCount(s,sep)==1? s: i==0? substring(s,0, indexOf(s, sep)): i==charCount(s,sep)? substring(s,indexOfN(s,sep,i)+1): substring(s,indexOfN(s,sep,i)+1,indexOfN(s,sep,i+1));
}

// 3) Agrega el token t al final de la cadena s.
void addToken(string& s, char sep, string t){

 s=(s==""?t:s+sep+t);
}

// 4) Remueve de s el token ubicado en la posicion i.
void removeTokenAt(string& s, char sep, int i){

s=(i==0 and tokenCount(s,sep)==1? "": i==0? substring(s,indexOf(s, sep)+1):i==charCount(s,sep)? substring(s,0,indexOfN(s,sep,i)): substring(s,0,indexOfN(s,sep,i))+substring(s,indexOfN(s,sep,i+1)));
}

// 5) Reemplaza por t el token de s ubicado en la posición i.
void setTokenAt(string& s,char sep,string t,int i){

 if(i==0){

  removeTokenAt(s,sep,i);

  s=(s==""? t: t+sep+s);
 }
 else{

  if(i==charCount(s,sep)){

   removeTokenAt(s,sep,i);
   s=s+sep+t;
  }
  else{

   s=substring(s,0,indexOfN(s,sep,i))+sep+t+substring(s,indexOfN(s,sep,i+1));
  }
 }

}

 // 6) Determinar la posición que el token t ocupa dentro de la cadena s,o un valor negativo si s no contiene a t.
int findToken(string s,char sep,string t){

 int i;

 for(i=0;i<tokenCount(s,sep);i++){

   if( getTokenAt(s,sep,i)==t){

    return i;
   }
 }

 return -1;
}



/*
// --[Funciones Token]--

int tokenCount(string s,char sep) // ok
{
   if(length(s)==0)
   {
      return 0;
   }
   else
   {
      return charCount(s,sep)+1;
   }
}

// pablo|juan|pedro|carlos
string getTokenAt(string s,char sep, int p)  // ok
{
   int d=(p==0)?0:indexOfN(s,sep,p)+1;
   int h=(p==tokenCount(s,sep)-1)?length(s):indexOfN(s,sep,p+1);
   return substring(s,d,h);
}

void addToken(string& s,char sep,string t) // ok
{
   if(tokenCount(s,sep)==0)
   {
      s=t;
   }
   else
   {
      s+=sep+t;
   }
}

string removeTokenAt(string& s,char sep, int p) //  ok
{
   string ret="";
   string ns="";
   int n=tokenCount(s,sep);
   for(int i=0; i<n; i++)
   {
      string tk = getTokenAt(s,sep,i);

      if( i!=p )
      {
         addToken(ns,sep,tk);
      }
      else
      {
         ret=tk;
      }
   }

   s=ns;
   return ret;
}

void setTokenAt(string& s,char sep, string t,int p) // ok
{
   string ret="";
   string ns="";
   int n=tokenCount(s,sep);
   for(int i=0; i<n; i++)
   {

      if( i!=p )
      {
         string tk = getTokenAt(s,sep,i);
         addToken(ns,sep,tk);
      }
      else
      {
         addToken(ns,sep,t);
      }
   }

   s=ns;

}

int findToken(string s,char sep, string t)
{
   int n=tokenCount(s,sep);
   for(int i=0;i<n;i++)
   {
      if( t==getTokenAt(s,sep,i) )
      {
         return i;
      }
   }

   return -1;
}

// --[/Funciones Token]--

*/
#endif
