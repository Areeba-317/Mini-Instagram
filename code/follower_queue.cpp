#include "follower_queue.h"
#include "coloring.cpp"
using namespace std;

follow_queue::follow_queue()
{
	front = rear = nullptr;
}

bool follow_queue::isEmpty()
{
	if (front == nullptr) {
		return true;
	}
	return false;
}

string follow_queue::getFront()
{
	if (this->isEmpty()) {
		cout<<UNDERLINE<<RED << "Queue is empty\n"<<RESET;
		return "";
	}
	return front->username;
}

void follow_queue::enQueue(string username)
{
	Fqueue_node* newNode = new Fqueue_node(username);

	if (this->isEmpty()) {
		front = rear = newNode;
		return;
	}

	rear->next = newNode;
	rear = newNode;
}

string follow_queue::deQueue()
{
	string user = front->username;

	if (this->isEmpty()) {
		cout << UNDERLINE << RED << "No current friend requests !"<<RESET;
		return "";
	}

	Fqueue_node* temp = front;
	front = front->next;

	if (front == nullptr)
		rear = nullptr;

	delete temp;

	return user;
}

void follow_queue::display()
{
	cout <<BG_BLUE<<YELLOW<< "Follow requests: "<<RESET << endl;
	Fqueue_node* curr = front;

	while (curr)
	{
		cout<<YELLOW << curr->username << ", "<<RESET;
		curr = curr->next;
	}
	cout << endl;
}