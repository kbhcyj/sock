// main �Լ����� title �Լ��� ȣ���Ͽ� ó�� ȭ���� �����ݴϴ�. 

void title(void) {
    int x = 5; //Ÿ��Ʋȭ���� ǥ�õǴ� x�·� 
    int y = 4; //Ÿ��Ʋȭ���� ǥ�õǴ� y��ǥ 
    int cnt;   //Ÿ��Ʋ �������� ���� ���� 

    gotoxy(x + 5, y + 2); printf("T E T R I S"); Sleep(100);
    gotoxy(x, y + 7); printf(" ENTER : ���ӽ���"); Sleep(100);
    gotoxy(x, y + 9); printf("  ��  : Rotaion");
    gotoxy(x, y + 10); printf(" ��/ �� : Left / Right");
    gotoxy(x, y + 11); printf("  ��   : Soft Drop");
    gotoxy(x, y + 8); printf(" P     : ���� ���߱�"); Sleep(100);
    gotoxy(x, y + 9); printf(" ESC   : ������ "); Sleep(100);

    for (cnt = 0;; cnt++) {
        if (kbhit()) break;
        sleep(10);
    }

    while (kbhit()) getch(); //���ۿ� ��ϵ� Ű���� ���� 
}