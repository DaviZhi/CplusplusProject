#include "Manager.h"

Manager_c::Manager_c(uint16_t id, string name, uint16_t occup_id)
{
  this->c_ID = id;
  this->c_Name = name;
  this->c_OccupID = occup_id;
}

//显示个人信息
void Manager_c::Show_Info()
{
  cout << "职工编号：" << this->c_ID
    << "\t职工姓名：" << this->c_Name
    << "\t岗位：" << this->Get_Occup_Name()
    << "\t岗位职责：执行老板下放的任务，给雇员发布任务" << endl;
}

//获取岗位名称
string Manager_c::Get_Occup_Name()
{
  return string("经理");
}