#pragma once
#include <iostream>
#include <string>
using namespace std;

/*职工抽象类*/
class Staff_c
{
public:

  //显示个人信息
  virtual void Show_Info() = 0;

  //获取岗位名称
  virtual string Get_Occup_Name() = 0;

  uint16_t c_ID;
  string c_Name;
  uint16_t c_OccupID;
};