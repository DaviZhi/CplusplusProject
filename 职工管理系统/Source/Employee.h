#pragma once
#include "Staff.h"

/*��Ա�����࣬�̳�ְ����*/
class Employee_c: public Staff_c
{
public:

  Employee_c(uint16_t id, string name, uint16_t occup_id);

  //��ʾ������Ϣ
  virtual void Show_Info();

  //��ȡ��λ����
  virtual string Get_Occup_Name();
};