#include <iostream>
#include <iostream>
#include <string>

#include <math.h> // Se incluye para log()
#include "Librerias/TAD/Arr.hpp"
#include "Librerias/TAD/Map.hpp"
#include "Librerias/TAD/List.hpp"
#include "Librerias/TAD/Stack.hpp"
#include "Librerias/TAD/Queue.hpp"
#include "Librerias/TAD/BitWriter.hpp"
#include "Librerias/TAD/BitReader.hpp"
#include "Librerias/TAD/HuffmanTree.hpp"
//#include "Librerias/TAD/HuffmanSetup.hpp"
#include "Librerias/Funciones/files.hpp"
#include "Librerias/Funciones/strings.hpp"
#include "Librerias/Funciones/arrays.hpp"


using namespace std;

struct Tabla {
    unsigned long int n;
    string cod;
};

/*struct Info {
   unsigned char c;
   unsigned int n;
       Info* izq;
       Info* right;
};*/

struct RegistroT {
    unsigned char c;
    unsigned char h;
    string codHuff;
};

//Funciones CMP
int cmpA(HuffmanTreeInfo nodo,HuffmanTreeInfo valor) {
    int retornar=-1;
    if(nodo.n==valor.n) {
        retornar=0;
    }
    return retornar;
}

int cmpInfo(HuffmanTreeInfo a, HuffmanTreeInfo b) {
    return (a.n>b.n)?1:-1;
}

bool endsWith(string fName,string cadena) {
    int posicion=lastIndexOf(fName,cadena[0]);
    string subcadena=substring(fName,posicion);
    return subcadena==cadena?true:false;
}

//Utilidades
void pantallaCarga(unsigned long long actual, unsigned long long total) {
    if(((actual*100/total)) > ((actual-1)*100/total)) cout << "\r" << (actual*100/total) << "% completado";
}

void borrarOriginal(string fName) {
    cout << "Desea borrar el archivo original (" << fName << ")?" << endl << "S/N" << endl;
    if(getchar()=='S') remove(fName.c_str());
}

bool fileExists(string fName) {
    bool x;
    FILE* f = fopen(fName.c_str(), "r+b");
    if(!f) {
        x = false;
        cout << "El archivo ingresado no existe" << endl;
    }
    else x = true;
    fclose(f);
    return x;
}

//Funciones de compresion
void contabilizarOcurrencias(string fName,Tabla tabla[]) {
    FILE* f = fopen(fName.c_str(),"r+b");
    unsigned int x;

    for(int i = 0; i!=256; i++) tabla[i].n=0;

    while(!feof(f)) {
        x = read<unsigned char>(f);
        if(!feof(f))tabla[x].n++;
    }

    fclose(f);
}

void completarListaEnlazada(List<HuffmanTreeInfo>& lista,Tabla tabla[]) {
    for(int i=0; i<256; i++) {
        if(tabla[i].n>0) {
            HuffmanTreeInfo p = *huffmanTreeInfo(i,tabla[i].n,NULL,NULL);
            /*p.c = i;
            p.n = tabla[i].n;
            p.left = NULL;
            p.right = NULL;*/
            listOrderedInsert<HuffmanTreeInfo>(lista,p,cmpInfo);
        }
    }
}

HuffmanTreeInfo padreDeHijos(HuffmanTreeInfo& a, HuffmanTreeInfo& b ) {
    HuffmanTreeInfo c = *huffmanTreeInfo(404,a.n+b.n,&a,&b);
    /*c.left = &a;
    c.right = &b;
    c.n = a.n+b.n;
    c.c = 404;*/

    return c;
}

/*HuffmanTreeInfo convertirListaEnArbol(List<HuffmanTreeInfo>& lista) {
    //Declaracion de variables
    HuffmanTreeInfo raiz;
    HuffmanTreeInfo* a;
    HuffmanTreeInfo* b;
    HuffmanTreeInfo c;

    listReset<HuffmanTreeInfo>(lista);
    //Para listas de un solo char
    if(listSize(lista)==1) {
        a = new HuffmanTreeInfo();//Raiz
        b = new HuffmanTreeInfo();//Hoja
        b = listNext(lista);
        a->n = b->n;
        a->left = b;
        raiz = *a;
    }
    //Mientras haya elementos en la lista, crear nodos del arbol
    else while(listHasNext(lista)) {
        a = new HuffmanTreeInfo();
        b = new HuffmanTreeInfo();
        c = padreDeHijos(*listNext(lista),*listNext(lista));

        pantallaCarga(i,listSize(lista));

        if(!listHasNext(lista)) raiz = c;
        else listOrderedInsert<HuffmanTreeInfo>(lista,c,cmpInfo);
    }
    //listReset<HuffmanTreeInfo>(lista);

    return raiz;
}*/

HuffmanTreeInfo convertirListaEnArbol(List<HuffmanTreeInfo>& lista)
{

    listReset<HuffmanTreeInfo>(lista);
    if(listSize(lista)==1) {//si hay un solo tipo de caracter en el archivo
        HuffmanTreeInfo* a;
        HuffmanTreeInfo* b;
        a = new HuffmanTreeInfo();//Raiz
        b = new HuffmanTreeInfo();//Hoja
        b = listNext(lista);
        a->n = b->n;// cantidad de ocurrencias
        a->left = b;
        a->right = NULL;
        listOrderedInsert<HuffmanTreeInfo>(lista,*a,cmpA);// se inserta la hoja creada
    }
    else{

        while(listHasNext(lista))
    {
        listReset<HuffmanTreeInfo>(lista);//reset de la lista para extraer los dos primeros de ella
        HuffmanTreeInfo* a = new HuffmanTreeInfo();//reservo espacio en memoria y apunto al mismo
        HuffmanTreeInfo* b = new HuffmanTreeInfo();//reservo espacio en memoria y apunto al mismo
        *a=*listNext<HuffmanTreeInfo>(lista);//copio el nodo de la lista al espacio reservado
        *b=*listNext<HuffmanTreeInfo>(lista);//copio el nodo de la lista al espacio reservado
        HuffmanTreeInfo c = padreDeHijos(*a,*b);
        listRemove<HuffmanTreeInfo,HuffmanTreeInfo>(lista,*a,cmpA);
        listRemove<HuffmanTreeInfo,HuffmanTreeInfo>(lista,*b,cmpA);
        listOrderedInsert<HuffmanTreeInfo>(lista,c,cmpInfo);
    }
    }
    listReset<HuffmanTreeInfo>(lista);
    return *listNext<HuffmanTreeInfo>(lista);
}

void asignarCodigoHuffman(HuffmanTreeInfo &raiz,Tabla tabla[]) {
    HuffmanTree arbol= huffmanTree(&raiz);
    string codHuffman="";
    while(huffmanTreeHasNext(arbol)) {
        HuffmanTreeInfo* p = huffmanTreeNext(arbol,codHuffman);
        tabla[p->c].cod=codHuffman;
    }
}


void generarArchivoComprimido(string fName,Tabla tabla[]) {
    //Declaracion de VARS
    FILE* archOg = fopen(fName.c_str(),"r+b");
    fName+=".huf";
    FILE* archNuevo = fopen(fName.c_str(),"w+b");
    BitWriter bw = bitWriter(archNuevo);

    //Escribir el primer byte y hallar el tamaño del archivo
    unsigned int hojas = 0;
    unsigned long long int tamanoArchivo=0;

    for(int i=0; i<256; i++) {
        if(tabla[i].n>0)
        {
            hojas++;
            tamanoArchivo += tabla[i].n;
        }
    }
    write<unsigned char>(archNuevo,hojas-1);

    //Escribir RegistrosT
    for(int a=0; a<256; a++) {
        if(tabla[a].n>0) {
            write<char>(archNuevo,(char)a);//Caracter
            write<char>(archNuevo,(char)length(tabla[a].cod));//Longitud

            int contador=0;
            for(int b=0; b<length(tabla[a].cod); b++) {
                if(contador==8)contador=0;
                bitWriterWrite(bw,charToInt(tabla[a].cod[b]));
                contador++;
            }
            if(contador<8)bitWriterFlush(bw);
        }
    }


    //Escribir tamaño del archivo
    write<unsigned long long int>(archNuevo,tamanoArchivo);

    //Escribir bits
    string codHuffman;
    unsigned char x;
    unsigned short contadorBits = 0;
    unsigned long long actualSize = 0;

    x = read<unsigned char>(archOg);
    while(!feof(archOg)) {
        for(int i=0; i<length(tabla[(int)x].cod); i++) {
            if(contadorBits==8) contadorBits=0;
            bitWriterWrite(bw,charToInt(tabla[(int)x].cod[i]));
            contadorBits++;
        }

        actualSize++;
        pantallaCarga(actualSize,tamanoArchivo);

        x = read<unsigned char>(archOg);
    }
    if(contadorBits<8) {
        bitWriterFlush(bw);
    }

    cout << endl << "Compresion exitosa";

    fclose(archOg);
    fclose(archNuevo);
}

void comprimir(string fName) {
    // Tabla de contadores
    Tabla tabla[256];

    // Paso 1
    cout << "Paso 1/4";
    contabilizarOcurrencias(fName,tabla);

    // Paso 2
    cout << "\rPaso 2/4";
    List<HuffmanTreeInfo> lista = list<HuffmanTreeInfo>();
    completarListaEnlazada(lista,tabla);

    // Paso 3
    cout << "\rPaso 3/4";
    HuffmanTreeInfo raiz = convertirListaEnArbol(lista);
    asignarCodigoHuffman(raiz,tabla);

    // Grabar
    cout << "\rPaso 4/4" << endl;
    generarArchivoComprimido(fName,tabla);
}

//Funciones de descompresion
RegistroT leerRegistroT(FILE* f) {
    RegistroT t;

    BitReader br = bitReader(f);
    t.c = read<unsigned char>(f);
    t.h = read<unsigned char>(f);
    for(int i=0; (int)i<t.h; i++) t.codHuff+=intToChar(bitReaderRead(br));

    return t;
}

void hallarHoja(HuffmanTreeInfo& raiz,HuffmanTreeInfo*& actual,RegistroT t) {
    int i=0;
    int j=0;
    HuffmanTreeInfo* nuevo;

    for(i=0; i<t.h; i++) {
        /*Leer bits
        Moverse en el arbol, y crear nodos requeridos
        Desplazar mascara
        */

        if(t.codHuff[i]=='0') {
            //Rama izquierda arbol
            if(!actual->left) {
                nuevo = huffmanTreeInfo(404,0,NULL,NULL);
                actual->left = nuevo;
            }
            actual = actual->left;
        }
        else if(t.codHuff[i]!='0') {
            //Rama derecha arbol
            if(!actual->right) {
                nuevo = huffmanTreeInfo(404,0,NULL,NULL);
                actual->right = nuevo;
            }
            actual = actual->right;
        }
        else cout << "Error en rearmado del arbol";
    }
    actual->c = t.c;
}

void procesarDatosComprimidos(FILE* archEntrada, FILE* archSalida, HuffmanTreeInfo raiz) {
    /*
    Leer bit
    Moverse en arbol
    Al llegar a una hoja escribir el char asociado
    */
    //Declaracion VARS
    BitReader br = bitReader(archEntrada);
    int bit;
    unsigned long long int contador = read<unsigned long long int>(archEntrada);//Almacena tamaño del archivo
    unsigned long long actualSize = 0;

    HuffmanTreeInfo* actual = new HuffmanTreeInfo();
    actual = &raiz;

    while(contador!=actualSize) {
        bit = bitReaderRead(br);
        if(bit!=0) actual = actual->right;
        else if(bit==0) actual = actual->left;
        else cout << "Error en descompresion del codigo";

        if(!actual->left && !actual->right) {
            write<unsigned char>(archSalida,actual->c);
            actual = &raiz;
            actualSize++;
            pantallaCarga(actualSize,contador);
        }
    }
}

void descomprimir(string fName) {
    //Archivos
    FILE* archEntrada = fopen(fName.c_str(),"r+b");

    //Declaracion de VARS
    unsigned long long int contador = read<unsigned char>(archEntrada);//Almacena cantidad de hojas
    char x;
    RegistroT t;//Informacion del .huf
    HuffmanTreeInfo raiz = *huffmanTreeInfo(404,0,NULL,NULL);//Nodo raiz
    HuffmanTreeInfo* actual = huffmanTreeInfo(404,0,NULL,NULL);//Nodo para recorrer el arbol

    //Armar el arbol
    cout << "Paso 1/2";
    for(int i=0; i<contador+1; i++) {
        //Leer y reiniciar variables
        actual = &raiz;
        t = leerRegistroT(archEntrada);
        hallarHoja(raiz,actual,t);
    }

    //Leer datos comprimidos
    cout << "\rPaso 2/2" << endl;
    fName = substring(fName,0,length(fName)-4);
    FILE* archSalida = fopen(("D " + fName).c_str(),"w+b");

    procesarDatosComprimidos(archEntrada,archSalida,raiz);
    cout << endl << "Descompresion exitosa, el nuevo archivo es: " << fName << endl;
    fclose(archSalida);
    fclose(archEntrada);
    borrarOriginal(fName+".huf");
}

int main(int argc,char** argv) {

    system("cls");
    string fName = argv[1];

    if( endsWith(fName,".huf")){
            if(fileExists(fName)) {
                cout << "Descomprimiendo " << fName << endl;
                descomprimir(fName);
            }
    }
    else if ( length(substring(fName,lastIndexOf(fName,'.')))>0 ) {
            if(fileExists(fName)){
                cout << "Comprimiendo " << fName << endl;
                comprimir(fName);
            }
    }
    else cout << "Ingrese un archivo valido";

    return 0;
}
