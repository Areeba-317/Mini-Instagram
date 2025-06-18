#include "hashing.h"
#include<iostream>
#include<iomanip>
#include "node.h"
#include<string>
#include"coloring.cpp"
using namespace std;


    hashing_list::hashing_list()
    {
        head = nullptr;
    }

    void hashing_list::insert(string username, string password, string city) {
        Node* newNode = new Node(username, password, city);
        newNode->next = head;
        head = newNode;
    }

    // Find a user in the linked list
    bool hashing_list::find(string username, string password) {
        Node* current = head;
        while (current) {
            if (current->name == username && current->password == password) {
                return true;
            }
            current = current->next;
        }
        return false;
    }




    //computing index for username and password combination
    int HashTable::hashFunction(string username, string password) {
        int hashValue = 0;
        string combined = username + password;
        for (int i = 0; i < combined.length(); i++) {
            hashValue += combined[i]; // Simple sum of ASCII values
        }
        return hashValue % BUCKETS; // Return an index within the table size
    }


    void HashTable::resize() {
        int newBuckets = BUCKETS * 2; // Double the size of the table
        hashing_list* newTable = new hashing_list[newBuckets];

        // Rehash all users into the new table
        for (int i = 0; i < BUCKETS; i++) {
            Node* current = table[i].head;
            while (current) {
                int newHashIndex = hashFunction(current->name, current->password) % newBuckets;
                newTable[newHashIndex].insert(current->name, current->password, current->city);
                current = current->next;
            }
        }

        delete[] table;
        table = newTable;
        BUCKETS = newBuckets;
    }

    // Insert user into the hash table
    void HashTable::insertUser(string username, string password, string city) {
        if (size > BUCKETS * 0.7) { // Check load factor (resize when > 70%) 
            //A load factor of 0.7 means that 70% of the hash table is filled with data
            resize();
        }

        int hashIndex = hashFunction(username, password);
        table[hashIndex].insert(username, password, city);
        size++;
        cout<<YELLOW << "User signed up successfully !~" << endl;
    }

    // Return a pointer to the Node (user) object if found
    Node* HashTable::findUser(string username, string password) {
        int hashIndex = hashFunction(username, password);
        Node* current = table[hashIndex].head;
        while (current) {
            if (current->name == username && current->password == password) {
                return current;  // Return the user object (Node) found
            }
            current = current->next;
        }
        return nullptr;  // Return nullptr if user is not found
    }

    // Find a user in the hash table by username only
    Node* HashTable::findUserByUsername(string username) {
        for (int i = 0; i < BUCKETS; i++) { // Traverse all buckets
            Node* current = table[i].head; // Get the head of the linked list at the bucket
            while (current) { // Traverse the linked list
                if (current->name == username) { // Check if the username matches
                    return current; // Return the user object (Node) found
                }
                current = current->next; // Move to the next node
            }
        }
        return nullptr; // Return nullptr if user is not found
    }

   
