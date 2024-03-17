#pragma once
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>
#define wall L'¡ö'
#define body L'¡ñ'
#define Pos_x 24
#define Pos_y 5
#define food L'¡ø'
#define KEY_PRESS(VK)  ((GetAsyncKeyState(VK)&0x1) ? 1 : 0)
enum Game_Status
{
	ok = 1,
	esc,
    killbywall,
	killbyself
};
enum Direction
{
	up=1,
	down,
	left,
	right
};
typedef struct Snakenode
{
	int x;
	int y;
	struct Snakenode* next;
}Snakenode,*psnakenode;

typedef struct snake
{
	psnakenode  psnack;
	psnakenode pfood;
	int score;
	int foodweight;
	int Sleeptime;
	enum Game_Status status;
	enum Direction dir;

}Snake,*pSnake;
void Setpos(short x, short y);
void Creatmap();

void  Gamestart(pSnake ps);
void Gamerun(pSnake ps);
void Gameend(pSnake ps);