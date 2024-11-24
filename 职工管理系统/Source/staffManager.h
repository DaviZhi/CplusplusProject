#pragma once
/*@brief:管理类
 *@content:
 * 1.与用户的沟通菜单界面
 * 2.对职工的增删改查的操作
 * 3.与文件的读写交互
 * 
 **/
#include <iostream>
using namespace std;

class StaffManager_c
{
public:
  //构造函数
  StaffManager_c();

  /*展示菜单*/
  void ShowMenu();

  void Exit_System();

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