#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <Windows.h>
#include <WinSock2.h>
#include <fcntl.h>
#include <locale>
#include <codecvt>
#include <vector>
#include <WS2tcpip.h>

using namespace std;


int main()
{
  setmode(_fileno(stdout), _O_U16TEXT);
  setlocale(LC_ALL, "Rus");
  SetConsoleCP(1251);

  WSADATA wsaData;
  ADDRINFO hints;
  ADDRINFO* addrResult;
  SOCKET ClientSocket = INVALID_SOCKET;
  SOCKET ListenSocket = INVALID_SOCKET;

  vector<const char*> messages;
  messages.push_back("Привет от сервера");
  messages.push_back("Пока от сервера");
  char recvBuffer[512];

  int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
  if (result != 0) {
    wcout << L"WSAStartup failed" << endl;
    return 1;
  }
  ZeroMemory(&hints, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;
  hints.ai_flags = AI_PASSIVE;


  result = getaddrinfo(NULL, "788", &hints, &addrResult);
  // get server info with all network interfaces
  if (result != 0) {
    wcout << L"getaddrinfo failed" << endl;
    return 1;
  }
  ListenSocket = socket(addrResult->ai_family, addrResult->ai_socktype, addrResult->ai_protocol);
  if (ListenSocket == INVALID_SOCKET) {
    wcout << L"socket creation with error" << endl;
    freeaddrinfo(addrResult);
    return 1;
  }
  result = bind(ListenSocket, addrResult->ai_addr, (int)addrResult->ai_addrlen);
  // binding to ListenSocket
  if (result == SOCKET_ERROR) {
    wcout << L"binding connect failed" << endl;
    freeaddrinfo(addrResult);
    WSACleanup();
    return 1;
  }
  // condition to trace binding connection failed

  result = listen(ListenSocket, SOMAXCONN);
  // listen function to ListenSocket with max client`s connections
  if (result == SOCKET_ERROR) {

    wcout << L"Listening failed" << endl;
    freeaddrinfo(addrResult);
    WSACleanup();
    return 1;
  }
  // condition to trace listening error

  ClientSocket = accept(ListenSocket, NULL, NULL);
  // accept function to ClientSocket from ListenSocket without any info about ClientSocket
  if (result == SOCKET_ERROR) {
    wcout << L"Accepting Failed" << endl;
    freeaddrinfo(addrResult);
    WSACleanup();
    return 1;
  }
  // condition to trace accepting error

  int i = 0;

  do {
    ZeroMemory(recvBuffer, 512);
    result = recv(ClientSocket, recvBuffer, 512, 0);
    string recvStr(recvBuffer, result);
    if (result > 0) {
      wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
      wstring wideStr = converter.from_bytes(recvStr);
      wcout << L"Получено " << result << L" байт" << endl;
      wcout << L"Получено " << wideStr << endl;
      result = send(ClientSocket, messages[i], (int)strlen(messages[i]), MSG_DONTROUTE);
      if (result == SOCKET_ERROR) {
        wcout << L"send Failed" << endl;
        freeaddrinfo(addrResult);
        WSACleanup();
        return 1;
      }
    }
    else if (result == 0) {
      wcout << L"Connection closed" << endl;
    }
    else {
      wcout << L"Message is not received" << endl;
    }
    i++;
  } while (result > 0);
  result = shutdown(ClientSocket, SD_SEND);
  if (result == SOCKET_ERROR) {
    wcout << L"shutdown error" << endl;
    freeaddrinfo(addrResult);
    WSACleanup();
    return 1;
  }
  closesocket(ClientSocket);
  closesocket(ListenSocket);
  freeaddrinfo(addrResult);
  WSACleanup();
}
