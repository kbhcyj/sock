//#include "stdafx.h"
#include <stdio.h>
#include <Winsock2.h>

#pragma comment(lib, "ws2_32")
#pragma warning(disable: 4996)

#define PORT	4567
#define PACKET_SIZE	1024
#define SERVER_IP	"192.168.117.1" 

int main() {
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET hSocket;
	hSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN tAddr = {};
	tAddr.sin_family = AF_INET;
	tAddr.sin_port = htons(PORT);
	tAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

	connect(hSocket, (SOCKADDR*)&tAddr, sizeof(tAddr));

	char	cMsg[] = "Client Send";
	send(hSocket, cMsg, strlen(cMsg), 0);

	char	cBuffer[PACKET_SIZE] = {};
	recv(hSocket, cBuffer, PACKET_SIZE, 0);

	printf("Recv Msg : %s\n", cBuffer);

	closesocket(hSocket);

	WSACleanup();
	return 0;
}