#pragma once
#include "Staff.h"

/*�ϰ�����࣬�̳�ְ����*/
class Boss_c : public Staff_c
{
public:

  Boss_c(uint16_t id, string name, uint16_t occup_id);

  //��ʾ������Ϣ
  virtual void Show_Info();

  //��ȡ��λ����
  virtual string Get_Occup_Name();
};