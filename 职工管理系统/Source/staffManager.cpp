#include "staffManager.h"

//构造函数实现
StaffManager_c::StaffManager_c()
{

}

void StaffManager_c::ShowMenu()
{
  cout << "**********************************" << endl;
  cout << "********* 0.退出管理程序 *********" << endl;
  cout << "********* 1.增加职工信息 *********" << endl;
  cout << "********* 2.显示职工信息 *********" << endl;
  cout << "********* 3.删除离职职工 *********" << endl;
  cout << "********* 4.修改职工信息 *********" << endl;
  cout << "********* 5.查找职工信息 *********" << endl;
  cout << "********* 6.按照编号排序 *********" << endl;
  cout << "********* 7.清空所有文档 *********" << endl;
  cout << "**********************************" << endl;
}

void StaffManager_c::Exit_System()
{
  cout << "欢迎下次使用哦！" << endl;
  system("pause");
  exit(0);
}

//析构函数实现
StaffManager_c::~StaffManager_c()
{

}
