#include"Teacher.h"

//默认构造
Teacher::Teacher()
{

}

//有参构造 参数：编号，姓名，密码
Teacher::Teacher(int id, string userName, string pwd)
{
	this->id == id;
	this->UserNanme = userName;
	this->Password= pwd;
}

//显示菜单
void Teacher::showMenu()
{
	cout << "-----------------老师：" << this->UserNanme << "------------------ " << endl;
	cout << endl << "您有以下权限:" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "\t\t--------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|          1.查看所有预约            |\n";
	cout << "\t\t|          2.  审核预约              |\n";
	cout << "\t\t|          0.  注销登录              |\n";
	cout << "\t\t--------------------------------------\n";
	cout << "----------------------------------------------------------" << endl;
	cout << "输入您的选择：" << endl;
	cout << "----------------------------------------------------------" << endl;
}

//显示所有预约信息
void Teacher::show_all_Order()
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
		cout << i + 1 << "、" << "学号:" << orf.mOrder_record[i]["studId"] << " " << "用户名:" << orf.mOrder_record[i]["username"] << " "
			<< "日期: 周" << orf.mOrder_record[i]["date"] << " " << " 时间段:" << (orf.mOrder_record[i]["time"] == "1" ? "上午" : "下午") << " "
			<< "机房编号:" << orf.mOrder_record[i]["roomId"] << " " << "状态：" << mstatus[atoi(orf.mOrder_record[i]["status"].c_str())] << endl;
	}
}

//审核
void Teacher::checkOrder()
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

	vector<int> mOrder_record_number;//记录找到的符合要求的记录是在文件中的第几条
	//寻找状态为1的记录
	for (int i = 0,index = 1; i < orf.order_num; i++)
	{
		if ("1" == orf.mOrder_record[i]["status"] )
		{
			mOrder_record_number.push_back(i);
			//显示符合条件的记录
			cout << index++ << "、" << "学号:" << orf.mOrder_record[i]["studId"] << " " << "用户名:" << orf.mOrder_record[i]["username"] << " "
				<< "日期: 周" << orf.mOrder_record[i]["date"] << " " << " 时间段:" << (orf.mOrder_record[i]["time"] == "1" ? "上午" : "下午") << " "
				<< "机房编号:" << orf.mOrder_record[i]["roomId"] << " " << "状态：" << mstatus[atoi(orf.mOrder_record[i]["status"].c_str())] << endl;
		}
		else
		{
			cout << "没有可以进行审核的预约记录！" << endl;
		}
	}
	cout << "请输入您要审核的记录,0代表返回：" << endl;
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
			cout << "请确认审核是否通过：1.通过；2.不通过" << endl;
			while (true)
			{
				cin >> select;  //select复用
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
				cout << "输入不正确，请重新输入！" << endl;
			}
			break;  //只让进行一次审核
		}
		cout << "输入有误，请重新输入！" << endl;
	}

	cout << "审核成功！" << endl;
	system("pause");
	system("cls");
}