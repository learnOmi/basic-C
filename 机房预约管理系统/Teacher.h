#pragma once
#include "Identity.h"
#include "OrderFileManage.h"
#include <vector>

class Teacher:public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι��� ��������ţ�����������
	Teacher(int id, string userName, string pwd);

	//��ʾ�˵�
	virtual void showMenu();

	//��ʾ����ԤԼ��Ϣ
	void show_all_Order();

	//���
	void checkOrder();

	//���
	int id;
};