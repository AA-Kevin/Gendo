#pragma once

#include "stdafx.h"
#include "HttpDownload.h"
#include <vector>

using std::vector;

//////////////////////////////////////////////////////////////////////////

#define WM_USER_PROG			WM_USER+100
#define WM_USER_TEXTPRINT		WM_USER+101
#define WM_USER_DELETE_ITEM		WM_USER+102


#define	Thread_OutCode_ProgRess	0x110
#define	Thread_OutCode_Print	0x120
#define Thread_OutCode_Sleep	0x130


class _Nv_Download_Ex;



//���񷢲������͵Ľṹ��
struct tagDownloadAttriBute
{
    __int64		int64FileSize;
    CHAR		strFileName[1024];
    CHAR		strURL[4096];
    CHAR		strFilePath[1024];
    CHAR		strCollie[4096];
    BOOL		bIsOpen;
    INT			nNameType;

    tagDownloadAttriBute()
    {
        int64FileSize = 0;
        memset(strFilePath, 0, sizeof(strFilePath));
        memset(strURL, 0, sizeof(strURL));
        memset(strFileName, 0, sizeof(strFileName));
        memset(strCollie, 0, sizeof(strCollie));
        bIsOpen	= FALSE;
        nNameType = -1;
    }

    ~tagDownloadAttriBute()
    {

    }
};


//��¼�����ļ����ȵĽṹ��
struct tag_Donwload_File_Ini_Data 
{
    string strUrl;
    string strPath;
    string strFileName;
    string strDataPrint;
    string strCoolie;
    __int64 n64ProgRessPos;
    __int64 n64FileSize;
    BOOL	bOpenFile;

    tag_Donwload_File_Ini_Data()
    {
        n64ProgRessPos = 0;
        bOpenFile = FALSE;
    }
};


//�߳��������ݽṹ��
struct tag_Download_Data 
{
    CProgressUI		*pProgress;
    _Nv_Download	*Nv_Download_;
    CTextUI			*pTextPrint;
    INT				 nPos;
    CListUI			*pList;
    _Nv_Download_Ex *pNv_Download_Ex;
    BOOL		     bMode;

    tag_Download_Data()
    {
        pProgress = NULL;
        Nv_Download_ = NULL;
        pTextPrint = NULL;
        nPos = 0;
        pList = NULL;
        pNv_Download_Ex = NULL;
        bMode = FALSE;
    }
};




class _Nv_Download_Ex
{
public:
    //��ʼ��
    _Nv_Download_Ex()
    { 
        m_ListItemPos=-1;
        m_Handle_ProgRess = NULL;
        m_Handle_Print = NULL;
        m_bClose       = FALSE;
        Nv_Download_   = NULL;
        m_bOpenFile    = NULL;
    };
    ~_Nv_Download_Ex(){};

    //////////////////////////////////////////////////////////////////////////
    //list item������ָ��
    CListUI						*m_pList;
    CListContainerElementUI		*m_pListElement;
    CVerticalLayoutUI			*m_pVerticalLayout;
    CButtonUI					*m_pBtnIco;
    CTextUI						*m_pTextFile;
    CTextUI						*m_pTextPrint;
    CTextUI						*m_pTextJdtBk;
    CProgressUI					*m_pProgRess;
    CButtonUI					*m_pBtnStop;
    CButtonUI					*m_pBtnGo;
    CButtonUI					*m_pBtnOK;
    CButtonUI					*m_pBtnClose;

    //DUI ������ָ��
    VOID                       *m_pCtrlMng;

    //���ع�����
    _Nv_Download				*Nv_Download_;

    string						m_strUrl;
    string						m_strFileSavePath;
    string						m_strCoolie;

    //��ǰlist��pos
    INT							m_ListItemPos;

    //�߳��˳�����
    HANDLE						m_Handle_ProgRess;
    HANDLE						m_Handle_Print;

    //�Ƿ�����list
    BOOL						m_bClose;
    //�Ƿ�ֱ�Ӵ��ļ�
    BOOL						m_bOpenFile;

    //��ȡ������ָ��
    BOOL SetCtrlMng(VOID *pdlg)
    {
        if (pdlg != NULL)
        {
            m_pCtrlMng = pdlg;
            return TRUE;
        }
        return FALSE;
    }
};

class DownloadDuiControlMng 
{
public:
    DownloadDuiControlMng(VOID) 
    {
        m_dwLinkCount = m_nTaskCount = 0;
        m_pDsgWnd = NULL;
    }
    ~DownloadDuiControlMng() {}

    //����list_item��DUI item
    BOOL create_ListItem(CHAR *strUrl, CHAR *strFilePath, char *strFileName, BOOL bOpenMode);
    //���һ��list item
    BOOL add_ListItem(CHAR *strUrl, CHAR *strFilePath, BOOL bOpenMode, _Nv_Download_Ex *pdlg);
    //��ȡlist pos
    INT  get_DownloadPtrPos(CControlUI* cContrCmp);
    //��ȡ��ǰӦ�ó���·��
    CHAR *get_ProcessPath(VOID);

    //��Ӽ�¼�ļ�
    BOOL AddDownloadRecord(CHAR *strUrl,
                           CHAR *strSaveFilePath,
                           CHAR *strFileName,
                           __in __int64 n64FileSize,
                           CHAR *strCoolie,
                           __in __int64 n64ProgRessPos,
                           CHAR *strPrint,
                           __in bool bOpenFile);

    //�޸ļ�¼�ļ�
    BOOL ModDownloadRecord(CHAR *strUrl,
                           CHAR *strSaveFilePath,
                           CHAR *strFileName,
                           CHAR *strCoolie,
                           __in __int64 n64FileSize,
                           __in __int64 n64ProgRessPos,
                           CHAR *strPrint,
                           __in bool bOpenFile);

    /* �ϵ������ļ���ʼ��*/
    BOOL ReInitDownloadRecord(VOID);
    /* ˢ�¼�¼�ļ� */
    BOOL FlushDownloadRecord(VOID);


    BOOL ModRecordFile(tag_Donwload_File_Ini_Data *pData);

    VOID set_StrSign(__in CHAR *strData);

public:
    //��������
    //CPaintManagerUI m_pm;
    VOID  *m_pDsgWnd;

public:

    //�������ۼ�
    DWORD			m_dwLinkCount;
    //�������ü���
    INT				m_nTaskCount;
    //��¼�����ļ�����
    vector<tag_Donwload_File_Ini_Data>	m_vtDownLoadFileData;

    //����׷������
    vector<_Nv_Download_Ex*>	        m_vt_Nv_Download;

public:
    _Nv_Download_Ex*  GetCurrentTaskByOptBtn(CControlUI* pBtn);
};