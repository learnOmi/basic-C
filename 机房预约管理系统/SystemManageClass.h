#pragma once
#include<iostream>
#include"Identity.h"


class SystemManager
{
public:
	//Ĭ�Ϲ��캯��
	SystemManager();

	//��¼���� �������������ͣ��ļ���
	void Login(int type,string filename);

	//����Ա��ݵ�½��Ĺ���
	void managerSonMenu(Identity* & person);

	//ѧ����ݵ�¼��Ĺ���
	void studentSonMenu(Identity*& person);

	//��ʦ��ݵ�¼��Ĺ���
	void teacherSonMenu(Identity*& person);

	//��������
	~SystemManager();
};