#include "Employee.h"

Employee_c::Employee_c(uint16_t id, string name, uint16_t occup_id)
{
  this->c_ID = id;
  this->c_Name = name;
  this->c_OccupID = occup_id;
}

//��ʾ������Ϣ
void Employee_c:: Show_Info()
{
  cout << "ְ����ţ�" << this->c_ID 
    << "\tְ��������" << this->c_Name 
    << "\t��λ��" << this->Get_Occup_Name() 
    << "\t��λְ����ɾ�����������" << endl;
}

//��ȡ��λ����
string Employee_c::Get_Occup_Name()
{
  return string("��Ա");
}