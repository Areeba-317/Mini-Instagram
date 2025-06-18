#pragma once
#include<iostream>
#include<iomanip>
#include "node.h"
#include<string>
using namespace std;

class hashing_list
{
public:
    Node* head;

    hashing_list();

    //insert at beginning
    void insert(string username, string password, string city);

    // Find a user in the linked list
    bool find(string username, string password);

    ~hashing_list() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

class HashTable {
    static const int INITIAL_BUCKETS = 10;
    int BUCKETS;
    hashing_list* table;
    int size;

    //computing index for username and password combination
    int hashFunction(string username, string password);


    void resize();

public:
    HashTable() : BUCKETS(INITIAL_BUCKETS), size(0) {
        table = new hashing_list[BUCKETS]; // Array of List objects
    }

    // Insert user into the hash table
    void insertUser(string username, string password, string city);

    // Return a pointer to the Node (user) object if found
    Node* findUser(string username, string password);

    // Find a user in the hash table by username only
    Node* findUserByUsername(string username);

    ~HashTable() {
        delete[] table;
    }
};
