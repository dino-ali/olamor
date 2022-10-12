// ----------------------------------------------------------------- BINARIO

// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

using namespace std;

class Node{
  char data;
  Node* izq;
  Node* der;
  
public:

  Node(){
      data=' ';
      izq = NULL;
      der =  NULL;
  }

  Node(char d){
      data=d;
      izq = NULL;
      der =  NULL;
  }
  
  char getData(){
      return data;
  }
  
  Node* getIzq(){
      return izq;
  }
  
  Node* getDer(){
      return der;
  }
  
  void setIzq(Node* iz){
      izq =  iz;
  }
  
  void setDer(Node* de){
      der =  de;
  }
  
  bool hasIzq(){
      return izq!=NULL;
  }
  
  bool hasDer(){
      return der!=NULL;
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
      Node* n = new Node('0');
      root = n;
  }
  
  void add(char d){
      Node* n = new Node(d);
      Node* t = root;
      bool found = false;
      while(!found){
        if(t->hasDer()){
            t =  t->getDer();
        }else{
            t->setDer(n);
            found=true;
        }   
          
      }
/*
      while(!found){
          if(t->getData() < n->getData()){
            if(t->hasDer()){
                t =  t->getDer();
            }else{
                t->setDer(n);
                found=true;
            }   
          }else{
            if(t->hasIzq()){
                t =  t->getIzq();
            }else{
                t->setIzq(n);
                found=true;
            } 
          }
      }
 */ 
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
    
  void addr(char d){
      if(root != NULL)
        addr(d, root, root);
      else
        root =  new Node(d);
    }

    void addr(char d, Node* t, Node* pt){
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

    
    
};

int main()
{
    
    Tree t;
    t.add('D');
    t.add('a');
    t.add('v');
    t.add('i');
    t.add('d');
    
    t.preorder();
    
    return 0;
}


// ----------------------------------------------------------------- CON DIFERENTES RAMAS

#include<iostream>
#include<string>
#include<list>

using namespace std;

class Node{
  char data;
  list<Node*> x;

public:

  Node(){
      data =' ';
      x = {};
  }

  Node(char d){
      data=d;
      x = {};
  }
  
  char getData(){
      return data;
  }
  
  list<Node*> getX(){
      return x;
  }
  
  void setX(list<Node*> y){
      x = y;
  }
  
    
};

class Tree{
  Node* root;

public:
  Tree(){
      Node* n = new Node('0');
      root = n;
  }
  
  void add(char d){
      Node* n = new Node(d);
      Node* t = root;
      bool found = false;
      
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
    
  void addr(char d){
      if(root != NULL)
        addr(d, root, root);
      else
        root =  new Node(d);
    }

    void addr(char d, Node* t, Node* pt){
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

    
    
};

int main()
{
    
    Tree t;
    
    string a = "David";
    string b = "Juan";
    for (int i = 0; i < a.length(); i++){
        t.addr(a[i]);
    }
    
    for (int i = 0; i < b.length(); i++){
        t.addr(b[i]);
    }    
    
    t.preorder();
    
    return 0;
}
