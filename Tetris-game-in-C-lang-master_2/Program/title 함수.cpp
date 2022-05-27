// main 함수에서 title 함수를 호출하여 처음 화면을 보여줍니다. 

void title(void) {
    int x = 5; //타이틀화면이 표시되는 x좌료 
    int y = 4; //타이틀화면이 표시되는 y좌표 
    int cnt;   //타이틀 프레임을 세는 변수 

    gotoxy(x + 5, y + 2); printf("T E T R I S"); Sleep(100);
    gotoxy(x, y + 7); printf(" ENTER : 게임시작"); Sleep(100);
    gotoxy(x, y + 9); printf("  ↑  : Rotaion");
    gotoxy(x, y + 10); printf(" ←/ → : Left / Right");
    gotoxy(x, y + 11); printf("  ↓   : Soft Drop");
    gotoxy(x, y + 8); printf(" P     : 게임 멈추기"); Sleep(100);
    gotoxy(x, y + 9); printf(" ESC   : 끝내기 "); Sleep(100);

    for (cnt = 0;; cnt++) {
        if (kbhit()) break;
        sleep(10);
    }

    while (kbhit()) getch(); //버퍼에 기록된 키값을 버림 
}