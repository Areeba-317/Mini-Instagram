#include "node.h"


Node::Node(string n, string p, string c)
{
	name = n;
	password = p;
	city = c;
	login_time = time(0);
	next = nullptr;
	edges = nullptr;
}

Node::Node()
{
	name = "";
	password = "";
	city = "";
	login_time = 0;
	next = nullptr;
	edges = nullptr;
}

void Node::add_edge(Node* u2, string s, chat_stack* c) {
	bool frd = 0;
	cout << "Friend or not (1 or 0): ";
	cin >> frd;
	edge* newEdge = new edge(frd, s, u2, c);
	newEdge->nxt = this->edges;
	this->edges = newEdge;
}

string Node::addpost()
{
	return user_posts.push();
}

void Node::addpost2(string s)
{
	friend_posts.push2(s);   //push into friend post stack
}

void Node::view_all2()
{
	friend_posts.view_all_posts();
}

void Node::del_recent_post()
{
	user_posts.delete_post();
}

void Node::view_recent()
{
	user_posts.view_recent();
}

void Node::view_all()
{
	user_posts.view_all_posts();
}

void Node::sendMsg(Node* user2) {
	edge* e = edges;
	while (e && (user2 != e->user2)) {
		e = e->nxt;
	}
	if (e) {
		string msg = "";
		cout << "Enter the message here: ";
		cin >> msg;
		/*message* M = new message(msg, name);*/
		e->chat->addMessage(msg, name);
	}
	else {
		cout << "You are not one the followers or friends of " << user2->name << endl;
	}
}

void Node::SeeMsgz(Node* user2) {
	edge* e = edges;
	while (e && (e->user2 != user2)) {
		e = e->nxt;
	}
	if (e) {
		e->chat->viewChat_newest_at_first();
	}
	else cout << "You are not friends with this user\nSend a friend request start chatting wit each other\n";
}

void Node::add_follower_notif(string s)
{
	nq.enQueueFollowReq(s);
}
void Node::add_message_notif(string s)
{
	nq.enQueueMessage(s);
}
void Node::display_notif_queue()
{
	nq.displayAllNotifs();
}
bool Node::check_notifs_empty()
{
	return nq.isEmpty();
}

bool Node::check_if_empty()
{
	return fq.isEmpty();
}
void Node::add_follower(string s)
{
	fq.enQueue(s);
}
string Node::accept_req()
{
	return fq.deQueue();
}
void Node::decline_req()
{
	fq.deQueue();
	cout << "Declined successfully ! " << endl;
}
void Node::display_requests()
{
	fq.display();
}

void Node::deleteEdge(Node* user) {
	if (edges == nullptr) {
		cout << "No edges to delete.\n";
		return; // No edges to delete
	}

	edge* cur = edges;
	edge* prev = nullptr;

	// Traverse the edge list to find the edge to delete
	while (cur != nullptr && cur->user2 != user) {
		prev = cur;
		cur = cur->nxt;
	}

	// If the edge was not found
	if (cur == nullptr) {
		cout << "User not found in your friend list.\n";
		return;
	}

	// If the edge to delete is the first edge
	if (prev == nullptr) {
		edges = cur->nxt; // Move the head to the next edge
	}
	else {
		prev->nxt = cur->nxt; // Bypass the current edge
	}

	// Delete the edge
	cout << "Removed " << cur->user2->name << " from your friend list.\n";
	delete cur->chat;
	delete cur; // Free the memory
}

void Node::operator = (Node* user2) {
	name = user2->name;
	password = user2->password;
	city = user2->city;
	login_time = user2->login_time;
	next = nullptr;
	edges = user2->edges;
}