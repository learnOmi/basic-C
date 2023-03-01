#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include<string>
#include"Global_File.h"
using namespace std;

class OrderFileManager
{
public:
	//构造函数
	OrderFileManager();

	//以 ：分割左右字符串
	void split(string str, map<string, string>& m);

	//初始化容器
	void InitMap();

	//更新记录
	void updateOrder();

	//记录预约条数
	int order_num;

	//记录所有的预约记录信息, key为记录条数 value具体记录键值对信息
	map<int, map<string, string>> mOrder_record;
};