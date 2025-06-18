#pragma once
#include<iostream>
#include<cstring>
using namespace std;

struct message {
	string user_name;
	string content;
	//bool status;
	message* nxt;
	message(string c, string u);
};

class chat_stack {
public:
	message* topMsg;
	chat_stack();
	void addMessage(string c, string u);
	//modified recently
	void viewChat_newest_at_last();
	//added recently
	void viewChat_newest_at_first();
	~chat_stack();
};