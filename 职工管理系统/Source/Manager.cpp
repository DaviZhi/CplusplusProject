#include "Manager.h"

Manager_c::Manager_c(uint16_t id, string name, uint16_t occup_id)
{
  this->c_ID = id;
  this->c_Name = name;
  this->c_OccupID = occup_id;
}

//��ʾ������Ϣ
void Manager_c::Show_Info()
{
  cout << "ְ����ţ�" << this->c_ID
    << "\tְ��������" << this->c_Name
    << "\t��λ��" << this->Get_Occup_Name()
    << "\t��λְ��ִ���ϰ��·ŵ����񣬸���Ա��������" << endl;
}

//��ȡ��λ����
string Manager_c::Get_Occup_Name()
{
  return string("����");
}