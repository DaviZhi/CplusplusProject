#include "staffManager.h"


//构造函数实现
StaffManager_c::StaffManager_c()
{
  this->memberNum_c = 0;

  this->staffArray_c = NULL;
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

void StaffManager_c::Add_Staff()
{
  cout << "请输入添加职工数量：" << endl;

  uint16_t addNum = 0;    //保存用户的输入数量
  cin >> addNum;

  if (addNum > 0)
  {
    uint16_t newSize = this->memberNum_c + addNum;    //新空间的人数

    /*开辟新空间*/
    Staff_c** newSpace = new Staff_c * [newSize];

    /*将原来空间下的数据拷贝到新空间下面*/
    if (this->memberNum_c != NULL)
    {
      for (uint16_t i = 0; i <= this->memberNum_c - 1; i++)
      {
        newSpace[i] = this->staffArray_c[i];    //把原来的数据拷贝到新空间
      }
    }

    for (uint16_t i = 0; i <= addNum - 1; i++)//添加新数据
    {
      uint16_t id;
      string name;
      uint16_t occup_id;

      cout << "请输入第" << i + 1 << "添加职工的ID：" << endl;
      cin >> id;
      cout << "请输入第" << i + 1 << "添加职工的姓名：" << endl;
      cin >> name;
      cout << "请输入第" << i + 1 << "添加职工的岗位：" << endl;
      cout << "1.雇员" << endl;
      cout << "2.经理" << endl;
      cout << "3.老板" << endl;
      cin >> occup_id;

      Staff_c* staff = NULL;

      switch (occup_id)
      {
      case 1:
      {
        staff = new Employee_c(id, name, occup_id);
        break;
      }
      case 2:
      {
        staff = new Manager_c(id, name, occup_id);
        break;
      }
      case 3:
      {
        staff = new Boss_c(id, name, occup_id);
        break;
      }
      default:
        break;
      }

      //将创建的职工职责保存到数组中
      newSpace[this->memberNum_c + i] = staff;

      //释放原有的空间
      delete[] this->staffArray_c;

      //更改新空间的指向
      this->staffArray_c = newSpace;

      //更新职工人数
      this->memberNum_c = newSize;
    }
    cout << "添加成功" << addNum << "名新职工" << endl;
  }
  else
  {
    cout << "输入有误" << endl;
  }
  system("pause");
  system("cls");
}

//析构函数实现
StaffManager_c::~StaffManager_c()
{

}
