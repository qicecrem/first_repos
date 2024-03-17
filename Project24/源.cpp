#include"Workmanger.h"
#include"employee.h"
int main()
{
	
	Workmanger a;
	int choice = 0;
	while (true)
	{

		a.Show_Menu();
		cout << "ÇëÊäÈëÄãµÄÑ¡Ôñ" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			a.exitSystem();
			break;
		case 1:
			a.Add_Emp();
			break;
		case 2:
			a.show_Emp();
			break;
		case 3:
			a.Del_Emp();
			break;
		case 4:
			a.Mod_Emp();
			break;
		case 5:
			a.Find_Emp();
			break;
		case 6:
			a.Sort_Emp();
			break;
		case 7:
			a.Clean_File();
			break;
		default:
			system("cls");
			break;
			
		}
	}
	return 0;
}