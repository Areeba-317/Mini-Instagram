//#include "edge.h"
#include"node.h"
//created two types of constructors here

edge::edge(bool r, string s, Node* u2, chat_stack* c)
{
	relation_type = r;
	status = s;
	user2 = u2;
	nxt = nullptr;
	chat = c;
}

//edge::edge()
//{
//	relation_type = 0;
//	status = " ";
//	user2 = nullptr;
//	nxt = nullptr;
//	chat = new chat_stack;
//}