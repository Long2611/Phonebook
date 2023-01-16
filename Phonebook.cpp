#include <iostream>
#include <fstream>
#include <string.h>
#include "Phonebook.h"

using namespace std;

void Phonebook::partial_search(string name, string search)
{
    int leng = search.length();
    cout << leng << endl;
    // The loop will lowercase the name for 
    for (int i = 0; i < name.length(); i++)
    {
        name[i] = tolower(name[i]);
    }
    for (int i = 0; i < name.length(); i++)
    {
        string temp = name.substr(i,leng);
        cout << temp << endl;
        if (temp == search)
        {
            cout << "Found\n";
            break;
        } 
    } 
}

void Phonebook::run()
{
    bool quit = false;
    string name, phone_numb, type, temp;
    string file_name = "myBook.txt";
    fstream file;
    bool file_read = false;
    while (!file_read) 
    {
        cout << "Name of phonebook file to read in: ";
        cin >> file_name;
        file.open(file_name.c_str());
        if(!file) // check if file is read or not read. 
        {
            cout << "Phonebook is not read, please re-enter phonebook file name " << endl;    
        } else {
            cout << "Phonebook successfully read in! \n";
            file_read = true;
            break;
        }
    }
    int line;
    file >> line;
    Linkedlist phonebook;
    for (int i = 0; i < line; i++)
    {
        file >> name >> phone_numb >> type;
        phonebook.insert_node_at_tail(name, phone_numb, type);
    }
    
    while(!quit)
    {
        string user_input, user_input2;
        cout << "Please enter person to search for: ";
        // cin >> user_input >> user_input2;
        // user_input += user_input2;
        getline(cin, user_input);
        if(user_input == ".")
        {
            cout << "Thank you for using this program!" << endl;
            quit = true;
            break;
        }
        else if(user_input[0] == '^' )
        {
            user_input = user_input.substr(1);
            phonebook.partial_get_data(user_input);
        }
        else if (user_input[0] == '@')
        {
            phonebook.modify_data(user_input);
        } else {
            phonebook.get_data(user_input);
        }
    }


}