#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

clock_t startDropT, endT, startGroundT; //clock_t: clock_t는 long을 다른 이름으로 typedef한 것, 반환값은 프로세스가 현재실행까지 걸린 clock(1sec == 1000clock) 수
/*
clock함수 사용법
1. 소스코드에서 내가 시간측정을 하길 원하는 시작지점에서 clock 함수를 호출
2. 소스코드에서 내가 시간특정을 끝내길 원하는 종료지점에서 clock 함수를 호출
3. 위의 2에서 1을 뺀다 => 해당 구간에서의 clock 수가 나옴
4. 3번의 결과를 1000으로 나누어주면 몇초인지가 나옴. 나누지 않는다면 밀리초 단위로 계산한 결과임.
*/
int x = 8, y = 0;
RECT blockSize; //RECT구조체: 사각형의 너비, 높이 및 위치
int blockForm;
int blockRotation = 0;
int key;

int block[7][4][4][4] = {
	{ // T 블럭
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{0,1,1,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,0,0},
			{0,1,0,0}
		}
	},
	{    // ㄹ 블럭
		{
			{0,0,0,0},
			{0,1,1,0},
			{1,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{1,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{0,1,0,0}
		}
	},
	{   // ㄹ 블럭 반대
		{
			{0,0,0,0},
			{1,1,0,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,0,0},
			{1,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,0,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,0,0},
			{1,0,0,0}
		}
	},
	{   // 1 블럭
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0}
		}
	},
	{   // ㄴ 블럭
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,0,0},
			{1,0,0,0},
			{1,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,1,0},
			{0,0,1,0},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{0,1,0,0},
			{1,1,0,0},
			{0,0,0,0}
		}
	},
	{   // ㄴ 블럭 반대
		{
			{0,0,0,0},
			{0,0,1,0},
			{1,1,1,0},
			{0,0,0,0}
		},
		{
			{1,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,1,0},
			{1,0,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		}
	},
	{   // ㅁ 블럭
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		}
	}
};

int space[15 + 1][10 + 2] = {  // 세로 15+1(아래벽)칸, 가로 10+2(양쪽 벽)칸  
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1}
};

void delCursor(); //커서의 깜빡임을 제거하기 위해 SetConsoleCursorInfo함수 사용
void gotoxy(int x, int y);
void CreateRandomForm(); //블럭이 내려올 때마다 랜덤으로 바뀌게 합니다. rand() % 7을 해주면 0~6의 랜덤한 값이 나오게 되는 것을 이용
bool CheckCrash(int x, int y); //충돌을 감지하는 함수입니다. 매개변수에 위치값을 넣고 블럭이 그 위치에 있을 때 충돌이 되는가를 검사합니다. 하나라도 겹치는 것이 있다면 true을 반환합니다. x좌표는 2당 1칸의 크기를 가지기 때문에 y는 그대로 쓰고 x는 x / 2로함
void DropBlock(); //0.8초마다 블럭을 한칸씩 밑으로 내리는 함수
void BlockToGround(); //블럭이 1.5초동안 땅에 닿아있을 때 아무 동작이 없다면 땅으로 변하게 합니다. 그리고 랜덤한 블럭을 만들고 위로 올립니다.
void RemoveLine(); //1줄이 되었다면 블럭을 제거합니다.
/*
그 줄에서부터 시작해서 한칸씩 다 땡긴다.

int j = 0; i - j >= 0; j++
그 줄에서부터 시작해서 위로 올라가면서 한칸씩 내리게 하는 코드.

int x = 1; x < 11; x++
	x = 0, x = 11 은 벽을 가리킴.

	if (i - j - 1 >= 0)는 천장이 아닐 때를 가리킴.

else 천장이면 더이상 블럭이 없으니 당겨올 수 없습니다.따라서 0을 저장함
*/
void DrawMap(); //맵의 형태와 쌓인 블럭을 그린다.
void DrawBlock(); //현재 블럭을 그립니다.
/*
block[7][4][4][4] 4차원 배열로 만들었습니다.

[7] : 7개의 블럭
[4] : 4개의 회전모양
[4] : 세로 모양
[4] : 가로 모양

[7] 부분에 랜덤으로 숫자를 주면 랜덤한 블럭이 나타나게 됩니다.
[4] 회전키를 누를 때마다 증감해주면 모양이 회전하게 됩니다.
*/
void InputKey(); //_kbhit로 입력을 감지하고 _getch로 입력을 받습니다.
/*
_kbhit로 입력을 감지하고 _getch로 입력을 받습니다.

_getch만 쓰면 입력받을 때까지 계속 대기하게 됩니다.

모양 바꾸기, 왼쪽, 오른쪽을 이동할 때마다 StartGroundT = clock()을 하는 이유는

startGroundT의 시간을 갱신해서 블럭이 땅으로 변하지 않게 하기 위해서 입니다.

만약 저 코드가 없다면 아무리 블럭을 이동, 모양을 바꿔도 땅에 닿으면 바로 다음 블럭이 나올 것입니다.

system("cls")는 실행하는데 시간이 약간 걸리므로 사용을 최소화하기 위해

키를 누를 때나 땅에 떨어질 때만 실행되게 했습니다.
*/

//이 테트리스는 문제없이 실행되나 블럭이 회전할 때 벽이나 땅과 겹치는 버그가 있습니다. 테트리스의 구조에 대해 설명하기 위해 최대한 간단하게 만들다보니 예외처리를 하지 않았습니다.

int main() {
	delCursor();
	startDropT = clock();
	CreateRandomForm();

	while (true) {
		DrawMap();
		DrawBlock();
		DropBlock();
		BlockToGround();
		RemoveLine();
		InputKey();
	}
	return 0;
}

void delCursor() {
	CONSOLE_CURSOR_INFO cursorinfo;
	cursorinfo.bVisible = 0; //커서의 표시 여부, 커서가 표시되면 이 멤버는 TRUE입니다.
	cursorinfo.dwSize = 1; //커서로 채워진 문자 셀의 백분율입니다. 이 값의 범위는 일반적으로 1에서 100 사이
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorinfo); //GetStdHandle 함수: 지정된 표준 디바이스(표준 입력, 표준 출력 또는 표준 오류)에 대한 핸들을 검색
	srand(time(NULL)); // 난수 생성
}

void gotoxy(int x, int y) {
	COORD pos; //COORD 구조체: 콘솔 화면 버퍼에서 문자 셀의 좌표를 정의함. 좌표계(0,0)의 원점은 버퍼의 왼쪽 위 셀에 있다.
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CreateRandomForm() {
	blockForm = rand() % 7; //rand()함수: 랜덤한 숫자를 반환(범위는 0~ RAND_MAX(= 32767) 까지)
}

bool CheckCrash(int x, int y) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[blockForm][blockRotation][i][j] == 1) {
				int t = space[i + y][j + x / 2];
				if (t == 1 || t == 2) { //1: 벽일 때, 2: 블럭일 때
					return true;
				}
			}
		}
	}
	return false;
}

void DropBlock() {
	endT = clock();
	if ((float)(endT - startDropT) >= 800) {
		if (CheckCrash(x, y + 1) == true) return;
		y++;
		startDropT = clock();
		startGroundT = clock();
		system("cls"); // 콘솔화면을 지워준다(스크린 클리어). 실행에 시간이 약간 걸린다.
	}
}

void BlockToGround() {
	if (CheckCrash(x, y + 1) == true) {
		if ((float)(endT - startGroundT) > 1500) {
			//현재 블록 저장
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (block[blockForm][blockRotation][i][j] == 1) {
						space[i + y][j + x / 2] = 2;
					}
				}
			}
			x = 8;
			y = 0;
			CreateRandomForm();
		}
	}
}

void RemoveLine() {
	for (int i = 15; i >= 0; i--) { //벽라인 제외한 값
		int count = 0;
		for (int j = 0; j < 11; j++) {
			if (space[i][j] == 2) {
				count++;
			}
		}
		if (count >= 10) { //벽돌이 다 차있다면
			for (int j = 0; i - j >= 0; j++) {
				for (int x = 1; x < 11; x++) {
					if (i - j - 1 >= 0)
						space[i - j][x] = space[i - j - 1][x];
					else //천장이면 0저장
						space[i - j][x] = 0;
				}
			}
		}
	}
}

void DrawMap() {
	gotoxy(0, 0);
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 12; j++) {
			if (space[i][j] == 1) {
				gotoxy(j * 2, i);
				printf("□");
			}
			else if (space[i][j] == 2) {
				gotoxy(j * 2, i);
				printf("■");
			}
		}
	}
}

void DrawBlock() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[blockForm][blockRotation][i][j] == 1) {
				gotoxy(x + j * 2, y + i);
				printf("■");
			}
		}
	}
}

void InputKey() {
	if (_kbhit()) { //_kbhit는 입력을 감지하는 함수
		key = _getch(); //_kbhit로 입력을 감지할 때마다 _getch함수로 입력을 받음
		switch (key) {
		case 32: //space
			blockRotation++;
			if (blockRotation >= 4) blockRotation = 0;
			startGroundT = clock();
			break;
		case 75: //left
			if (CheckCrash(x - 2, y) == false) {
				x -= 2;
				startGroundT = clock();
				break;
		case 77: //right
			if (CheckCrash(x + 2, y) == false) {
				x += 2;
				startGroundT = clock();
			}
			break;
		case 80: //down
			if (CheckCrash(x, y + 1) == false)
				y++;
			break;
			}
			system("cls");
		}
	}
}