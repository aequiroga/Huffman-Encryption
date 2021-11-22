#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

using namespace std;

template <typename T>
int add(T arr[],unsigned int& len, T e) {
	arr[len] = e;
	len++;
	return len-1;
}

// [1|2|3|x|4]
template <typename T>
void insert(T arr[],int& len,T e,int p) {
	len++;
	for(int i=len; i!=p; i--) {
		arr[i] = arr[i-1];
	}
	arr[p] = e;
}

template <typename T>
T remove(T arr[],int& len, int p) {
	T e = arr[p];
	for(int i=p; i<len; i++) {
		arr[i] = arr[i+1];
	}
	len--;
	return e;
}

template <typename T,typename K>
int find(T arr[],int len,K k, int cmpTK(T,K)) {
	int pos = -1;
	for(int i=0;i<len;i++) {
		if(!(cmpTK(arr[i],k))) pos = i;
	}
	return pos;
}


template <typename T>
int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T)) {
	int pos = -1;
	if(len) {
		if(len>1){
			for(int i=0;i<len;i++) {
				if(cmpTT(arr[i],e)<0 && cmpTT(arr[i+1],e)>0 && pos == -1) {
				pos = i+1;
				insert<T>(arr,len,e,pos);
					//len++;
				}
			}
		}
		else {
			pos = cmpTT(arr[0],e)>0?1:0;
			insert<T>(arr,len,e,pos);
			}
	}
	else {
		pos = add<T>(arr,len,e);
	}
	return pos;
}


template <typename T>
void sort(T arr[],int len,int cmpTT(T,T)) {
	int x,y;
	T aux;
	for(x=0; x<len-1; x++) {
		for(y=0;y<len-1;y++) {
			if(cmpTT(arr[y],arr[y+1])>0) {
				aux = arr[y];
				arr[y] = arr[y+1];
				arr[y+1] = aux;
			}
		}
	}
}
#endif

