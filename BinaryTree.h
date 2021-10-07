#include <iostream>
using namespace std;
#include "Node.h"
template<typename T>
class BinaryTree{
    private:
        Node<T>*m_pRoot;
    public:
        BinaryTree(){
            this->m_pRoot=0;
        }
        void insert(T value){
            if(!this->m_pRoot){
                this->m_pRoot=new Node<T>(value);
                return;
            }
            else{
                Node<T>*pAux=this->m_pRoot;
                Node<T>*pAuxAntes;
                while(pAux){
                    if(pAux->value==value)return;
                    pAuxAntes=pAux;
                    pAux=pAux->m_pSon[pAux->value<value];
                }
                pAuxAntes->m_pSon[pAuxAntes->value<value]=new Node<T>(value);
                
            
            }
        }
        void insertRecursive(T value,Node<T>*&pAux){
            if(!pAux){
                pAux=new Node<T>(value);
                return;
            }
            else{
                insertRecursive(value,pAux->m_pSon[pAux->value<value]);
            }
        }
        void insertRecursive(T value){
            insertRecursive(value,this->m_pRoot);
        }
        void printPreorden(Node<T>*pAux){
            if(!pAux)return;
            cout<<pAux->value<<endl;
            printPreorden(pAux->m_pSon[0]);
            printPreorden(pAux->m_pSon[1]);
        }
        void printPreorden(){
            printPreorden(this->m_pRoot);
        }
        void printInorden(Node<T>*pAux){
            if(!pAux)return;
            printInorden(pAux->m_pSon[0]);
            cout<<pAux->value<<endl;
            printInorden(pAux->m_pSon[1]);
        }
        void printInorden(){
            printInorden(this->m_pRoot);
        }
        void printPostorden(Node<T>*pAux){
            if(!pAux)return;
            printPostorden(pAux->m_pSon[0]);
            printPostorden(pAux->m_pSon[1]);
            cout<<pAux->value<<endl;
        }
        void printPostorden(){
            printPostorden(this->m_pRoot);
        }
        bool findRecursive(T value,Node<T>*pAux){
            if(!pAux)return false;
            if(pAux->value==value)return true;
            else findRecursive(value,pAux->m_pSon[pAux->value<value]);
        }
        bool findRecursive(T value){
            return findRecursive(value,this->m_pRoot);
        }
        bool findIterative(T value){
            Node<T>*pAux=this->m_pRoot;
            while(pAux){
                if(pAux->value==value)return true;
                pAux=pAux->m_pSon[pAux->value<value];
            }
            return false;
        }
        T getPadre(T value){
            if(!this->m_pRoot||!findIterative(value)||value==this->m_pRoot->value)return -1;
            Node<T>*pAux=this->m_pRoot;
            Node<T>*pAuxAntes;
            while(pAux){
                pAuxAntes=pAux;
                pAux=pAux->m_pSon[pAux->value<value];
                if(pAux->value==value)return pAuxAntes->value;
            }
        }
        T getHermano(T value){
            if(!this->m_pRoot||!findIterative(value)||value==this->m_pRoot->value)return -1;
            Node<T>*pAux=this->m_pRoot;
            //Node<T>*pAuxAntes;
            while(pAux){
                //pAuxAntes=pAux;
                //pAux=pAux->m_pSon[pAux->value<value];
                if(pAux->m_pSon[pAux->value<value]->value==value && pAux->m_pSon[pAux->value>value])return pAux->m_pSon[pAux->value>value]->value;
                if(!pAux->m_pSon[pAux->value>value]) return -1;
                pAux=pAux->m_pSon[pAux->value<value];
            }
        }
};
