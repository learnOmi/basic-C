#include"Administrator.h"

//默认构造函数
Administrator::Administrator()
{
	this->Initvector();
}

//有参构造 参数：账号、名称、密码
Administrator::Administrator(string username, string pwd)
{
	this->UserNanme = username;
	this->Password = pwd;
	this->Initvector();
}

//菜单界面
void Administrator::showMenu()
{
	cout << "-----------------管理员"<< this->UserNanme << "------------------ " << endl;
	cout << endl << "您有以下权限:" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "\t\t--------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|            1.添加账号              |\n";
	cout << "\t\t|            2.查看账号             |\n";
	cout << "\t\t|            3.查看机房              |\n";
	cout << "\t\t|            4.清空预约              |\n";
	cout << "\t\t|            0.注销登录              |\n";
	cout << "\t\t--------------------------------------\n";
	cout << "----------------------------------------------------------" << endl;
	cout << "输入您的选择：" << endl;
	cout << "----------------------------------------------------------" << endl;
}


//打印记录格式的函数
void myprint(Teacher t)
{
	cout << "id:" << t.id << "\t" << "用户：" << t.UserNanme << "\t" << "密码:" << t.Password << endl;
}

void myprint2(Student& t)
{
	cout << "id:" << t.id << "\t" << "用户：" << t.UserNanme << "\t" << "密码:" << t.Password << endl;
}

void myprint3(ComputerRoom& t)
{
	cout << "机房号:" << t.rm_nmb << "\t" << "数量：" << t.num <<  endl;
}

//查看用户
void Administrator::showUser()
{
	cout << "要查看的用户账号类型是？" << endl;
	cout << "1.老师；2.学生" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		if (vTeach.size() == 0)
		{
			cout << "不存在任何教师账户！" << endl;
			system("pause");
			system("cls");
			return;
		}

		cout << "所有的教师账户为：" << endl;
		for_each(vTeach.begin(), vTeach.end(), myprint);
	}
	else if(select == 2)
	{
		if (vStud.size() == 0)
		{
			cout << "不存在任何学生账户！" << endl;
			return;
		}

		cout << "所有的学生账户为：" << endl;
		for_each(vStud.begin(), vStud.end(), myprint2);
	}
	system("pause");
	system("cls");
}

//添加用户
void Administrator::addUser()
{
	int type;  //接收输入的类型
	int code;  //接收编号或学号
	string filename; //确定操作哪个文件
	while (true)
	{
		cout << "请选择添加的账号类型：" << endl;
		cout << "1.教师；2.学生" << endl;

		cin >> type;
		if (type == 1)
		{
			cout << "请输入教师编号：" << endl;
			filename = Teach_File;
		}
		else if (type == 2)
		{
			cout << "请输入学号：" << endl;
			filename = Stud_File;
		}
		else
		{
			cout << "选择不正确！请重新输入" << endl;
			system("pause");
			//类型不正确直接进行下一轮循环
			continue;
		}
		cin >> code;
		//判断是否已经存在了该用户
		while (this->isExisted(code, type))
		{
			cout << "该号码已使用，请重新输入正确的号码:" << endl;
			cin >> code;
		}
		//没有重复后退出循环
		break;
	}


	//接收用户名和密码
	string username, pwd;
	cout << "请输入用户名:" << endl;
	cin >> username;
	cout << "请输入密码:" << endl;
	cin >> pwd;

	//保存记录到文件
	ofstream ofs(filename, ios::out | ios::app);
	ofs << code << " " << username << " " << pwd << endl;
	ofs.close();

	cout << "添加成功！" << endl;
	system("pause");
	system("cls");

	//更新容器中的记录
	this->Initvector();
}


//查看机房信息
void Administrator::showComputer()
{
	cout << "所有的机房信息如下" << endl;
	for_each(vComp.begin(), vComp.end(), myprint3);
}

//清空预约
void Administrator::ClearOrder()
{
	ofstream ofs(Order_File, ios::trunc);
	ofs.close();
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}

//初始化容器
void Administrator::Initvector()
{
	//如果数据量很大怎么办呢？

	//因为每次添加账号的过程都会读入，防止前一次读入的数据残留
	this->vStud.clear();
	this->vTeach.clear();

	//读入教师记录
	ifstream ifs(Teach_File, ios::in);
	if (!ifs.is_open())
	{
		cout << "打开文件失败！" << endl;
		ifs.close();
		return;
	}


	Teacher t;
	while (ifs>>t.id&&ifs>>t.UserNanme&&ifs>>t.Password)
	{
		this->vTeach.push_back(t); //***不知为何，写用匿名对象的插入方式插入不进去
	}
	ifs.close();

	//读入学生记录
	ifstream ifs2(Stud_File, ios::in);
	if (!ifs2.is_open())
	{
		cout << "打开文件失败！" << endl;
		ifs2.close();
		return;
	}

	Student s;
	while (ifs2 >> s.id && ifs2 >> s.UserNanme && ifs2 >> s.Password)
	{
		this->vStud.push_back(s);
	}
	ifs2.close();

	//读入机房信息
	ifstream ifs3(Comp_File, ios::in);
	ComputerRoom cr;
	while (ifs3 >> cr.rm_nmb && ifs3 >> cr.num)
	{
		this->vComp.push_back(cr);
	}
	ifs3.close();
}


//检测重复参数 参数：学生或者职工编号，检测类型
bool Administrator::isExisted(int id, int type)
{
	//cout << "调用isExitsted()" << endl;
	if (type == 1)
	{
		for (vector<Teacher>::iterator it = this->vTeach.begin(); it != this->vTeach.end(); it++)
		{
			if (id == it->id)
			{
				//cout << "该老师已经存在" << endl;
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
				//cout << "该学生已经存在" << endl;
				return true;
			}
		}
		return false;
	}
}