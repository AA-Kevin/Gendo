#ifndef ROP_REGISTRY_H
#define ROP_REGISTRY_H
#include "stdafx.h"
#include <winreg.h>


#define HKCR	HKEY_CLASSES_ROOT
#define HKCU	HKEY_CURRENT_USER
#define HKLM	HKEY_LOCAL_MACHINE
#define HKU		HKEY_USERS

#define RTN_OK 0 
#define RTN_ERROR 13

#define REGSALL   KEY_ALL_ACCESS
#define REGSREAD  KEY_READ
#define REGSWRITE KEY_WRITE

#define MAX_REG_LEN 32

class RopRegistry
{
public:
    RopRegistry();
    virtual ~RopRegistry();
public:
    DWORD DeleteKeyNT(HKEY hStartKey , LPTSTR pKeyName );
    LONG  EnumKey(DWORD dwIndex, LPTSTR lpName);
    LONG  EnumValue(DWORD dwIndex, LPTSTR lpName,DWORD* NameLen, LPTSTR lpValue, DWORD* ValueLen);

    BOOL IsKeyExist(HKEY hKeyRoot, LPCTSTR pszPath);
	BOOL IsKeyExistEx(HKEY hKeyRoot, LPCTSTR pszPath,LPCTSTR Key);
    //���ü�ֵ�İ�ȫ�ԡ�
    int SetKeySecurity(HKEY hRootKey, LPCTSTR pszSubKey);
    //��ָ���ļ�ֵ��
    LONG Open(HKEY hKeyRoot, LPCTSTR pszPath);
    LONG Delete(HKEY hKeyRoot, LPCTSTR pszPath);
    int  MakeMultiSz(LPTSTR lpBuf, LPCTSTR lpData);


    void Close();//�ر�ע���
	//дע���
    LONG Write(LPCTSTR pszKey, DWORD  dwVal);
    LONG Write(LPCTSTR pszKey, LPCTSTR pszVal);
    LONG WriteMultiSz(LPCTSTR pszKey, LPCTSTR pszVal);
    LONG Write(LPCTSTR pszKey, const BYTE* pData, DWORD dwLength);

	//��ע���
    LONG Read(LPCTSTR pszKey, DWORD&  dwVal);
    LONG Read(LPCTSTR pszKey, const TCHAR *sVal);
    LONG Read(LPCTSTR pszKey, BYTE* pData, DWORD& dwLength);
    LONG ReadMultiSz(LPCTSTR pszKey, const char * sVal,DWORD& dwLen);

    HKEY  m_hKey;//ע���ļ�ֵ��
};

#endif