#include"Teacher.h"

//Ĭ�Ϲ���
Teacher::Teacher()
{

}

//�вι��� ��������ţ�����������
Teacher::Teacher(int id, string userName, string pwd)
{
	this->id == id;
	this->UserNanme = userName;
	this->Password= pwd;
}

//��ʾ�˵�
void Teacher::showMenu()
{
	cout << "-----------------��ʦ��" << this->UserNanme << "------------------ " << endl;
	cout << endl << "��������Ȩ��:" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "\t\t--------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|          1.�鿴����ԤԼ            |\n";
	cout << "\t\t|          2.  ���ԤԼ              |\n";
	cout << "\t\t|          0.  ע����¼              |\n";
	cout << "\t\t--------------------------------------\n";
	cout << "----------------------------------------------------------" << endl;
	cout << "��������ѡ��" << endl;
	cout << "----------------------------------------------------------" << endl;
}

//��ʾ����ԤԼ��Ϣ
void Teacher::show_all_Order()
{
	OrderFileManager orf;
	if (orf.order_num == 0)
	{
		cout << "��¼�����ڣ�" << endl;
		system("pause");
		system("cls");
		return;
	}

	map<int, string> mstatus;
	mstatus.insert(make_pair(1, "�����"));
	mstatus.insert(make_pair(2, "��ԤԼ"));
	mstatus.insert(make_pair(-1, "ԤԼʧ��"));
	mstatus.insert(make_pair(0, "ԤԼȡ��"));

	//�������ԤԼ��¼
	for (int i = 0; i < orf.order_num; i++)
	{
		cout << i + 1 << "��" << "ѧ��:" << orf.mOrder_record[i]["studId"] << " " << "�û���:" << orf.mOrder_record[i]["username"] << " "
			<< "����: ��" << orf.mOrder_record[i]["date"] << " " << " ʱ���:" << (orf.mOrder_record[i]["time"] == "1" ? "����" : "����") << " "
			<< "�������:" << orf.mOrder_record[i]["roomId"] << " " << "״̬��" << mstatus[atoi(orf.mOrder_record[i]["status"].c_str())] << endl;
	}
}

//���
void Teacher::checkOrder()
{
	OrderFileManager orf;
	//�ж��Ƿ��м�¼
	if (orf.order_num == 0)
	{
		cout << "��¼�����ڣ�" << endl;
		system("pause");
		system("cls");
		return;
	}

	//�������ֺ�״̬�Ķ�Ӧ
	map<int, string> mstatus;
	mstatus.insert(make_pair(1, "�����"));
	mstatus.insert(make_pair(2, "��ԤԼ"));
	mstatus.insert(make_pair(-1, "ԤԼʧ��"));
	mstatus.insert(make_pair(0, "ԤԼȡ��"));

	vector<int> mOrder_record_number;//��¼�ҵ��ķ���Ҫ��ļ�¼�����ļ��еĵڼ���
	//Ѱ��״̬Ϊ1�ļ�¼
	for (int i = 0,index = 1; i < orf.order_num; i++)
	{
		if ("1" == orf.mOrder_record[i]["status"] )
		{
			mOrder_record_number.push_back(i);
			//��ʾ���������ļ�¼
			cout << index++ << "��" << "ѧ��:" << orf.mOrder_record[i]["studId"] << " " << "�û���:" << orf.mOrder_record[i]["username"] << " "
				<< "����: ��" << orf.mOrder_record[i]["date"] << " " << " ʱ���:" << (orf.mOrder_record[i]["time"] == "1" ? "����" : "����") << " "
				<< "�������:" << orf.mOrder_record[i]["roomId"] << " " << "״̬��" << mstatus[atoi(orf.mOrder_record[i]["status"].c_str())] << endl;
		}
		else
		{
			cout << "û�п��Խ�����˵�ԤԼ��¼��" << endl;
		}
	}
	cout << "��������Ҫ��˵ļ�¼,0�����أ�" << endl;
	int select;
	while (true)
	{
		cin >> select;
		if (select == 0)
		{
			return;
		}
		if (select >= 1 && select <= mOrder_record_number.size())
		{
			cout << "��ȷ������Ƿ�ͨ����1.ͨ����2.��ͨ��" << endl;
			while (true)
			{
				cin >> select;  //select����
				if (select == 1)
				{
					orf.mOrder_record[mOrder_record_number[select - 1]]["status"] = "2";  
					orf.updateOrder();
					break;
				}
				else if(select == 2)
				{
					orf.mOrder_record[mOrder_record_number[select - 1]]["status"] = "-1"; 
					orf.updateOrder();
					break;
				}
				cout << "���벻��ȷ�����������룡" << endl;
			}
			break;  //ֻ�ý���һ�����
		}
		cout << "�����������������룡" << endl;
	}

	cout << "��˳ɹ���" << endl;
	system("pause");
	system("cls");
}