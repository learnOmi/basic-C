#pragma once
#include "Identity.h"
#include "Global_File.h"
#include <fstream>
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include <algorithm>
#include "ComputerRoom.h"

class Administrator :public Identity
{
public:
	//默认构造函数
	Administrator();

	//有参构造 参数：名称、密码
	Administrator(string username, string pwd);

	//菜单界面
	virtual void showMenu();

	//查看用户
	void showUser();

	//添加用户
	void addUser();

	//查看机房信息
	void showComputer();

	//清空预约
	void ClearOrder();

	//初始化容器
	void Initvector();

	//检测重复参数 参数：学生或者职工编号，检测类型
	bool isExisted(int id,int type);

	//存放从文件读入的学生、教师记录
	vector<Student> vStud;
	vector<Teacher> vTeach;
	//存放电脑房信息
	vector<ComputerRoom> vComp;
};