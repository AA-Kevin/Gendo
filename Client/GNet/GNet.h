// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� GNET_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// GNET_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef GNET_EXPORTS
#define GNET_API __declspec(dllexport)
#else
#define GNET_API __declspec(dllimport)
#endif
#include "stdafx.h"
#include <Windows.h>
#include "RopBase.h"
#include "RopUtil.h"
#include "RopProcess.h"
#include "RopNetState.h"

#define  TAPNAME "TAP-Win32 Adapter V9"
#define  TAPIP   "10.8.18.8"

extern "C"
{
    GNET_API INT  TapInstall();
    GNET_API INT  TapUnstall();
    GNET_API INT  TapStatus();
    GNET_API INT  TapRestore();
    GNET_API INT  TapSetIpDns(char *ip, char *mask, char *gw, char *dns1, char *dns2);
};


typedef INT  (*pfnTapInstall)();
typedef INT  (*pfnTapUnstall)();
typedef INT  (*pfnTapStatus)();
typedef INT  (*pfnTapRestore)();
typedef INT  (*pfnTapSetIpDns)(char *, char *, char *, char *, char *);
