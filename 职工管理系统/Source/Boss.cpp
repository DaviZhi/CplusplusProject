#include "Boss.h"

Boss_c::Boss_c(uint16_t id, string name, uint16_t occup_id)
{
  this->c_ID = id;
  this->c_Name = name;
  this->c_OccupID = occup_id;
}

//显示个人信息
void Boss_c::Show_Info()
{
  cout << "职工编号：" << this->c_ID
    << "\t职工姓名：" << this->c_Name
    << "\t岗位：" << this->Get_Occup_Name()
    << "\t岗位职责：掌管公司发展方向" << endl;
}

//获取岗位名称
string Boss_c::Get_Occup_Name()
{
  return string("老板");
}