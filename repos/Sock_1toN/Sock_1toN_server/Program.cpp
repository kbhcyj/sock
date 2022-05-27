#define _WINSOCK_DEPRECATED_WARNINGS
#pragma warning(disable:4996)
#pragma comment(lib, "ws2_32.lib")

#include <stdio.h>
#include <WinSock2.h>
#include <process.h>
#include <string.h>

int server_inet()
