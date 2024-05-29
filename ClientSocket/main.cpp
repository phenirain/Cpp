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
 // set ru language

  WSADATA wsaData;
  // object to store data about Windows Socket
  ADDRINFO hints;
  // object to store info about socket(flags(AI_PASSIVE - LISTEn), family address(AF_INET - IPV4),
  // socktype(SOCK_STREAM - to stream,
  // ai_protocol(IPPROTO_TCP - TCP)
  ADDRINFO* addrResult;
  // object to store structures containing suitable addresses that match the search criteria.
  SOCKET ClientSocket = INVALID_SOCKET;
  // object of socket - is uninitialize

  vector<const char*> messages;
  // vector to store messages from client
  messages.push_back("Привет от клиента");
  messages.push_back("Пока от клиента");
  char recvBuffer[512];
  // it is object to receive data from server

  int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
  // initialize winsock
  if (result != 0) {
    wcout << L"WSAStartup failed" << endl;
    return 1;
  }
  // condition to trace initialization error
  ZeroMemory(&hints,sizeof(hints));
  // set all memory of hinst to zero 0x00 to avoid errors
  hints.ai_family = AF_INET; // set IPv4
  hints.ai_socktype = SOCK_STREAM; // set Stream Sockets
  hints.ai_protocol = IPPROTO_TCP; // set TCP protocol

  result = getaddrinfo("localhost", "788", &hints, &addrResult);
  // get server info
  if (result != 0) {
    wcout << L"getaddrinfo failed" << endl;
    return 1;
  }
  // condition to trace get server info error
  ClientSocket = socket(addrResult->ai_family, addrResult->ai_socktype, addrResult->ai_protocol);
  // initialize socket - IPv4, Stream Socket, TCP protocol
  if (ClientSocket == INVALID_SOCKET) {
    wcout << L"socket creation with error" << endl;
    freeaddrinfo(addrResult);
    return 1;
  }
  // condition to trace initialization error of socket

  result = connect(ClientSocket, addrResult->ai_addr, (int)addrResult->ai_addrlen);
  // connect to ClientSocket with socket, address, and len of address
  if (result==SOCKET_ERROR) {
    wcout << L"Unable to connect server" << endl;
    freeaddrinfo(addrResult);
    WSACleanup();
    return 1;
  }
  // condition to trace connection error
  for (const char* message: messages) {
    result = send(ClientSocket, message, (int)strlen(message), MSG_DONTROUTE);
    // send function with ClientSocket, buffer of data, len of bytes to send and no route flag
    if (result == SOCKET_ERROR) {
      wcout << L"send Failed" << endl;
      freeaddrinfo(addrResult);
      WSACleanup();
      return 1;
    }
    // condition to trace sending error
    wcout << L"Sent " << result << L" bytes" << endl;
  }

  result = shutdown(ClientSocket, SD_SEND);
  // shutdown function with ServerSocket, and flag of how to shutdown connection - shutdown to send data
  if (result == SOCKET_ERROR) {
    wcout << L"shutdown error" << endl;
    freeaddrinfo(addrResult);
    WSACleanup();
    return 1;
  }
  // condition to trace shutdowning error
  do {
    ZeroMemory(recvBuffer, 512);
    // set all memory of receive buffer to 0x00 to avoid errors
    result = recv(ClientSocket, recvBuffer, 512, 0);
    // recv - receive function with ClientSocket, buffer of data, len of data and zero flags
    string recvStr(recvBuffer, result);
    // initialize string to store string of receive information with buffer of data and size of byte
    if (result > 0) {
      wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
      // object of converter
      wstring wideStr = converter.from_bytes(recvStr);
      // converting of recvStr to normal string
      wcout << L"Получено " << result << L" байт" << endl;
      wcout << L"Получено " << wideStr << endl;
    }
    else if (result == 0) {
      wcout << L"Connection closed" << endl;
    }
    // condition to info about closed connection
    else {
      wcout << L"Message is not received" << endl;
    }
    // condition to info about receiving message
  } while (result > 0);
  closesocket(ClientSocket);
  // close connection with socket and clear memory about this socket
  freeaddrinfo(addrResult);
  // clear memory about network address of the server
  WSACleanup();
  // clear all resources to work this library
}
