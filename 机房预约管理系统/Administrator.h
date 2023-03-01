#pragma once
#include "Identity.h"
#include "Global_File.h"
#include <fstream>
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include <algorithm>
#include "ComputerRoom.h"

class Administrator :public Identity
{
public:
	//Ĭ�Ϲ��캯��
	Administrator();

	//�вι��� ���������ơ�����
	Administrator(string username, string pwd);

	//�˵�����
	virtual void showMenu();

	//�鿴�û�
	void showUser();

	//����û�
	void addUser();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ
	void ClearOrder();

	//��ʼ������
	void Initvector();

	//����ظ����� ������ѧ������ְ����ţ��������
	bool isExisted(int id,int type);

	//��Ŵ��ļ������ѧ������ʦ��¼
	vector<Student> vStud;
	vector<Teacher> vTeach;
	//��ŵ��Է���Ϣ
	vector<ComputerRoom> vComp;
};