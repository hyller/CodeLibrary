/* ************************************
*《精通Windows API》
* 示例代码
* server.c
* 14.1 socket通信
**************************************/
/* 头文件 */
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
/* 常量 */
#define DEFAULT_PORT "10000" // 端口
#define MAX_REQUEST 1024 // 接收数据的缓存大小
#define BUF_SIZE 4096 // 发送数据的缓存大小

/*************************************
* CommunicationThread
* 功能	用于接收和发送数据的线程
*			为每一个连接的客户端创建一个接收发送数据的线程，
*			可以使用多个客户端同时连接到服务端
* 参数	lpParameter，SOKCET
**************************************/
DWORD WINAPI CommunicationThread(
								 LPVOID lpParameter
								 )
{
	DWORD dwTid = GetCurrentThreadId();
	// 获得参数sokcet
	SOCKET socket = (SOCKET)lpParameter;
	// 为接收数据分配空间
	LPSTR szRequest = HeapAlloc(GetProcessHeap(),0, MAX_REQUEST);
	int iResult;
	int bytesSent;// 用于保存send的返回值，实际发送的数据的大小

	// 接收数据
	iResult = recv(socket, // socket
		szRequest, // 接收缓存
		MAX_REQUEST, // 缓存大小
		0);// 标志
	if (iResult == 0)// 接收数据失败，连接已经关闭
	{
		printf("Connection closing...\n");
		HeapFree(GetProcessHeap(), 0 ,szRequest);
		closesocket(socket);
		return 1;
	}
	else if (iResult == SOCKET_ERROR)// 接收数据失败，socket错误
	{
		printf("recv failed: %d\n", WSAGetLastError());
		HeapFree(GetProcessHeap(), 0 ,szRequest);
		closesocket(socket);
		return 1;
	}
	else if (iResult > 0) // 接收数据成功
	{
		// 显示接收到的数据
		printf("\tCommunicationThread(%d)\tBytes received: %d\n", dwTid, iResult);
		printf("\tCommunicationThread(%d)\trequest string is (%s)\n",dwTid, szRequest);

		// 如果接收到的数据是"download file"
		if (lstrcmpi(szRequest, "download file") == 0)
		{
			// 读取文件download.txt将发送
			HANDLE hFile;
			LPVOID lpReadBuf; // 发送缓存
			DWORD dwBytesRead;
			DWORD dwFileSize;
			DWORD dwSendFile = 0;
			hFile = CreateFile("download.txt",
				GENERIC_READ,
				FILE_SHARE_READ,
				NULL,
				OPEN_EXISTING,
				FILE_ATTRIBUTE_NORMAL,
				NULL);

			if (hFile == INVALID_HANDLE_VALUE)
			{
				printf("\tCommunicationThread\tCould not open file (error %d)\n", 
					GetLastError());
				send(socket, "error", 6, 0);
				closesocket(socket);
				return 1;
			}
			// 分配发送数据缓存
			lpReadBuf = HeapAlloc(GetProcessHeap(), 0 , BUF_SIZE);
			// 获取文件大小
			dwFileSize = GetFileSize(hFile, NULL);
			// 循环发送
			while(1)
			{
				// 读文件到缓存
				if(!ReadFile(hFile, lpReadBuf, BUF_SIZE, &dwBytesRead, NULL))
				{
					printf("\tCommunicationThread\tCould not read from file (error %d)\n", 
						GetLastError());
					closesocket(socket);
					CloseHandle(hFile);
					return 1;
				}
				// 发送读取的文件数据
				bytesSent = send(socket, lpReadBuf, dwBytesRead, 0);
				if( bytesSent == SOCKET_ERROR)
				{
					printf("\tCommunicationThread\tsend error %d\n", 
						WSAGetLastError());
					closesocket(socket);
					CloseHandle(hFile);
					return 1;
				}
				// 显示发送数据的大小
				printf("\tCommunicationThread(%d)\tsend %d bytes\n", dwTid,  bytesSent);
				// 累加，已经发送的大小
				dwSendFile += dwBytesRead;
				// 如果所有文件数据都已经发送
				if(dwSendFile == dwFileSize)
				{
					printf("\tCommunicationThread\tFile download ok\n");
					break;// 退出循环
				}
			}
			// 释放内存、关闭连接，关闭文件
			HeapFree(GetProcessHeap(), 0 , lpReadBuf);
			CloseHandle(hFile);
			closesocket(socket);
		}
		// 如果接收到的数据是"get information"
		else if (lstrcmpi(szRequest, "get information") == 0)
		{
			// 发送数据
			bytesSent = send(socket, // socket
				"this is information", // 数据
				lstrlen("this is information")+1, // 数据长度
				0);// 标志
			// 判断是否成功
			if( bytesSent == SOCKET_ERROR)
			{
				printf("\tCommunicationThread\tsend error %d\n", 
					WSAGetLastError());
				closesocket(socket);
				return 1;
			}
			printf("\tCommunicationThread(%d)\tsend %d bytes\n",dwTid, bytesSent);
		}
		else// 收到未知数据
		{
			printf ("unreferenced request\n");
		}
	}
	// 释放接收数据缓存，关闭socket
	HeapFree(GetProcessHeap(), 0 ,szRequest);
	closesocket(socket);
	return 0;
}

/*************************************
* int __cdecl main(void)
* 功能	socket服务端
**************************************/
int __cdecl main(void)
{
	WSADATA wsaData;
	SOCKET ListenSocket = INVALID_SOCKET;// 监听socket
	SOCKET ClientSocket = INVALID_SOCKET;// 连接socket
	struct addrinfo *result = NULL,
		hints;
	int iResult;// 保存返回结果

	// 初始化Winsock，保证Ws2_32.dll已经加载
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != 0)
	{
		printf("WSAStartup failed: %d\n", iResult);
		return 1;
	}
	// 地址
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// 获取主机地址，保证网络协议可用等
	iResult = getaddrinfo(NULL, // 本机
		DEFAULT_PORT, // 端口
		&hints, // 使用的网络协议，连接类型等
		&result);// 结果
	if ( iResult != 0 )
	{
		printf("getaddrinfo failed: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	// 创建socket，用于监听
	ListenSocket = socket(
		result->ai_family, // 网络协议，AF_INET，IPv4
		result->ai_socktype, // 类型，SOCK_STREAM
		result->ai_protocol);// 通信协议，TCP
	if (ListenSocket == INVALID_SOCKET)
	{
		printf("socket failed: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}
	// 绑定到端口
	iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR)
	{
		printf("bind failed: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}
	printf("bind\n");

	freeaddrinfo(result);// reuslt不再使用

	// 开始监听
	iResult = listen(ListenSocket, SOMAXCONN);
	printf("start listen......\n");
	if (iResult == SOCKET_ERROR)
	{
		printf("listen failed: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}
	while (1)
	{
		// 接收客户端的连接，accept函数会等待，直到连接建立
		printf("ready to accept\n");
		ClientSocket = accept(ListenSocket, NULL, NULL);
		// accept函数返回，说明已经有客户端连接
		// 返回连接socket
		printf("accept a connetion\n");
		if (ClientSocket == INVALID_SOCKET)
		{
			printf("accept failed: %d\n", WSAGetLastError());
			closesocket(ListenSocket);
			break;// 等待连接错误，退出循环
		}
		// 为每一个连接创建一个数据发送的接收线程，
		// 使服务端又可以立即接收其他客户端的连接
		if(!CreateThread(
			NULL,
			0,
			CommunicationThread, // 线程函数
			(LPVOID)ClientSocket, // 将socket作为参数
			0,
			NULL))
		{
			printf("Create Thread error (%d)", GetLastError());
			break;
		}
	}
	// 循环退出，释放DLL。
	WSACleanup();
	return 0;
}