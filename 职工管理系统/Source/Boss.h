#pragma once
#include "Staff.h"

/*老板抽象类，继承职工类*/
class Boss_c : public Staff_c
{
public:

  Boss_c(uint16_t id, string name, uint16_t occup_id);

  //显示个人信息
  virtual void Show_Info();

  //获取岗位名称
  virtual string Get_Occup_Name();
};