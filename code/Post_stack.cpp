#include "Post_stack.h"
#include "post.h"
#include<string>
#include"coloring.cpp"
#pragma warning(disable: 4996)

Post_stack::Post_stack()
{
	top = NULL;
}

Post_stack::~Post_stack()
{

}

Post* Post_stack::getTop() {
	return top;
}

string Post_stack:: push()
{
	string s;
	cout <<BG_BLUE<<YELLOW<< "Enter post content: " <<RESET<< endl;//input content
	cin.ignore();
	getline(cin, s);
	time_t currentTime = time(0);//inputing curent date + time
	
	Post *p = new Post(s, currentTime);//creating a new post

	p->next = top;//push the post into stackk
	top = p;
	cout<<YELLOW << "Posted ~ ! "<<RESET << endl;
	cout << endl;
	return s;
}

void Post_stack::push2(string s)
{
	time_t currentTime = time(0);//inputing curent date + time
	Post* p = new Post(s, currentTime);//creating a new post

	p->next = top;//push the post into stackk
	top = p;

}

void Post_stack::push1(Post* P) {
	P->next = top;
	top = P;
}


Post* Post_stack:: delete_post()
{
	Post* temp;
	temp = top;
	top = top->next;

	temp->next = nullptr; 
	cout<<YELLOW << "Deleted post ! "<<RESET << endl;
	cout << endl;
	return temp;

}

void Post_stack::view_recent()
{
	cout<<YELLOW << "Displaying recent post ! "<<RESET << endl;
	cout <<BG_BLUE<<YELLOW<< "Content: "<<RESET<<YELLOW << top->content <<RESET<< endl;
	cout << BG_BLUE << YELLOW << "Time posted: " << RESET << YELLOW << ctime(&top->time_posted)<<RESET << endl;
	cout << endl;
}

void Post_stack::view_all_posts()
{
	Post* temp=top;   //intitializing temporary var to top
	
	while (temp)
	{
		cout<<BG_BLUE<<YELLOW << "Content: " <<RESET<<YELLOW<< temp->content <<RESET<< endl;
		cout << BG_BLUE << YELLOW << "Time posted: " << RESET << YELLOW << ctime(&temp->time_posted) <<RESET<< endl;
		cout <<YELLOW<< ";------------;" <<RESET<< endl;
		temp = temp->next;
	}
}