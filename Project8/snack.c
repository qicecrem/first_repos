#include"snack.h"
void Createfood(pSnake ps) {
	int x = 0;
	int y = 0;
	again:
	do {
		x = rand() % 53 + 2;
		y = rand() % 24 + 1;
	} while (x % 2 != 0);
	psnakenode cur = ps->psnack;
	while (cur)
	{
		if (x == cur->x && y == cur->y) {
			goto again;
		}
		cur = cur->next;
	}
	psnakenode pFood = (psnakenode)malloc(sizeof(Snakenode));
	if (pFood == NULL) {
		perror("pfood");
		return;
	}
	pFood->x = x;
	pFood->y = y;
	ps->pfood = pFood;
	Setpos(x, y);
	wprintf(L"%lc", food);
	
}
void Creatmap()
{
	Setpos(0, 0);
	int i = 0;
	for (i = 0; i <= 56; i+=2) {
		wprintf(L"%lc", wall);

	}
	for (i = 1; i <= 25; i++)
	{
		Setpos(0, i);
		wprintf(L"%lc", wall);
	}
	for (i = 1; i <= 25; i++) {
		Setpos(56, i);
		wprintf(L"%lc", wall);
	}
	for (i = 0; i <=56; i+=2) {
		Setpos(i, 26);
		wprintf(L"%lc", wall);
	}
}

void Setpos(short x, short y)
{
	COORD pos = { x,y };
	HANDLE hOutput = NULL;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);

}
void Initsnack(pSnake ps)
{
	int i = 0;
	psnakenode cur = NULL;
	for (i = 0; i < 5; i++) {
		cur = (psnakenode)malloc(sizeof(Snakenode));
		if (cur == NULL) {
			perror("malloc");
			return;
		}
		cur->x = Pos_x + 2 * i;
		cur->y = Pos_y;
		cur->next = NULL;
		if (ps->psnack == NULL)
		{
			ps->psnack = cur;
		}
		else {
			cur->next = ps->psnack;
			ps->psnack = cur;
		}
	}
	cur = ps->psnack;
	while (cur) {
		Setpos(cur->x, cur->y);
		wprintf(L"%lc", body);
		cur = cur->next;
	}
	ps->dir = right;
	ps->foodweight = 10;
	ps->pfood = NULL;
	ps->score = 0;
	ps->Sleeptime = 200;
	ps->status = ok;

}

void Welcomtogame()
{
	Setpos(35, 10);
	printf("欢迎来到贪吃蛇游戏\n");
	Setpos(38, 20);
	system("pause");
	system("cls");
	Setpos(57, 10);
	printf("用↑.↓.←.→.来控制蛇的移动，F3是加速，F4是减速");
	Setpos(57, 11);
	printf("加速能得到更高分数");
	Setpos(38, 20);
	system("pause");
	system("cls");
}
void Gamestart(pSnake ps)
{
	system("mode con cols=108 lines=30");
	system("title 贪吃蛇");
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO curdorInfo;
	GetConsoleCursorInfo(handle, &curdorInfo);
	curdorInfo.bVisible = false;
	SetConsoleCursorInfo(handle, &curdorInfo);
	Welcomtogame();
	Creatmap();
	Initsnack(ps);
	Createfood(ps);
}
void printfHelpinfo()
{
	Setpos(60, 15);
	printf("1.不能穿墙，不能咬到自己");
	Setpos(60, 16);
	printf("用↑.↓.←.→.来控制蛇的移动\n"); 
	Setpos(60, 17);
	printf("F3是加速，F4是减速\n");

}
void pause()
{
	while (1) {
		Sleep(100);
		if (KEY_PRESS(VK_SPACE)) {
			break;
		}
	}
}
int  Nextisfood(pSnake ps, psnakenode pnext) {
	return (ps->pfood->x == pnext->x) && (ps->pfood->y == pnext->y);
}
void Eatfood(pSnake ps,psnakenode pnext)
{
	pnext->next = ps->psnack;
	ps->psnack = pnext;
	psnakenode cur= ps->psnack;
	while (cur) {
		Setpos(cur->x, cur->y);
		wprintf(L"%lc", body);
		cur = cur->next;

	}
	ps->score += ps->foodweight;
	free(ps->pfood);
	Createfood(ps);
}
void Noteatfood(pSnake ps, psnakenode pnext) 
{
	pnext->next = ps->psnack;
	ps->psnack = pnext;
	psnakenode cur =ps->psnack ;
	while (cur->next->next != NULL) {
		Setpos(cur->x, cur->y);
		wprintf(L"%lc ",body);
		cur = cur->next;

	}
	Setpos(cur->next->x, cur->next->y); 
		printf("  ");
	
	free(cur->next);
	cur->next = NULL;

}
void Killbywall(pSnake ps)
{
	if (ps->psnack->x == 0 || ps->psnack->x == 56 || ps->psnack->y == 0 || ps->psnack->y == 26) {
		ps->status = killbywall;
	}
}
int Killbyself(pSnake ps) {
	psnakenode cur = ps->psnack->next;
	while (cur) {
		if (cur->x == ps->psnack->x && cur->y == ps->psnack->y) {
			ps->status = killbyself;
			return 1;
		}
		cur = cur->next;
	}
	return 0;
	
}

void Snakemove(pSnake ps) {
	psnakenode pnext = (psnakenode)malloc(sizeof(Snakenode));
	if (pnext == NULL) {
		perror("snakemove");
		return;
	}
	pnext->next = NULL;
	switch (ps->dir)
	{
	case up:
		pnext->x = ps->psnack->x;
		pnext->y = ps->psnack->y - 1;
		break;
	case down:
		pnext->x = ps->psnack->x;
		pnext->y = ps->psnack->y + 1;
		break;
	case left:
		pnext->x = ps->psnack->x-2;
		pnext->y = ps->psnack->y ;
		break;
	case right:
		pnext->x = ps->psnack->x+2;
		pnext->y = ps->psnack->y ;
		break;
	}
	if (Nextisfood(ps, pnext)) {
		Eatfood(ps,pnext);

	}
	else
	{
		Noteatfood(ps, pnext);
	}
	Killbywall(ps);
	Killbyself(ps);

}

void Gamerun(pSnake ps) {
	printfHelpinfo();
	do {
		Setpos(62, 10);
		printf("总分：%5d\n", ps->score);
		Setpos(62, 11);
		printf("食物的分值：%d\n", ps->foodweight);
		if (KEY_PRESS(VK_UP) && ps->dir != down) {
			ps->dir = up;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->dir != up)
		{
			ps->dir = down;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->dir != right) {
			ps->dir = left;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->dir != left) {
			ps->dir = right;

		}
		else if (KEY_PRESS(VK_ESCAPE)) {
			ps->status = esc;
			break;
		}
		else if (KEY_PRESS(VK_SPACE)) {
			pause();
		}
		else if (KEY_PRESS(VK_F3))
		{
			if (ps->Sleeptime >= 80)
			{
				ps->Sleeptime -= 30;
				ps->foodweight += 2;
			}
		}
		else if (KEY_PRESS(VK_F4)) {
			if (ps->foodweight > 2)
			{
				ps->Sleeptime += 30;
				ps->foodweight -= 2;
			}
		}
			Snakemove(ps);
			Sleep(ps->Sleeptime);


		}while (ps->status == ok);

	}

void Gameend(pSnake ps) {
	Setpos(20, 12);
	switch (ps->status)
	{
	case esc:
		printf("主动退出游戏");
		break;
	case killbywall:
		printf("撞墙游戏结束");
		break;
	case killbyself:
		printf("咬到自己游戏结束");
			break;

	}
	psnakenode cur = ps->psnack;
	psnakenode del = NULL;
	while (cur) {
		del = cur;
		cur = cur->next;
		free(del);
	}
	ps->psnack = NULL;
	free(ps->pfood);
	ps->pfood = NULL;
}
