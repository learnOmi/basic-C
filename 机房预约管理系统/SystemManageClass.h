#pragma once
#include<iostream>
#include"Identity.h"


class SystemManager
{
public:
	//默认构造函数
	SystemManager();

	//登录功能 参数：操作类型，文件名
	void Login(int type,string filename);

	//管理员身份登陆后的功能
	void managerSonMenu(Identity* & person);

	//学生身份登录后的功能
	void studentSonMenu(Identity*& person);

	//教师身份登录后的功能
	void teacherSonMenu(Identity*& person);

	//析构函数
	~SystemManager();
};