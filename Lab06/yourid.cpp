//  Lab06
//  Created by Jesus Vera 
//  Copyright © 2020 UC Merced. All rights reserved.


#include <iostream>

#include <list>

#include <sstream>

#include <iterator>

using namespace std;


//class 'HashChain'

class HashChain

{
    
    list<int> hashChain;
    
public:
    
    
    
    //constructors and functions for this program
    
    HashChain(int value);
    
    void push(int value);
    
    int search(int value);
    
    bool deleteHashKey(int value);
    
    void displayValues();
    
};



//constructor line

HashChain::HashChain(int value)

{
    
    hashChain.push_front(value);
    
}



//push function line

void HashChain::push(int value)

{
    
    hashChain.push_front(value);
    
}



//This function searches for hash key value

int HashChain::search(int value)

{
    
    int k = 0;
    
    for (list<int> ::iterator i = hashChain.begin(); i != hashChain.end(); i++)
        
    {
        
        if (*i == value)
            
        {
            
            return k;
            
        }
        
        k++;
        
    }
    
    return -1;
    
}



//This function delete the hash key value

bool HashChain::deleteHashKey(int value)

{
    
    //declare iterator in this line
    
    list<int> ::iterator i = hashChain.begin();
    
    int in = search(value);
    
    if (in == -1)
        
    {
        
        return false;
        
    }
    
    else
        
    {
        
        while (in > 0)
            
        {
            
            i++;
            
            in--;
            
        }
        
        hashChain.erase(i);
        
        return true;
        
    }
    
}



//This function display the hash key values

void HashChain::displayValues()

{
    
    for (list<int> ::iterator i = hashChain.begin(); i != hashChain.end(); i++)
        
    {
        
        cout << *i << "->";
        
    }
    
}





//hash table class

class HashTable

{
    
    HashChain** hashTable;
    
    int sizeoftableCopy = 0;
    
public:
    
    
    
    //constructors and functions
    
    HashTable(int sizeoftable);
    
    ~HashTable();
    
    string hashTableSearch(int value);
    
    void insertHashValue(int value);
    
    bool deleteHashKey(int value);
    
    void displayingTable();
    
};







//This is the constructor of class

HashTable::HashTable(int sizeoftable)

{
    
    hashTable = new HashChain * [sizeoftable];
    
    sizeoftableCopy = sizeoftable;
    
    for (int i = 0; i < sizeoftable; i++)
        
    {
        
        hashTable[i] = NULL;
        
    }
    
}





//This is the destructor of class

HashTable::~HashTable()

{
    
    //here it is deleting values
    
    for (int i = 0; i < sizeoftableCopy; i++)
        
    {
        
        if (hashTable[i])
            
        {
            
            delete hashTable[i];
            
        }
        
        delete hashTable;
        
    }
    
}



//This is the search function of class

string HashTable::hashTableSearch(int value)

{
    
    int hVal = value % sizeoftableCopy;
    
    if (hashTable[hVal])
        
    {
        
        if (hashTable[hVal]->search(value) != -1)
            
        {
            
            return to_string(hVal) + "," + to_string(hashTable[hVal]->search(value));
            
        }
        
    }
    
    return "";
    
    
    
}



//This function is used for insert the value in hash table

void HashTable::insertHashValue(int values)

{
    
    int hash = values % sizeoftableCopy;
    
    if (hashTable[hash])
        
    {
        
        hashTable[hash]->push(values);
        
    }
    
    else
        
    {
        
        hashTable[hash] = new HashChain(values);
        
    }
    
}



//This function is used for delete the value from hash table

bool HashTable::deleteHashKey(int values)

{
    
    string index = hashTableSearch(values);
    
    
    
    string look;
    
    //delete value if it exists
    
    if (index != "")
        
    {
        
        istringstream str(index);
        
        getline(str, look, ',');
        
        int hashIndex = stoi(look);
        
        if (hashTable[hashIndex]->deleteHashKey(values))
            
        {
            
            return true;
            
        }
        
    }
    
    return false;
    
}



//This function is used for display table

void HashTable::displayingTable()

{
    
    for (int i = 0; i < sizeoftableCopy; i++)
        
    {
        
        cout << i << ":";
        
        if (hashTable[i])
            
        {
            
            hashTable[i]->displayValues();
            
        }
        
        cout << ";" << endl;
        
    }
    
}



//main driver function

int main()

{
    
    //variables declaration
    
    int sizeoftable;
    
    cin >> sizeoftable;
    
    HashTable* hashTable = new HashTable(sizeoftable);
    
    string indexValue ="";
    
    string inputValue = "";
    
    cin >> inputValue;
    
    
    
    
    
    while (inputValue[0] != 'e')
        
    {
        
        
        
        //check user option
        
        if (inputValue[0] == 'i')
            
        {
            
            hashTable->insertHashValue(stoi(inputValue.substr(1))); //insertHashValue value
            
        }
        
        
        
        //check if value is 'o' or not
        
        if (inputValue[0] == 'o')
            
        {
            
            hashTable->displayingTable(); //display hash table
            
        }
        
        //check if value is d or not
        
        if (inputValue[0] == 'd')
            
        {
            
            int value = stoi(inputValue.substr(1));
            
            if (hashTable->deleteHashKey(value)) //deletes key
                
            {
                
                cout << value << ":DELETED;" << endl;
                
            }
            
            else
                
            {
                
                cout << value << ":DELETE_FAILED;" << endl;
                
            }
            
        }
        
        
        
        //check if value is s or not
        
        if (inputValue[0] == 's')
            
        {
            
            int key = stoi(inputValue.substr(1));
            
            indexValue = hashTable->hashTableSearch(key); //search key
            
            if (indexValue != "")
                
            {
                
                cout << key << ":FOUND_AT" << indexValue << ";" << endl;
                
            }
            
            else
                
            {
                
                cout << key << ":NOT_FOUND;" << endl;
                
            }
            
        }
        
        cin >> inputValue;
        
    }
    
}


