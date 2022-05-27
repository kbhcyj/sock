void reset(void) {
	FILE* file = fopen("score.dat", "rt"); //score.dat������ ���� 
	if (file == 0) { best_score = 0; }
	else {
		fscanf(file, "%d", &best_score); //������ ������ �ְ����� �ҷ��� 
		fclose(file); //���� �ݱ� 
	}

	level = 1; //���������� �ʱ�ȭ
	score = 0;
	level_goal = 1000;
	key = 0;
	cnt = 0;
	speed = 100;

	system("cls");
	reset_main(); //main_org�� �ʱ�ȭ 
	draw_map(); //����ȭ���� �׸� 
	draw_main(); //�������� �׸� 
	b_type_next = rand() % 7; //�������� ���� ��� ������ �����ϰ� ���� 
	new_block(); //���ο� ����� �ϳ� ����  
}

// reset �Լ����� ȣ�� �ϴ� �Լ���
// ���� ���� �������� �ʱ�ȭ �մϴ� main �����ǰ� copy ���������� ���� �մϴ�. 
void reset_main(void) { //������ �ʱ�ȭ 
	int i, j;


	for (i = 0; i < MAIN_Y; i++) {
		for (j = 0; j < MAIN_X; j++) {
			main_org[i][j] = 0;
			main_cpy[i][j] = 100;
		}
	}
	for (j = 1; j < MAIN_X; j++) //y���� 3�� ��ġ�� õ���� ���� 
		main_org[3][j] = CEILLING;


	for (i = 1; i < MAIN_Y - 1; i++) { //�¿� ���� ����
		main_org[i][0] = WALL;
		main_org[i][MAIN_X - 1] = WALL;
	}
	for (j = 0; j < MAIN_X; j++) { //�ٴں� 
		main_org[MAIN_Y - 1][j] = WALL;
	}
}