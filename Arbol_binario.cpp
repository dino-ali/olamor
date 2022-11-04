/// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include <cmath>

using namespace std;

int max(int a, int b){
    if (a > b){
        return a;
    }else{
        return b;
    }
}

class Node{
  int data;
  Node* izq;
  Node* der;
  Node* pad;
  
public:

  Node(){
      data=0;
      izq = NULL;
      der =  NULL;
      pad = NULL;
  }

  Node(int d){
      data=d;
      izq = NULL;
      der =  NULL;
      pad = NULL;
  }
  
  int getData(){
      return data;
  }
  
  Node* getIzq(){
      return izq;
  }
  
  Node* getDer(){
      return der;
  }
  
  Node * getPad(){
      return pad;
  }
  
  void setIzq(Node* iz){
      izq =  iz;
  }
  
  void setDer(Node* de){
      der =  de;
  }
  
  void setPad(Node* pa){
      pad = pa;
  }
  
  bool hasIzq(){
      return izq!=NULL;
  }
  
  bool hasDer(){
      return der!=NULL;
  }
  
  bool hasPad(){
      return pad!=NULL;
  }
  
  bool isHoja(){
      if(izq == NULL && der == NULL)
        return true;
        
      return false;
  }
    
};

class Tree{
  Node* root;

public:
  Tree(){
      root = NULL;
  }
  
  Node* getRt(){
      return root;
  }
  
  void add(int d){
      Node* n = new Node(d);
      if(root == NULL){
          root = n;
          n->setPad(root);
      }else{
          Node* t = root;
          bool found = false;
          while(!found){
              if(t->getData() < n->getData()){
                if(t->hasDer()){
                    t =  t->getDer();
                }else{
                    t->setPad(t);
                    t->setDer(n);
                    found=true;
                }   
              }else{
                if(t->hasIzq()){
                    t =  t->getIzq();
                }else{
                    t->setPad(t);
                    t->setIzq(n);
                    found=true;
                } 
              }
          }
      }
  }

  void preorder(){
      preorder(root);
  }

  void preorder(Node* r){
      if(r != NULL){
          cout<<r->getData()<<"\t";
          preorder(r->getIzq());
          preorder(r->getDer());
      }
  }
    
    void addr(int d){
      if(root != NULL)
        addr(d, root, root);
      else
        root =  new Node(d);
    }

    void addr(int d, Node* t, Node* pt){
        if(t == NULL){
            Node* n = new Node(d);
            if(d < pt->getData()){
                pt->setIzq(n);
            }else{
                pt->setDer(n);
            }
        }else{
            if(d < t->getData()){
                addr(d, t->getIzq(), t);
            }else{
                addr(d, t->getDer(), t);
            }
        }
    }

    int getHeight(Node* t){
        if (t == NULL){
            return 0;
        }else{
            int i = getHeight(t->getIzq());
            int d = getHeight(t->getDer());
            int m = max(i,d);
            return m + 1;            
        }
    }   
    
    bool isBalance(Node* t){
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
    
    bool isIzqHeavy(Node* t){
        if (getHeight(t->getIzq()) > getHeight(t->getDer())){
            return true;
        }
        return false;
    }
    
    Node* getParent(int d, Node* t){
        if(t == NULL){
            return NULL;
        }else{
            if(t->getData() == d){
                return NULL;
            }else{
                if (t->getData() > d){
                    if (t->hasIzq()){
                        if (t->getIzq()->getData() == d){
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
                        if (t->getDer()->getData() == d){
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
    
    bool isHijIzq(int d){
        Node* h = root;
        if (h == NULL){
            return false;
        }else{
            if(h->getData() == d){
                return false;
            }else{
                if (h->getData() < d){
                    return false;
                }else{
                    while(h->getData() > d){
                        if(h->hasIzq()){
                            if(h->getIzq()->getData() == d){
                                return true;
                            }else{
                                h = h->getIzq();
                            }
                        }else{
                            break;
                        }
                    }
                }    
            }
        }
    }
    
    void addrAVL(int d, Node* t, Node* pt){
        
        if (t == NULL){
            Node* n = new Node(d);
            if(d < pt->getData()){
                pt->setIzq(n);
            }else{
                pt->setDer(n);
            }
        }else{
            if(d < t->getData()){
                addrAVL(d, t->getIzq(), t);
            }else{
                addrAVL(d, t->getDer(), t);
            }
            
            
            if(!isBalance(t)){
                if(isIzqHeavy(t)){
                    if(isHijIzq(d)){
                        Node* z = t->getIzq();
                        pt = getParent(d, t);
                        t->setIzq(z->getDer());
                        z->setDer(t);
                        if (pt == NULL){
                            root = z;
                        }else{
                            pt -> setIzq(z);
                        }
                    }
                }
            }
        }
    }
};

int main()
{
    
    Tree t;
    t.addr(18);
    t.addr(12);
    t.addr(11);
    t.addr(10);
    t.addr(24);
    
    t.preorder();
    
    
    int df = t.getHeight(t.getRt()->getIzq()) - t.getHeight(t.getRt()->getDer());
    cout << endl << df << endl;
    cout << t.isBalance(t.getRt()); 
    cout << endl << t.isHijIzq(12);
}

