#include "linkedlist.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include<strstream>
using namespace std;
///
node*head;
vector<node*>vec;
///

linkedlist::linkedlist(){}

///O-O-O-O-O-O-O-O-O-O-O-O--O-O-O-O-O-O-O-O-O-O-O--->

istream& operator>>(istream & in, contact &cont)
{
    cout << "Enter contact (^_^) \n";

    cout << "Enter phone number : " ;
    getline(in,cont.number);
    cout << "Enter name : " ;
    getline(in,cont.name);

    return in;
}

///O-O-O-O-O-O-O-O-O-O-O-O--O-O-O-O-O-O-O-O-O-O-O--->

void linkedlist::addContact(fstream &file)
{
    contact cont;
    cin >> cont;
    file.write((char*)&cont.number[0],cont.number.length())<<" ";
    file.write((char*)&cont.name[0],cont.name.length());
    file << endl ;


}
///O-O-O-O-O-O-O-O-O-O-O-O--O-O-O-O-O-O-O-O-O-O-O--->

void linkedlist::inserT (contact &cont)
{

    node* new_node = new node();
    new_node->number = cont.number;
    new_node->name = cont.name;
    new_node->num.push_back(cont.number);

    if (head == NULL)
    {
        head = new_node;
        return ;
    }

    node* curr = head ;

    if(curr->name == new_node->name)
    {
        curr->num.push_back(new_node->number);
        return ;
    }

    else
    {
        while(curr->next != NULL)
        {
            curr = curr->next ;

            if(curr->name == new_node->name)
            {
                curr->num.push_back(new_node->number);
                return;

            }

        }
        curr->next = new_node ;
    }
}
///O-O-O-O-O-O-O-O-O-O-O-O--O-O-O-O-O-O-O-O-O-O-O--->

void linkedlist::loadData (fstream &file)
{
    contact cont;
    string temp;
    while(getline(file,temp,' '))
    {

        cont.number = temp;
        getline(file,temp,'\n');
        cont.name = temp ;
        inserT(cont);
    }

}
///O-O-O-O-O-O-O-O-O-O-O-O--O-O-O-O-O-O-O-O-O-O-O--->

void linkedlist::sortAlphabetical()
{
    node*curr = head;
    while(curr != NULL)
    {
        vec.push_back(curr);
        curr = curr->next;
    }
    unsigned int n = vec.size();
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n-i-1; j++){
            if (vec[j]->name[0] == vec[j+1]->name[0] && vec[j]->name[1] > vec[j+1]->name[1])
                swap(vec[j], vec[j+1]);
            if(vec[j]->name[0] > vec[j+1]->name[0])
                swap(vec[j], vec[j+1]);
        }
    }
}

///O-O-O-O-O-O-O-O-O-O-O-O--O-O-O-O-O-O-O-O-O-O-O--->
void linkedlist::printCont()
{
    sortAlphabetical();
     for(int i=0 ; i<vec.size();i++)
     {
         cout << vec[i]->name << ' ' ;
         for(int j=0 ; j<vec[i]->num.size();j++)
        {
            cout << vec[i]->num[j] << " ";
        }
        cout <<endl;
     }
     cout <<endl;
}
///O-O-O-O-O-O-O-O-O-O-O-O--O-O-O-O-O-O-O-O-O-O-O--->
/*
void linkedlist::print ()
{
    node* curr = head ;
    while (curr != NULL)
    {
        cout << curr->name <<' ';
        for(int i=0 ; i<curr->num.size();i++)
        {
            cout << curr->num[i] << " ";
        }
        cout <<endl;
        curr = curr->next ;
    }
    cout << '\n' ;
}
*/

