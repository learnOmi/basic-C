#pragma once
#include"Identity.h"
#include"Global_File.h"
#include "ComputerRoom.h"
#include <vector>
#include<fstream>
#include <algorithm>
#include"OrderFileManage.h"

class Student :public Identity
{
public:
	//Ĭ�Ϲ���
	Student();

	//�вι���  ������ѧ�š�����������
	Student(int id,string username,string pwd);

	//����˵�
	virtual void showMenu();

	//��ʼ������
	void InitVector();

	//��ʾ������Ϣ
	void showComputerRoom();

	//����ԤԼ
	void applyOreder();

	//�鿴����ԤԼ
	void show_my_Order();

	//�鿴����ԤԼ
	void show_all_Order();

	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ��ѧ��
	int id;
	//������Ϣ
	vector<ComputerRoom> vComp;
};