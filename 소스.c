#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define ENTER 0x0d
#define ESC 0x1b
void initailize();
void gotoxy(int, int);
void cursor_off();
char get_alphabet();
char screen[24][80];
void display_screen();
void sleep(long wait);
void clear_screen();
void play_game();
void clear_array();

void main()
{
	char ch = 0;
	initailize();
	while (ch != ESC)
	{
		gotoxy(0, 24);
		printf("게임을 시작하려면 엔터, 종료하려면 ESC를 누르세요.");
		ch = _getch();
		if (ch == ENTER)
		{
			gotoxy(0, 24);
			printf("점수 :                                                         ");
			play_game();
		}
		clear_screen();
		sleep(1000);
	}
}

void initailize()
{
	srand(time(NULL));
	cursor_off();
}
void gotoxy(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void cursor_off()
{
	CONSOLE_CURSOR_INFO Coff = { 100,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Coff);
}

char get_alphabet()
{
	int y, x;
	char alpha;
	do {
		x = rand() % 80;
		y = rand() % 24;
	} while (screen[y][x] != 0);
	alpha = (rand() % 26) + 'A';
	screen[y][x] = alpha;
	return alpha;
}

void display_screen()
{
	int y, x;
	for (y = 0; y < 24; y++)
		for (x = 0; x < 80; x++)
			if (screen[y][x] != 0)
			{
				gotoxy(x, y);
				_putch(screen[y][x]);
			}
}

void sleep(long wait)
{
	clock_t goal;
	goal = wait + clock();
	while (goal > clock());
}

void clear_screen()
{
	int y, x;
	for (y = 0; y < 24; y++)
		for (x = 0; x < 80; x++)
			if (screen[y][x] != 0)
			{
				gotoxy(x, y);
				_putch(' ');
			}
}

void play_game()
{
	int score;
	char keyin, alphabet;

	score = 0;
	clear_array();
	do {
		clear_screen();
		sleep(1000);
		alphabet = get_alphabet();
		display_screen();
		keyin = _getch();
		keyin = toupper(keyin);
		if (keyin == alphabet);
		{
			score += 1;
			gotoxy(7, 24);
			printf("%2d", score);
		}
	} while (keyin == alphabet);
}

void clear_array()
{
	int x, y;
	for (y = 0; y < 24; y++)
		for (x = 0; x < 80; x++)
			screen[y][x] = 0;
}