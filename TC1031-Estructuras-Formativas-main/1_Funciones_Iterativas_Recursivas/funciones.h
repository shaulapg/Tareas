/*
 * funciones.h
 
 * Shaula Suhail Paz Garay
 * A01712013
 * 
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>

class Funciones{
    public:

    int sumaIterativa(int n){
        int sum = 0;
        for(int i = 1; i <= n; i++)
            sum += i;
        return sum;
    }

    long sumaRecursiva(int n){
        if(n <= 0)
            return 0;
        else
            return n + sumaRecursiva(n - 1);
    }

    int sumaDirecta(int n){
        return n * (n + 1) / 2;
    }
};

#endif