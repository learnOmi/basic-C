#pragma once
#include"Identity.h"
#include"Global_File.h"
#include "ComputerRoom.h"
#include <vector>
#include<fstream>
#include <algorithm>
#include"OrderFileManage.h"

class Student :public Identity
{
public:
	//默认构造
	Student();

	//有参构造  参数：学号、姓名、密码
	Student(int id,string username,string pwd);

	//界面菜单
	virtual void showMenu();

	//初始化容器
	void InitVector();

	//显示机房信息
	void showComputerRoom();

	//申请预约
	void applyOreder();

	//查看自身预约
	void show_my_Order();

	//查看所有预约
	void show_all_Order();

	//取消预约
	void cancelOrder();

	//学生学号
	int id;
	//机房信息
	vector<ComputerRoom> vComp;
};