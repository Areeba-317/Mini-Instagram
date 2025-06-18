#pragma once
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class queue_node
{
public:

	string notif;
	queue_node* next;

	queue_node(string s)
	{
		notif = s;
		next = nullptr;
	}
};

class notif_queue
{
public:

	queue_node* front, *rear; 

	notif_queue();

	bool isEmpty();

	string getFront();
	void enQueueFollowReq(string username);

	void enQueueMessage(string username);

	void displayAllNotifs();

};