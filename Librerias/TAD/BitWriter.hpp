#include <iostream>
#include <math.h>
#include "../Funciones/files.hpp"

using namespace std;

struct BitWriter
{
    FILE* file;
    int bits[7];
    unsigned char byte; //Ultimo bit escrito
    int pos; //Pos vector
};

BitWriter bitWriter(FILE* f){
    BitWriter temp;
    temp.file = f;
    temp.pos = 0;
    return temp;
}

void bitWriterWrite(BitWriter& bw,int bit) {
    bw.bits[bw.pos] = bit; //Se escribe el bit
    //cout << bit;
    bw.pos++;
    if(bw.pos>7) { //Si se completo el byte, se lo escribe en el archivo
        //Para formar el bit, se obtiene el codigo del char que forman los bits en formato decimal.
        int charCode = 0;
        int exp = 0;
        for(int i=7;i>=0;i--) {
            charCode+= bw.bits[i]*pow(2,exp);
            exp++;
        }
    //cout << "/" << charCode << "/";
    bw.byte = charCode;
    write<unsigned char>(bw.file,bw.byte);
    bw.pos = 0;
    }
}

void bitWriterFlush(BitWriter& bw) {
    if(bw.pos!=0) {
        for(int i=bw.pos;i<8;i++) {
            bitWriterWrite(bw,0);
        }
    }
}
