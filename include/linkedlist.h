#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <fstream>
#include<bits/stdc++.h>

using namespace std;

struct contact
{
    string name;
    string number;
};

struct node
{
   string name;
   string number;
   vector<string> num;
   node*next;
};

class linkedlist
{
private :

public:

        linkedlist();
        friend istream& operator>>(ifstream & in,contact &cont);
        void addContact(fstream &file);
        void loadData (fstream &file);
        void inserT(contact&cont);
        void sortAlphabetical();
        void print ();
        void printCont();

};

#endif // LINKEDLIST_H
