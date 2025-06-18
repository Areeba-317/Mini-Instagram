#include<iomanip>
#include<iostream>
#include "post.h"
using namespace std;

class Post_stack
{
	Post* top;

public:

	Post_stack();
	~Post_stack();
	string push();
	void push2(string s);
	void push1(Post* P);
	Post* getTop();
	Post* delete_post();
	void view_recent();
	void view_all_posts();
};