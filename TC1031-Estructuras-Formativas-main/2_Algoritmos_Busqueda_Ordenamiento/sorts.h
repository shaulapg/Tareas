/*
 * sorts.h

 * Shaula Suhail Paz Garay
 * A01712013
 * 
 */

#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <list>

template <class T>
class Sorts{
    private:
    void swap(std::vector<T>&, int, int);

    public:
    void ordenaSeleccion(std::vector<T>&);
    void ordenaBurbuja(std::vector<T>&);
    void ordenaMerge(std::vector<T>&);
    void mergeSplit(std::vector<T> &, std::vector<T> &, int, int);
    void mergeArray(std::vector<T> &, std::vector<T> &, int, int, int);
    void copyArray(std::vector<T> &, std::vector<T> &, int, int);
    int busqSecuencial(const std::vector<T>&, int);
    int busqBinaria(const std::vector<T>&, int);
};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
void Sorts<T>::ordenaSeleccion(std::vector<T> &v){
	for(int i = 0; i < v.size() - 1; i++){
		int aux = i;
		for(int j = i + 1; j < v.size(); j++)
			if(v[aux] > v[j])
				aux = j;
	swap(v, i, aux);
	}
}

template <class T>
void Sorts<T>::ordenaBurbuja(std::vector<T>&v){
    for (int i = v.size() - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (v[j] > v[j + 1])
				swap(v, j, j + 1);
}

template <class T>
void Sorts<T>::ordenaMerge(std::vector<T>&v){
    int low = 0, high = v.size() - 1, mid;
    std::vector<T> tmp(v.size());
    mergeSplit(v, tmp, 0, v.size() - 1);
}

template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	int mid;

	if ((high - low) < 1)
		return;
	mid = (high + low) / 2;
	mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copyArray(A, B, low, high);
}

template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
	int i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid &&j <= high) {
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid)
		for (; j <= high; j++)
			B[k++] = A[j];
	else
		for (; i <= mid; i++)
			B[k++] = A[i];
}

template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++)
		A[i] = B[i];
}

template <class T>
int Sorts<T>::busqSecuencial(const std::vector<T> &v, int busc){
    for(int i = 0; i < v.size(); i++)
        if(v[i] == busc)
            return i;
    return -1;
}

template <class T>
int Sorts<T>::busqBinaria(const std::vector<T>&v, int busc){

    int low = 0, high = v.size() - 1, mid;

    while(low <= high){
        mid = (low + high) / 2;
        if (v[mid] > busc)
            high = mid - 1;
        else if(v[mid] < busc)
            low = mid + 1;
        else
            return mid;       
    }
	return -1;
}

#endif