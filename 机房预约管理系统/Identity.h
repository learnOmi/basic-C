#pragma once
#include<iostream>
#include<string>
using namespace std;

class Identity  //��� �����ࣻ���������������ԺͲ���
{
public:
	virtual void showMenu() = 0;  //��ʾ�˵�

	string UserNanme;  //�û���
	string Password;  //����
};