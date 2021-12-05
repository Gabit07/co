


#include "../pch.h"
#include <math.h>
#include <Winsock2.h>
#include <wchar.h>
#include "CommonUtil.h"
#include "assert.h"
#include "configure.h"
#include <locale>



unsigned int _fastcall CommonUtil::CharLen(char *szSrc)
{
	unsigned int unLen = 0;
	while(szSrc[unLen] != '\0') unLen++;
	return unLen;
}

int _fastcall CommonUtil::Find(LPVOID pBuf1, unsigned int unszBuf1, LPVOID pBuf2, unsigned int unszBuf2, unsigned int unIncrementBytes /* = 1 */, int nOffset /* = NULL */)
{
	if ( !pBuf1 || !pBuf2 || !unszBuf1 || !unszBuf2 )
		return -1;

	unsigned int nRemain = unszBuf2 / sizeof(unsigned int);
	unsigned int nByte   = unszBuf2 % sizeof(unsigned int);

	if(nOffset < 0)
		nOffset = 0;

	if(unszBuf1 < (unsigned int)(nOffset + unszBuf2))
		return -1;

	for(unsigned int nIdx=nOffset; nIdx<=(unszBuf1 - unszBuf2); nIdx += unIncrementBytes)
	{
		bool bCompareMemory = true;
		PINT pRef1 = (PINT)((LPBYTE)pBuf1 + nIdx);
		PINT pRef2 = (PINT)pBuf2;
		
		for(unsigned int nIdxMem=0; nIdxMem<nRemain; ++nIdxMem)
		{
			if(*pRef1 != *pRef2)
			{
				bCompareMemory = false;
				break;
			}

			pRef1++;
			pRef2++;
		}

		if(bCompareMemory && nByte)
		{
			if((LPBYTE)pRef1 + sizeof(int) > (LPBYTE)pBuf1 + unszBuf1)
			{
				for(unsigned int nIdxRest=0; nIdxRest<nByte; nIdxRest++)
				{
					if(((LPBYTE)pRef1)[nIdxRest] != ((LPBYTE)pRef2)[nIdxRest]) 
					{
						bCompareMemory = false;
						break;
					}
				}
			}
			else
			{
				int nShift = (sizeof(int) - nByte) * 8;
				if(*pRef1 << nShift != *pRef2 << nShift) 
					bCompareMemory = false;
			}
		}

		if(bCompareMemory) 
			return nIdx;
	}
	return -1;
}

//------------------------------------------------------------------------
/**
	@brief 문자열 파싱
*///----------------------------------------------------------------------
unsigned int _fastcall CommonUtil::StrToken(char *szSource, char *szDelimit, char *szResult[])
{
	unsigned int i;
	char *tok;
	char *type; 
	i = 0;
	tok = strtok_s(szSource, szDelimit, &type);

	if(tok == NULL)
	{
		return 0;
	}

	szResult[i] = tok;

	while((tok = strtok_s(NULL, szDelimit, &type)) != NULL) 
	{
		if(tok) szResult[++i]=tok;
	}
	return (i+1);
}

//------------------------------------------------------------------------
/**
	@brief 숫자 검사
*///----------------------------------------------------------------------
bool _fastcall CommonUtil::IsNumber(const char *szText)
{
	for(size_t i=0; i<strlen(szText); ++i)
	{
		if(!_istdigit(szText[i]))
			return false;
	}
	return true;
}

//------------------------------------------------------------------------
/**
	@brief  UTF8 -> ANSI
*///----------------------------------------------------------------------
void _fastcall CommonUtil::UTF8toANSI(char *szUTF8, char *szANSI)   
{   
	if(szUTF8 == NULL)
		return;

	wchar_t wszUnicode[1024] = {0,};
	UTF8toUNICODE(szUTF8, wszUnicode); // UTF-8 -> UNICODE
	UNICODEtoANSI(wszUnicode, szANSI); // UNICODE -> ANSI
}  

//------------------------------------------------------------------------
/**
	@brief  ANSI -> UTF8
*///----------------------------------------------------------------------
void _fastcall CommonUtil::ANSItoUTF8(char *szANSI, char *szUTF8)
{
	if(szANSI == NULL)
		return;
	
	wchar_t wszUnicode[1024] = {0,};
	ANSItoUNICODE(szANSI, wszUnicode);  // ANSI -> UNICODE
	UNICODEtoUTF8(wszUnicode, szUTF8);  // UNICODE -> UTF8
}

//------------------------------------------------------------------------
/**
	@brief  UTF8 -> UNICODE
*///----------------------------------------------------------------------
void _fastcall CommonUtil::UTF8toUNICODE(char *szUTF8, wchar_t *szUNICODE)
{
	if(szUTF8 == NULL)
		return;

	int nLen = MultiByteToWideChar(CP_UTF8, 0, szUTF8, (int)strlen(szUTF8), NULL, NULL); 
	MultiByteToWideChar(CP_UTF8, 0, szUTF8, (int)strlen(szUTF8), szUNICODE, nLen); 
}

//------------------------------------------------------------------------
/**
	@brief  UNICODE -> UTF8
*///----------------------------------------------------------------------
void _fastcall CommonUtil::UNICODEtoUTF8(wchar_t *wszUNICODE, char *szUTF8)
{
	if(wszUNICODE == NULL)
		return;

	int nLen = WideCharToMultiByte(CP_UTF8, 0, wszUNICODE, (int)wcslen(wszUNICODE), NULL, 0, NULL, NULL); 
	WideCharToMultiByte(CP_UTF8, 0, wszUNICODE, (int)wcslen(wszUNICODE), szUTF8, nLen, NULL, NULL); 
}

//------------------------------------------------------------------------
/**
	@brief  UNICODE -> ANSI
*///----------------------------------------------------------------------
void _fastcall CommonUtil::UNICODEtoANSI(wchar_t *wszUNICODE, char *szANSI)
{
	if(wszUNICODE == NULL)
		return;

	int nLen = WideCharToMultiByte(CP_ACP, 0, wszUNICODE, -1, NULL, 0, NULL, NULL);
	WideCharToMultiByte(CP_ACP, 0, wszUNICODE, -1, szANSI, nLen, NULL, NULL ); 
}

char* _fastcall CommonUtil::UNICODEtoANSI(wchar_t *wszUNICODE)
{
	if(wszUNICODE == NULL)
		return NULL;

	char szBuffer[1024] = {0,};
	int nLen = WideCharToMultiByte(CP_ACP, 0, wszUNICODE, -1, NULL, 0, NULL, NULL);
	WideCharToMultiByte(CP_ACP, 0, wszUNICODE, -1, szBuffer, nLen, NULL, NULL ); 

	return _strdup(szBuffer);
}

//------------------------------------------------------------------------
/**
	@brief  ANSI -> UNICODE
*///----------------------------------------------------------------------
void _fastcall CommonUtil::ANSItoUNICODE(char *szANSI, wchar_t *wszUNICODE)
{
	if(szANSI == NULL)
		return;
	int nLen = MultiByteToWideChar(CP_ACP, 0, szANSI, (int)strlen(szANSI), NULL, NULL); 
	MultiByteToWideChar(CP_ACP, 0, szANSI, (int)strlen(szANSI), wszUNICODE, nLen); 
}

wchar_t* _fastcall CommonUtil::ANSItoUNICODE(char *szANSI)
{
	if(szANSI == NULL)
		return NULL;

	wchar_t wszBuffer[1024] = {0,};
	int nLen = MultiByteToWideChar(CP_ACP, 0, szANSI, (int)strlen(szANSI), NULL, NULL); 
	MultiByteToWideChar(CP_ACP, 0, szANSI, (int)strlen(szANSI), wszBuffer, nLen); 

	return _wcsdup(wszBuffer);
}

//------------------------------------------------------------------------
/**
	@brief  jpg->HBITMAP (전체경로)
*///----------------------------------------------------------------------
HBITMAP _fastcall CommonUtil::JpgtoHbitamp(char *szFilePath)
{

	// Use IPicture stuff to use JPG / GIF files
	IPicture* p;
	LPSTREAM s = NULL;
	//IPersistStream* ps;
	HGLOBAL hG;
	LPVOID pp;
	
	FILE* fp;
	errno_t FPchk;

	// Read file in memory
	FPchk = fopen_s(&fp, szFilePath, "rb");
	if(FPchk != 0)
		return NULL;

	fseek(fp, 0, SEEK_END);
	int fs = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	hG = GlobalAlloc(GMEM_MOVEABLE, fs);
	if(!hG)
	{
		fclose(fp);
		return NULL;
	}
	pp = GlobalLock(hG); 
	fread(pp, 1, fs, fp);
	fclose(fp);
	GlobalUnlock(hG); 
	
	CreateStreamOnHGlobal(hG, TRUE, &s); 
	OleLoadPicture(s, fs, false, IID_IPicture, (void**)&p);
	if(!p)
	{
		s->Release();
		GlobalFree(hG);
		return NULL;
	}
	s->Release();
	GlobalFree(hG);

	HBITMAP hB = 0;
	p->get_Handle((OLE_HANDLE*)&hB);

	// Copy the image. Necessary, because upon p's release,
	// the handle is destroyed.
	HBITMAP hBB = (HBITMAP)CopyImage(hB, IMAGE_BITMAP, 0, 0, LR_COPYRETURNORG);
	p->Release();
	return hBB;   
}

//------------------------------------------------------------------------
/**
	@brief  jpg->HBITMAP (전체경로)
*///----------------------------------------------------------------------
void _fastcall CommonUtil::JpgtoHbitamp(char *szFilePath, HBITMAP &hBitmap)
{

	// Use IPicture stuff to use JPG / GIF files
	IPicture* p;
	LPSTREAM s = NULL;
	//IPersistStream* ps;
	HGLOBAL hG;
	LPVOID pp;
	
	FILE* fp;
	errno_t FPchk;

	// Read file in memory
	FPchk = fopen_s(&fp, szFilePath, "rb");
	if(FPchk != 0)
		return;

	fseek(fp, 0, SEEK_END);
	int fs = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	hG = GlobalAlloc(GMEM_MOVEABLE, fs);
	if(!hG)
	{
		fclose(fp);
		return;
	}
	pp = GlobalLock(hG); 
	fread(pp, 1, fs, fp);
	fclose(fp);
	GlobalUnlock(hG); 
	
	CreateStreamOnHGlobal(hG, TRUE, &s); 
	OleLoadPicture(s, fs, false, IID_IPicture, (void**)&p);
	if(!p)
	{
		s->Release();
		GlobalFree(hG);
		return;
	}
	s->Release();
	GlobalFree(hG);

	HBITMAP hB = 0;
	p->get_Handle((OLE_HANDLE*)&hB);

	// Copy the image. Necessary, because upon p's release,
	// the handle is destroyed.
	hBitmap = (HBITMAP)CopyImage(hB, IMAGE_BITMAP, 0, 0, LR_COPYRETURNORG);
	p->Release();
}

//------------------------------------------------------------------------
/**
	@brief 유니코드 Replace
*///----------------------------------------------------------------------
int _fastcall CommonUtil::wcsReplace(wchar_t* dest, size_t numberOfElements, const wchar_t* comp, const wchar_t* replace) 
{
	assert(dest);
	assert(comp);
	assert(replace);

	size_t destLen = wcslen(dest);
	size_t compLen = wcslen(comp);
	size_t replaceLen = wcslen(replace);

	wchar_t* findStr = NULL;
	int replaceCount = 0, find=0;
	while((findStr = wcsstr(dest, comp)) != NULL) {
		if (numberOfElements <= size_t(destLen + (replaceLen - compLen))) {
			assert(0);
			return -1;
		}

		find = static_cast<int>(findStr-dest);
		wmemmove(&dest[find + replaceLen], &dest[find + compLen], destLen - (find + compLen));
		destLen = destLen + (replaceLen - compLen);
		dest[destLen] = L'\0';
		wmemcpy(&dest[find], replace, replaceLen);
		replaceCount++;
	}

	return replaceCount;
}

//------------------------------------------------------------------------
/**
	@brief 공백제거
*///----------------------------------------------------------------------
char* _fastcall CommonUtil::ltrim(char *string)
{
	while( *string )
	{
		if( isspace( *string ) )
		{
			++string;
		}
		else
			break;
	}

	return string;
}

char*_fastcall CommonUtil::rtrim(char *string)
{
	size_t len = strlen( string ) - 1;

	while( len >= 0 )
	{
		if( isspace( *( string + len ) ) )
		{
			len--;
		}
		else
			break;
	}

	*( string + ++len ) = 0; 

	return string;
}

char* _fastcall CommonUtil::trim(char *string)
{
	return (ltrim(rtrim( string)));
}

//------------------------------------------------------------------------
/**
	@brief dns -> ip
*///----------------------------------------------------------------------
char* _fastcall CommonUtil::GetDNStoIPAddress(char *szDns)
{
	WSADATA wsaData;   
	
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) 
		return NULL;
	
	LPHOSTENT lpHost = gethostbyname(szDns);
	if(!lpHost)
		return NULL;
	
	char *szIpAddr = inet_ntoa(*(in_addr *)*lpHost->h_addr_list);
	WSACleanup();

	if(!szIpAddr)
		return NULL;

	return _strdup(szIpAddr);
}

void _fastcall CommonUtil::GetLocalIPAddress(char *szDest, int nDestLength)
{
	WORD wVersionRequested;
	WSADATA wsaData;
	char szName[128] = {0,};
		 
	PHOSTENT hostinfo;
	wVersionRequested = MAKEWORD(2, 0);
	if(WSAStartup(wVersionRequested, &wsaData ) == 0)
	{
		if(gethostname(szName, sizeof(szName)) == 0)
		{
			if((hostinfo = gethostbyname(szName)) != NULL)
				strcat_s(szDest, nDestLength, inet_ntoa (*(struct in_addr *)*hostinfo->h_addr_list));
		}     
		WSACleanup();
	}
}

void _fastcall CommonUtil::GetLocalIPAddress(wchar_t *wszDest, int nDestLength)
{
	WORD wVersionRequested;
	WSADATA wsaData;
	char szName[128] = {0,};
	char szIpAddress[64] = {0,};
	long int *pAddress;

	PHOSTENT hostinfo;
	SOCKADDR_IN Addr;

	wVersionRequested = MAKEWORD(2, 0);
	if(WSAStartup(wVersionRequested, &wsaData ) == 0)
	{
		if(gethostname(szName, sizeof(szName)) == 0)
		{
			hostinfo = gethostbyname(szName);

			while(*hostinfo->h_addr_list != NULL)
			{
				pAddress = (long int *)*hostinfo->h_addr_list;
				Addr.sin_addr.s_addr = *pAddress;
				
#if 1
				CommonUtil::ANSItoUNICODE(inet_ntoa(Addr.sin_addr), wszDest);
				break;
#endif
				
				hostinfo->h_addr_list++;
			}
		}     
		WSACleanup();
	}
}

const int C1  = 18361;
const int C2  = 47124;
const int KEY = 29452;
//------------------------------------------------------------------------
/**
	@brief 암호화
*///----------------------------------------------------------------------
void _fastcall CommonUtil::Encrypt(char *source, char *destination, unsigned int length)
{
	unsigned int i;
	int Key = KEY;

	if (!source || !destination || length <= 0)
		return;

	for(i=0; i<length; ++i)
	{
		destination[i] = source[i]^Key >> 8;
		Key = (destination[i] + Key) * C1 + C2;
	}
}

void _fastcall CommonUtil::Decrypt(char *source, char *destination, unsigned int length)
{
	unsigned int i;
	char PreviousBlock;
	int	 Key = KEY;

	if(!source || !destination || length <= 0)
		return;

	for(i=0; i<length; ++i)
	{
		PreviousBlock = source[i];
		destination[i] = source[i]^Key >> 8;
		Key = (PreviousBlock + Key) * C1 + C2;
	}
}

BOOL _fastcall CommonUtil::ExistFile(CString strPath)
{
	CFileFind finder;
	BOOL bWorking = finder.FindFile(strPath);
	int nCount = 0;
	BOOL	bRet = FALSE;
	CString strOut;
	int nMinusIndex = 2;
	while (bWorking)
	{
		bWorking = finder.FindNextFile();
		if ( finder.IsDirectory() || finder.IsDots() )
			continue;
		else
		{
			CString strPath2;
			strPath2 = finder.GetFileName();
			bRet = TRUE;
		}
		CommonUtil::Wait(1);
	}
	return bRet;
}

BOOL _fastcall CommonUtil::ExistDirectory(CString strDirectory)
{
	WIN32_FIND_DATA sData;
	HANDLE sHandle;
	sHandle = FindFirstFile(strDirectory, &sData);
	if(sHandle != INVALID_HANDLE_VALUE)
	{
		FindClose(sHandle);
		return TRUE;
	}
	else
	{
		FindClose(sHandle);
		return FALSE;
	}
}

void _fastcall CommonUtil::Wait(DWORD dwT)
{
	DWORD dwST = GetTickCount();
	DWORD val = GetTickCount() - dwST;

	while (val < dwT)
	{
		val = GetTickCount() - dwST;
		if (val >= dwT) break;
		HandleAllMessage();
		Sleep(1);
	}
}

int _fastcall CommonUtil::HandleAllMessage()
{
	int returnValue;
	MSG Mess;
	do
	{
		returnValue = ::PeekMessage(&Mess, NULL, 0, 0, PM_REMOVE);
		if (returnValue)
		{
			::TranslateMessage(&Mess);
			::DispatchMessage(&Mess);
		}
		Sleep(0);
	} while (returnValue);

	return returnValue;
}

LARGE_INTEGER counter_start;

double _fastcall CommonUtil::Clock_set()
{
	double duration_milisec;
	LARGE_INTEGER freq, set;
	if (!QueryPerformanceFrequency(&freq))
		return -1000.;

	QueryPerformanceCounter(&set);

	LARGE_INTEGER duration;
	duration.QuadPart = (set.QuadPart - counter_start.QuadPart);
	duration_milisec = (double)duration.QuadPart / (freq.QuadPart / 1000.0);

	return duration_milisec;
}

//int _fastcall CommonUtil::DefectClassToIndex(int nOpticNo, int nDefectClass)
//{
//	int nidx = -1;
//	switch(nOpticNo)
//	{
//	case OPTIC_EDGE:
//		{
//			if(nDefectClass == DCLAS_NEL7A)
//			{
//				nidx = 0;
//			}
//			else if(nDefectClass == DCLAS_NEL7B)
//			{
//				nidx = 1;
//			}
//			else if(nDefectClass == DCLAS_NEL7C || nDefectClass == DCLAS_NEL7D)
//			{
//				nidx = 2;
//			}
//			else if(nDefectClass == DCLAS_NEL7E)
//			{
//				nidx = 3;
//			}
//			break;
//		}
//	case OPTIC_REFLECT:// 하반사
//		{
//			if(nDefectClass == DCLAS_NEL6A)
//			{
//				nidx = 0;
//			}
//			else if(nDefectClass == DCLAS_NEL6B)
//			{
//				nidx = 1;
//			}
//			else if(nDefectClass == DCLAS_NEL6C)
//			{
//				nidx = 2;
//			}
//			break;
//		}
//	case OPTIC_DIRECT:
//		{
//			if(nDefectClass == DCLAS_NEL4A)
//			{
//				nidx = 0;
//			}
//			else if(nDefectClass == DCLAS_NEL4B)
//			{
//				nidx = 1;
//			}
//			else if(nDefectClass == DCLAS_NEL4D)
//			{
//				nidx = 2;
//			}
//			else
//			{
//				nidx = 2;
//			}
//			break;
//		}
//
//	}
//
//	return nidx;
//}
/************************************************************************/
/* 검사모델 Grid section                                                                   */
/************************************************************************/
wchar_t* _fastcall CommonUtil::GetColumName(int nCol)
{
	static wchar_t *wszColName[] = {L"백점", L"흑점", L"검출크기(mm)", L"미검영역", L"쿠닉판단", L"X-Skip",
	 L"UseBlob", L"미사용", L"Tape거리", L"Skip거리", L"최대밝기", L"최소밝기", L"SizeUp", L"SizeDn",
	L"C-Flip", L"(15)미사용", L"(16)미사용", L"수직Skip", L"미사용", L"강Size", L"약백점", L"약흑점"};
	
		
	return wszColName[nCol];
}

/************************************************************************/
/* 원단모델 Grid  section                                                                   */
/************************************************************************/
wchar_t* _fastcall CommonUtil::GetRollBaseColumName(int nCol)
{
	static wchar_t *wszColName[] = {L"알람최대밝기", L"알람최소밝기", L"Shutter", L"Cal X", L"Cal Y",
	L"Frame len", L"SFX", L"SFY", L"Tape거리"};


	return wszColName[nCol];
}

wchar_t* _fastcall CommonUtil::GetRollBaseParamName(int nCol)
{
	static wchar_t *wszParamName[] = {L"alram_maxgray", L"alram_mingray", L"shutter", L"cal_x", L"cal_y",
		L"frame_len", L"scale_x", L"scale_y", L"cal_frame"};


	return wszParamName[nCol];
}

bool _fastcall CommonUtil::WriteToFile(const char* filename, const char* buffer, int len)
{
	FILE* fp = nullptr;

	//_wfopen_s(&fp, filename, L"wb, ccs=UTF-16)
	fopen_s(&fp, filename, "wb"); 

	if (fp == nullptr)
	{
		return false;
	}

	size_t fileSize = fwrite(buffer, 1, len, fp);

	fclose(fp);

	return true;
}

// read
bool _fastcall CommonUtil::ReadFromFile(const char* filename, char* buffer, int len)
{
	FILE* fp = nullptr;
	fopen_s(&fp, filename, "rb");

	if (fp == nullptr)
	{
		return false;
	}

	size_t fileSize = fread(buffer, 1, len, fp);

	fclose(fp);

	return true;
}

void _fastcall CommonUtil::MakeDirectory(CString strPath)
{
	CString strTemp1, strTemp2;
	int nStart = 0, nEnd = 0;

	while ((nEnd = strPath.Find('\\', nStart)) >= 0)
	{
		strTemp2 = strPath.Mid(nStart, nEnd - nStart);
		CreateDirectory(strTemp1 + strTemp2, NULL);

		strTemp1 += strTemp2;
		strTemp1 += L"\\";
		nStart = nEnd + 1;
	}

}

BOOL _fastcall CommonUtil::AutoCreateDirectoryAndFile(CString strPath)
{
	CString strTmp;
	BOOL bRet = TRUE;
	int nStt = 0, nlen = strPath.GetLength();

	if (strPath.Find(L"\\", 0) < 0)
		bRet = FALSE;

	while (nlen >= nStt && bRet)
	{
		nStt = strPath.Find(L"\\", nStt);
		if (nStt < 0)
			break;
		nStt++;
		strTmp = strPath.Left(nStt);
		CreateDirectory(strTmp, NULL);
		if (::GetFileAttributes(strTmp) == -1)
			bRet = FALSE;
	}

	return bRet;
}

bool _fastcall CommonUtil::CheckMarkStringBufferSize(char* _str)
{
	int nLength = static_cast<int>(strlen(_str));
	if (nLength >= _MARK_PROTOCOL_BUF_SIZE)
	{
		return false;
	}

	return true;
}

void _fastcall CommonUtil::Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void _fastcall CommonUtil::WriteLog(CString strFile, CString str)
{
	_wsetlocale(LC_ALL, L"en_US.utf8");

	AutoCreateDirectoryAndFile(strFile);

	FILE* fp;
	fp = fopen(CW2AEX<256>(strFile), "a");

	if (!fp)
		return;
	wchar_t* buf = new wchar_t[_MARK_PROTOCOL_BUF_SIZE];
	ZeroMemory(buf, _MARK_PROTOCOL_BUF_SIZE);

	StrCpyW(buf, str);

	fputws(buf, fp);
	fputws(L"\n", fp);

	delete[] buf;
	fclose(fp);
}

int extern CommonUtil::Compare(const void* first, const void* second)
{
	if (*(int*)first < *(int*)second) return -1;
	else if (*(int*)first > * (int*)second) return 1;
	else return 0;
}

double _fastcall CommonUtil::CalcSeta(CPoint p1, CPoint p2)
{
	double dSeta = 0.f;
	double dX, dY = 0;
	dX = abs(p1.x - p2.x);
	dY = abs(p1.y - p2.y);
	dSeta = atan(dY / dX);
	dSeta *= 180 / 3.141592654;

	return dSeta;
}

