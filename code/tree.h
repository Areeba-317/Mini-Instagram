#pragma once
#include <iostream>
#include <string>
using namespace std;

class treeNode {
public:
    string username;
    treeNode* left;
    treeNode* right;

    treeNode(string s) : username(s), left(nullptr), right(nullptr) {}
};

class tree {
public:
    treeNode* root;

    tree() : root(nullptr) {}

    void insert(string s);

    string search(const string& username) const;

    void display() const;

private:
    // Helper function to insert a new node
    treeNode* insert(treeNode* root, string s);

    // Helper function to search for a node
    treeNode* search(treeNode* root, const string& username) const;

    // Helper function for in-order traversal
    void inorder(treeNode* root) const;
};
