#include "staffManager.h"

//���캯��ʵ��
StaffManager_c::StaffManager_c()
{

}

void StaffManager_c::ShowMenu()
{
  cout << "**********************************" << endl;
  cout << "********* 0.�˳�������� *********" << endl;
  cout << "********* 1.����ְ����Ϣ *********" << endl;
  cout << "********* 2.��ʾְ����Ϣ *********" << endl;
  cout << "********* 3.ɾ����ְְ�� *********" << endl;
  cout << "********* 4.�޸�ְ����Ϣ *********" << endl;
  cout << "********* 5.����ְ����Ϣ *********" << endl;
  cout << "********* 6.���ձ������ *********" << endl;
  cout << "********* 7.��������ĵ� *********" << endl;
  cout << "**********************************" << endl;
}

void StaffManager_c::Exit_System()
{
  cout << "��ӭ�´�ʹ��Ŷ��" << endl;
  system("pause");
  exit(0);
}

//��������ʵ��
StaffManager_c::~StaffManager_c()
{

}
