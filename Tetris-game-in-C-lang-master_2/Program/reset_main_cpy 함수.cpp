void reset_main_cpy(void) { //main_cpy�� �ʱ�ȭ 
    int i, j;

    for (i = 0; i < MAIN_Y; i++) {         //�����ǿ� ���ӿ� ������ �ʴ� ���ڸ� ���� 
        for (j = 0; j < MAIN_X; j++) {  //�̴� main_org�� ���� ���ڰ� ���� �ϱ� ���� 
            main_cpy[i][j] = 100;
        }
    }
}