#pragma once
#include<iostream>
#include<string>
using namespace std;

class Identity  //身份 抽象类；提炼出公共的属性和操作
{
public:
	virtual void showMenu() = 0;  //显示菜单

	string UserNanme;  //用户名
	string Password;  //密码
};