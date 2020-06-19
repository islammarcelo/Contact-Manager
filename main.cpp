#include <iostream>
#include <fstream>
#include "linkedlist.h"
using namespace std;

struct contact2
{
    string name;
    string number;
};
///__________________________________________________
struct Node
{
    string name,number ;
    Node* left ;
    Node* right ;
    int priority;
    int hieght;
};
Node* root;
///__________________________________________________

int hieght (Node *curr)
{
    if (curr==NULL)
        return 0;
    return curr->hieght;
}
///__________________________________________________

int getBalance(Node* curr)
{
    if (curr == NULL)
        return 0;
    return hieght(curr->left)-hieght(curr->right);
}
///__________________________________________________
Node* right_rot(Node* y)
{

    if (y == NULL || y->left == NULL )
        return NULL;
    Node* x = y->left;
    Node* t2 = x->right;
    x->right=y ;
    y->left=t2;
    y->hieght=max(hieght(y->left),hieght(y->right));
    x->hieght=max(hieght(x->left),hieght(x->right));
    return x ;
}
///__________________________________________________

Node* left_rot(Node* x)
{

    if (x == NULL || x->left == NULL )
        return NULL;
    Node* y = x->left;
    Node* t2 = y->right;
    y->right=x ;
    x->left=t2;
    x->hieght=max(hieght(x->left),hieght(x->right));
    y->hieght=max(hieght(y->left),hieght(y->right));
    return y ;
}
///__________________________________________________

Node*inserT(Node*root,contact2&cont)
{
    if (root==NULL)
    {
        Node* new_node = new Node();
        new_node->name = cont.name;
        new_node->number = cont.number;
        new_node->priority = rand()%100;
        return new_node;
    }
    if (cont.number == root->number)
        return root;
    if (cont.number < root->number)
    {
        root->left = inserT(root->left,cont);
        //if (root->priority > root->left->priority)
        // root = right_rot(root);
    }

    else if (cont.number > root->number)
    {
        root->right=inserT(root->right,cont);
       // if(root->priority < root->right->priority)
        //root = left_rot(root);
    }
    return root ;

    root->hieght = 1+max(hieght(root->left),hieght(root->right)); ///O(1);
    int balance = getBalance(root);

    if (balance < -1 && cont.number > root->right->number)
        return left_rot(root);
    if (balance > 1 && cont.number > root->left->number)
    {
        root->left = left_rot(root->left);
        return right_rot(root);
    }
    if (balance > 1 && cont.number < root->left->number)
        return right_rot(root);
    if (balance < -1 && cont.number < root->right->number)
    {
        root->right = right_rot(root->right);
        return left_rot(root);
    }
    return root ;

}
///__________________________________________
void loadData (fstream &file)
{
    contact2 cont;
    string temp;
    while(getline(file,temp,' '))
    {

        cont.number = temp;
        getline(file,temp,'\n');
        cont.name = temp ;
        root = inserT(root,cont);

    }

}

///__________________________________________
void preorder(Node*root)
{
    if (root==NULL)
    {
        return;
    }

    cout <<root->name <<' '<<root->number<<'\n';
    preorder(root->left);
    preorder(root->right);
}
///___________________________________________
void add(string number)
{
  contact2 cont;
  cont.number = number;
  root = inserT(root,cont);
}
///___________________________________________
void Find(Node*root,string number)
{
    if (root == NULL)
        return;
    if(root->number == number)
    {
      cout <<root->name<<" "<<root->number<<'\n';
      return;
    }
    Find(root->left,number);
    Find(root->right,number);
}

int main()
{
   linkedlist a;
   fstream file ("allcontacts.txt",ios::app|ios::in|ios::out);
   /*
   a.addContact(file);
   a.addContact(file);
   a.addContact(file);
   a.addContact(file);
   a.addContact(file);
    */
    //a.loadData(file);
    //a.printCont();
    loadData(file);
    add("01235536");
    Find(root,"01235536");
    return 0;
}
