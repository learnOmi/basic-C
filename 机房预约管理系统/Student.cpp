#include"Student.h"

//默认构造
Student::Student()
{

}

//有参构造  参数：学号、姓名、密码
Student::Student(int id, string username, string pwd)
{
	this->id == id;
	this->UserNanme = username;
	this->Password = pwd;
	this->InitVector();
}

//界面菜单
void Student::showMenu()
{
	cout << "-----------------学生：" << this->UserNanme << "------------------ " << endl;
	cout << endl << "您有以下权限:" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "\t\t--------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|          1.  申请预约              |\n";
	cout << "\t\t|          2.查看自身预约            |\n";
	cout << "\t\t|          3.查看所有预约            |\n";
	cout << "\t\t|          4.  取消预约              |\n";
	cout << "\t\t|          0.  注销登录              |\n";
	cout << "\t\t--------------------------------------\n";
	cout << "----------------------------------------------------------" << endl;
	cout << "输入您的选择：" << endl;
	cout << "----------------------------------------------------------" << endl;
}

//初始化容器,读入机房信息
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

//打印函数
void myprint(ComputerRoom& cr)
{
	cout << "机房编号：" << cr.rm_nmb << "\t" << "剩余数量：" << cr.num << endl;
}


//显示机房信息
void Student::showComputerRoom()
{
	for_each(this->vComp.begin(), this->vComp.end(), myprint);
}

//申请预约
void Student::applyOreder()
{
	//参数：星期，上下午，房间号
	int date, span, room_numb;
	
	while (true)
	{
		cout << "请选择周一至周五：" << endl;
		cout << "1.周一；2.周二；3.周三；4.周四；5.周五" << endl;
		cin >> date;
		if(date>=1&&date <=5)
		{
			break;
		}
		cout << "请重新输入!" << endl;
	}

	while (true)
	{
		cout << "请选择时间段：" << endl;
		cout << "1.上午；2.下午" << endl;
		cin >> span;
		if (span >= 1 && date <= 2)
		{
			break;
		}
		cout << "请重新输入!" << endl;
	}

	//显示机房信息
	this->showComputerRoom();

	while (true)
	{
		cout << "请选择机房，输入机房编号：" << endl;
		cin >> room_numb;
		if (room_numb >= 1 && room_numb <= 3)  //这里相当于限定了机房的编号了，想要更复杂的功能需要重新设计数据格式
		{
			break;
		}
		cout << "请重新输入!" << endl;
	}

	cout << "预约成功！审核中" << endl;

	//输出记录到文件
	ofstream ofs(Order_File,ios::out | ios::app);
	ofs << "studId:" << this->id << " " << "username:" << this->UserNanme << " "
		<< "date:" << date << " " << " time:" << span << " " << "roomId:" << room_numb << "status"<< 1 << endl;
	ofs.close();

	cout << "预约中，请等待老师审核！" << endl;
	system("pause");
}

//查看自身预约
void Student::show_my_Order()
{
	OrderFileManager orf;
	//判断是否有记录
	if (orf.order_num == 0)
	{
		cout << "记录不存在！" << endl;
		system("pause");
		system("cls");
		return;
	}

	//用于数字和状态的对应
	map<int, string> mstatus;
	mstatus.insert(make_pair(1, "审核中"));
	mstatus.insert(make_pair(2, "已预约"));
	mstatus.insert(make_pair(-1, "预约失败"));
	mstatus.insert(make_pair(0, "预约取消"));
	//寻找和自身id相等的预约记录
	for (int i = 0; i < orf.order_num; i++)
	{
		if (this->id == atoi(orf.mOrder_record[i]["studId"].c_str()))  //c_str()把string转化为const char*, atoi()把const char*转化为int
		{
			cout<< "学号:" << orf.mOrder_record[i]["studId"] << " " << "用户名:" << orf.mOrder_record[i]["username"] << " "
				<< "日期: 周" << orf.mOrder_record[i]["date"] << " " << " 时间段:" << (orf.mOrder_record[i]["time"]== "1" ? "上午" : "下午" ) << " " 
				<< "机房编号:" << orf.mOrder_record[i]["roomId"] << " " << "状态：" << mstatus[atoi(orf.mOrder_record[i]["status"].c_str())] << endl;
		}
	}
}

//查看所有预约
void Student::show_all_Order() 
{
	OrderFileManager orf;
	if (orf.order_num == 0)
	{
		cout << "记录不存在！" << endl;
		system("pause");
		system("cls");
		return;
	}

	map<int, string> mstatus;
	mstatus.insert(make_pair(1, "审核中"));
	mstatus.insert(make_pair(2, "已预约"));
	mstatus.insert(make_pair(-1, "预约失败"));
	mstatus.insert(make_pair(0, "预约取消"));

	//输出所有预约记录
	for (int i = 0; i < orf.order_num; i++)
	{
		cout << i+1 << "、" << "学号:" << orf.mOrder_record[i]["studId"] << " " << "用户名:" << orf.mOrder_record[i]["username"] << " "
			<< "日期: 周" << orf.mOrder_record[i]["date"] << " " << " 时间段:" << (orf.mOrder_record[i]["time"] == "1" ? "上午" : "下午") << " "
			<< "机房编号:" << orf.mOrder_record[i]["roomId"] << " " << "状态：" << mstatus[atoi(orf.mOrder_record[i]["status"].c_str())] << endl;
	}
}

//取消预约
void Student::cancelOrder()
{
	OrderFileManager orf;
	//判断是否有记录
	if (orf.order_num == 0)
	{
		cout << "记录不存在！" << endl;
		system("pause");
		system("cls");
		return;
	}

	//用于数字和状态的对应
	map<int, string> mstatus;
	mstatus.insert(make_pair(1, "审核中"));
	mstatus.insert(make_pair(2, "已预约"));
	mstatus.insert(make_pair(-1, "预约失败"));
	mstatus.insert(make_pair(0, "预约取消"));

	cout << "只有状态为：审核中或者已预约 的才可以取消！" << endl;

	
	vector<int> mOrder_record_number;//记录找到的符合要求的记录是在文件中的第几条
	//寻找自己的状态为1或2的记录
	for (int i = 0,index=1; i < orf.order_num; i++)
	{
		if (atoi(orf.mOrder_record[i]["studId"].c_str()) == this->id)
		{
			if ("1" == orf.mOrder_record[i]["status"] || "2" == orf.mOrder_record[i]["status"])  
			{
				mOrder_record_number.push_back(i);
				//显示符合条件的记录
				cout << index++ << "、" << "学号:" << orf.mOrder_record[i]["studId"] << " " << "用户名:" << orf.mOrder_record[i]["username"] << " "
					<< "日期: 周" << orf.mOrder_record[i]["date"] << " " << " 时间段:" << (orf.mOrder_record[i]["time"] == "1" ? "上午" : "下午") << " "
					<< "机房编号:" << orf.mOrder_record[i]["roomId"] << " " << "状态：" << mstatus[atoi(orf.mOrder_record[i]["status"].c_str())] << endl;
			}
			else
			{
				cout << "没有可以进行取消预约的记录！" << endl;
			}
		}
	}
	cout << "请输入您要取消的记录,0代表返回：" << endl;
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
			orf.mOrder_record[mOrder_record_number[select - 1]]["status"] = "0";  //只让进行一次更改，想要进行多次更改，需要重新把更新后的记录再显示一边
			orf.updateOrder();
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	
	cout << "取消预约成功！" << endl;
	system("pause");
	system("cls");
}