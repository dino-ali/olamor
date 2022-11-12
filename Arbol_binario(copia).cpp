#include<iostream>
#include<cmath>
using namespace std;

int max(int a, int b){
    if (a > b){
        return a;
    }else{
        return b;
    }
}

class Nodo{
    int dato;
    Nodo* izq;
    Nodo* der;

public:  
    Nodo(int i){
        dato = i;
        izq = NULL;
        der = NULL;
    }
    
    Nodo(){
        dato = 0;
        izq = NULL;
        der = NULL;
    }
    
    int getDato(){
        return dato;
    }
    
    Nodo* getIzq(){
    return izq;
    }
    
    Nodo* getDer(){
    return der;
    }
    
    void setDato(int i){
        dato = i;
    }
    
    void setIzq(Nodo* i){
        izq = i;
    }
    
    void setDer(Nodo* i){
        der = i;
    }
    
    bool isHoja(){
        if(izq == NULL && der == NULL)
            return true;
        
        return false;
    }
    
    bool hasIzq(){
        return izq!=NULL;
    }
    
    bool hasDer(){
        return der!=NULL;    
    }
};


class Tree{
    Nodo* root;
    
public:
    Tree(){
        root = NULL;
    }
    
    Nodo* getRt(){
      return root;
    }

    void addr(int d){
      if(root != NULL)
        addr(d, root, root);
      else
        root =  new Nodo(d);
    }
    
    void addr(int d, Nodo* t, Nodo* pt){
        if(t == NULL){
            Nodo* n = new Nodo(d);
            if(d < pt->getDato()){
                pt->setIzq(n);
            }else{
                pt->setDer(n);
            }
        }else{
            if(d < t->getDato()){
                addr(d, t->getIzq(), t);
            }else{
                addr(d, t->getDer(), t);
            }
        }
    }

    
    void preorder(){
      preorder(root);
    }
    
    void preorder(Nodo* r){
      if(r != NULL){
          cout<<r->getDato()<<"\t";
          preorder(r->getIzq());
          preorder(r->getDer());
      }
    }
    
    int getHeight(Nodo* t){
        if (t == NULL){
            return 0;
        }else{
            int i = getHeight(t->getIzq());
            int d = getHeight(t->getDer());
            int m = max(i,d);
            return m + 1;            
        }
    } 
    
    bool isIzq_Heavy(Nodo* t){
        if (getHeight(t->getIzq()) > getHeight(t->getDer())){
            return true;
        }
        return false;
    }
    
    bool isHijo_Izq(int d){
        Nodo* p = getParent(d, root);  
        if(p != NULL){  
            if(p->getIzq() == NULL){  
                return false;
            }else{
                return p->getIzq()->getDato() == d;  
            }
        }else{
            return false;
        }
    }

    bool isBalance(Nodo* t){
        int df = 0;
        if (t->hasDer() and t->hasIzq()){
            df = getHeight(t->getIzq()) - getHeight(t->getDer());
            df = abs(df);
        }
        if (df <= 1){
            return true;
        }
        return false;
    }
    
    void t_izqOder(bool p, Nodo* pt, Nodo* z){ 
        if(p){
            pt->setIzq(z);
        }else{
            pt->setDer(z);
        }
    }

    Nodo* getParent(int d, Nodo* t){
        if(t == NULL){
            return NULL;
        }else{
            if(t->getDato() == d){
                return NULL;
            }else{
                if (t->getDato() > d){
                    if (t->hasIzq()){
                        if (t->getIzq()->getDato() == d){
                            return t;
                        }
                        else{
                            return getParent(d, t->getIzq());
                        }
                    }else{  
                        return NULL;
                    }
                }else{
                    if (t->hasDer()){
                        if (t->getDer()->getDato() == d){
                            return t;
                        }
                        else{
                            return getParent(d, t->getDer());
                        }
                    }else{  
                        return NULL;
                    } 
                }
            }
        }

    }
    
    void addrAVL(int d){
        if(root == NULL){  
            root =  new Nodo(d);
        }else{
            addrAVL(d, root, root);   
        }
    }
    
    void addrAVL(int d, Nodo* t, Nodo* pt){
        
        if(t == NULL){ 
            Nodo* n = new Nodo(d);
            if(d < pt->getDato()){
                pt->setIzq(n);
            }else{
                pt->setDer(n);
            }
        }else{  
            if(d < t->getDato()){
                addrAVL(d, t->getIzq(), t);
            }else{
                addrAVL(d, t->getDer(), t);
            }
    
            if(!isBalance(t)){
                bool p = isHijo_Izq(t->getDato());  
                pt = getParent(t->getDato(), root);  
                if(isIzq_Heavy(t)){  
                    Nodo* z = t->getIzq();
                    if(isHijo_Izq(d)){
                        t->setIzq(z->getDer());
                        z->setDer(t);
                        if(pt == NULL){
                            root = z;
                        }else{
                            t_izqOder(p, pt, z);
                        }
                    }else{
                        Nodo* ZD = z->getDer();
                        z->setDer(ZD->getIzq());
                        ZD->setIzq(z);
                        t->setIzq(ZD->getDer());
                        ZD->setDer(t);
                        t_izqOder(p, pt, ZD);
                    }
                }else{ 
                    Nodo* z = t->getDer();
                    if(!isHijo_Izq(d)){
                        t->setDer(z->getIzq());
                        z->setIzq(t);
                        if(pt == NULL){
                            root = z;
                        }else{
                            t_izqOder(p, pt, z);
                        }
                    }else{
                        Nodo* ZI = z->getIzq();
                        z->setIzq(ZI->getDer());
                        ZI->setDer(z);
                        t->setDer(ZI->getIzq());
                        ZI->setIzq(t);
                        t_izqOder(p, pt, ZI);
                    }
                }
            }
        }
    }
    

    
};

int main(){
    
    Tree t = Tree();

    t.addrAVL(2);
    t.addrAVL(1);
    t.addrAVL(5);
    t.addrAVL(7);
    t.addrAVL(9);
    t.addrAVL(11);
    t.addrAVL(13);
    t.addrAVL(17);
    t.addrAVL(19);
    t.addrAVL(16);
    
    t.preorder();
    
    return 0;
}
