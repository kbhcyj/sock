//�ڵ忡 �ʿ��� ������ϰ� ��ũ���Լ� ���� 

#include <stdio.h>  //����� �Լ��� �����ϴ� ��� 
#include <windows.h>//windows �Լ��� �����ϴ� ��� 
#include <conio.h>  //�ܼ� ����� �Լ��� �����ϴ� ��� 
#include <time.h>   //�ð� ���� �Լ��� ��Ƴ��� ���̺귯�� ��� 
#include <stdlib.h> //���ڿ� ��ȯ,�ǻ� ��������, ���� �޸� ���� �Լ��� �����ϴ� ��� 


#define LEFT 75   //�·� �̵�  
#define RIGHT 77  //��� �̵� 
#define UP 72     //ȸ�� 
#define DOWN 80   //soft drop 
#define SPACE 32  //hard drop
#define p 112     //�Ͻ�����
#define P 80      //�Ͻ�����
#define ESC 27    //�������� 

#define false 0
#define true 1 

#define ACTIVE_BLOCK -2 // �����ǹ迭�� ����� ����� ���µ� 
#define CEILLING -1     // ����� �̵��� �� �ִ� ������ 0 �Ǵ� ���� ������ ǥ�� 
#define EMPTY 0         // ����� �̵��� �� ���� ������ ����� ǥ�� 
#define WALL 1
#define INACTIVE_BLOCK 2 // �̵��� �Ϸ�� ��ϰ� 

#define MAIN_X 11 //������ ����ũ�� 
#define MAIN_Y 23 //������ ����ũ��  
#define MAIN_X_ADJ 3 //������ ��ġ���� 
#define MAIN_Y_ADJ 1 //������ ��ġ���� 

#define STATUS_X_ADJ MAIN_X_ADJ+MAIN_X+1 //��������ǥ�� ��ġ����