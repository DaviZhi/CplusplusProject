#include "staffManager.h"


//���캯��ʵ��
StaffManager_c::StaffManager_c()
{
  this->memberNum_c = 0;

  this->staffArray_c = NULL;
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

void StaffManager_c::Add_Staff()
{
  cout << "���������ְ��������" << endl;

  uint16_t addNum = 0;    //�����û�����������
  cin >> addNum;

  if (addNum > 0)
  {
    uint16_t newSize = this->memberNum_c + addNum;    //�¿ռ������

    /*�����¿ռ�*/
    Staff_c** newSpace = new Staff_c * [newSize];

    /*��ԭ���ռ��µ����ݿ������¿ռ�����*/
    if (this->memberNum_c != NULL)
    {
      for (uint16_t i = 0; i <= this->memberNum_c - 1; i++)
      {
        newSpace[i] = this->staffArray_c[i];    //��ԭ�������ݿ������¿ռ�
      }
    }

    for (uint16_t i = 0; i <= addNum - 1; i++)//���������
    {
      uint16_t id;
      string name;
      uint16_t occup_id;

      cout << "�������" << i + 1 << "���ְ����ID��" << endl;
      cin >> id;
      cout << "�������" << i + 1 << "���ְ����������" << endl;
      cin >> name;
      cout << "�������" << i + 1 << "���ְ���ĸ�λ��" << endl;
      cout << "1.��Ա" << endl;
      cout << "2.����" << endl;
      cout << "3.�ϰ�" << endl;
      cin >> occup_id;

      Staff_c* staff = NULL;

      switch (occup_id)
      {
      case 1:
      {
        staff = new Employee_c(id, name, occup_id);
        break;
      }
      case 2:
      {
        staff = new Manager_c(id, name, occup_id);
        break;
      }
      case 3:
      {
        staff = new Boss_c(id, name, occup_id);
        break;
      }
      default:
        break;
      }

      //��������ְ��ְ�𱣴浽������
      newSpace[this->memberNum_c + i] = staff;

      //�ͷ�ԭ�еĿռ�
      delete[] this->staffArray_c;

      //�����¿ռ��ָ��
      this->staffArray_c = newSpace;

      //����ְ������
      this->memberNum_c = newSize;
    }
    cout << "��ӳɹ�" << addNum << "����ְ��" << endl;
  }
  else
  {
    cout << "��������" << endl;
  }
  system("pause");
  system("cls");
}

//��������ʵ��
StaffManager_c::~StaffManager_c()
{

}
