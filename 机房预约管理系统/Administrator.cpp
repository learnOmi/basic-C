#include"Administrator.h"

//Ĭ�Ϲ��캯��
Administrator::Administrator()
{
	this->Initvector();
}

//�вι��� �������˺š����ơ�����
Administrator::Administrator(string username, string pwd)
{
	this->UserNanme = username;
	this->Password = pwd;
	this->Initvector();
}

//�˵�����
void Administrator::showMenu()
{
	cout << "-----------------����Ա"<< this->UserNanme << "------------------ " << endl;
	cout << endl << "��������Ȩ��:" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "\t\t--------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|            1.����˺�              |\n";
	cout << "\t\t|            2.�鿴�˺�             |\n";
	cout << "\t\t|            3.�鿴����              |\n";
	cout << "\t\t|            4.���ԤԼ              |\n";
	cout << "\t\t|            0.ע����¼              |\n";
	cout << "\t\t--------------------------------------\n";
	cout << "----------------------------------------------------------" << endl;
	cout << "��������ѡ��" << endl;
	cout << "----------------------------------------------------------" << endl;
}


//��ӡ��¼��ʽ�ĺ���
void myprint(Teacher t)
{
	cout << "id:" << t.id << "\t" << "�û���" << t.UserNanme << "\t" << "����:" << t.Password << endl;
}

void myprint2(Student& t)
{
	cout << "id:" << t.id << "\t" << "�û���" << t.UserNanme << "\t" << "����:" << t.Password << endl;
}

void myprint3(ComputerRoom& t)
{
	cout << "������:" << t.rm_nmb << "\t" << "������" << t.num <<  endl;
}

//�鿴�û�
void Administrator::showUser()
{
	cout << "Ҫ�鿴���û��˺������ǣ�" << endl;
	cout << "1.��ʦ��2.ѧ��" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		if (vTeach.size() == 0)
		{
			cout << "�������κν�ʦ�˻���" << endl;
			system("pause");
			system("cls");
			return;
		}

		cout << "���еĽ�ʦ�˻�Ϊ��" << endl;
		for_each(vTeach.begin(), vTeach.end(), myprint);
	}
	else if(select == 2)
	{
		if (vStud.size() == 0)
		{
			cout << "�������κ�ѧ���˻���" << endl;
			return;
		}

		cout << "���е�ѧ���˻�Ϊ��" << endl;
		for_each(vStud.begin(), vStud.end(), myprint2);
	}
	system("pause");
	system("cls");
}

//����û�
void Administrator::addUser()
{
	int type;  //�������������
	int code;  //���ձ�Ż�ѧ��
	string filename; //ȷ�������ĸ��ļ�
	while (true)
	{
		cout << "��ѡ����ӵ��˺����ͣ�" << endl;
		cout << "1.��ʦ��2.ѧ��" << endl;

		cin >> type;
		if (type == 1)
		{
			cout << "�������ʦ��ţ�" << endl;
			filename = Teach_File;
		}
		else if (type == 2)
		{
			cout << "������ѧ�ţ�" << endl;
			filename = Stud_File;
		}
		else
		{
			cout << "ѡ����ȷ������������" << endl;
			system("pause");
			//���Ͳ���ȷֱ�ӽ�����һ��ѭ��
			continue;
		}
		cin >> code;
		//�ж��Ƿ��Ѿ������˸��û�
		while (this->isExisted(code, type))
		{
			cout << "�ú�����ʹ�ã�������������ȷ�ĺ���:" << endl;
			cin >> code;
		}
		//û���ظ����˳�ѭ��
		break;
	}


	//�����û���������
	string username, pwd;
	cout << "�������û���:" << endl;
	cin >> username;
	cout << "����������:" << endl;
	cin >> pwd;

	//�����¼���ļ�
	ofstream ofs(filename, ios::out | ios::app);
	ofs << code << " " << username << " " << pwd << endl;
	ofs.close();

	cout << "��ӳɹ���" << endl;
	system("pause");
	system("cls");

	//���������еļ�¼
	this->Initvector();
}


//�鿴������Ϣ
void Administrator::showComputer()
{
	cout << "���еĻ�����Ϣ����" << endl;
	for_each(vComp.begin(), vComp.end(), myprint3);
}

//���ԤԼ
void Administrator::ClearOrder()
{
	ofstream ofs(Order_File, ios::trunc);
	ofs.close();
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Administrator::Initvector()
{
	//����������ܴ���ô���أ�

	//��Ϊÿ������˺ŵĹ��̶�����룬��ֹǰһ�ζ�������ݲ���
	this->vStud.clear();
	this->vTeach.clear();

	//�����ʦ��¼
	ifstream ifs(Teach_File, ios::in);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		ifs.close();
		return;
	}


	Teacher t;
	while (ifs>>t.id&&ifs>>t.UserNanme&&ifs>>t.Password)
	{
		this->vTeach.push_back(t); //***��֪Ϊ�Σ�д����������Ĳ��뷽ʽ���벻��ȥ
	}
	ifs.close();

	//����ѧ����¼
	ifstream ifs2(Stud_File, ios::in);
	if (!ifs2.is_open())
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		ifs2.close();
		return;
	}

	Student s;
	while (ifs2 >> s.id && ifs2 >> s.UserNanme && ifs2 >> s.Password)
	{
		this->vStud.push_back(s);
	}
	ifs2.close();

	//���������Ϣ
	ifstream ifs3(Comp_File, ios::in);
	ComputerRoom cr;
	while (ifs3 >> cr.rm_nmb && ifs3 >> cr.num)
	{
		this->vComp.push_back(cr);
	}
	ifs3.close();
}


//����ظ����� ������ѧ������ְ����ţ��������
bool Administrator::isExisted(int id, int type)
{
	//cout << "����isExitsted()" << endl;
	if (type == 1)
	{
		for (vector<Teacher>::iterator it = this->vTeach.begin(); it != this->vTeach.end(); it++)
		{
			if (id == it->id)
			{
				//cout << "����ʦ�Ѿ�����" << endl;
				return true;
			}
		}
		return false;
	}
	else if (type == 2)
	{
		for (vector<Student>::iterator it = this->vStud.begin(); it != this->vStud.end(); it++)
		{
			if (id == it->id)
			{
				//cout << "��ѧ���Ѿ�����" << endl;
				return true;
			}
		}
		return false;
	}
}