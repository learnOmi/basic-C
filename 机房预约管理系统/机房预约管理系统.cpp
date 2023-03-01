#include<iostream>
#include"SystemManageClass.h"
#include"Global_File.h"
using namespace std;

int main()
{
	SystemManager sm;

	while (true)
	{
		cout << "-----------------欢迎来到机房预约管理系统-----------------" << endl;
		cout << endl << "请输入您的身份进行登录:" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "\t\t--------------------------------------\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|            1.学生代表              |\n";
		cout << "\t\t|            2.老    师              |\n";
		cout << "\t\t|            3.管 理 员              |\n";
		cout << "\t\t|            0.退    出              |\n";
		cout << "\t\t--------------------------------------\n";
		cout << "----------------------------------------------------------" << endl;
		cout << "输入您的选择：" << endl;
		cout << "----------------------------------------------------------" << endl;

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1://学生代表
			sm.Login(choice, Stud_File);
			system("pause");
			system("cls");
			break;
		case 2://老师
			sm.Login(choice, Teach_File);
			system("pause");
			system("cls");
			break;
		case 3://管理员
			sm.Login(choice, Admin_File);
			system("pause");
			system("cls");
			break;
		case 0://退出
			cout << "欢迎下一次使用" << endl;
			system("pause");
			system("cls");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}