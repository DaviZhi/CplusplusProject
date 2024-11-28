#pragma once
/*@brief:管理类
 *@content:
 * 1.与用户的沟通菜单界面
 * 2.对职工的增删改查的操作
 * 3.与文件的读写交互
 * 
 **/
#include <iostream>
#include "Staff.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
using namespace std;

/*职工管理抽象类*/
class StaffManager_c
{
public:
  //构造函数
  StaffManager_c();

  /*展示菜单*/
  void ShowMenu();

  /*退出系统*/
  void Exit_System();

  /*记录职工人数*/
  uint16_t memberNum_c;

  /*职工数组指针，存放职工相关信息*/
  Staff_c** staffArray_c;

  /*添加职工功能*/
  void Add_Staff();

  //析构函数
  ~StaffManager_c();

  enum
  {
    EXIT_SYSTEM,
    ADD_STAFF_INFO,
    DISPLAY_STAFF_INFO,
    DELETE_RESIGNED_STAFF,
    MODIFY_STAFF_INFO,
    FIND_STAFF_INFO,
    SORT_BY_NUMBER,
    CLEAR_ALL_DOC
  }oper_info_e;
};