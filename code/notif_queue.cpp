#include "notif_queue.h"
#include<iostream>
#include<iomanip>
#include"coloring.cpp"
using namespace std;

notif_queue::notif_queue()
{
	front = nullptr;
	rear = nullptr;
}

bool notif_queue::isEmpty()
{
	if (front == nullptr) {
		return true;
	}
	return false;
}

string notif_queue::getFront() {

	// Checking if the queue is empty
	if (this->isEmpty()) {
		cout<<UNDERLINE<<RED << "Notification Queue is empty\n"<<RESET;
		return "";
	}
	return front->notif;
}

void notif_queue::enQueueFollowReq(string username) // enqueues follow request message in queue
{
	string msg = username + " has sent you a follow request ! ";

	queue_node* newNode = new queue_node(msg);  //creating a new node based on the message

	if (this->isEmpty()) {
		front = rear = newNode;
		return;
	}

	rear->next = newNode;
	rear = newNode;
}

void notif_queue::enQueueMessage(string username) // enqueues if message was sent to user
{
	string msg = username + " has sent you a message ! ";

	queue_node* newNode = new queue_node(msg);  //creating a new node based on the message

	if (this->isEmpty()) {
		front = rear = newNode;
		return;
	}

	rear->next = newNode;
	rear = newNode;
}

void notif_queue::displayAllNotifs()
{
	queue_node* curr = front;
	while (curr)
	{
		cout << curr->notif << endl;
		curr = curr->next;
	}

}

