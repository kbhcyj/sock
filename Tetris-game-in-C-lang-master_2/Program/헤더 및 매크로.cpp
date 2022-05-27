//코드에 필요한 헤더파일과 매크로함수 정의 

#include <stdio.h>  //입출력 함수를 제공하는 헤더 
#include <windows.h>//windows 함수를 제공하는 헤더 
#include <conio.h>  //콘솔 입출력 함수를 제공하는 헤더 
#include <time.h>   //시관 관련 함수를 모아놓은 라이브러리 헤더 
#include <stdlib.h> //문자열 변환,의사 난수생성, 동적 메모리 관리 함수를 제공하는 헤더 


#define LEFT 75   //좌로 이동  
#define RIGHT 77  //우로 이동 
#define UP 72     //회전 
#define DOWN 80   //soft drop 
#define SPACE 32  //hard drop
#define p 112     //일시정지
#define P 80      //일시정지
#define ESC 27    //게임종료 

#define false 0
#define true 1 

#define ACTIVE_BLOCK -2 // 게임판배열에 저장될 블록의 상태들 
#define CEILLING -1     // 블록이 이동할 수 있는 공간은 0 또는 음의 정수료 표현 
#define EMPTY 0         // 블록이 이동할 수 없는 공간은 양수로 표현 
#define WALL 1
#define INACTIVE_BLOCK 2 // 이동이 완료된 블록값 

#define MAIN_X 11 //게임판 가로크기 
#define MAIN_Y 23 //게임판 세로크기  
#define MAIN_X_ADJ 3 //게임판 위치조정 
#define MAIN_Y_ADJ 1 //게임판 위치조정 

#define STATUS_X_ADJ MAIN_X_ADJ+MAIN_X+1 //게임정보표시 위치조정