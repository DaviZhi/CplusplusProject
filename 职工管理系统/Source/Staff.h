#pragma once
#include <iostream>
#include <string>
using namespace std;

/*ְ��������*/
class Staff_c
{
public:

  //��ʾ������Ϣ
  virtual void Show_Info() = 0;

  //��ȡ��λ����
  virtual string Get_Occup_Name() = 0;

  uint16_t c_ID;
  string c_Name;
  uint16_t c_OccupID;
};