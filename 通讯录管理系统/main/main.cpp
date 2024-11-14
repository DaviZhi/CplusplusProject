#include <iostream>
#include <string.h>
using namespace std;

/*******************Private Define*************************************/

/*ͨѶ¼�������*/
#define             ADDRESS_LIST_MAX_CAPACITY   1000

/*******************Private Enum**************************************/

/*ͨѶ¼������ö��*/
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

/*�Ա���Ϣö������*/
typedef enum
{
  MAN = 0,
  WOMAN,
  OTHER,
}gender_choice_info_e;

/******************Private Structure**********************************/

/*��ϵ����Ϣ�ṹ������*/
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
  contact_info_t contact_array[ADDRESS_LIST_MAX_CAPACITY];  //��ϵ������
  uint16_t current_contacts_num;
  addr_list_oper_e addr_list_oper;
}address_list_t;

/******************Private Function**********************************/

/*ͨѶ¼�����˵�չʾ*/
void ShowMenu(void)
{
  cout << "*********************" << endl;
  cout << "1.*** �����ϵ�� ****" << endl;
  cout << "2.*** ��ʾ��ϵ�� ****" << endl;
  cout << "3.*** ɾ����ϵ�� ****" << endl;
  cout << "4.*** ������ϵ�� ****" << endl;
  cout << "5.*** �޸���ϵ�� ****" << endl;
  cout << "6.*** �����ϵ�� ****" << endl;
  cout << "0.*** �˳�ͨѶ¼ ****" << endl;
  cout << "*********************" << endl;
}

/*ͨѶ¼��ʼ��*/
void Address_List_Init(address_list_t* addr_list)
{
  addr_list->current_contacts_num = 0;
}

/* @brief:�����ϵ��
 * @param:ͨѶ¼�ṹ��ָ��
 */
void Add_Contact(address_list_t* addr_list)
{
  if (addr_list->current_contacts_num >= ADDRESS_LIST_MAX_CAPACITY)
  {
    cout << "����ͨѶ¼�������޷���ӣ�" << endl;
    return;
  }
  else
  {
    string Name;
    cout << "������������" << endl;
    cin >> Name;
    addr_list->contact_array[addr_list->current_contacts_num].name = Name;

    uint16_t Gender;
    cout << "�������Ա�(MAN/WOMAN/OTHER)��" << endl;
    cout << "0---��" << endl;
    cout << "1---Ů" << endl;
    cout << "2---����" << endl;

    /*��ѭ��ǿ��Ҫ������MAN||WOMAN||OTHER*/
    while (1)
    {
      cin >> Gender;

      if (Gender == MAN || Gender == WOMAN || Gender == OTHER)
      {
        addr_list->contact_array[addr_list->current_contacts_num].gender_num = Gender;
        break;
      }
      cout << "���벻����Ҫ�����������룡" << endl;
    }

    uint16_t Age;
    cout << "���������䣺" << endl;
    cin >> Age;
    addr_list->contact_array[addr_list->current_contacts_num].age = Age;

    string Phone_Number;
    cout << "������绰���룺" << endl;
    cin >> Phone_Number;
    addr_list->contact_array[addr_list->current_contacts_num].phone_number = Phone_Number;

    string Address;
    cout << "�������ַ��" << endl;
    cin >> Address;
    addr_list->contact_array[addr_list->current_contacts_num].address = Address;

    cout << "��ӳɹ���" << endl;
    system("pause");

    addr_list->current_contacts_num++;      //����ͨѶ¼��ǰ��ϵ������

    system("cls");      //����
  }
}

/*�����ִ�����Ա�תΪ�������Ա𣬱�Show_Contact��������*/
static string TurnNum_To_RealGender(contact_info_t* contact_info)
{
  switch (contact_info->gender_num)
  {
  case MAN:
    return "��";

  case WOMAN:
    return "Ů";

  case OTHER:
    return "δ֪";
  }
}

/* @brief:��ʾ��ϵ��
 * @param:ͨѶ¼�ṹ��ָ��
 */
void Show_Contact(address_list_t* addr_list)
{
  if (addr_list->current_contacts_num == 0)
  {
    cout << "��¼Ϊ�գ�" << endl;
  }
  else
  {
    for (uint16_t i = 0; i < addr_list->current_contacts_num; i++)
    {
      cout << "������" << addr_list->contact_array[i].name <<"\t";

      addr_list->contact_array[i].gender_for_real = TurnNum_To_RealGender(&addr_list->contact_array[i]);

      cout << "�Ա�" << addr_list->contact_array[i].gender_for_real << "\t";
      cout << "���䣺" << addr_list->contact_array[i].age << "\t";
      cout << "�绰���룺" << addr_list->contact_array[i].phone_number << "\t";
      cout << "��ַ��" << addr_list->contact_array[i].address << endl;
    }
  }

  system("pause");
  system("cls");    //����
}

/* @brief:�ж���ϵ���Ƿ����
 * @param1:ͨѶ¼�ṹ��ָ��address_list_t
 * @param2:Ҫ���ҵ�Ŀ����target_name
 * @return:Ŀ�����ֵ�λ��i����-1
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
  return -1;      //������������������û�ҵ�target���ͷ���-1
}

/* @brief:ɾ����ϵ��
 * @param:ͨѶ¼�ṹ��ָ��
 */
void Delete_Contact(address_list_t* addr_list)
{
  string name_to_be_deleted;

  cout << "������Ҫɾ������ϵ��������" << endl;
  cin >> name_to_be_deleted;

  if (isContactExist(addr_list, name_to_be_deleted) == -1)
  {
    cout << "δ�鵽����ϵ�ˡ�" << endl;
  }
  else
  {
    for (uint16_t i = isContactExist(addr_list, name_to_be_deleted); 
      i < addr_list->current_contacts_num; i++)   //ɾ������������Ϊ�˷���û��������
    {
      addr_list->contact_array[i] = addr_list->contact_array[i + 1];
    }
    addr_list->current_contacts_num--;    //����ͨѶ¼�е���ϵ������

    cout << "ɾ���ɹ���" << endl;
  }

  system("pause");
  system("cls");
}

/* @brief:������ϵ��
 * @param1:ͨѶ¼�ṹ��ָ��
 */
void Find_Contact(address_list_t* addr_list)
{
  string name_to_be_found;

  cout << "������Ҫ���ҵ���ϵ��������" << endl;
  cin >> name_to_be_found;

  if (isContactExist(addr_list, name_to_be_found) == -1)
  {
    cout << "δ�鵽����ϵ�ˡ�" << endl;
  }
  else
  {
    cout << "���ҽ����" << endl;

    cout << "������" << addr_list->contact_array[isContactExist(addr_list, name_to_be_found)].name << "\t";

    addr_list->contact_array[isContactExist(addr_list, name_to_be_found)]
      .gender_for_real = TurnNum_To_RealGender(&addr_list->contact_array[isContactExist(addr_list, name_to_be_found)]);

    cout << "�Ա�" << addr_list->contact_array[isContactExist(addr_list, name_to_be_found)].gender_for_real << "\t";
    cout << "���䣺" << addr_list->contact_array[isContactExist(addr_list, name_to_be_found)].age << "\t";
    cout << "�绰���룺" << addr_list->contact_array[isContactExist(addr_list, name_to_be_found)].phone_number << "\t";
    cout << "��ַ��" << addr_list->contact_array[isContactExist(addr_list, name_to_be_found)].address << endl;
  }

  system("pause");
  system("cls");
}

/* @brief:�޸���ϵ��
 * @param1:ͨѶ¼�ṹ��ָ��
 */
void Modify_Contact(address_list_t* addr_list)
{
  string name_to_be_modified;

  cout << "������Ҫ�޸ĵ���ϵ�˵�������" << endl;
  cin >> name_to_be_modified;

  if (isContactExist(addr_list, name_to_be_modified) == -1)
  {
    cout << "δ�鵽����ϵ�ˡ�" << endl;
  }
  else
  {
    string new_name;
    cout << "�������µ�������" << endl;
    cin >> new_name;
    addr_list->contact_array[isContactExist(addr_list, name_to_be_modified)].name = new_name;

    uint16_t new_gender;
    cout << "�������Ա�(MAN/WOMAN/OTHER)��" << endl;
    cout << "0---��" << endl;
    cout << "1---Ů" << endl;
    cout << "2---����" << endl;
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
      cout << "��ӭ�´�ʹ��Ŷ!" << endl;
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