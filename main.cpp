//
//  main.cpp
//  proj3poo
//
//  Created by Petrino Popa on 13/05/2020.
//  Copyright © 2020 Petrino Popa. All rights reserved.
//

#include <iostream>
#include <cassert>
using namespace std;

#include "set.hpp"

int main() {
    
    int s[10], size;
    size=5;
    for(int i=0;i<size;i++)
        s[i] = i;
    Set<int,int> s1 = Set<int,int>(size,s);
    s1.print();
    cout<<endl;
    s1.add(5);
    s1.print();
    cout<<endl;
    s1.remove();
    s1.print();
    cout<<endl;
    assert(s1.checkElem(4) == 1);
    assert(s1.getSize()==5);
    cout<<"codul este functional"<<endl;
    cout<<s1;
    cout<<s1[1]<<endl;
    return 0;
    
}
