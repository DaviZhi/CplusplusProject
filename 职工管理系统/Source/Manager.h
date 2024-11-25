#pragma once
#include "Staff.h"

/*经理抽象类，继承职工类*/
class Manager_c :public Staff_c
{
public:

  Manager_c(uint16_t id, string name, uint16_t occup_id);

  //显示个人信息
  virtual void Show_Info();

  //获取岗位名称
  virtual string Get_Occup_Name();
};