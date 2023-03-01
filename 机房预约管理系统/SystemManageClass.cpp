#include "SystemManageClass.h"
#include<fstream>
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Administrator.h"

//Ĭ�Ϲ��캯��
SystemManager::SystemManager()
{

}

//��¼����
void SystemManager::Login(int type, string filename)
{
	//����ָ��ָ��������󣬷�������˵�
	Identity* person = NULL;

	//��ȡ��Ӧ�ļ�¼�ļ�
	ifstream ifs(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "û���κ��û����û���¼��ȡʧ�ܣ�" << endl;
		ifs.close();
		return;
	}

	int id = 0;  //���ܽ�ʦ����ѧ����id
	string username;  //�û���
	string pwd;  //����
	if (type == 1)
	{
		cout << "������ѧ��" << endl;
		cin >> id;
	}
	else if(type == 2)
	{
		cout << "�������ʦ���" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> username;
	cout << "����������" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ�������֤
		int temp_id;
		string temp_name;
		string temp_pwd;
		while (ifs >> temp_id && ifs >> temp_name && ifs >> temp_pwd)
		{
			if (id == temp_id && username == temp_name && pwd == temp_pwd)
			{
				cout << "��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				//��¼�ɹ�����ʾ��Ӧ�Ĳ˵�����
				person = new Student(id, username, pwd);
				this->studentSonMenu(person);
				return;
			}
		}

	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int temp_id2;
		string temp_name2;
		string temp_pwd2;
		while (ifs >> temp_id2 && ifs >> temp_name2 && ifs >> temp_pwd2)
		{
			if (id == temp_id2 && username == temp_name2 && pwd == temp_pwd2)
			{
				cout << "��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				//��¼�ɹ�����ʾ��Ӧ�Ĳ˵�����
				person = new Teacher(id, username, pwd);
				this->teacherSonMenu(person);
				return;
			}
		}
	}
	else
	{
		//����Ա��֤
		string temp_name3;
		string temp_pwd3;
		while (ifs >> temp_name3 && ifs >> temp_pwd3)
		{
			if (username == temp_name3 && pwd == temp_pwd3)
			{
				cout << "��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				//��¼�ɹ�����ʾ��Ӧ�Ĳ˵�����
				person = new Administrator(username, pwd);
				this->managerSonMenu(person);
				return;
			}
		}
	}

	cout << "��¼ʧ��!" << endl;
	system("pause");
	system("cls");
	return;
}

//����Ա��ݵ�¼����Ӳ˵�����,��Ϊ��ͬ��ݵ�¼���ӽ������ܴ�����˵����д��һ��������
void SystemManager::managerSonMenu(Identity* & person)
{
	//����ָ��ǿ��ת��Ϊ����ָ��,�Ա���������������Ա
	Administrator* pointer = (Administrator*)person;

	//����Ա�˵�����ѭ��
	while (true)
	{
		//�����Ӳ˵�
		person->showMenu();

		//�û�����ѡ��
		int select;
		cin >> select;
		if (select == 1) //����˺�
		{
			pointer->addUser();
		}
		else if (select == 2) //�鿴�˺�
		{
			pointer->showUser();
		}
		else if (select == 3)  //�鿴����
		{
			pointer->showComputer();
		}
		else if (select == 4)  //���ԤԼ
		{
			pointer->ClearOrder();
		}
		else  //ע����¼�������Ӳ˵�����ѭ��
		{
			delete pointer;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	
}

//ѧ����ݵ�¼����Ӳ˵�����
void SystemManager::studentSonMenu(Identity*& person)
{
	//����ָ��ǿ��ת��Ϊ����ָ��,�Ա���������������Ա
	Student* pointer = (Student*)person;

	//����Ա�˵�����ѭ��
	while (true)
	{
		//�����Ӳ˵�
		person->showMenu();

		//�û�����ѡ��
		int select;
		cin >> select;
		if (select == 1) //����ԤԼ
		{
			pointer->applyOreder();
		}
		else if (select == 2) //�鿴����ԤԼ
		{
			pointer->show_my_Order();
		}
		else if (select == 3)  //�鿴����ԤԼ
		{
			pointer->show_all_Order();
		}
		else if (select == 4)  //ȡ��ԤԼ
		{
			pointer->cancelOrder();
		}
		else  //ע����¼�������Ӳ˵�����ѭ��
		{
			delete pointer;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}


//��ʦ��ݵ�¼����Ӳ˵�����
void SystemManager::teacherSonMenu(Identity*& person)
{
	//����ָ��ǿ��ת��Ϊ����ָ��,�Ա���������������Ա
	Teacher* pointer = (Teacher*)person;

	//����Ա�˵�����ѭ��
	while (true)
	{
		//�����Ӳ˵�
		person->showMenu();

		//�û�����ѡ��
		int select;
		cin >> select;
		if (select == 1) //�鿴���е�ԤԼ
		{
			pointer->show_all_Order();
		}
		else if (select == 2) //���
		{
			pointer->checkOrder();
		}
		else  //ע����¼�������Ӳ˵�����ѭ��
		{
			delete pointer;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}


//��������
SystemManager::~SystemManager()
{

}