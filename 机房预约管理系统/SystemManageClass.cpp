#include "SystemManageClass.h"
#include<fstream>
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Administrator.h"

//默认构造函数
SystemManager::SystemManager()
{

}

//登录功能
void SystemManager::Login(int type, string filename)
{
	//父类指针指向子类对象，方便调出菜单
	Identity* person = NULL;

	//读取对应的记录文件
	ifstream ifs(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "没有任何用户或用户记录读取失败！" << endl;
		ifs.close();
		return;
	}

	int id = 0;  //接受教师或者学生的id
	string username;  //用户名
	string pwd;  //密码
	if (type == 1)
	{
		cout << "请输入学号" << endl;
		cin >> id;
	}
	else if(type == 2)
	{
		cout << "请输入教师编号" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> username;
	cout << "请输入密码" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证
		int temp_id;
		string temp_name;
		string temp_pwd;
		while (ifs >> temp_id && ifs >> temp_name && ifs >> temp_pwd)
		{
			if (id == temp_id && username == temp_name && pwd == temp_pwd)
			{
				cout << "登录成功！" << endl;
				system("pause");
				system("cls");
				//登录成功后显示对应的菜单界面
				person = new Student(id, username, pwd);
				this->studentSonMenu(person);
				return;
			}
		}

	}
	else if (type == 2)
	{
		//教师身份验证
		int temp_id2;
		string temp_name2;
		string temp_pwd2;
		while (ifs >> temp_id2 && ifs >> temp_name2 && ifs >> temp_pwd2)
		{
			if (id == temp_id2 && username == temp_name2 && pwd == temp_pwd2)
			{
				cout << "登录成功！" << endl;
				system("pause");
				system("cls");
				//登录成功后显示对应的菜单界面
				person = new Teacher(id, username, pwd);
				this->teacherSonMenu(person);
				return;
			}
		}
	}
	else
	{
		//管理员验证
		string temp_name3;
		string temp_pwd3;
		while (ifs >> temp_name3 && ifs >> temp_pwd3)
		{
			if (username == temp_name3 && pwd == temp_pwd3)
			{
				cout << "登录成功！" << endl;
				system("pause");
				system("cls");
				//登录成功后显示对应的菜单界面
				person = new Administrator(username, pwd);
				this->managerSonMenu(person);
				return;
			}
		}
	}

	cout << "登录失败!" << endl;
	system("pause");
	system("cls");
	return;
}

//管理员身份登录后的子菜单功能,因为不同身份登录的子界面差异很大，所以说不能写在一个函数中
void SystemManager::managerSonMenu(Identity* & person)
{
	//父类指针强制转换为子类指针,以便调用子类的其他成员
	Administrator* pointer = (Administrator*)person;

	//管理员菜单功能循环
	while (true)
	{
		//调出子菜单
		person->showMenu();

		//用户输入选择
		int select;
		cin >> select;
		if (select == 1) //添加账号
		{
			pointer->addUser();
		}
		else if (select == 2) //查看账号
		{
			pointer->showUser();
		}
		else if (select == 3)  //查看机房
		{
			pointer->showComputer();
		}
		else if (select == 4)  //清空预约
		{
			pointer->ClearOrder();
		}
		else  //注销登录，跳出子菜单功能循环
		{
			delete pointer;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	
}

//学生身份登录后的子菜单功能
void SystemManager::studentSonMenu(Identity*& person)
{
	//父类指针强制转换为子类指针,以便调用子类的其他成员
	Student* pointer = (Student*)person;

	//管理员菜单功能循环
	while (true)
	{
		//调出子菜单
		person->showMenu();

		//用户输入选择
		int select;
		cin >> select;
		if (select == 1) //申请预约
		{
			pointer->applyOreder();
		}
		else if (select == 2) //查看自身预约
		{
			pointer->show_my_Order();
		}
		else if (select == 3)  //查看所有预约
		{
			pointer->show_all_Order();
		}
		else if (select == 4)  //取消预约
		{
			pointer->cancelOrder();
		}
		else  //注销登录，跳出子菜单功能循环
		{
			delete pointer;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}


//教师身份登录后的子菜单功能
void SystemManager::teacherSonMenu(Identity*& person)
{
	//父类指针强制转换为子类指针,以便调用子类的其他成员
	Teacher* pointer = (Teacher*)person;

	//管理员菜单功能循环
	while (true)
	{
		//调出子菜单
		person->showMenu();

		//用户输入选择
		int select;
		cin >> select;
		if (select == 1) //查看所有的预约
		{
			pointer->show_all_Order();
		}
		else if (select == 2) //审核
		{
			pointer->checkOrder();
		}
		else  //注销登录，跳出子菜单功能循环
		{
			delete pointer;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}


//析构函数
SystemManager::~SystemManager()
{

}