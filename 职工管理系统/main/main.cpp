#include <iostream>
#include "staffManager.h"
#include "Employee.h"

using namespace std;

int main()
{
  StaffManager_c sm;
  uint16_t choice;

  while (true)
  {
    sm.ShowMenu();
    cout << "���������ѡ��" << endl;
    cin >> choice;

    switch (choice)
    {
    case sm.EXIT_SYSTEM:
    {
      sm.Exit_System();
      break;
    }
    case sm.ADD_STAFF_INFO:
    {

      break;
    }
    case 2:
    {
      break;
    }
    case 3:
    {
      break;
    }
    case 4:
    {
      break;
    }
    case 5:
    {
      break;
    }
    case 6:
    {
      break;
    }
    case 7:
    {
      break;
    }
    default:
    {
      cout << "Error operate!" << endl;
      system("pause");
      system("cls");
      break;
    }
    }
  }

  system("pause");
}