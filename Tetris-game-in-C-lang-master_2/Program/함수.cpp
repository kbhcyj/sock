//�Լ� ����

void title(void); //Ÿ��Ʋ ȭ�� 
void reset(void);
void reset_main(void); //���� ������(main_org[][]�� �ʱ�ȭ
void reset_main_cpy(void); //copy ������(main_cpy[][]�� �ʱ�ȭ
void draw_map(void); //���� ��ü �������̽��� ǥ��
void draw_main(void); //�������� �׸� 
void new_block(void); //���ο� ����� �ϳ� ���� 
void check_key(void); //Ű����� Ű�� �Է¹��� 
void drop_block(void); //����� �Ʒ��� ����Ʈ�� 
int check_crush(int bx, int by, int rotation); //bx, by��ġ�� rotationȸ������ ���� ��� �浹 �Ǵ� 
void move_block(int dir); //dir�������� ����� ������ 
void check_line(void); //���� ����á������ �Ǵ��ϰ� ���� 
void check_level_up(void); //������ǥ�� �޼��Ǿ������� �Ǵ��ϰ� levelup��Ŵ 
void check_game_over(void); //���ӿ������� �Ǵ��ϰ� ���ӿ����� ���� 
void pause(void);//������ �Ͻ�������Ŵ 