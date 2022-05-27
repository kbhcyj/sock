void draw_map(void) { //게임 상태 표시를 나타내는 함수 
    int y = 3; //level, goal, score만 게임중에 값이 바뀔수 도 있음 그 y값을 따로 저장해둠
              //그래서 혹시 게임 상태 표시 위치가 바뀌어도 그 함수에서 안바꿔도 되게...

    gotoxy(STATUS_X_ADJ, STATUS_Y_LEVEL = y); printf("LEVEL : %5d", cnt);
    gotoxy(STATUS_X_ADJ, STATUS_Y_GOAL = y + 1); printf("GOAL : %5d", 10 - cnt);
    gotoxy(STATUS_X_ADJ, y + 2); printf("+-  N E X T  -+ ");
    gotoxy(STATUS_X_ADJ, y + 3); printf("|             | ");
    gotoxy(STATUS_X_ADJ, y + 4); printf("|             | ");
    gotoxy(STATUS_X_ADJ, y + 5); printf("|             | ");
    gotoxy(STATUS_X_ADJ, y + 6); printf("|             | ");
    gotoxy(STATUS_X_ADJ, y + 7); printf("+-- -  -  - --+ ");
    gotoxy(STATUS_X_ADJ, y + 8); printf(" YOUR SCORE :");
    gotoxy(STATUS_X_ADJ, STATUS_Y_SCORE = y + 9); printf("        %6d", score);
    gotoxy(STATUS_X_ADJ, y + 10); printf(" LAST SCORE :");
    gotoxy(STATUS_X_ADJ, y + 11); printf("        %6d", last_score);
    gotoxy(STATUS_X_ADJ, y + 12); printf(" BEST SCORE :");
    gotoxy(STATUS_X_ADJ, y + 13); printf("        %6d", best_score);
    gotoxy(STATUS_X_ADJ, y + 15); printf("   ↑   : Rotation   SPACE : Hard Drop");
    gotoxy(STATUS_X_ADJ, y + 16); printf(" ←  → : Left / Right   P   : Pause");
    gotoxy(STATUS_X_ADJ, y + 17); printf("   ↓   : Soft Drop     ESC  : Quit");

}