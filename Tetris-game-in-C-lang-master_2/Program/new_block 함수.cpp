// ���ο� ���� ������ �Լ� new_block

void new_block(void) { //���ο� ��� ����  
    int i, j;

    bx = (MAIN_X / 2) - 1; //��� ���� ��ġx��ǥ(�������� ���) 
    by = 0;  //��� ������ġ y��ǥ(���� ��) 
    b_type = b_type_next; //���������� ������ 
    b_type_next = rand() % 7; //���� ���� ���� 
    b_rotation = 0;  //ȸ���� 0������ ������ 

    new_block_on = 0; //new_block flag�� ��  

    for (i = 0; i < 4; i++) { //������ bx, by��ġ�� ������  
        for (j = 0; j < 4; j++) {
            if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i][bx + j] = ACTIVE_BLOCK;
        }
    }
    for (i = 1; i < 3; i++) { //���ӻ���ǥ�ÿ� ������ ���ú��� �׸� 
        for (j = 0; j < 4; j++) {
            if (blocks[b_type_next][0][i][j] == 1) {
                gotoxy(STATUS_X_ADJ + 2 + j, i + 6);
                printf("��");
            }
            else {
                gotoxy(STATUS_X_ADJ + 2 + j, i + 6);
                printf("  ");
            }
        }
    }
}