#include <iostream>
#include <conio.h>
#include "BinaryTree.h"
using namespace std;
int main(){
    BinaryTree<int>test;
    test.insert(7);
    test.insert(8);
    test.insert(5);
    test.insert(4);
    test.insert(3);
    test.insert(10);
    test.insert(2);
    test.insert(6);
    
    cout<<"Imprimiendo en Preorden: "<<endl;
    test.printPreorden();
    cout<<"Imprimiendo en Inorden: "<<endl;
    test.printInorden();
    cout<<"Imprimiendo en Postorden: "<<endl;
    test.printPostorden();
    int a=7;
    (test.findIterative(a))?cout<<"Se encontro el numero "<<a<<" en el arbol binario"<<endl:cout<<"No se encontro el numero "<<a<<" en el arbol binario"<<endl;
    (nullptr==0)?cout<<"nullptr es igual a 0"<<endl:cout<<"nullptr no es igual a 0"<<endl;
    cout<<"El padre de "<<a<<" es "<<test.getPadre(a)<<endl;
    cout<<"El hermano de "<<a<<" es "<<test.getHermano(a)<<endl;
    getch();
 
    return 0;
}