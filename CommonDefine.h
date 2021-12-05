//-------------------------------------------------------------------------------------------------
/**     
    @file   CommonDefine.h 
    @date   
*///----------------------------------------------------------------------------------------------- 
#ifndef CommonDefine_H_
#define CommonDefine_H_

#include <afxwin.h>


#define round(x)               (x < 0 ? int(x - 0.5) : int(x + 0.5))
/*----------------------------------------------------------------------*/
/*                           공통 사용 매크로                           */
/*----------------------------------------------------------------------*/

#ifndef SAFE_MEM_NEW
#define	SAFE_MEM_NEW(Type, szMem)			(Type *)Allocate(szMem * sizeof(Type))
#endif

#ifndef SAFE_MEM_DELETE
#define	SAFE_MEM_DELETE(pMem)				if(pMem) { free(pMem); pMem = NULL; }
#endif

#ifndef SAFE_RELEASE
#define	SAFE_RELEASE(pObj)					if(pObj) { pObj->Release(); pObj = NULL; }
#endif

#ifndef SAFE_DELETE
#define	SAFE_DELETE(pMem)					if(pMem) { delete pMem; pMem = NULL; }
#endif

#ifndef SAFE_DELETE_ARRAY
#define	SAFE_DELETE_ARRAY(pMem)			    if(pMem) { delete[] pMem; pMem = NULL; }
#endif

#ifndef SAFE_CLOSE_HANDLE
#define	SAFE_CLOSE_HANDLE(hHandle)		    if ( hHandle != NULL && hHandle != INVALID_HANDLE_VALUE ) { CloseHandle(hHandle); hHandle = NULL; }
#endif

#ifndef INVALID_VALUE
#define	INVALID_VALUE						(-1)
#endif

#ifndef IS_VALID_VALUE
#define	IS_VALID_VALUE(x)					((bool)(x != INVALID_VALUE))
#endif

#ifndef IS_INVALID_VALUE
#define	IS_INVALID_VALUE(x)					((bool)(x == INVALID_VALUE))
#endif

#ifndef IS_INVALID_POINT
#define	IS_INVALID_POINT(pMem)				((bool)(pMem == NULL || pMem == 0xfeeefeee))
#endif

/*----------------------------------------------------------------------*/
/*                         비트 플래그 매크로                           */
/*----------------------------------------------------------------------*/
#ifndef MAKE_BIT
#define	MAKE_BIT(x)							(0x01 << (x))
#endif

#ifndef EXTRACT_BIT
#define	EXTRACT_BIT(nValue, nBitValue)		((nValue) & (nBitValue))
#endif

#ifndef IS_BIT_SET
#define	IS_BIT_SET(nValue, nBitValue)		((bool)(EXTRACT_BIT(nValue, nBitValue) == (nBitValue)))
#endif

#ifndef BIT_SET
#define	BIT_SET(nValue, nBitValue)			((nValue) |= nBitValue)
#endif

#ifndef BIT_RESET
#define	BIT_RESET(nValue, nBitValue)		((nValue) &= ~(nBitValue))
#endif

#ifndef MAKE_MASK
#define	MAKE_MASK(nBit)						(nBit ? 0xFFFFFFFF >> (32 - nBit) : NULL)
#endif

#ifndef MAKE_MASK64
#define	MAKE_MASK64(nBit)					(nBit ? 0xFFFFFFFFFFFFFFFF >> (64 - nBit) : NULL)
#endif

#ifndef RECT_WIDTH
#define RECT_WIDTH(rect)   (rect.right - rect.left)
#endif

#ifndef RECT_HEIGHT
#define RECT_HEIGHT(rect)  (rect.bottom - rect.top)
#endif

#ifndef PRECT_WIDTH
#define PRECT_WIDTH(rect)   (rect->right - rect->left)
#endif

#ifndef PRECT_HEIGHT
#define PRECT_HEIGHT(rect)  (rect->bottom - rect->top)
#endif

#ifndef RECT_RIGHT
#define RECT_RIGHT(rect)   (rect->left + rect->right)
#endif

#ifndef RECT_BOTTOM
#define RECT_BOTTOM(rect)  (rect->top + rect->bottom)
#endif

#define LogB(x, base) logf(x)/logf(base)

#define TEST_SIMULATION_MODE

// 광학계 PC 연결개수
#define MAX_CONNECTION 90


// 클라이언트 뷰 사이즈
#define ClientViewWidth 1550
#define ClientViewHeight 950


// 경로
#define DEFAULT_NEXTEYE						"c:\\nexteye\\"
#define	CONNECT_PATH	DEFAULT_NEXTEYE "Connect_List.txt"
#define CONTECIOPATH    "C:\\NEXTEYE\\ContecIo.ini"
#define INSP_LOW        "D:\\INSP_LOW\\"
#define LOT_DATA_PATH  L"C:\\NEXTEYE\\BCR_MARK_PROGRAM\\BCR_MARK_LOG\\LOT\\"

// batch file or Lot Proc path
//#define	DEFAULT_DIRECTORY_NAME				L"CTRL_SERVER"
//#define D_DRIVE                             L"D:\\"
//#define	INSP_DATA_LOW_PATH					L"INSP_LOW\\"
//#define	INSIDE_FILE_PATH					L"C:\\NEXTEYE\\INSIDE_FILE"
//#define	CSV_SIMUL_FILE_PATH					L"INSP_LOW\\INSP_SIMUL_COTING\\"
//#define	DATA_BACKUP							L"E:\\" // 컨트롤서버에서 네트워크 드라이브 E:를 파일서버 주소에 맞추어 사용 [2/18/2020 Kimjinwoo]
//#define	CLIENT_TEXT_COPY_END_INSIDE_FILE	INSIDE_FILE_PATH L"\\client_text_copy_end.txt"
//#define	CLIENT_IMG_COPY_END_INSIDE_FILE		INSIDE_FILE_PATH L"\\client_img_copy_end.txt"
//#define	CLIENT_IMG_COPY_BATCH_FILE			INSIDE_FILE_PATH L"\\client_img_copy.bat"
//#define CLIENT_IMG_COPY_BATCH_FILE_F		INSIDE_FILE_PATH L"\\client_img_copy_f.bat"
#define SEPARATOR L"-----------------------------------------------"

// udp 관련 정의
#define		WSA_ASYNC			(WM_USER+1)
#define     WM_INVALIDATE       (WM_USER+5)
#define		WM_XDATARRECIEVED	(WM_USER+100+2)
#define	    BUFFER_SIZE			20480		//128*128+1000
#define	    DEFAULT_TIMEOUT		100L
#define     PARAM_DUMMY			"NULL"
#define		DEFAULT_PORT			6000
#define     MAX_BADIMAGE_FILENAME 100

/* 결점 이미지 디스플레이 사이즈*/
#define NG_IMAGE_X 128
#define NG_IMAGE_Y 128

#define NG_IMAGE_X180 180
#define NG_IMAGE_Y180 180

/* 롤맵 그리기 모드 */
#define REALTIMEDRAW  0
#define REPORTDRAW    1
// rollmap timer
#define WM_TIMER_INVALIDATE 0
#define WM_TIMER_SIMUL      1
#define WM_TIMER_DEFECT_VIEW 2
#define WM_TIMER_MARK_RESET_MAP 3
#define WM_TIMER_TITLE_VIEW     4

//mark buffer
#define MAX_BUFFER          3

//프로그램 모드
#define CONTROLSERVER  0
#define FILESERVER 1
#define MARKINGSERVER 2

#define DISTANCE(x1,y1,x2,y2) sqrt((double)((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)))

#define MAX_LEN 7000


//MARKING
#define	MAX_FORCE_MARK				2
#define MK_ALL_OUTPUT				200
#define MK_TAPE2_MANUAL_OUTPUT		201
#define MK_TAPE_AUTO_OUTPUT			202
#define MK_TAPE2_AUTO_OUTPUT		203
#define MK_TAPE3_AUTO_OUTPUT		204
#define MK_NOZZLE_TEST_OUTPUT		999
#define MARK1UNITCOUNT              20

#define MAX_IO_COUNT 12


/***************************************/
/* 시뮬레이션 타입 정의(타이머)        */
/***************************************/
#define _TIMER_SIMUL_STAIR_TYPE      2828
#define _TIMER_SIMUL_SIDEOFFSET_TYPE 2929
#define _TIMER_SIMUL_RANDOM_TYPE     3030
/* 타이머 정의 */
#define _TIMER_SERVO_CHECK           3131
#define _TIMER_ALARM                 3232
#define _TIMER_MARKMAP_REDRAW        3333
#define _TIMER_GIF                   3434
#define _TIMER_MOTOR_POS             3535
#define _TIMER_HOMEUI_UPDATE         3636
#define _TIMER_DIO_CHECK             3737


typedef struct tagPARAMETER
{
	int   nTotalPort;
	char  ComName[MAX_CONNECTION][10];//컴퓨터이름 
	float param[MAX_CONNECTION][40];  //Param데이타
	float system[MAX_CONNECTION][10];  //Calib데이타 

	char  MachineName[100];			//시스템 이름 "CC01", "CC02" ...
	char  ModelName[100];			//검사모델이름 (VW, W3, W1, ....)
}PARAMETER;

extern PARAMETER g_Param;

typedef struct __ST_CONNECTLIST
{
	__ST_CONNECTLIST()
	{
		ZeroMemory(this, sizeof(*this));
	}
	char pc_name[128];
	char ip_addr[128];
	int	port;
	int	connection;
	int status;		//only for BCR
	int clientUdp_port;
}ST_CONNECTLIST, *PST_CONNECTLIST;



/* 패킷 데이터 구조체 정의 */

#define NET_CMD_ACCEPT_DEFECTDATA 10000 // 기존 롤 장비의 서버나, 비전의 명령과 같도록 한다 
#define NET_CMD_ACCEPT_VIRTUALDATA 10001

typedef struct __ST_PACKET_MESSAGE
{
	__ST_PACKET_MESSAGE()
	{
		ZeroMemory(this, sizeof(*this));
	}
	WPARAM wparam;
	LPARAM lparam;
}ST_PACKET_MESSAGE, *PST_PACKET_MESSAGE;



typedef struct __ST_DEFECTDATA
{
	__ST_DEFECTDATA()
	{
		ZeroMemory(this, sizeof(*this));
	}
	
	int frame;
	int pcnumber;
	int defect_class;

	float defect_posx;
	float defect_posy;
	//float abs_posy;
	float defect_size;

	int bcrindex;
	double      encoder_pos; // BCR 마킹기만 사용
	bool		bMark;       // BCR 마킹기만 사용
	BOOL        bColor; // 1:증가 2: 감소

	int cmdUpDown;
	int headerline; // test 검증용
	int group_id;
	
	//char filename[MAX_BADIMAGE_FILENAME];

}ST_DEFECTDATA, *PST_DEFECTDATA;

typedef struct __ST_DEFECTPACKET
{
	__ST_DEFECTPACKET() {
		ZeroMemory(this, sizeof(*this));
	}
	int frame;
	int pcnumber;
	int defect_class;

	float defect_posx;
	float defect_posy;
	float defect_size;

}ST_DEFECTPACKET, *PST_DEFECTPACKET;


// 연결 테스트 패킷
typedef struct __ST_PACKET_NETTEST
{
	__ST_PACKET_NETTEST()
	{
		ZeroMemory(this, sizeof(*this));
	}

}ST_PACKET_NETTEST;


typedef struct __POINT
{
	double x;
	double y;
}TPOINT;

typedef struct __ST_ROI
{
	__ST_ROI()
	{
		ZeroMemory(this, sizeof(*this));
	}
	CRect rect;
	TPOINT pt[4];
	float fSeta;

}ST_RECT, * PST_RECT;

enum class CEdgeDirection {
	toRight = 0,
	toLeft,
	toBottom,
	toTop,
	horizontal,
	vertical,
};

/************************************************************************/
/* 퓨리에 트랜스폼 위한 구조체                                          */
/************************************************************************/
typedef struct __ST_FURIE_IMG_VAR
{
	__ST_FURIE_IMG_VAR()
	{
		ZeroMemory(this, sizeof(*this));
	}
	double dRes;
	double dRes_Re;
	double dRes_Im;
}ST_FURIE_VAL, * PST_FURIE_VAL, ** PPST_FURIE_VAL;

typedef struct __ST_FURIE_DATA
{
	__ST_FURIE_DATA()
	{
		ZeroMemory(this, sizeof(*this));
	}
	double d_Re;
	double d_Im;
}ST_FURIEDATA, * PST_FURIEDATA;

// 디스플레이 화면 크기
#define DISP_FOV_X 800
#define DISP_FOV_Y 800

// 실제 이미지 버퍼 크기
#define IMAGE_BUFFER_SIZE_X 8192//4096
#define IMAGE_BUFFER_SIZE_Y 10000//4096

#define TRACKER_COUNT 4

#define LINE_4K 4096
#define LINE_8K 8192
#define LINE_16K 16384

#endif // CommonDefine_H_