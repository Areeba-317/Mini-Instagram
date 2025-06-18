#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include "Node.h"
#include"hashing.h"
using namespace std;

class Graph {
    Node* Users;
    int capacity;
    int no_of_users;
public:
    Graph(int);
    void AddBiDirectionalEdge(string user1_name, string user2_name);
    void AddUniDirectionalEdge(string user1_name, string user2_name);
    void addUser(Node*);
    Node* findUser(string user_name);
    void printUsers();
    void printFollowers(Node* user);
    void checkFollowersForStack(Node* user, string s, HashTable& ht);
    ~Graph();
};

//class List {
//public:
//    Node* AdjNodes;
//    Node* user;
//
//    List() : AdjNodes(nullptr), user(nullptr) {}
//    void addEdge(Node* user2) {
//        Node* u = AdjNodes;
//        bool found = 0;
//        while (u) {
//            if (u->name== user2->name) {
//                found = 1;
//                break;
//            }
//            u = u->next;
//        }
//        if (!found) {
//            user2->next = AdjNodes;
//            AdjNodes = user2;
//        }
//    }
//    void printEdges() const{
//        Node* N = AdjNodes;
//        while (N) {
//            cout << N->name;
//            cout << ",";
//            N = N->next;
//        }
//        cout << endl;
//    }
//};



/*class UserGraph {
public:
    int v;      // Number of users
    List* arr;  // Array of adjacency lists

    UserGraph(int users) {
        v = users;
        arr = new List[v];
    }

    ~UserGraph() {
        for (int i = 0; i < v; i++) {
            Node* current = arr[i].AdjNodes;
            while (current) {
                Node* temp = current;
                current = current->next;
                temp->next = nullptr;
                delete temp;
            }
        }
        delete[] arr;
    }

    // Add a user to the graph
    void addUser(int index, string name, string password, string city) {
        if (index >= v) {
            cout << "Invalid index for user!" << endl;
            return;
        }
        Node* newNode = new Node(name, password, city);
        if (arr[index].user == nullptr) arr[index].user = newNode;
        else cout << "This user already exists.\n";
    }

    void addEdge(int user1_index, int user2_index) {
        if ((user1_index >= v) || (user2_index >= v)) {
            cout << "Atleast one of the users doesn't exist." << endl;
            return;
        }
        arr[user1_index].addEdge(new Node(arr[user2_index].user));
        arr[user2_index].addEdge(new Node(arr[user1_index].user));
    }

    void printEdges() {
        for (int i = 0; i < v; i++) {
            cout << "Friends of " << arr[i].user->name << ": ";
            arr[i].printEdges();
            cout << "\n";
        }
    }


};*/