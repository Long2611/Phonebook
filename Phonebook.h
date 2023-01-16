#include <iostream>
#include <string>
#ifndef PHONEBOOK_H
#define PHONEBOOK_H
using namespace std;

class Node
{
    public:
    string data[6][2];
    Node* next;

};

class Linkedlist
{
    private:
    bool found;
    string name, phone_numb, entry;
    public:
    Node* head;
    Node* tail;
    Linkedlist();//constructor
    void insert_node_at_tail(string name, string phone_numb, string entry);
    void print_node();
    Node* search_node(string node_data);
    void modify_data(string info);
    string lower_case(string name);
    void get_data(string name);
    void partial_get_data(string name);
};

class Phonebook
{
    private:
    public:
    void run();
    void partial_search(string name, string search);
};


#endif