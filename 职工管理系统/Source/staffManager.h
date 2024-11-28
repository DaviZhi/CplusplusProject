#pragma once
/*@brief:������
 *@content:
 * 1.���û��Ĺ�ͨ�˵�����
 * 2.��ְ������ɾ�Ĳ�Ĳ���
 * 3.���ļ��Ķ�д����
 * 
 **/
#include <iostream>
#include "Staff.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
using namespace std;

/*ְ�����������*/
class StaffManager_c
{
public:
  //���캯��
  StaffManager_c();

  /*չʾ�˵�*/
  void ShowMenu();

  /*�˳�ϵͳ*/
  void Exit_System();

  /*��¼ְ������*/
  uint16_t memberNum_c;

  /*ְ������ָ�룬���ְ�������Ϣ*/
  Staff_c** staffArray_c;

  /*���ְ������*/
  void Add_Staff();

  //��������
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