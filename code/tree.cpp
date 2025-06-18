#pragma once
#include "tree.h"
using namespace std;

    void tree::insert(string s) {
        root = insert(root, s);
    }

    string tree::search(const string& username) const {
        treeNode* result = search(root, username);
        return result ? result->username : ""; // Return the username if found, otherwise an empty string
    }

    void tree::display() const {
        inorder(root);
    }

    // Helper function to insert a new node
    treeNode* tree::insert(treeNode* root, string s) {
        if (root == nullptr) {
            return new treeNode(s); // Create a new tree node
        }
        if (s < root->username) {
            root->left = insert(root->left, s);
        }
        else if (s > root->username) {
            root->right = insert(root->right, s);
        }
        return root;
    }

    // Helper function to search for a node
    treeNode* tree::search(treeNode* root, const string& username) const {
        if (root == nullptr || root->username == username) {
            return root; // Found or not found
        }
        if (username < root->username) {
            return search(root->left, username);
        }
        return search(root->right, username);
    }

    // Helper function for in-order traversal
    void tree::inorder(treeNode* root) const {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->username << endl;
            inorder(root->right);
        }
    }

