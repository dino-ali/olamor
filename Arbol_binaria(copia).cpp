#include<iostream>
#include<cmath>
#define SPACE 10
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
        return izq == NULL && der == NULL;
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
        Nodo* p = es_padre(d);  
        if(p != NULL){  
            if(p->getIzq() == NULL){  
                return false;
            }else{
                return p->getIzq()->getDato() == d;  
            }
        }
        return false;
    }

    bool isBalanced(Nodo* t){
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
    
    void t_izqOder(bool p, Nodo* pt, Nodo* z){  //Saber si el nodo que va a ser el nuevo hijo de pt va a la izquierda o derecha.
        if(p){
            pt->setIzq(z);
        }else{
            pt->setDer(z);
        }
    }
    
    Nodo* es_padre(int x, Nodo* t){
        if(t != NULL){  //Si el nodo existe
            if(t->getDato() == x){  //Si el nodo es la raíz, no tiene padre
                return NULL;
            }
            if(x<t->getDato()){  //Si el dato es menor al nodo, buscamos a la izquierda
                if(t->hasIzq()){  //Revisamos que exista el nodo izquierdo
                    if(t->getIzq()->getDato() == x){  //Si el nodo izquierdo es el dato, retornamos el nodo t 
                        return t;
                    }else{  //Si no, buscamos en el nodo izquierdo
                        Nodo* ni = t->getIzq();
                        return es_padre(x, ni);
                    }
                }
            }else{  //Si el dato es mayor al nodo, buscamos a la derecha
                if(t->hasDer()){  //Revisamos que exista el nodo derecho
                    if(t->getDer()->getDato() == x){  //Si el nodo derecho es el dato, retornamos el nodo t
                        return t;
                    }else{  //Si no, buscamos en el nodo derecho
                        Nodo* nd = t->getDer();
                        return es_padre(x, nd);
                    }
                }
            }
        }
        return NULL;
    }
    
    Nodo* es_padre(int x){
        return es_padre(x, root);
    }
    
    void addAVL(int d, Nodo* t, Nodo* pt){
        if(t == NULL){  //Caso base: Si el hijo de pt no existe, se coloca el dato nuevo dependiendo de si es mayor o menor que pt
            Nodo* n = new Nodo(d);
            if(d < pt->getDato()){
                pt->setIzq(n);
            }else{
                pt->setDer(n);
            }
        }else{  //Si no, se evalua si revisamos al lado izquierdo o derecho de t 
            if(d < t->getDato()){
                addAVL(d, t->getIzq(), t);
            }else{
                addAVL(d, t->getDer(), t);
            }
            
            //Balanceo
            if(!isBalanced(t)){
                
                bool p = isHijo_Izq(t->getDato());  //Revisamos si t es hijo izquierdo o derecho
                pt = es_padre(t->getDato());  //Obtenemos el padre de t
                
                if(isIzq_Heavy(t)){  //Si el lado izquierdo es el desbalanceado
                    Nodo* z = t->getIzq();
                    if(isHijo_Izq(d)){
                        //Rotación todo izquierda
                        t->setIzq(z->getDer());
                        z->setDer(t);
                        if(pt == NULL){
                            root = z;
                        }else{
                            t_izqOder(p, pt, z);
                        }
                    //Rotación desbalance en la izquierda pero dato insertado en la derecha
                    }else{
                        Nodo* ZD = z->getDer();
                        z->setDer(ZD->getIzq());
                        ZD->setIzq(z);
                        t->setIzq(ZD->getDer());
                        ZD->setDer(t);
                        t_izqOder(p, pt, ZD);
                    }
                }else{  //Si el lado derecho está desbalanceado
                    Nodo* z = t->getDer();
                    if(!isHijo_Izq(d)){
                        //Rotación todo derecha
                        t->setDer(z->getIzq());
                        z->setIzq(t);
                        if(pt == NULL){
                            root = z;
                        }else{
                            t_izqOder(p, pt, z);
                        }
                    //Rotación desbalance en la derecha pero dato insertado en la izquierda
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
    
    void addAVL(int d){
        if(root == NULL){  //Caso base: El dato agregado es la raiz
            root =  new Nodo(d);
        }else{
            addAVL(d, root, root);  //Si no, se hace recursividad desde la raiz   
        }
    }
    
};

int main(){
    Tree t = Tree();
    t.addAVL(2);
    t.addAVL(3);
    t.addAVL(5);
    t.addAVL(7);
    t.addAVL(9);
    t.addAVL(11);
    t.addAVL(13);
    t.addAVL(17);
    t.addAVL(19);
    t.addAVL(21);
    t.preorder();
    return 0;
}
