#ifndef ROP_UPDATE_H
#define ROP_UPDATE_H
// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� ROPUPDATE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// ROPUPDATE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifndef  ROPUPDATE_EXPORTS
#define ROPUPDATE_EXPORTS
#endif

#ifdef ROPUPDATE_EXPORTS
#define ROPUPDATE_API __declspec(dllexport)
#else
#define ROPUPDATE_API __declspec(dllimport)
#endif


typedef enum {
    PHASE_CONNECT_SERVER = 1,
    PHASE_CHECK_VERSION,
    PHASE_DOWNLOAD_COMPONENT,
    PHASE_UPDATE_COMPONENT,
}UPDATE_PHASE_E;


/* UI phase step call back function while updateing */
typedef void (*PUiPhaseStepCB)(unsigned int iNeedTime,  unsigned int iSubPhaseType, char *sName);    // sub phase steps

typedef BOOL (*PIsServerAvaliable)();
typedef BOOL (*PIsNeedUpdate)();
typedef BOOL (*PUpdate)();
typedef int  (*PInit)(PUiPhaseStepCB pUiStepCB);
typedef void (*PFinl)();


extern "C" {
    ROPUPDATE_API BOOL IsServerAvaliable(void);
    ROPUPDATE_API BOOL IsNeedUpdate(void);
    ROPUPDATE_API BOOL Update(void);
    ROPUPDATE_API INT  UpdateNotice(TCHAR *pMsg, INT row, INT col_size);
    ROPUPDATE_API int  Init(PUiPhaseStepCB pUiStepCB, PVOID pOnProgressCtx);
    ROPUPDATE_API void Finl(void);
};



#include "RopUtil.h"
#define UpDbg(...) ModDbg(DEBUG_L_DEBUG, CTRL_UPDATE_MODULE, ##__VA_ARGS__)
#define UpErr(...) ModDbg(DEBUG_L_CRITICAL, CTRL_UPDATE_MODULE, ##__VA_ARGS__)

#endif