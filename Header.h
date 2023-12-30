#pragma once
#pragma warning
#include<iostream>
using namespace std;

class bank
{
protected:
	string first_name;//globalization of variable: first_name to store users first name 
	string last_name;//globalization of variable: last_name for last name of user
	char password[8], password2[8];//globalization of variable: password for password set by user & password2 for password confirmation
	string cnic, line, c, d, bal, pw;
	char type, ch;
	long long dep;//globalzation of variable: dep for amount deposited(altered later when user deposit,withdraw,transfer funds)
};

class admin : public bank
{
public:
	void customer();
	void del();
	void edit();
	void search();
	void view();
	void review(string& c);
};

class user : public bank
{
public:
	void login();
	void balance();
	void withdraw();
	void transfer();
	void deposit();
};