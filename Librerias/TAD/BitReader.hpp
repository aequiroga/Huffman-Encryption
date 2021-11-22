#include <iostream>
#include "../Funciones/files.hpp"

struct BitReader
{
    FILE* file;
    unsigned char byte; //Ultimo bit escrito
    int pos; //Pos vectorde bits
};

BitReader bitReader(FILE* f) {
    BitReader br;
    br.file = f;
    br.pos = -7;
    return br;
}


int bitReaderRead(BitReader& br) {
    int bit = 0;
    unsigned int mask = 128; // La mascara inicia en |1000|0000|, y se desplaza para ir obteniendo cada bit
    if(br.pos == -7 || br.pos > 7){
        //cout << " / " << endl;
        br.byte = read<unsigned char>(br.file);
        br.pos = 0;
    }

    for(int i = 0; i<br.pos ; i++) {//Desplazamiento del archivo
        mask = mask>>1;
    }

    if(br.byte&mask) bit = 1; //La mascara devuelve un 1
    br.pos++;
    //cout << "pos: " << br.pos << endl;
    return bit;
}
