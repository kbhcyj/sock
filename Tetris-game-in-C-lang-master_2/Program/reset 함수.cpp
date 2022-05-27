void reset(void) {
	FILE* file = fopen("score.dat", "rt"); //score.dat파일을 연결 
	if (file == 0) { best_score = 0; }
	else {
		fscanf(file, "%d", &best_score); //파일이 열리면 최고점수 불러옴 
		fclose(file); //파일 닫기 
	}

	level = 1; //각종변수를 초기화
	score = 0;
	level_goal = 1000;
	key = 0;
	cnt = 0;
	speed = 100;

	system("cls");
	reset_main(); //main_org를 초기화 
	draw_map(); //게임화면을 그림 
	draw_main(); //게임판을 그림 
	b_type_next = rand() % 7; //다음번에 나올 블록 종류를 랜덤하게 생성 
	new_block(); //새로운 블록을 하나 만듦  
}

// reset 함수에서 호출 하는 함수들
// 제일 먼저 게임판을 초기화 합니다 main 게임판과 copy 게임판으로 구분 합니다. 
void reset_main(void) { //게임판 초기화 
	int i, j;


	for (i = 0; i < MAIN_Y; i++) {
		for (j = 0; j < MAIN_X; j++) {
			main_org[i][j] = 0;
			main_cpy[i][j] = 100;
		}
	}
	for (j = 1; j < MAIN_X; j++) //y값이 3인 위치에 천장을 만듬 
		main_org[3][j] = CEILLING;


	for (i = 1; i < MAIN_Y - 1; i++) { //좌우 벽을 만듦
		main_org[i][0] = WALL;
		main_org[i][MAIN_X - 1] = WALL;
	}
	for (j = 0; j < MAIN_X; j++) { //바닥벽 
		main_org[MAIN_Y - 1][j] = WALL;
	}
}