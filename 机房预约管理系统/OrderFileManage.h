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
	//���캯��
	OrderFileManager();

	//�� ���ָ������ַ���
	void split(string str, map<string, string>& m);

	//��ʼ������
	void InitMap();

	//���¼�¼
	void updateOrder();

	//��¼ԤԼ����
	int order_num;

	//��¼���е�ԤԼ��¼��Ϣ, keyΪ��¼���� value�����¼��ֵ����Ϣ
	map<int, map<string, string>> mOrder_record;
};