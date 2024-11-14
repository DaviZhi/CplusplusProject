#include <iostream>
#include <string.h>
using namespace std;

/*******************Private Define*************************************/

/*通讯录最大容量*/
#define             ADDRESS_LIST_MAX_CAPACITY   1000

/*******************Private Enum**************************************/

/*通讯录操作集枚举*/
typedef enum
{
  EXIT,
  ADD_CONTACT,
  SHOW_CONTACT,
  DELETE_CONTACT,
  FIND_CONTACT,
  MODIFY_CONTACT,
  CLEAR_CONTACT,
}addr_list_oper_e;

/*性别信息枚举类型*/
typedef enum
{
  MAN = 0,
  WOMAN,
  OTHER,
}gender_choice_info_e;

/******************Private Structure**********************************/

/*联系人信息结构体类型*/
typedef struct Contact
{
  string name;
  uint16_t gender_num;
  string gender_for_real;
  uint16_t age;
  string phone_number;
  string address;
}contact_info_t;

typedef struct Address_list
{
  contact_info_t contact_array[ADDRESS_LIST_MAX_CAPACITY];  //联系人数组
  uint16_t current_contacts_num;
  addr_list_oper_e addr_list_oper;
}address_list_t;

/******************Private Function**********************************/

/*通讯录操作菜单展示*/
void ShowMenu(void)
{
  cout << "*********************" << endl;
  cout << "1.*** 添加联系人 ****" << endl;
  cout << "2.*** 显示联系人 ****" << endl;
  cout << "3.*** 删除联系人 ****" << endl;
  cout << "4.*** 查找联系人 ****" << endl;
  cout << "5.*** 修改联系人 ****" << endl;
  cout << "6.*** 清空联系人 ****" << endl;
  cout << "0.*** 退出通讯录 ****" << endl;
  cout << "*********************" << endl;
}

/*通讯录初始化*/
void Address_List_Init(address_list_t* addr_list)
{
  addr_list->current_contacts_num = 0;
}

/* @brief:添加联系人
 * @param:通讯录结构体指针
 */
void Add_Contact(address_list_t* addr_list)
{
  if (addr_list->current_contacts_num >= ADDRESS_LIST_MAX_CAPACITY)
  {
    cout << "错误！通讯录已满，无法添加！" << endl;
    return;
  }
  else
  {
    string Name;
    cout << "请输入姓名：" << endl;
    cin >> Name;
    addr_list->contact_array[addr_list->current_contacts_num].name = Name;

    uint16_t Gender;
    cout << "请输入性别(MAN/WOMAN/OTHER)：" << endl;
    cout << "0---男" << endl;
    cout << "1---女" << endl;
    cout << "2---其他" << endl;

    /*死循环强制要求输入MAN||WOMAN||OTHER*/
    while (1)
    {
      cin >> Gender;

      if (Gender == MAN || Gender == WOMAN || Gender == OTHER)
      {
        addr_list->contact_array[addr_list->current_contacts_num].gender_num = Gender;
        break;
      }
      cout << "输入不符合要求，请重新输入！" << endl;
    }

    uint16_t Age;
    cout << "请输入年龄：" << endl;
    cin >> Age;
    addr_list->contact_array[addr_list->current_contacts_num].age = Age;

    string Phone_Number;
    cout << "请输入电话号码：" << endl;
    cin >> Phone_Number;
    addr_list->contact_array[addr_list->current_contacts_num].phone_number = Phone_Number;

    string Address;
    cout << "请输入地址：" << endl;
    cin >> Address;
    addr_list->contact_array[addr_list->current_contacts_num].address = Address;

    cout << "添加成功！" << endl;
    system("pause");

    addr_list->current_contacts_num++;      //更新通讯录当前联系人数量

    system("cls");      //清屏
  }
}

/*把数字代表的性别转为真正的性别，被Show_Contact函数调用*/
static string TurnNum_To_RealGender(contact_info_t* contact_info)
{
  switch (contact_info->gender_num)
  {
  case MAN:
    return "男";

  case WOMAN:
    return "女";

  case OTHER:
    return "未知";
  }
}

/* @brief:显示联系人
 * @param:通讯录结构体指针
 */
void Show_Contact(address_list_t* addr_list)
{
  if (addr_list->current_contacts_num == 0)
  {
    cout << "记录为空！" << endl;
  }
  else
  {
    for (uint16_t i = 0; i < addr_list->current_contacts_num; i++)
    {
      cout << "姓名：" << addr_list->contact_array[i].name <<"\t";

      addr_list->contact_array[i].gender_for_real = TurnNum_To_RealGender(&addr_list->contact_array[i]);

      cout << "性别：" << addr_list->contact_array[i].gender_for_real << "\t";
      cout << "年龄：" << addr_list->contact_array[i].age << "\t";
      cout << "电话号码：" << addr_list->contact_array[i].phone_number << "\t";
      cout << "地址：" << addr_list->contact_array[i].address << endl;
    }
  }

  system("pause");
  system("cls");    //清屏
}

/* @brief:判断联系人是否存在
 * @param1:通讯录结构体指针address_list_t
 * @param2:要查找的目标名target_name
 * @return:目标名字的位置i或者-1
 **/
int16_t isContactExist(address_list_t* addr_list, string target_name)
{
  for (uint16_t i = 0; i < addr_list->current_contacts_num; i++)
  {
    if (addr_list->contact_array[i].name == target_name)
    {
      return (int16_t)i;
    }
  }
  return -1;      //遍历所有人名后若还没找到target，就返回-1
}

/* @brief:删除联系人
 * @param:通讯录结构体指针
 */
void Delete_Contact(address_list_t* addr_list)
{
  string name_to_be_deleted;

  cout << "请输入要删除的联系人姓名：" << endl;
  cin >> name_to_be_deleted;

  if (isContactExist(addr_list, name_to_be_deleted) == -1)
  {
    cout << "未查到该联系人。" << endl;
  }
  else
  {
    for (uint16_t i = isContactExist(addr_list, name_to_be_deleted); 
      i < addr_list->current_contacts_num; i++)   //删除操作，这里为了方便没有用链表
    {
      addr_list->contact_array[i] = addr_list->contact_array[i + 1];
    }
    addr_list->current_contacts_num--;    //更新通讯录中的联系人数量

    cout << "删除成功！" << endl;
  }

  system("pause");
  system("cls");
}

/* @brief:查找联系人
 * @param1:通讯录结构体指针
 */
void Find_Contact(address_list_t* addr_list)
{
  string name_to_be_found;

  cout << "请输入要查找的联系人姓名：" << endl;
  cin >> name_to_be_found;

  if (isContactExist(addr_list, name_to_be_found) == -1)
  {
    cout << "未查到该联系人。" << endl;
  }
  else
  {
    cout << "查找结果：" << endl;

    cout << "姓名：" << addr_list->contact_array[isContactExist(addr_list, name_to_be_found)].name << "\t";

    addr_list->contact_array[isContactExist(addr_list, name_to_be_found)]
      .gender_for_real = TurnNum_To_RealGender(&addr_list->contact_array[isContactExist(addr_list, name_to_be_found)]);

    cout << "性别：" << addr_list->contact_array[isContactExist(addr_list, name_to_be_found)].gender_for_real << "\t";
    cout << "年龄：" << addr_list->contact_array[isContactExist(addr_list, name_to_be_found)].age << "\t";
    cout << "电话号码：" << addr_list->contact_array[isContactExist(addr_list, name_to_be_found)].phone_number << "\t";
    cout << "地址：" << addr_list->contact_array[isContactExist(addr_list, name_to_be_found)].address << endl;
  }

  system("pause");
  system("cls");
}

/* @brief:修改联系人
 * @param1:通讯录结构体指针
 */
void Modify_Contact(address_list_t* addr_list)
{
  string name_to_be_modified;

  cout << "请输入要修改的联系人的姓名：" << endl;
  cin >> name_to_be_modified;

  if (isContactExist(addr_list, name_to_be_modified) == -1)
  {
    cout << "未查到该联系人。" << endl;
  }
  else
  {
    string new_name;
    cout << "请输入新的姓名：" << endl;
    cin >> new_name;
    addr_list->contact_array[isContactExist(addr_list, name_to_be_modified)].name = new_name;

    uint16_t new_gender;
    cout << "请输入性别(MAN/WOMAN/OTHER)：" << endl;
    cout << "0---男" << endl;
    cout << "1---女" << endl;
    cout << "2---其他" << endl;
    cin >> new_gender;
    addr_list->contact_array[isContactExist(addr_list, name_to_be_modified)].gender_num = new_gender;
  }
}

int main()
{
  address_list_t address_list;
  short select;
//  ShowMenu();
  Address_List_Init(&address_list);

  while (1)
  {
    ShowMenu();

    cin >> select;

    switch (select)
    {
    case ADD_CONTACT:
    {
      Add_Contact(&address_list);
      break;
    }
    case SHOW_CONTACT:
    {
      Show_Contact(&address_list);
      break;
    }
    case DELETE_CONTACT:
    {
      Delete_Contact(&address_list);
      break;
    }
    case FIND_CONTACT:
    {
      Find_Contact(&address_list);
      break;
    }
    case MODIFY_CONTACT:
    {
      break;
    }
    case CLEAR_CONTACT:
    {
      break;
    }
    case EXIT:
    {
      cout << "欢迎下次使用哦!" << endl;
//      system("pause");
      return 0;
      break;
    }
    default:
      cout << "Error operate!" << endl;
      break;
    }
  }
//  system("pause");
  return 0;
}