#include<iostream>
#include"SystemManageClass.h"
#include"Global_File.h"
using namespace std;

int main()
{
	SystemManager sm;

	while (true)
	{
		cout << "-----------------��ӭ��������ԤԼ����ϵͳ-----------------" << endl;
		cout << endl << "������������ݽ��е�¼:" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "\t\t--------------------------------------\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|            1.ѧ������              |\n";
		cout << "\t\t|            2.��    ʦ              |\n";
		cout << "\t\t|            3.�� �� Ա              |\n";
		cout << "\t\t|            0.��    ��              |\n";
		cout << "\t\t--------------------------------------\n";
		cout << "----------------------------------------------------------" << endl;
		cout << "��������ѡ��" << endl;
		cout << "----------------------------------------------------------" << endl;

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1://ѧ������
			sm.Login(choice, Stud_File);
			system("pause");
			system("cls");
			break;
		case 2://��ʦ
			sm.Login(choice, Teach_File);
			system("pause");
			system("cls");
			break;
		case 3://����Ա
			sm.Login(choice, Admin_File);
			system("pause");
			system("cls");
			break;
		case 0://�˳�
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			system("cls");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}