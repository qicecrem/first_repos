#include"contach.h"
int main()
{
	Contact con;
	Contactinit(&con);
	int op = 0;
	do {
		menu();
		printf("«Î—°‘Ò");
		scanf("%d", &op);
		switch (op) {
		case 1:
			Contactadd(&con);
			break;
		case 2:
			Contactdel(&con);
			break;
		case 3:
			Contactfindn(&con);
			break;
		case 4:
			Contactmodify(&con);
			break;
		case 5:
			Contactshow(&con);
		default:
			printf("error");
			break;

		}

	} while (op);
	Contactinit(&con);
	return 0;
}