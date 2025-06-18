#pragma once
#include<iomanip>
#include<iostream>
#include<string>
using namespace std;

class Fqueue_node
{
public:

	string username;
	Fqueue_node* next;

	Fqueue_node(string s)
	{
		username = s;
		next = nullptr;
	}
};

class follow_queue
{
public:

	Fqueue_node* front, * rear;

	follow_queue();

	bool isEmpty();

	string getFront();

	void enQueue(string username);
 
	string deQueue();

	void display();
};