#include"message_stack.h"

message::message(string c, string u) {
	//status = 0;
	content = c;
	user_name = u;
	nxt = nullptr;
}

chat_stack::chat_stack() {
	topMsg = nullptr;
}
void chat_stack::addMessage(string c, string u) {
	message* msg = new message(c, u);
	msg->nxt = topMsg;
	topMsg = msg;
}
//modified recently
void chat_stack::viewChat_newest_at_last() {
	message* reversedStack = nullptr;
	message* cur = topMsg;
	while (cur) {
		message* newMsg = new message(cur->content, cur->user_name);
		newMsg->nxt = reversedStack;
		reversedStack = newMsg;
	}
	cur = reversedStack;
	while (cur) {
		cout << cur->user_name << ": " << cur->content << endl;
		cur = cur->nxt;
		reversedStack->nxt = nullptr;
		delete reversedStack;
		reversedStack = cur;
	}
}
//added recently
void chat_stack::viewChat_newest_at_first() {
	message* cur = topMsg;
	cout << "Messages: \n";
	while (cur) {
		cout << cur->user_name << ": \n" << cur->content << endl;
		cur = cur->nxt;
	}
	if (topMsg == nullptr) cout << "No Messages Yet\nStart a new conversion\n";
}
chat_stack::~chat_stack() {
	while (topMsg) {
		message* temp = topMsg;
		topMsg = topMsg->nxt;
	}
}