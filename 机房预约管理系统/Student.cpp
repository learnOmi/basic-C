#include"Student.h"

//Ĭ�Ϲ���
Student::Student()
{

}

//�вι���  ������ѧ�š�����������
Student::Student(int id, string username, string pwd)
{
	this->id == id;
	this->UserNanme = username;
	this->Password = pwd;
	this->InitVector();
}

//����˵�
void Student::showMenu()
{
	cout << "-----------------ѧ����" << this->UserNanme << "------------------ " << endl;
	cout << endl << "��������Ȩ��:" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "\t\t--------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|          1.  ����ԤԼ              |\n";
	cout << "\t\t|          2.�鿴����ԤԼ            |\n";
	cout << "\t\t|          3.�鿴����ԤԼ            |\n";
	cout << "\t\t|          4.  ȡ��ԤԼ              |\n";
	cout << "\t\t|          0.  ע����¼              |\n";
	cout << "\t\t--------------------------------------\n";
	cout << "----------------------------------------------------------" << endl;
	cout << "��������ѡ��" << endl;
	cout << "----------------------------------------------------------" << endl;
}

//��ʼ������,���������Ϣ
void Student::InitVector()
{
	ifstream ifs(Comp_File, ios::in);
	ComputerRoom cr;
	while (ifs >> cr.rm_nmb && ifs >> cr.num)
	{
		this->vComp.push_back(cr);
	}
	ifs.close();
}

//��ӡ����
void myprint(ComputerRoom& cr)
{
	cout << "������ţ�" << cr.rm_nmb << "\t" << "ʣ��������" << cr.num << endl;
}


//��ʾ������Ϣ
void Student::showComputerRoom()
{
	for_each(this->vComp.begin(), this->vComp.end(), myprint);
}

//����ԤԼ
void Student::applyOreder()
{
	//���������ڣ������磬�����
	int date, span, room_numb;
	
	while (true)
	{
		cout << "��ѡ����һ�����壺" << endl;
		cout << "1.��һ��2.�ܶ���3.������4.���ģ�5.����" << endl;
		cin >> date;
		if(date>=1&&date <=5)
		{
			break;
		}
		cout << "����������!" << endl;
	}

	while (true)
	{
		cout << "��ѡ��ʱ��Σ�" << endl;
		cout << "1.���磻2.����" << endl;
		cin >> span;
		if (span >= 1 && date <= 2)
		{
			break;
		}
		cout << "����������!" << endl;
	}

	//��ʾ������Ϣ
	this->showComputerRoom();

	while (true)
	{
		cout << "��ѡ����������������ţ�" << endl;
		cin >> room_numb;
		if (room_numb >= 1 && room_numb <= 3)  //�����൱���޶��˻����ı���ˣ���Ҫ�����ӵĹ�����Ҫ����������ݸ�ʽ
		{
			break;
		}
		cout << "����������!" << endl;
	}

	cout << "ԤԼ�ɹ��������" << endl;

	//�����¼���ļ�
	ofstream ofs(Order_File,ios::out | ios::app);
	ofs << "studId:" << this->id << " " << "username:" << this->UserNanme << " "
		<< "date:" << date << " " << " time:" << span << " " << "roomId:" << room_numb << "status"<< 1 << endl;
	ofs.close();

	cout << "ԤԼ�У���ȴ���ʦ��ˣ�" << endl;
	system("pause");
}

//�鿴����ԤԼ
void Student::show_my_Order()
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
	//Ѱ�Һ�����id��ȵ�ԤԼ��¼
	for (int i = 0; i < orf.order_num; i++)
	{
		if (this->id == atoi(orf.mOrder_record[i]["studId"].c_str()))  //c_str()��stringת��Ϊconst char*, atoi()��const char*ת��Ϊint
		{
			cout<< "ѧ��:" << orf.mOrder_record[i]["studId"] << " " << "�û���:" << orf.mOrder_record[i]["username"] << " "
				<< "����: ��" << orf.mOrder_record[i]["date"] << " " << " ʱ���:" << (orf.mOrder_record[i]["time"]== "1" ? "����" : "����" ) << " " 
				<< "�������:" << orf.mOrder_record[i]["roomId"] << " " << "״̬��" << mstatus[atoi(orf.mOrder_record[i]["status"].c_str())] << endl;
		}
	}
}

//�鿴����ԤԼ
void Student::show_all_Order() 
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
		cout << i+1 << "��" << "ѧ��:" << orf.mOrder_record[i]["studId"] << " " << "�û���:" << orf.mOrder_record[i]["username"] << " "
			<< "����: ��" << orf.mOrder_record[i]["date"] << " " << " ʱ���:" << (orf.mOrder_record[i]["time"] == "1" ? "����" : "����") << " "
			<< "�������:" << orf.mOrder_record[i]["roomId"] << " " << "״̬��" << mstatus[atoi(orf.mOrder_record[i]["status"].c_str())] << endl;
	}
}

//ȡ��ԤԼ
void Student::cancelOrder()
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

	cout << "ֻ��״̬Ϊ������л�����ԤԼ �Ĳſ���ȡ����" << endl;

	
	vector<int> mOrder_record_number;//��¼�ҵ��ķ���Ҫ��ļ�¼�����ļ��еĵڼ���
	//Ѱ���Լ���״̬Ϊ1��2�ļ�¼
	for (int i = 0,index=1; i < orf.order_num; i++)
	{
		if (atoi(orf.mOrder_record[i]["studId"].c_str()) == this->id)
		{
			if ("1" == orf.mOrder_record[i]["status"] || "2" == orf.mOrder_record[i]["status"])  
			{
				mOrder_record_number.push_back(i);
				//��ʾ���������ļ�¼
				cout << index++ << "��" << "ѧ��:" << orf.mOrder_record[i]["studId"] << " " << "�û���:" << orf.mOrder_record[i]["username"] << " "
					<< "����: ��" << orf.mOrder_record[i]["date"] << " " << " ʱ���:" << (orf.mOrder_record[i]["time"] == "1" ? "����" : "����") << " "
					<< "�������:" << orf.mOrder_record[i]["roomId"] << " " << "״̬��" << mstatus[atoi(orf.mOrder_record[i]["status"].c_str())] << endl;
			}
			else
			{
				cout << "û�п��Խ���ȡ��ԤԼ�ļ�¼��" << endl;
			}
		}
	}
	cout << "��������Ҫȡ���ļ�¼,0�����أ�" << endl;
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
			orf.mOrder_record[mOrder_record_number[select - 1]]["status"] = "0";  //ֻ�ý���һ�θ��ģ���Ҫ���ж�θ��ģ���Ҫ���°Ѹ��º�ļ�¼����ʾһ��
			orf.updateOrder();
			break;
		}
		cout << "�����������������룡" << endl;
	}
	
	cout << "ȡ��ԤԼ�ɹ���" << endl;
	system("pause");
	system("cls");
}