#include"OrderFileManage.h"

//构造函数
OrderFileManager::OrderFileManager()
{
	this->InitMap();
}

//以 ：分割字符串
void OrderFileManager::split(string str, map<string, string>& m)
{
	//分割  ： 左右的字符
	string key, val;

	int pos = str.find(":");
	if (pos != -1)
	{
		key = str.substr(0, pos);
		val = str.substr(pos + 1, str.size() - pos);
		m.insert(make_pair(key, val));
	}
}

//初始化Map
void OrderFileManager::InitMap()
{
	ifstream ifs(Order_File, ios::in);
	this->order_num = 0;
	//用对应的字段接受文件中的对应数据，都是型如 xx：xxx的格式
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
		//往mOrder_record容器中插入一条记录
		this->mOrder_record.insert(make_pair(this->order_num, m));
		this->order_num++;
	}
	ifs.close();
}

//更新记录
void OrderFileManager::updateOrder()
{
	if (this->order_num == 0)
	{
		//无记录不用操作
		return;
	}
	//保存到Order_File.txt
	ofstream ofs(Order_File, ios::out|ios::trunc);
	for (int i = 0; i < mOrder_record.size(); i++)
	{
		ofs << "studId:" << this->mOrder_record[i]["studId"] << " " << "username:" << this->mOrder_record[i]["username"] << " "
			<< "date:" << this->mOrder_record[i]["date"] << " " << " time:" << this->mOrder_record[i]["time"] << " " << "roomId:" << this->mOrder_record[i]["roomId"] 
			<< " " << "status" << this->mOrder_record[i]["status"] << endl;

	}
	ofs.close();
	//更新记录之后重新读入Map容器
	this->InitMap();
}