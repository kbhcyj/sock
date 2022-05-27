//참고 사이트: https://kevinthegrey.tistory.com/26

// review_0225_Socket.cpp: 콘솔 응용 프로그램의 진입점을 정의함.

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

//#include "stdafx.h"
#include <stdio.h>
#include <WinSock2.h>	// 소켓을 사용하기 위한 헤더파일

#pragma comment(lib, "ws2_32")	// 위에서 정의한 헤더파일들을 가져다 쓰기위한 링크
#pragma warning(disable: 4996)

#define PORT	4567
#define PACKET_SIZE	1024

int main() {
	WSADATA wsaData;	// Windows의 소켓 초기화 정보를 저장하기위한 구초제. 이미 선언되어있는 구조체임.
	WSAStartup(MAKEWORD(2, 2), &wsaData);	// WSAStartup(소켓버전, WSADATA 구조체 주소);
	/*
	# 소켓을 사용하기위한 헤더 include 및 기본설정 지정

	#
	#include<WinSock2.h> & #pragma comment(lib, "ws_32")
	소켓을 사용하기 위해선 라이브러리를 링크 걸어줘야 한다.
	ws2_32는 lib파일이다. lib파일은 실제 구현부분을 바이너리화 시킨 파일이다.
	보통은 헤더에 선언한 기능들을 cpp에 구현하고, 이 cpp에 구현된 내용들이 리이브러리화 된다.
	즉, WinSock2.h 에 선언한 기능들을 사용하겠다고, ws2_32에 라이브러리를 링크걸어주는 것이다.
	참고로 stdio.h를 사용하는 이유는 C++에서 C문법을 가져다 쓰며 구현하려하기 때문이다.

	#
	#define PORT 4567 & #define PACKET_SIZE 1024
	PORT를 사용할 때는 예약된 포트를 제외하고 사용하여야 한다.
	따라서 4자리 포트중 임의의 숫자를 할당하였다.
	또한 패킷사이즈를 정의해주었다.

	WSAStartup(소켓버전, WSADATA 구조체 주소);
	: 이 함수를 가장 먼저 호출해준다.
	이 함수를 호출해서 Windows에 어느 소켓을 활용할 것인지 알려준다.
	첫번째 인자는 소켓 버전이 들어간다. 2.2 버전을 활용할건데 WORD 타입으로 들어가게 된다.
	WORD는 unsigned short 타입을 typedef 해놓은 것이다. 그런데 2.2 버전은 실수이므로,
	2.2라는 실수를 정수값으로 변환하여 넣어줄 수 있어야 한다. MAKEWORD 매크로를 이용해서 만들어준다.
	2번째 인자는 WSADATA 구조체의 포인터 타입이 들어간다.
	*/

	SOCKET hListen;	// hListen = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	hListen - socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	/*
	# 소켓생성

	#
	hListen = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKET은 핸들이다. 핸들이란 운영체제가 관리하는 커널오브젝트의 한 종류이다.
	커널오브젝트는 운영체제가 관리하는 커널이라는 특수한 영영게 존재하는 오브젝트이다.
	윈도우를 생성해도 해당 윈도우의 핸들이 생성되고 운영체제가 그 핸들을 이용해서
	어떤 프로그램인지를 구분한다던지 하는 기능을 제공한다.

	TCP 소켓은 크게 2가지로 나뉘게 된다.
	첫번째는 다른 컴퓨터로부터 들어오는 접속중인 요청을 수락해주는 소켓이 존재해야 한다.
	두번째는 다른 컴퓨터와 연결된 소켓이 있어야 한다.

	컴퓨터는 IP 주소라는 개념을 이용하여 해당 컴퓨터의 주소정보를 만들어낸다.
	IP 주소는 크게 2가지로 나뉘게 된다. IPv4타입 IPv6타입이다.
	IPv4타입은 32bit 주소 체계로 일반적으로 사용하는 주소이다.
	그런데 32bit를 이용하여 표현하는 값의 한계가 이어서 IPv6 타입이 만들어지게 되었다.
	IPv6 타입은 16byte 주소체계이다. 천문학적인 값의 표현이 가능하므로 엄청나게 많은 컴퓨터에 IP주소를 할당해 줄 수 있다.
	PF_INET 을 넣어주면 IPv4 타입을 사용한다는 것이다.
	SOCK_STREAM 을 넣어주면 연결지향형 소켓을 만들겠다는 의미이다.
	세번째 인자는 protocol이 들어간다. protocol은 통신규약을 말한다.
	IPPROTO_TCP 는 TCP를 사용하겠다고 지정해주는것이다.
	*/

	SOCKADDR_IN tListenAddr = {};
	tListenAddr.sin_family = AF_INET;
	tListenAddr.sin_port = htons(PORT);
	tListenAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	/*
	# 소켓의 구성요소를 담을 구조체 생성 및 값 할당
	위에 언급한 소켓의 구성요소들을 지정해준다.
	주소정보를 만들어낸다. 주소를 구성하는 것은 IP와 PORT 2가지로 구성된다.
	IP는 주소이고 PORT는 일종의 구멍을 만들어서 해당 구멍을 이용하여 통신하도록 해준다.
	이런 PORT를 정확하게 구성을 해 주어야 해당 포트를 이용하여
	각각의 프로그램중 어느 프로그램인지를 인식하여 통신할 수 있다.

	#
	SOCKADDR_IN ListenADDR = {};
	SOCKADDR_IN 구조체
	Internet Address Family에서 Windows 소켓에서 소켓을 연결할 로컬 또는 원격 주소를 지정하는 데 사용된다.
	즉, 주소정보를 담아두는 구조체이다.

	메모리에 데이터를 저장할때 크게 2가지 방식이 존재한다. 빅엔디안, 리틀엔디안 이라는 방식이다.
	예를 들어 16진수 0x12345678 이 있을 경우 빅엔디안과 리틀엔디안으로 어떻게 메모리 공간에 저장되는지를 비교해보자.
	빅엔디안: 12 34 56 78	// 네트워크상 표준 프로토콜
	리틀엔디안: 78 56 34 12	// 주로 인텔(Intel)프로세스 계열
	서로 다른 방식을 사용하는 컴퓨터 간에 데이터를 주고받을 경우 문제가 발생할 수 있다.
	그래서 네트워크 표준은 빅엔디안을 활용한다.

	tListenAddr.sin_family = AF_INET;
	: 인자들에 대한 설명중 sin_family는 반드시 AF_INET 이어야 함을 알 수 있다.
	#define AF_INET	2	//	internetwork: UDP, TCP, etc.
	로 기존에 정의되어 있다.

	tListenAddr.sin_port = htons(PORT);
	: PORT 번호를 설정한다. PORT 번호는 2바이트 안에서 표현할 수 있는 숫자로 정해야 하고
	기본으로 정해진 포트를 제외한 포트번호를 설정해야 한다.
	헤더파일을 include하는 최 상단부 하단에 #define 으로 4567로 설정해 주었다.
	htons: host to network short의 약자다. 이 함수를 거치면 무조건 빅엔디안 방식으로 데이터를 변환하여 설정한다.

	tListenAddr.sin_Addr.s_Addr = htonl(INADDR_ANY);
	: 서버는 현재 동작되는 컴퓨터의 IP 주소로 설정해주어야 한다. 우리(본 프로그램)는 따로 서버를 두지 않고 구현할 것이기 때문.
	따라서 INADDR_ANY를 넣어주면 현재 동작되는 컴퓨터의 IP 주소로 설정하게 된다.
	s_addr은 IPv4 Internet address를 의미한다.
	*/

	bind(hListen, (SOCKADDR*)&tListenAddr, sizeof(tListenAddr));
	listen(hListen, SOMAXCONN);
	/*
	# 소켓에 위에 설정한 주소정보를 묶어주고, 소켓을 접속대기상태로 만들어줌
	#
	bind(hListen, (SOCKADDR*)&tListenAddr, sizeof(tListenAddr));
	bind(소켓, 소켓 구성요소 구조체의 주소, 그 구조체의 크기);

	bind 함수는 소켓에 주소정보를 연결한다.
	즉, Listen 소켓의 역할은 접속승인만 해준다. 위에서 설정한 주소정보를 WinSock2.h 에 정의된 bind 함수를 이용하여 소켓에 묶어준다.
	첫번째 인자로는 위에 선언한 소켓을 넣어준다.
	두번째 인자로는 bind 될 소켓에 할당할 주소정보를 담고있는 구조체의 주소가 들어간다. (SOCKADDR* 타입 형변환)
	세번째 인자로는 두번째 인자로 넣은 구조체의 크기가 들어간다.

	listen(hListen, SOMAXCONN);
	listen 함수는 연결을 수신하는 상태로 소켓의 상태를 변경한다. 즉, 소켓을 접속 대기상태로 만들어준다.
	SOMAXCONN은 한꺼번에 요청 가능한 최대 접속승인 수를 의미한다.
	*/

	SOCKADDR_IN tClntAddr = {};
	int iClntSize = sizeof(tClntAddr);
	SOCKET hClient = accept(hListen, (SOCKADDR*)&tClntAddr, &iClntSize);
	/*
	# 클라이언트 측 소켓 생성 및 정보를 담을 구조세 생성 및 값 할당, 클라이언트가 접속 요청하면 승인해주는 역할

	#
	SOCKET hClient = accept(hListen, (SOCKADDR*)&tClntAddr, &iClntSize);
	accept(소켓, 소켓 구성요소 주소체의 주소, 그 구조체의 크기를 담고있는 변수의 주소);

	accept 함수를 이용하여 접속 요청을 수락해준다. 이 함수는 동기화된 방식으로 동작한다.
	동기화된 방식이란 요청을 마무리 하기 전까지 계속 대기상태에 놓이게 되는 것을 말한다.
	즉 요청이 들어오기 전까지 이 함수는 안빠져나온다.
	접속 요청을 승인하면 연결된 소켓이 만들어져서 리턴된다. 이렇게 만들어진 소켓을 이용해서 통신해야 한다.
	첫번째 인자로는 소켓을 넣어준다.
	두번째 인자로는 accpet 할 클라이언트측 주소정보 구조체의 주소가 들어간다. (SOCKADDR* 타입 형변환)
	세번째 인자로는 두번째 인자로 넣은 구조체의 크기를 저장해둔 변수의 주소가 들어간다.
	*/

	char	cBuffer[PACKET_SIZE] = {};
	recv(hClient, cBuffer, PACKET_SIZE, 0);
	printf("Recv Msg : %s\n", cBuffer);

	char	cMsg[] = "Server Send";
	send(hClient, cMsg, strlen(cMsg), 0);

	closesocket(hClient);
	closesocket(hListen);
	/*
	# 클라이언트 측으로부터 정보를 받아오고 출력, 클라이언트에 정보 전송

	#
	char cBuffer[PACKET_SIZE] = {};
	: 클라이언트측 정보를 수신하기위해 기존에 정의해둔 패킷 크기만큼 버퍼를 생성한다.

	recv(hClient, cBuffer, PACKET_SIZE, 0);
	recv(소켓, 수신 정보를 담을 배열주소, 그 배열의 크기, flag)

	recv 함수는 대상 소켓으로부터 보내온 정보를 받아주는 역할을 한다.
	보내준 데이터가 없다면 여기에서 받을때까지 계속 대기상태에 있게 된다.
	flag 값으로는 flag를 활성화시키지 않을것이기에 0을 지정해준다.
	그 이후 수신한 정보를 C 문법으로 출력한다.

	send(hListen, cMsg, strlen(cMsg), 0);
	수신과 같은 맥락으로 서버가 메시지를 클라이언트 측에 전달한다.

	#
	closesock(hClient);
	closesock(hListen);
	해당 소켓을 닫아준다.
	*/


	WSACleanup();
	/*
	WSACleanup();
	:  소켓을 활용하는 것은 WSAStartup 함수와 WSACleanup 함수 사이에 작성해댜 한다. 생성자와 소멸자 같은 개념이다.
	 WSACleanup 함수는 WSAStartup을 하면서 지정한 내용을 지워준다.
	*/
	return 0;
}