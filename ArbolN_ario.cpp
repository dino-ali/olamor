#include<iostream>
#include <stack>        
#include <vector>

using namespace std;

class Node{
  int data;
  vector<Node*> hij;
  
public:

  Node(){
      data=0;
      hij = {};
  }

  Node(int d){
      data=d;
      hij = {};
  }
  
  int getData(){
      return data;
  }
  
  vector<Node*> getHij(){
      return hij;
  }
  
  void setHij(Node* h){
      hij.push_back(h);
  }  
  
  bool isHoja(){
      if(hij.empty())
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
  
  void add(int d){
      Node* n = new Node(d);
      if(root == NULL){
          root = n;
      }else{
          Node* t = root;
          bool found = false;
          while(!found){
              if(t->getData() < n->getData()){
                /*
                if(t->isHoja()){
                    t =  t->getHij();
                }else{
                */
                t->setHij(n);
                found=true;
                //}
                
              }else{
                /*
                if(t->isHoja()){
                    t =  t->getHij();
                }else{
                */
                t->setHij(n);
                found=true;
                //} 
              }
          }
      }
  }
/*
  void preorder(){
      preorder(root);
  }

  void preorder(vector<Node*> r){
      if(r != NULL){
          cout<<r->getData()<<"\t";
          preorder(r->getHij());
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
                pt->setHij(n);
            }else{
                pt->setHij(n);
            }
        }else{
            if(d < t->getData()){
                addr(d, t->getHij(), t);
            }else{
                addr(d, t->getHij(), t);
            }
        }
    }
  */  
    
    
};

int main()
{
    
    Tree t;

    return 0;
}



