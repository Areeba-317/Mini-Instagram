#include "post.h"

Post::Post(string s, time_t t)
{
	content = s;
	time_posted = t;
}

Post::Post(Post* P) {
	content = P->content;
	time_posted = P->time_posted;
	next = nullptr;
}