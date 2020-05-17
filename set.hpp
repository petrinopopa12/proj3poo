//
//  set.hpp
//  proj3poo
//
//  Created by Petrino Popa on 14/05/2020.
//  Copyright © 2020 Petrino Popa. All rights reserved.
//


#ifndef set_hpp
#define set_hpp
#include <iostream>
#include <fstream>
using namespace std;

#include <stdio.h>

template <class F>
class Comparator /* <int> */ {
    bool ok = false;
public:
    bool checkPar(F a, F b){
        if(a%2 == b%2) {
            ok = true;
            return true; }
        return false;
    }
};

template <class T, class F = Comparator<T>>
class Set {
    int s_size;
    T *s_set;
    
public:
    
    Set();
    Set(int ,int s[]);
    ~Set();
    Set(const Set& s);
    Set operator=(const Set &s);
    void add(T );
    int getSize();
    bool checkElem(T );
    void remove();
    void print();
    T & operator[](const int index);
    
};

//initializare fara parametrii
template <class T, class F>
Set<T,F>::Set() {
    s_size = 0;
    s_set = new int [s_size];
    for(int i=0;i<s_size;i++)
        s_set[i] = 0;
}

//initializare
template <class T, class F>
Set<T,F>::Set(int size,int s[]) {
    s_size = size;
    s_set = new int [s_size];
    for(int i=0;i<s_size;i++)
        s_set[i] = s[i];
}

//destructor pentru set
template <class T, class F>
Set<T,F>::~Set() {
    delete s_set;
}

//copy constructor
/*template <class T, class F>
Set<T,F>::Set(const Set& s) {
    s_set=new int [s_size];
    for(int i=0;i<s_size;i++)
        s_set[i] = s[i];
}*/

//constructor de atribuire
template <class T, class F>
Set<T,F> Set<T,F>::operator= (const Set &s) {
    delete s_set;
    s_size = s.getSize();
    s_set = new int [s_size];
    for(int i=0;i<s_size;i++)
        s_set[i]=s.s_set[i];
}

//constructor pt adaugarea unui element
template <class T, class F>
void Set<T,F>::add(T x) {
    T * s = new T[s_size + 1];
    for (int i = 0; i < s_size; i++)
    {
        s[i] = s_set[i];
    }
    s_size++;
    delete s_set;
    s_set = s;
    s_set[s_size - 1] = x;
}

// constructor pentru aflarea marimii setului
template <class T, class F>
int Set<T,F>::getSize() {
    return this->s_size;
}

//constructor pentru a verifica daca un element se afla in set
template <class T, class F>
bool Set<T,F>::checkElem(T x) {
    for(int i=0;i<s_size;i++)
        if(s_set[i] == x)
            return true;
    return false;
}

//constructor pentru stergerea unui element din set
template <class T, class F>
void Set<T,F>::remove() {
    T * s = new T[s_size];
    for (int i = 0; i < s_size; i++)
    {
        s[i] = s_set[i];
    }
    delete s_set;
    s_set = s;
    s_set[s_size - 1] = NULL;
    s_size--;
}

//supraincarcarea operatorului de afisare
template <class T, class F>
ostream &operator <<(ostream &g,Set<T,F>& s){
    for(int i=0;i<s.getSize();i++)
        g << s[i] << " ";
    g << endl;
    return g;
}

//functie pentru afisat setul
template <class T, class F>
void Set<T,F>::print() {
    for(int i=0;i < s_size;i++)
        cout<<s_set[i]<<" ";
}

//supraincarcarea parantezelor []
template <class T, class F>
T & Set<T,F>::operator[](const int index){
    return s_set[index];
}


#endif 
