#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<ctime>
#include "Post_stack.h"
#include "edge.h"
#include "notif_queue.h"
#include "follower_queue.h"
#include"message_stack.h"
//#include"coloring.cpp"
#pragma warning(disable: 4996)
using namespace std;
class Node;

class edge
{
public:
	bool relation_type;
	string status;
	Node* user2;
	edge* nxt;
	chat_stack* chat;
	edge(bool r, string s, Node* u2, chat_stack* c);
	//edge();
};

class Node
{

public:
	string name;
	string password;
	string city;
	time_t login_time;
	Post_stack user_posts;
	Post_stack friend_posts;
	edge* edges;
	Node* next;
	notif_queue nq;
	follow_queue fq;

	Node(string n, string p, string c);
	Node();

	//made changes
	void sendMsg(Node* user2);
	//made changes
	void SeeMsgz(Node* user2);

	//post stack related
	string addpost();      //returns a string to be acesssed by the other stack
	void del_recent_post();
	void view_recent();
	void view_all();

	//friend post stack related
	void addpost2(string s);
	void view_all2();

	void add_edge(Node* u2, string s, chat_stack* c);

	//queue related
	void add_follower_notif(string s);
	void add_message_notif(string s);
	void display_notif_queue();
	bool check_notifs_empty();

	bool check_if_empty();
	void add_follower(string s);
	string accept_req();
	void decline_req();
	void display_requests();

	void deleteEdge(Node* user);

	void operator = (Node* user2);
};