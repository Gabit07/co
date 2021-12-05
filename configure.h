#ifndef configure_H_
#define configure_H_

#define PROGRAM_TITLE       _T("NEXTEYE BCR MARK (ver 1.0.0.3)")

#define DEBUG_CONSOLE   // 콘솔창




//------------------------------------------------------------------------
/**
	@brief 시간 측정 매크로
*///----------------------------------------------------------------------
#define CHECK_TIME_START      __int64 freq, start, end; if (QueryPerformanceFrequency((_LARGE_INTEGER*)&freq))  {QueryPerformanceCounter((_LARGE_INTEGER*)&start);  
#define CHECK_TIME_END(a,b)   QueryPerformanceCounter((_LARGE_INTEGER*)&end);  a=(float)((double)(end - start)/freq*1000); b=true; } else b=false;

/*----------------------------------------------------------------------*/
/*                           db 라이브러리 로딩                           */
/*----------------------------------------------------------------------*/
typedef void (CALLBACK *CALLBACK_FTP_RECV) (bool, unsigned char *, unsigned __int64);

// 프로그램 이력 파일 경로

#define PROGRAM_REPORT_PATH L"C:\\NEXTEYE\\BCR_MARK_PROGRAM\\BCR_MARK_DATA\\REPORT\\ProgramReport.txt"

// 모델 경로
#define LINEFIT_PARAMETER          L"C:\\NEXTEYE\\MyInspect\\linefit.ini"
#define BINARY_PARAMETER           L"C:\\NEXTEYE\\MyInspect\\binary.ini"
#define BLOB_PARAMETER             L"C:\\NEXTEYE\\MyInspect\\blob.ini"
#define ROI_PARAMETER              L"C:\\NEXTEYE\\MyInspect\\roi.ini"

// 로그 파일 이름

#define MARK_IN_LOG L"Mark_In.txt"
#define MARK_OUT_LOG L"Mark_Out.txt"
#define CCLINK_LOG L"CCLink.txt"
#define NETWORK_LOG L"NetWork.txt"
#define SYSTEM_LOG L"System.txt"
#define MOTOR_LOG L"MotorKit.txt"

// Motor Command
enum {
	_COMMAND_MOTOR_ORIGIN = -2,
	_COMMAND_MOTOR_MOVE = -1,
	_COMMAND_MOTOR_READY_POSITION=0,
	_COMMAND_MOTOR_EXCUTE_POSITION,
	_COMMAND_CYLINDER_UP,
	_COMMAND_CYLINDER_DOWN,



	_COMMAND_COUNT
};

//#define MAX_BUFFER          1024 * 1024
#define MAX_PACKET          200 * 1024

#define CRLF                "\r\n"

#define MAX_MENU            6
#define PROGRAM_WIDTH       1920
#define PROGRAM_HEIGHT      1080
#define TITLE_HEIGHT        40
#define LEFT_WIDTH          300
#define BOTTOM_HEIGHT       40
#define MAINVIEWGAP         320

// 리스트 메뉴 색
#define COLOR_LIST_NORMAL   RGB(255, 255, 255)//RGB(79, 79, 79)

// Title 색
#define COLOR_BLACK         RGB(0, 0, 0)
#define COLOR_BLACK_LITTLE  RGB(45,45,45)
#define COLOR_BACKGRND      RGB(35,35,35)
#define COLOR_TITLE         RGB(72,72,72)//RGB(44, 61, 90)
#define COLOR_MOVE          RGB(74, 104, 153)
#define COLOR_GRAY          RGB(229, 231, 232)
#define COLOR_GRAY2         RGB(230, 231, 239)
#define COLOR_WHITE         RGB(255, 255, 255)
#define COLOR_SKY_BLUE		RGB(0, 216, 255)
#define COLOR_ORANGE		RGB(255, 128, 64)
#define COLOR_GREEN			RGB(171, 242, 0)
#define COLOR_RED			RGB(255, 0, 0)
#define COLOR_YELLOW        RGB(255,255,0)
#define COLOR_BLUE          RGB(132, 192, 252)
#define COLOR_BROWN         RGB(163, 21, 21)
#define COLOR_BORA          RGB(93, 107, 153)
#define COLOR_BORA_REV      RGB(187, 198, 241)
#define COLOR_WHITE2        RGB(247,249,254)
#define COLOR_LIGHTYELLOW   RGB(250,250,210)
#define COLOR_PUPLE         RGB(255,51,255)


#define _UPPER_LINE 100
#define _UNDER_LINE 200

enum
{
	eCMD_UPPER_NOZZLE = 0,
	eCMD_LOWER_NOZZLE,
};

// 카메라 사용 비트
#define CAMERA_USE_BIT       20

/*----------------------------------------------------------------------*/
/*                             유저 메세지 정의                           */
/*----------------------------------------------------------------------*/
enum
{
	WM_UMSG_STATUS = WM_USER + 1,
	
	MSG_STATUS_CONNECTION = WM_UMSG_STATUS+1,
	MSG_UPDATEVIEWER_DEFECTDATA = WM_UMSG_STATUS+2,
	MSG_UPDATEDATA = WM_UMSG_STATUS+3,
	MSG_ROLLMAP_DOT_LINE = WM_UMSG_STATUS+400,
	MSG_ROLLMAP_SCALE_X1,
	MSG_ROLLMAP_SCALE_X10,
	MSG_ROLLMAP_TEXT_VIEW_X,
	MSG_ROLLMAP_70MM_VIEW_X,
	MSG_SIMBOL_HEADER_SPLICE,
	MSG_SIMBOL_DOT_CLASH,
	MSG_SIMBOL_70MM_HEADER_CLASH,
	MSG_RANDOM_BOUNDARY_VALUE,
	MSG_BUFFER_CLEAR,
	MSG_JOG_DOWN,
	MSG_JOG_UP,
	MSG_SERVO_ON,
};


/*----------------------------------------------------------------------*/
/*                               폰트 인덱스                             */
/*----------------------------------------------------------------------*/
enum
{
	FONT_9NORMAL = 0,
	FONT_9BOLD,
	FONT_10NORMAL,
	FONT_10BOLD,
	FONT_11NORMAL,
	FONT_11BOLD,
	FONT_12NORMAL,
	FONT_12BOLD,
	FONT_14NORMAL,
	FONT_14BOLD,
	FONT_16NORMAL,
	FONT_16BOLD,
	FONT_18NORMAL,
	FONT_18BOLD,
	FONT_20NORMAL,
	FONT_20BOLD,
	FONT_22NORMAL,
	FONT_22BOLD,
	FONT_COUNT
};

/*----------------------------------------------------------------------*/
/*                               메뉴 아이디                              */
/*----------------------------------------------------------------------*/
enum
{
	MENU_MAIN = 0,
	MENU_SETUP,
	MENU_IO,
	MENU_MAP,
	MENU_NETWORK,
	MENU_MOTOR_SET,
	MENU_LOG,
	MENU_REPORT
};

/************************************************************************/
/* kjw cam id                                                        */
/************************************************************************/
enum {
	NEL4_1 = 0,
	NEL4_2, NEL4_3, NEL4_4, NEL4_5, NEL4_6, NEL4_7, NEL4_8, NEL4_9, NEL4_10, NEL4_11, NEL4_12, NEL4_13, NEL4_14,
	NEL6_1,
	NEL6_2, NEL6_3, NEL6_4, NEL6_5, NEL6_6, NEL6_7, NEL6_8, NEL6_9, NEL6_10, NEL6_11, NEL6_12, NEL6_13, NEL6_14,
	NEL7_1,
	NEL7_2, NEL7_3, NEL7_4, NEL7_5, NEL7_6, NEL7_7, NEL7_8, NEL7_9, NEL7_10, NEL7_11, NEL7_12, NEL7_13, NEL7_14,
};
/************************************************************************/
/* kjw machine id                                                        */
/************************************************************************/
enum
{
	// 카메라 넘버들 담으면 42부터 시작되어야 함
	Dev_Light = 0,
	Dev_MarkController,
	Dev_ContecIo,
	Dev_CClinkIo,
	Dev_CounterBoard,
	Dev_ServoMotor,
	MACHINE_COUNT
};

enum {
	eICON_WARNNING = 0,
	eICON_ERROR,
	eICON_MESSAGE,
};



static unsigned int DEFECT_COLOR[] = 
{
	{ RGB(128, 64, 64) }, { RGB(132, 192, 252) }, { RGB(181, 230, 29) },
	{ RGB(255, 0, 0) }, { RGB(0, 255, 0) }, { RGB(0, 0, 255) },
	{ RGB(255, 242, 0) }, { RGB(0, 255, 255) }, { RGB(255, 0, 255) },
	{ RGB(128, 0, 255) }, { RGB(255, 128, 0) }, { RGB(0, 64, 64) },
	{ RGB(255, 174, 201) }, { RGB(34, 177, 76) }
};

/*광학군 넘버*/
enum
{
	OPTIC_DIRECT=0,
	OPTIC_REFLECT,
	OPTIC_EDGE,
	NEL_OPTICS_ITEM,
};

/* packet 커맨드 넘버*/
enum
{
	udp_CmdInspData = 0,
	udp_CmdNetTest,
	udp_CmdDummy,
};

/* 레포트 칼럼항목 */
enum{
	colDate=0,colLotName,colFrame,colPcNo,colDummy,colindex,
	colClass,colPosX,colPosY,colSizeX,colSizeY,colimgPath,
};

/* contec io bit */
enum
{
	BIT0 = 0,
	BIT1,
	BIT2,
	BIT3,
	BIT4,
	BIT5,
	BIT6,
	BIT7,
};

/* 결점맵 디스플레이*/
enum
{
	MARK_SHOW=0,
	SMARK_SHOW,
	ALL_SHOW,
	
};

enum {
	eKorean = 0,
	eChinese,
};

enum
{
	eDefectParamGrid=0,
	eRollBaseGrid,
	eAllGrid
};

#define MAX_HEADER_COUNT 4
#define MAX_LIGHT_CONNECT 2

/*device list ID*/
enum
{
	eContecIo_Board1 = 0,
	eContecIo_Board2,
	eContecIo_Board3,
	e7396_Card1,
	e7396_Card2,
	eMotion_Board,
	DEVICE_LIST_COUNT
};
/* device data*/

/*BCR Mark Protocol*/
enum {
	_eSTART_PRINT_ = 0,
	_eSTOP_PRINT_,
	_eTEST_TEXT_,
	_eSINGLE_MARK_,
	_eGROUP_MARK_,
};

enum {
	_eDOT_CLASH=1,
	_eHEADER_CLASH,
};

typedef struct __ST_DEVICE
{
	__ST_DEVICE()
	{
		ZeroMemory(this, sizeof(*this));
	}
	int   nDevId;
	int   nIndex;
	bool  bConnect;
	TCHAR czName[128];
	DWORD_PTR pDevHwnd;

}ST_DEVICE, *PST_DEVICE;

/* motion counter define */
#define	AXIS_XX			0
#define	AXIS_ZZ			0
#define	AXIS_RR			0
#define	MAX_AXIS		4

/************************************************************************/
/* 모델관련 경로                                                                     */
/************************************************************************/
#define INSP_PARAM_PATH _T("C:\\NEXTEYE\\CTRL_SERVER\\INS_PARAMETER\\")
#define GRADE_PARAM_PATH _T("C:\\NEXTEYE\\CTRL_SERVER\\GRADE_PARAMETER\\")

#define _MARK_PROTOCOL_BUF_SIZE 4096

enum {
	//vision
	INSP_HOUGH_LINEFIT = 0,
	FILTER_BINARY,
	INSP_BLOB,
	FILTER_SOBEL,
	FILTER_GAUSIAN,
	FILTER_MEDIAN,
	
	INSP_LINEAR_LINEFIT,
	INSP_HOUGH_ELIPSE,
	INSP_ROTATE,
	INSP_FIND_CORNER,
	INSP_HERRISS_CORNER,
	INSP_CURVE_FIT,
	FILTER_LAPLACIAN,
	FILTER_WBFILTER,
	INSP_AFFINE,
	FILTER_GAMMA_CORRECT,
	FILTER_CONTRAST_STRECH,
	INSP_HISTO_GRAPH,
	INSP_HISTO_PROCESS,
	FILTER_UNSHARPNNING,
	FURIE_TRANSFORM,

	//ROI
	POLY_ROI,
	ROUND_RECT_ROI,
	ELIPSE_ROI,

};

// Corner type
enum
{
	eLEFT_TO_RIGHT = 0,
	eRIGHT_TO_LEFT,
	eTOP_TO_BOTTOM,
	eBOTTOM_TO_TOP,
};

enum {
	FIND_LOW = 0,
	FIND_HIGH,

};

enum {
	Zoom1_8 = 0,
	Zoom1_4,
	Zoom1_2,
	Zoom1,
	ZoomFit,
	ZoomX2,
	ZoomX4,
	ZoomX8
};

enum {
	INVERSE = -1,
	NONE = 1,
};

/************************************************************************/
/* 19.12.12 결점 클래스 정리                                            */
/************************************************************************/
#define     AI_CLASS    0x20000
#define     AI_TIMEOUT  0x80000
#define     LOW_DEFECT  0x10000

/* 700번대 엣지투과 */
#define		DCLAS_NEL7A	0x0701	//백점				// 엣지투과 - 명이물
#define		DCLAS_NEL7A_LOW		0x010701			// 엣지투과 - 약 명이물
#define		DCLAS_NEL7B	0x0702	//흑점				// 엣지투과 - 암이물
#define		DCLAS_NEL7E	0x0703	//스킵이물			// 엣지투과 - 명암이물
#define		DCLAS_NEL7C	0x0704						// 엣지투과 - 동일결점
#define		DCLAS_NEL7D	0x0705						// 엣지투과 - 동일결점
#define		DCLAS_NEL7D_LOW		0x010705			// 엣지투과 - 약 동일결점
#define		DCLAS_NEL7F	0x0706	
/* add kjw 18.11.21 700번대 엣지투과 Ai Class define                            */
#define     DCLAS_NEL7A_AI  0x20701 // 명이물ai
#define     DCLAS_NEL7B_AI  0x20702 // 흑점ai
#define		DCLAS_NEL7C_AI	0x20704						
#define		DCLAS_NEL7D_AI	0x20705						
#define     DCLAS_NEL7E_AI  0x20703 // 스킵이물ai
#define		DCLAS_NEL7F_AI	0x20706	

/* 600번대 하반사 */
#define		DCLAS_NEL6A	0x0601	//백점				
#define		DCLAS_NEL6B	0x0602	//흑점				 
#define		DCLAS_NEL6C	0x0605	//주기성불량		
#define		DCLAS_NEL6D	0x0606	//F사마킹
#define		DCLAS_NEL6E	0x0603	//스킵이물
/* 600 번대 AI Class define */
#define		DCLAS_NEL6A_AI	0x20601	//백점				
#define		DCLAS_NEL6B_AI	0x20602	//흑점				
#define		DCLAS_NEL6D_AI	0x20606	//F사마킹
#define		DCLAS_NEL6E_AI	0x20603	//스킵이물
#define     AI_NEL6_TIMEOUT      0x80600
#define     DCLAS_NEL6F_AI_OK 0x20607 // 떨림
#define     DCLAS_NEL6G_AI_OK 0x20608 // 표면

/*400번대 정투과 */
#define		DCLAS_NEL4A	0x0401	//점이물			 
#define		DCLAS_NEL4B	0x0402	//선이물			 
#define		DCLAS_NEL4B_LOW	0x010402				 
#define		DCLAS_NEL4C	0x0405	//주기성불량		 
#define		DCLAS_NEL4C_LOW	0x010405				 
#define		DCLAS_NEL4D	0x0406	// 동일결점			
#define		DCLAS_NEL4E	0x0403	//				 	  
#define		DCLAS_NEL4F	0x0404	//					
/*  add kjw 18.11.21 kjw 400번대 정투과 Ai Class define                        */
#define		DCLAS_NEL4A_AI	0x20401	
#define		DCLAS_NEL4B_AI	0x20402	
#define		DCLAS_NEL4C_AI	0x20405	
#define		DCLAS_NEL4D_AI	0x20406	
#define		DCLAS_NEL4E_AI	0x20403		
#define		DCLAS_NEL4F_AI	0x20404		

#define     AI_NEL4_TIMEOUT      0x80400
#define     DCLAS_NEL4G_AI_OK 0x20407 // 떨림

#endif // configure_H_