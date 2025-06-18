#pragma once
#include<iomanip>
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class Post
{

public:
	string content;
	time_t time_posted;
	Post* next;
	Post(string s, time_t t);
	Post(Post* P);
};