#include"OrderFileManage.h"

//���캯��
OrderFileManager::OrderFileManager()
{
	this->InitMap();
}

//�� ���ָ��ַ���
void OrderFileManager::split(string str, map<string, string>& m)
{
	//�ָ�  �� ���ҵ��ַ�
	string key, val;

	int pos = str.find(":");
	if (pos != -1)
	{
		key = str.substr(0, pos);
		val = str.substr(pos + 1, str.size() - pos);
		m.insert(make_pair(key, val));
	}
}

//��ʼ��Map
void OrderFileManager::InitMap()
{
	ifstream ifs(Order_File, ios::in);
	this->order_num = 0;
	//�ö�Ӧ���ֶν����ļ��еĶ�Ӧ���ݣ��������� xx��xxx�ĸ�ʽ
	string date, span, studId, username, roomId, status;
	while (ifs >> studId && ifs >> username && ifs >> date && ifs >> span && ifs >> roomId && ifs >> status)
	{
		map<string, string> m;
		this->split(studId, m);
		this->split(username, m);
		this->split(date,m);
		this->split(span, m);
		this->split(roomId, m);
		this->split(status, m);
		//��mOrder_record�����в���һ����¼
		this->mOrder_record.insert(make_pair(this->order_num, m));
		this->order_num++;
	}
	ifs.close();
}

//���¼�¼
void OrderFileManager::updateOrder()
{
	if (this->order_num == 0)
	{
		//�޼�¼���ò���
		return;
	}
	//���浽Order_File.txt
	ofstream ofs(Order_File, ios::out|ios::trunc);
	for (int i = 0; i < mOrder_record.size(); i++)
	{
		ofs << "studId:" << this->mOrder_record[i]["studId"] << " " << "username:" << this->mOrder_record[i]["username"] << " "
			<< "date:" << this->mOrder_record[i]["date"] << " " << " time:" << this->mOrder_record[i]["time"] << " " << "roomId:" << this->mOrder_record[i]["roomId"] 
			<< " " << "status" << this->mOrder_record[i]["status"] << endl;

	}
	ofs.close();
	//���¼�¼֮�����¶���Map����
	this->InitMap();
}