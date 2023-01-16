#include <iostream>
#include <string.h>
#include "Phonebook.h"

using namespace std;

//constructor for Linkedlist class that node will contain a 2D array
Linkedlist::Linkedlist()
{
    head = NULL;
}

//function will create new node and add it at the tail.
// it also add data entry and phone_numb to a 2d arr
void Linkedlist::insert_node_at_tail(string name, string phone_numb, string entry)
{
    Node *new_node = new Node();
    new_node->data[0][0] = name;
    new_node->data[1][0] = phone_numb;
    new_node->data[1][1] = entry;

    if(head == NULL)
    {
        head = new_node;
        return;
    }  
    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

// function will receive a string and return a same
// string with all lowercase to void case sensitive
string Linkedlist::lower_case(string name)
{
    for (int i = 0; i < name.length(); i++)
    {
        name[i] = tolower(name[i]);
    }
    return name;
}

// function will every node in the Linkedlist class
// function created for testing and implementation.
void Linkedlist::print_node()
{
    if(head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }
    Node *curr_node = head;
    while (curr_node != NULL)
    {
        for (int i = 1; i < 6; i++)
        {
            if(curr_node->data[i][0].length() == 0)
            {
                break;
            }
            cout << curr_node->data[0][0] << " " << curr_node->data[i][0] 
            << " " << curr_node->data[i][1] << endl;
        }
        curr_node = curr_node->next;
    }
}

// function will check if any node's data already created
// if found, return a node pointer
// not found, return NULL
Node* Linkedlist::search_node(string name)
{
    Node *curr_node = head;
    if(head == NULL)
    {
        cout << "Not found b/c empty list" << endl;
        return curr_node = NULL;
    }
    while (curr_node != NULL)
    {
        string temp = lower_case(curr_node->data[0][0]);
        if (temp == name)
        {
            // cout << "The value is: " << curr_node->data[0][0] << endl;
            return curr_node;
        }
        curr_node = curr_node->next;
    }
    return curr_node = NULL;
}

// function will print out all element in the 2d array 
// at the node with the string name.
void Linkedlist::get_data(string name)
{
    bool found = false;
    Node *curr_node = head;
    while (curr_node != NULL)
    {
        name = lower_case(name);
        string temp;
        temp = curr_node->data[0][0].substr(0,name.length());
        temp = lower_case(temp);
        if (name == temp)
        {
            for (int i = 1; i < 6; i++)
            {
                if(curr_node->data[i][0].length() == 0)
                {
                    break;
                }
                cout << curr_node->data[0][0] << " " << curr_node->data[i][0] 
                << " " << curr_node->data[i][1] << endl;
                found = true;
            }
            break;
        }
        curr_node = curr_node->next;
    }
    if (!found)
    {
       cout << "***No Entry found.***" << endl;
    }
}

// function will print out all element in the 2d array
// it can partial search for the string name.
void Linkedlist::partial_get_data(string name)
{
    bool found = false;
    Node *curr_node = head;
    name = lower_case(name);
    int leng = name.length();
    while(curr_node != NULL)
    {
        for(int i = 0; i < curr_node->data[0][0].length() ;i++)
        {
            string temp = curr_node->data[0][0].substr(i,leng);
            temp = lower_case(temp);
            // cout << temp << " and " << name << endl;
            if (temp == name)
            {
                for (int i = 1; i < 6; i++)
                {
                    if(curr_node->data[i][0].length() == 0)
                    {
                        return;
                    }
                cout << curr_node->data[0][0] << " " << curr_node->data[i][0] 
                << " " << curr_node->data[i][1] << endl;
                }
                return;
            }
        }
        curr_node = curr_node->next;
    }
    if (!found)
    {
       cout << "***No Entry found.***" << endl;
    }
}

// function will check if entry and name in node's data exist
// if name or entry found, it will modify the 2d array 
// if name is not found, call function insert_node_at_tail()
// to add new node to the linked list.
void Linkedlist::modify_data(string info)
{
    string word, name, name2, entry, phone_numb;
    int count = 0, counter = 1;
    for (int i = 2; i < info.length(); i++)
    {
        word = " ";
        counter += 1;
        if (i == info.length() - 1) // last input
        {
            word = info.substr(count+1, counter);
            entry = word;
        } 
        if (info[i] == ' ')
        {
            if (count+1 == 1) //first input
            {
                word = info.substr(count+2, i-2);
                name = word;
                name2 = word;
            } else {
                word = info.substr(count+1, counter-1);
                phone_numb = word;
            }
        counter = 0;
        count = i;
        }
    }
    name = lower_case(name);
    Node *curr_node = search_node(name);
    if (curr_node == NULL)
    {
        insert_node_at_tail(name2, phone_numb, entry);
        cout << "***New entry for " <<
        name2 << "***" << endl;
        return;
    }
    for (int i = 0; i < 6; i++)
    {
        if (curr_node->data[i][1] == entry)
        {
            curr_node->data[i][0] = phone_numb;
            cout << "***Added to " <<
            curr_node->data[0][0] << "***" << endl;
            return;
        }

        if (curr_node->data[i][0].length() == 0)
        {
            curr_node->data[i][0] = phone_numb;
            curr_node->data[i][1] = entry;
            cout << "***Added to " <<
            curr_node->data[0][0] << "***" << endl;
            return;
        } 
    }
    cout << "Max entry, cannot add more" << endl;
    delete[] curr_node;
}
