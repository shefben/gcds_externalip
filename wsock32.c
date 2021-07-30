// Wrapper for wsock32.dll - C++ Source Code - 75 exports
// Original author unknown.
// Modified by NuWON Development Team. 
// 7/29/2021

//Scroll to sys_inet_ntoa to view the functions involved with this patch.


#include <windows.h>
#include <stdio.h>
#include <wininet.h> 
#include <urlmon.h>
#include <stdint.h>
#include <winsock.h>
#include "wsock.h"
#include <tchar.h>
#pragma comment(lib, "wininet")
#pragma comment(lib, "urlmon")


typedef void (*lpfn_accept)(void);
lpfn_accept orig_accept;

void sys_accept(void)
{
   (*orig_accept)();
}


typedef int (*lpfn_bind)(SOCKET,const struct sockaddr*, int);
lpfn_bind orig_bind;
/*
The bind function associates a local address with a socket.
*/
int sys_bind(SOCKET s, const struct sockaddr *name, int namelen)
{
	return (*orig_bind)(s, name, namelen);
}


typedef void (*lpfn_closesocket)(void);
lpfn_closesocket orig_closesocket;

void sys_closesocket(void)
{
   (*orig_closesocket)();
}


typedef void (*lpfn_connect)(void);
lpfn_connect orig_connect;

void sys_connect(void)
{
   (*orig_connect)();
}

typedef void (*lpfn_getpeername)(void);
lpfn_getpeername orig_getpeername;

void sys_getpeername(void)
{
   (*orig_getpeername)();
}


typedef int (*lpfn_getsockname)(SOCKET, const struct sockaddr*, int);
lpfn_getsockname orig_getsockname;
/*
The getsockname function retrieves the local name for a socket.
*/
int sys_getsockname(SOCKET s, const struct sockaddr *name, int namelen)
{	
   return (*orig_getsockname)(s, name, namelen);
}


typedef void (*lpfn_getsockopt)(void);
lpfn_getsockopt orig_getsockopt;

void sys_getsockopt(void)
{
   (*orig_getsockopt)();
}


typedef void (*lpfn_htonl)(void);
lpfn_htonl orig_htonl;

void sys_htonl(void)
{
   (*orig_htonl)();
}


typedef void (*lpfn_htons)(void);
lpfn_htons orig_htons;
/*
The htons function converts a u_short from host to TCP/IP network byte order (which is big-endian).
*/
void sys_htons(void)
{
   (*orig_htons)();
}


typedef int (*lpfn_inet_addr)(const char *);
lpfn_inet_addr orig_inet_addr;
/*
The inet_addr function converts a string containing an IPv4 dotted-decimal address into a proper address for the IN_ADDR structure.
*/
int sys_inet_addr(const char * input)
{
   return (*orig_inet_addr)(input);
}
char* GetIP(void);
typedef char* (*lpfn_inet_ntoa)(struct in_addr);
lpfn_inet_ntoa orig_inet_ntoa;
/*
The inet_ntoa function converts an (Ipv4) Internet network address into an ASCII string in Internet standard dotted-decimal format.
*/
char* sys_inet_ntoa(struct in_addr addr_input)
{
   addr_input.S_un.S_addr = inet_addr(GetIP());
	
   return (*orig_inet_ntoa)(addr_input);
}
char* GetIP(void) 
{
    char szPath[256], szRead[128], *Token, szSite[] = "http://checkip.dyndns.org/Current IP Check.htm";
    char *szRet = malloc(256);
	GetTempPath(256, szPath);
    strcat(szPath, "my_ip.txt");
	
    if (URLDownloadToFile(0, szSite, szPath, 0, 0) == S_OK) 
		{
			FILE *fIpHtm = fopen(szPath, "a+");
			if (fIpHtm) 
				{
					fgets(szRead, 128, fIpHtm);
					Token = strrchr(szRead, ':');
					Token = strtok(Token, "<");
					lstrcpyn(szRead, Token + 2, sizeof(szRead));
					sprintf(szRet, "%s", szRead);
					return szRet;
				}

		}
	else
		{			
			if (URLDownloadToFile(0, "https://myexternalip.com/raw", szPath, 0, 0) == S_OK) 
				{
					FILE *fIpHtm = fopen(szPath, "a+");
					if (fIpHtm) 
						{
							fgets(szRead, 47, fIpHtm);
							sprintf(szRet, "%s", szRead);
							return szRet;
						}
				}
		}
	MessageBox(0, "Cannot Pull external IP from checkip.dyndns.com or myexternalip.com/raw.\n please contact NuWON Support at:\n support@neuwon.com\n or create a topic on the NuWON forum\n Resorting to 127.0.0.1\n", "External IP ERROR",MB_OK|MB_SYSTEMMODAL);
    return "127.0.0.1";
}
 
typedef void (*lpfn_ioctlsocket)(void);
lpfn_ioctlsocket orig_ioctlsocket;

void sys_ioctlsocket(void)
{
   (*orig_ioctlsocket)();
}


typedef void (*lpfn_listen)(void);
lpfn_listen orig_listen;

void sys_listen(void)
{
   (*orig_listen)();
}


typedef void (*lpfn_ntohl)(void);
lpfn_ntohl orig_ntohl;

void sys_ntohl(void)
{
   (*orig_ntohl)();
}


typedef void (*lpfn_ntohs)(void);
lpfn_ntohs orig_ntohs;

void sys_ntohs(void)
{
   (*orig_ntohs)();
}


typedef void (*lpfn_recv)(void);
lpfn_recv orig_recv;

void sys_recv(void)
{
   (*orig_recv)();
}

typedef int (FAR PASCAL*lpfn_recvfrom)(IN SOCKET s, OUT char FAR * buf, IN int len, IN int flags, OUT struct sockaddr FAR *from, IN OUT int FAR * fromlen);
lpfn_recvfrom orig_recvfrom;

int FAR PASCAL sys_recvfrom(IN SOCKET s, OUT char FAR * buf, IN int len, IN int flags, OUT struct sockaddr FAR *from, IN OUT int FAR * fromlen)
{

   return (*orig_recvfrom)(s, buf, len, flags, from, fromlen);
}


typedef void (*lpfn_select)(void);
lpfn_select orig_select;

void sys_select(void)
{
   (*orig_select)();
}


typedef void (*lpfn_send)(void);
lpfn_send orig_send;

void sys_send(void)
{
   (*orig_send)();
}


typedef void (*lpfn_sendto)(void);
lpfn_sendto orig_sendto;

void sys_sendto(void)
{
   (*orig_sendto)();
}


typedef void (*lpfn_setsockopt)(void);
lpfn_setsockopt orig_setsockopt;

void sys_setsockopt(void)
{
   (*orig_setsockopt)();
}


typedef void (*lpfn_shutdown)(void);
lpfn_shutdown orig_shutdown;

//I could be useful
void sys_shutdown(void)
{
   (*orig_shutdown)();
}


typedef void (*lpfn_socket)(void);
lpfn_socket orig_socket;

void sys_socket(void)
{
   (*orig_socket)();
}


typedef void (*lpfn_MigrateWinsockConfiguration)(void);
lpfn_MigrateWinsockConfiguration orig_MigrateWinsockConfiguration;

void sys_MigrateWinsockConfiguration(void)
{
   (*orig_MigrateWinsockConfiguration)();
}


typedef struct hostent* (*lpfn_gethostbyaddr)(const char*,int,int);
lpfn_gethostbyaddr orig_gethostbyaddr;

struct hostent* sys_gethostbyaddr( const char *addr, int len,int type)
{
   return (*orig_gethostbyaddr)(addr,len,type);
}

typedef struct hostent *(*lpfn_gethostbyname)(const char *);
lpfn_gethostbyname orig_gethostbyname;
/*
The gethostbyname function retrieves host information corresponding to a host name from a host database.
*/

struct hostent *sys_gethostbyname(const char *name)
{
	return (*orig_gethostbyname)(name);
}

typedef void (*lpfn_getprotobyname)(void);
lpfn_getprotobyname orig_getprotobyname;

void sys_getprotobyname(void)
{
   (*orig_getprotobyname)();
}


typedef void (*lpfn_getprotobynumber)(void);
lpfn_getprotobynumber orig_getprotobynumber;

void sys_getprotobynumber(void)
{
   (*orig_getprotobynumber)();
}


typedef void (*lpfn_getservbyname)(void);
lpfn_getservbyname orig_getservbyname;

void sys_getservbyname(void)
{
   (*orig_getservbyname)();
}


typedef void (*lpfn_getservbyport)(void);
lpfn_getservbyport orig_getservbyport;

void sys_getservbyport(void)
{
   (*orig_getservbyport)();
}


typedef int (*lpfn_gethostname)(char*, int);
lpfn_gethostname orig_gethostname;
/*
The gethostname function retrieves the standard host name for the local computer.
*/
int sys_gethostname(char *name, int namelen)
{
   return (*orig_gethostname)(name, namelen);
}


typedef void (*lpfn_WSAAsyncSelect)(void);
lpfn_WSAAsyncSelect orig_WSAAsyncSelect;

void sys_WSAAsyncSelect(void)
{
   (*orig_WSAAsyncSelect)();
}


typedef void (*lpfn_WSAAsyncGetHostByAddr)(void);
lpfn_WSAAsyncGetHostByAddr orig_WSAAsyncGetHostByAddr;

void sys_WSAAsyncGetHostByAddr(void)
{
   (*orig_WSAAsyncGetHostByAddr)();
}


typedef void (*lpfn_WSAAsyncGetHostByName)(void);
lpfn_WSAAsyncGetHostByName orig_WSAAsyncGetHostByName;

void sys_WSAAsyncGetHostByName(void)
{
   (*orig_WSAAsyncGetHostByName)();
}


typedef void (*lpfn_WSAAsyncGetProtoByNumber)(void);
lpfn_WSAAsyncGetProtoByNumber orig_WSAAsyncGetProtoByNumber;

void sys_WSAAsyncGetProtoByNumber(void)
{
   (*orig_WSAAsyncGetProtoByNumber)();
}


typedef void (*lpfn_WSAAsyncGetProtoByName)(void);
lpfn_WSAAsyncGetProtoByName orig_WSAAsyncGetProtoByName;

void sys_WSAAsyncGetProtoByName(void)
{
   (*orig_WSAAsyncGetProtoByName)();
}


typedef void (*lpfn_WSAAsyncGetServByPort)(void);
lpfn_WSAAsyncGetServByPort orig_WSAAsyncGetServByPort;

void sys_WSAAsyncGetServByPort(void)
{
   (*orig_WSAAsyncGetServByPort)();
}


typedef void (*lpfn_WSAAsyncGetServByName)(void);
lpfn_WSAAsyncGetServByName orig_WSAAsyncGetServByName;

void sys_WSAAsyncGetServByName(void)
{
   (*orig_WSAAsyncGetServByName)();
}


typedef void (*lpfn_WSACancelAsyncRequest)(void);
lpfn_WSACancelAsyncRequest orig_WSACancelAsyncRequest;

void sys_WSACancelAsyncRequest(void)
{
   (*orig_WSACancelAsyncRequest)();
}


typedef void (*lpfn_WSASetBlockingHook)(void);
lpfn_WSASetBlockingHook orig_WSASetBlockingHook;

void sys_WSASetBlockingHook(void)
{
   (*orig_WSASetBlockingHook)();
}


typedef void (*lpfn_WSAUnhookBlockingHook)(void);
lpfn_WSAUnhookBlockingHook orig_WSAUnhookBlockingHook;

void sys_WSAUnhookBlockingHook(void)
{
   (*orig_WSAUnhookBlockingHook)();
}


typedef void (*lpfn_WSAGetLastError)(void);
lpfn_WSAGetLastError orig_WSAGetLastError;

void sys_WSAGetLastError(void)
{
   (*orig_WSAGetLastError)();
}


typedef void (*lpfn_WSASetLastError)(void);
lpfn_WSASetLastError orig_WSASetLastError;

void sys_WSASetLastError(void)
{
   (*orig_WSASetLastError)();
}


typedef void (*lpfn_WSACancelBlockingCall)(void);
lpfn_WSACancelBlockingCall orig_WSACancelBlockingCall;

void sys_WSACancelBlockingCall(void)
{
   (*orig_WSACancelBlockingCall)();
}


typedef void (*lpfn_WSAIsBlocking)(void);
lpfn_WSAIsBlocking orig_WSAIsBlocking;

void sys_WSAIsBlocking(void)
{
   (*orig_WSAIsBlocking)();
}


typedef void (*lpfn_WSAStartup)(void);
lpfn_WSAStartup orig_WSAStartup;

void sys_WSAStartup(void)
{
   (*orig_WSAStartup)();
}

//I could be useful too
typedef void (*lpfn_WSACleanup)(void);
lpfn_WSACleanup orig_WSACleanup;

void sys_WSACleanup(void)
{
   (*orig_WSACleanup)();
}


typedef void (*lpfn___WSAFDIsSet)(void);
lpfn___WSAFDIsSet orig___WSAFDIsSet;

void sys___WSAFDIsSet(void)
{
   (*orig___WSAFDIsSet)();
}


typedef void (*lpfn_WEP)(void);
lpfn_WEP orig_WEP;

void sys_WEP(void)
{
   (*orig_WEP)();
}


typedef void (*lpfn_WSApSetPostRoutine)(void);
lpfn_WSApSetPostRoutine orig_WSApSetPostRoutine;

void sys_WSApSetPostRoutine(void)
{
   (*orig_WSApSetPostRoutine)();
}


typedef void (*lpfn_inet_network)(void);
lpfn_inet_network orig_inet_network;

void sys_inet_network(void)
{
   (*orig_inet_network)();
}


typedef void (*lpfn_getnetbyname)(void);
lpfn_getnetbyname orig_getnetbyname;

void sys_getnetbyname(void)
{
   (*orig_getnetbyname)();
}


typedef void (*lpfn_rcmd)(void);
lpfn_rcmd orig_rcmd;

void sys_rcmd(void)
{
   (*orig_rcmd)();
}


typedef void (*lpfn_rexec)(void);
lpfn_rexec orig_rexec;

void sys_rexec(void)
{
   (*orig_rexec)();
}


typedef void (*lpfn_rresvport)(void);
lpfn_rresvport orig_rresvport;

void sys_rresvport(void)
{
   (*orig_rresvport)();
}


typedef void (*lpfn_sethostname)(void);
lpfn_sethostname orig_sethostname;

void sys_sethostname(void)
{
   (*orig_sethostname)();
}


typedef void (*lpfn_dn_expand)(void);
lpfn_dn_expand orig_dn_expand;

void sys_dn_expand(void)
{
   (*orig_dn_expand)();
}


typedef void (*lpfn_WSARecvEx)(void);
lpfn_WSARecvEx orig_WSARecvEx;

void sys_WSARecvEx(void)
{
   (*orig_WSARecvEx)();
}


typedef void (*lpfn_s_perror)(void);
lpfn_s_perror orig_s_perror;

void sys_s_perror(void)
{
   (*orig_s_perror)();
}


typedef void (*lpfn_GetAddressByNameA)(void);
lpfn_GetAddressByNameA orig_GetAddressByNameA;

void sys_GetAddressByNameA(void)
{
   (*orig_GetAddressByNameA)();
}


typedef void (*lpfn_GetAddressByNameW)(void);
lpfn_GetAddressByNameW orig_GetAddressByNameW;

void sys_GetAddressByNameW(void)
{
   (*orig_GetAddressByNameW)();
}


typedef void (*lpfn_EnumProtocolsA)(void);
lpfn_EnumProtocolsA orig_EnumProtocolsA;

void sys_EnumProtocolsA(void)
{
   (*orig_EnumProtocolsA)();
}


typedef void (*lpfn_EnumProtocolsW)(void);
lpfn_EnumProtocolsW orig_EnumProtocolsW;

void sys_EnumProtocolsW(void)
{
   (*orig_EnumProtocolsW)();
}


typedef void (*lpfn_GetTypeByNameA)(void);
lpfn_GetTypeByNameA orig_GetTypeByNameA;

void sys_GetTypeByNameA(void)
{
   (*orig_GetTypeByNameA)();
}


typedef void (*lpfn_GetTypeByNameW)(void);
lpfn_GetTypeByNameW orig_GetTypeByNameW;

void sys_GetTypeByNameW(void)
{
   (*orig_GetTypeByNameW)();
}


typedef void (*lpfn_GetNameByTypeA)(void);
lpfn_GetNameByTypeA orig_GetNameByTypeA;

void sys_GetNameByTypeA(void)
{
   (*orig_GetNameByTypeA)();
}


typedef void (*lpfn_GetNameByTypeW)(void);
lpfn_GetNameByTypeW orig_GetNameByTypeW;

void sys_GetNameByTypeW(void)
{
   (*orig_GetNameByTypeW)();
}


typedef void (*lpfn_SetServiceA)(void);
lpfn_SetServiceA orig_SetServiceA;

void sys_SetServiceA(void)
{
   (*orig_SetServiceA)();
}


typedef void (*lpfn_SetServiceW)(void);
lpfn_SetServiceW orig_SetServiceW;

void sys_SetServiceW(void)
{
   (*orig_SetServiceW)();
}


typedef void (*lpfn_GetServiceA)(void);
lpfn_GetServiceA orig_GetServiceA;

void sys_GetServiceA(void)
{
   (*orig_GetServiceA)();
}


typedef void (*lpfn_GetServiceW)(void);
lpfn_GetServiceW orig_GetServiceW;

void sys_GetServiceW(void)
{
   (*orig_GetServiceW)();
}


typedef void (*lpfn_NPLoadNameSpaces)(void);
lpfn_NPLoadNameSpaces orig_NPLoadNameSpaces;

void sys_NPLoadNameSpaces(void)
{
   (*orig_NPLoadNameSpaces)();
}


typedef void (*lpfn_TransmitFile)(void);
lpfn_TransmitFile orig_TransmitFile;

void sys_TransmitFile(void)
{
   (*orig_TransmitFile)();
}


typedef void (*lpfn_AcceptEx)(void);
lpfn_AcceptEx orig_AcceptEx;

void sys_AcceptEx(void)
{
   (*orig_AcceptEx)();
}


typedef void (*lpfn_GetAcceptExSockaddrs)(void);
lpfn_GetAcceptExSockaddrs orig_GetAcceptExSockaddrs;

void sys_GetAcceptExSockaddrs(void)
{
   (*orig_GetAcceptExSockaddrs)();
}


//  That's all the stubs, now for the boilerplate code.

BOOL Initialize(void)
{
   HMODULE hModule;
   char szOrigDll[MAX_PATH];


   GetSystemDirectory(szOrigDll, MAX_PATH);
   if( !((strlen(szOrigDll) + strlen("\\wsock32.dll")) < MAX_PATH) ) { return FALSE; }
   strcat(szOrigDll, "\\wsock32.dll");


   hModule = LoadLibrary(szOrigDll);
   if( hModule == NULL ) return FALSE;

   orig_accept = (lpfn_accept)GetProcAddress(hModule, "accept");
   orig_bind = (lpfn_bind)GetProcAddress(hModule, "bind");
   orig_closesocket = (lpfn_closesocket)GetProcAddress(hModule, "closesocket");
   orig_connect = (lpfn_connect)GetProcAddress(hModule, "connect");
   orig_getpeername = (lpfn_getpeername)GetProcAddress(hModule, "getpeername");
   orig_getsockname = (lpfn_getsockname)GetProcAddress(hModule, "getsockname");
   orig_getsockopt = (lpfn_getsockopt)GetProcAddress(hModule, "getsockopt");
   orig_htonl = (lpfn_htonl)GetProcAddress(hModule, "htonl");
   orig_htons = (lpfn_htons)GetProcAddress(hModule, "htons");
   orig_inet_addr = (lpfn_inet_addr)GetProcAddress(hModule, "inet_addr");
   orig_inet_ntoa = (lpfn_inet_ntoa)GetProcAddress(hModule, "inet_ntoa");
   orig_ioctlsocket = (lpfn_ioctlsocket)GetProcAddress(hModule, "ioctlsocket");
   orig_listen = (lpfn_listen)GetProcAddress(hModule, "listen");
   orig_ntohl = (lpfn_ntohl)GetProcAddress(hModule, "ntohl");
   orig_ntohs = (lpfn_ntohs)GetProcAddress(hModule, "ntohs");
   orig_recv = (lpfn_recv)GetProcAddress(hModule, "recv");
   orig_recvfrom = (lpfn_recvfrom)GetProcAddress(hModule, "recvfrom");
   orig_select = (lpfn_select)GetProcAddress(hModule, "select");
   orig_send = (lpfn_send)GetProcAddress(hModule, "send");
   orig_sendto = (lpfn_sendto)GetProcAddress(hModule, "sendto");
   orig_setsockopt = (lpfn_setsockopt)GetProcAddress(hModule, "setsockopt");
   orig_shutdown = (lpfn_shutdown)GetProcAddress(hModule, "shutdown");
   orig_socket = (lpfn_socket)GetProcAddress(hModule, "socket");
   orig_MigrateWinsockConfiguration = (lpfn_MigrateWinsockConfiguration)GetProcAddress(hModule, "MigrateWinsockConfiguration");
   orig_gethostbyaddr = (lpfn_gethostbyaddr)GetProcAddress(hModule, "gethostbyaddr");
   orig_gethostbyname = (lpfn_gethostbyname)GetProcAddress(hModule, "gethostbyname");
   orig_getprotobyname = (lpfn_getprotobyname)GetProcAddress(hModule, "getprotobyname");
   orig_getprotobynumber = (lpfn_getprotobynumber)GetProcAddress(hModule, "getprotobynumber");
   orig_getservbyname = (lpfn_getservbyname)GetProcAddress(hModule, "getservbyname");
   orig_getservbyport = (lpfn_getservbyport)GetProcAddress(hModule, "getservbyport");
   orig_gethostname = (lpfn_gethostname)GetProcAddress(hModule, "gethostname");
   orig_WSAAsyncSelect = (lpfn_WSAAsyncSelect)GetProcAddress(hModule, "WSAAsyncSelect");
   orig_WSAAsyncGetHostByAddr = (lpfn_WSAAsyncGetHostByAddr)GetProcAddress(hModule, "WSAAsyncGetHostByAddr");
   orig_WSAAsyncGetHostByName = (lpfn_WSAAsyncGetHostByName)GetProcAddress(hModule, "WSAAsyncGetHostByName");
   orig_WSAAsyncGetProtoByNumber = (lpfn_WSAAsyncGetProtoByNumber)GetProcAddress(hModule, "WSAAsyncGetProtoByNumber");
   orig_WSAAsyncGetProtoByName = (lpfn_WSAAsyncGetProtoByName)GetProcAddress(hModule, "WSAAsyncGetProtoByName");
   orig_WSAAsyncGetServByPort = (lpfn_WSAAsyncGetServByPort)GetProcAddress(hModule, "WSAAsyncGetServByPort");
   orig_WSAAsyncGetServByName = (lpfn_WSAAsyncGetServByName)GetProcAddress(hModule, "WSAAsyncGetServByName");
   orig_WSACancelAsyncRequest = (lpfn_WSACancelAsyncRequest)GetProcAddress(hModule, "WSACancelAsyncRequest");
   orig_WSASetBlockingHook = (lpfn_WSASetBlockingHook)GetProcAddress(hModule, "WSASetBlockingHook");
   orig_WSAUnhookBlockingHook = (lpfn_WSAUnhookBlockingHook)GetProcAddress(hModule, "WSAUnhookBlockingHook");
   orig_WSAGetLastError = (lpfn_WSAGetLastError)GetProcAddress(hModule, "WSAGetLastError");
   orig_WSASetLastError = (lpfn_WSASetLastError)GetProcAddress(hModule, "WSASetLastError");
   orig_WSACancelBlockingCall = (lpfn_WSACancelBlockingCall)GetProcAddress(hModule, "WSACancelBlockingCall");
   orig_WSAIsBlocking = (lpfn_WSAIsBlocking)GetProcAddress(hModule, "WSAIsBlocking");
   orig_WSAStartup = (lpfn_WSAStartup)GetProcAddress(hModule, "WSAStartup");
   orig_WSACleanup = (lpfn_WSACleanup)GetProcAddress(hModule, "WSACleanup");
   orig___WSAFDIsSet = (lpfn___WSAFDIsSet)GetProcAddress(hModule, "__WSAFDIsSet");
   orig_WEP = (lpfn_WEP)GetProcAddress(hModule, "WEP");
   orig_WSApSetPostRoutine = (lpfn_WSApSetPostRoutine)GetProcAddress(hModule, "WSApSetPostRoutine");
   orig_inet_network = (lpfn_inet_network)GetProcAddress(hModule, "inet_network");
   orig_getnetbyname = (lpfn_getnetbyname)GetProcAddress(hModule, "getnetbyname");
   orig_rcmd = (lpfn_rcmd)GetProcAddress(hModule, "rcmd");
   orig_rexec = (lpfn_rexec)GetProcAddress(hModule, "rexec");
   orig_rresvport = (lpfn_rresvport)GetProcAddress(hModule, "rresvport");
   orig_sethostname = (lpfn_sethostname)GetProcAddress(hModule, "sethostname");
   orig_dn_expand = (lpfn_dn_expand)GetProcAddress(hModule, "dn_expand");
   orig_WSARecvEx = (lpfn_WSARecvEx)GetProcAddress(hModule, "WSARecvEx");
   orig_s_perror = (lpfn_s_perror)GetProcAddress(hModule, "s_perror");
   orig_GetAddressByNameA = (lpfn_GetAddressByNameA)GetProcAddress(hModule, "GetAddressByNameA");
   orig_GetAddressByNameW = (lpfn_GetAddressByNameW)GetProcAddress(hModule, "GetAddressByNameW");
   orig_EnumProtocolsA = (lpfn_EnumProtocolsA)GetProcAddress(hModule, "EnumProtocolsA");
   orig_EnumProtocolsW = (lpfn_EnumProtocolsW)GetProcAddress(hModule, "EnumProtocolsW");
   orig_GetTypeByNameA = (lpfn_GetTypeByNameA)GetProcAddress(hModule, "GetTypeByNameA");
   orig_GetTypeByNameW = (lpfn_GetTypeByNameW)GetProcAddress(hModule, "GetTypeByNameW");
   orig_GetNameByTypeA = (lpfn_GetNameByTypeA)GetProcAddress(hModule, "GetNameByTypeA");
   orig_GetNameByTypeW = (lpfn_GetNameByTypeW)GetProcAddress(hModule, "GetNameByTypeW");
   orig_SetServiceA = (lpfn_SetServiceA)GetProcAddress(hModule, "SetServiceA");
   orig_SetServiceW = (lpfn_SetServiceW)GetProcAddress(hModule, "SetServiceW");
   orig_GetServiceA = (lpfn_GetServiceA)GetProcAddress(hModule, "GetServiceA");
   orig_GetServiceW = (lpfn_GetServiceW)GetProcAddress(hModule, "GetServiceW");
   orig_NPLoadNameSpaces = (lpfn_NPLoadNameSpaces)GetProcAddress(hModule, "NPLoadNameSpaces");
   orig_TransmitFile = (lpfn_TransmitFile)GetProcAddress(hModule, "TransmitFile");
   orig_AcceptEx = (lpfn_AcceptEx)GetProcAddress(hModule, "AcceptEx");
   orig_GetAcceptExSockaddrs = (lpfn_GetAcceptExSockaddrs)GetProcAddress(hModule, "GetAcceptExSockaddrs");

   //We might want to make sure these aren't null, but it'll be apparent if something we call isn't.
   return TRUE;
}

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
   if( dwReason == DLL_PROCESS_ATTACH )
   {
      DisableThreadLibraryCalls(hInstance);
      return Initialize();
   }

   return TRUE;
}
