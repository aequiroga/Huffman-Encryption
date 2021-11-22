

#ifndef HUFFMANTREE
#define HUFFMANTREE

#include "Stack.hpp"
using namespace std;

// Info de los nodos del arbol
struct HuffmanTreeInfo
{
   unsigned int c;
   unsigned long long int n;
   HuffmanTreeInfo* left;
   HuffmanTreeInfo* right;
};

HuffmanTreeInfo* huffmanTreeInfo(unsigned int c, unsigned long long n, HuffmanTreeInfo* left, HuffmanTreeInfo* right)
{
   HuffmanTreeInfo* node = new HuffmanTreeInfo();
   node->c=c;
   node->n=n;
   node->left=left;
   node->right=right;
   return node;
}


// ---------------------
// -- TAD HuffmanTree --

struct HuffmanTree
{
   Stack<HuffmanTreeInfo*> pila;
   Stack<string> pilaCod;
};

// init function
HuffmanTree huffmanTree(HuffmanTreeInfo* root)
{
   HuffmanTree tu;
   tu.pila = stack<HuffmanTreeInfo*>();
   tu.pilaCod = stack<string>();
   stackPush<string>(tu.pilaCod,"");
   stackPush<HuffmanTreeInfo*>(tu.pila,root);
   return tu;
}

bool huffmanTreeHasNext(HuffmanTree ht)
{
   return !stackIsEmpty<HuffmanTreeInfo*>(ht.pila);
}

HuffmanTreeInfo* huffmanTreeNext(HuffmanTree& tu,string& cod)
{
  // cout << "Entre a la funcion" << endl;
   bool hoja=false;
   HuffmanTreeInfo* p = NULL;
   string zz;

   while( !stackIsEmpty<HuffmanTreeInfo*>(tu.pila) && !hoja )
   {
      //cout << "Entre al while" << endl;
      p = stackPop<HuffmanTreeInfo*>(tu.pila);
      zz = stackPop<string>(tu.pilaCod);
      //cout << "Nodo: " << (char)p->c << "   " << p->n << endl;

      if( p->right!=NULL )
      {
         stackPush<HuffmanTreeInfo*>(tu.pila,p->right);
         stackPush<string>(tu.pilaCod,zz+"1");
      }

      if( p->left!=NULL )
      {
         stackPush<HuffmanTreeInfo*>(tu.pila,p->left);
         stackPush<string>(tu.pilaCod,zz+"0");
      }

      if( p->left==NULL && p->right==NULL)
      {
         hoja = true;
         cod.clear();
         cod.append(zz);
      }
      else
      {
         p = NULL;
      }
    //cout << "Stack size: " << stackSize(tu.pila) << endl;
   }
   return p;
}

HuffmanTreeInfo* huffmanTreeCreateDemoTree()
{
   // nivel 5 (ultimo nivel)
   HuffmanTreeInfo* nS = huffmanTreeInfo('A', 1, NULL, NULL);
   HuffmanTreeInfo* nR = huffmanTreeInfo('B', 1, NULL, NULL);
   HuffmanTreeInfo* nN = huffmanTreeInfo('C', 1, NULL, NULL);
   HuffmanTreeInfo* nI = huffmanTreeInfo('C', 1, NULL, NULL);

   // nivel 4
   HuffmanTreeInfo* a2 = huffmanTreeInfo('E', 2, nS, nR);

   HuffmanTreeInfo* a1 = huffmanTreeInfo('F', 2, nN, nI);
   HuffmanTreeInfo* nT = huffmanTreeInfo('G', 2, NULL, NULL);
   HuffmanTreeInfo* nE = huffmanTreeInfo('H', 2, NULL, NULL);
   HuffmanTreeInfo* nA = huffmanTreeInfo('I', 2, NULL, NULL);
   HuffmanTreeInfo* nU = huffmanTreeInfo('U', 1, NULL, NULL);

   // nivel 3
   HuffmanTreeInfo* nC = huffmanTreeInfo('J', 7, NULL, NULL);
   HuffmanTreeInfo* nM = huffmanTreeInfo('K', 5, NULL, NULL);
   HuffmanTreeInfo* nESP = huffmanTreeInfo('L', 5, NULL, NULL);
   HuffmanTreeInfo* a5 = huffmanTreeInfo('M', 4, a2, a1);
   HuffmanTreeInfo* a4 = huffmanTreeInfo('N', 4, nT, nE);
   HuffmanTreeInfo* a3 = huffmanTreeInfo('O', 3, nA, nU);

   // nivel 2
   HuffmanTreeInfo* a8 = huffmanTreeInfo('P', 12, nC, nM);
   HuffmanTreeInfo* nO = huffmanTreeInfo('Q', 11, NULL, NULL);
   HuffmanTreeInfo* a7 = huffmanTreeInfo('R', 9, nESP, a5);
   HuffmanTreeInfo* a6 = huffmanTreeInfo('S', 7, a4, a3);

   // nivel 1
   HuffmanTreeInfo* a10 = huffmanTreeInfo('T', 23, a8, nO);
   HuffmanTreeInfo* a9  = huffmanTreeInfo('U', 16, a7, a6);

   // nivel 0 (raiz)
   HuffmanTreeInfo* a11 = huffmanTreeInfo('X', 39, a10, a9);

   return a11;
}

void huffmanTreeDemo()
{
   // obtengo el arbol
   HuffmanTreeInfo* root = huffmanTreeCreateDemoTree();

   // recorro el arbol usando TAD HuffmanTree
   HuffmanTree ht = huffmanTree(root);

   string cod;
   while( huffmanTreeHasNext(ht) )
   {
      HuffmanTreeInfo* x = huffmanTreeNext(ht,cod);
      cout << x->c << ", ("<<x->n <<"), " << "[" << cod <<"]" << endl;
   }
}



#endif
