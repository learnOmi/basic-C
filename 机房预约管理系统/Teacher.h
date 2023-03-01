#pragma once
#include "Identity.h"
#include "OrderFileManage.h"
#include <vector>

class Teacher:public Identity
{
public:
	//默认构造
	Teacher();

	//有参构造 参数：编号，姓名，密码
	Teacher(int id, string userName, string pwd);

	//显示菜单
	virtual void showMenu();

	//显示所有预约信息
	void show_all_Order();

	//审核
	void checkOrder();

	//编号
	int id;
};