#ifndef CommonUtil_H_
#define CommonUtil_H_


#include <afxdb.h>



namespace CommonUtil
{
	unsigned int _fastcall CharLen(char *szSrc);
	HBITMAP  _fastcall JpgtoHbitamp(char *szFilePath);
	void  _fastcall JpgtoHbitamp(char *szFilePath, HBITMAP &hBitmap);
	int  _fastcall Find(LPVOID pBuf1, unsigned int nszBuf1, LPVOID pBuf2, unsigned int unszBuf2, unsigned int unIncrementBytes = 1, int nOffset = NULL);

	unsigned int  _fastcall StrToken(char *szSource, char *szDelimit, char *szResult[]);
	bool _fastcall IsNumber(const char *szText);

	void _fastcall UNICODEtoANSI(wchar_t *wszUNICODE, char *szANSI);
	void _fastcall ANSItoUNICODE(char *szANSI, wchar_t *wszUNICODE);
	wchar_t* _fastcall ANSItoUNICODE(char *szANSI);
	char* _fastcall UNICODEtoANSI(wchar_t *wszUNICODE);

	void _fastcall UTF8toANSI(char *szUTF8, char *szANSI);
	void _fastcall ANSItoUTF8(char *szANSI, char *szUTF8);
	
	void _fastcall UTF8toUNICODE(char *szUTF8, wchar_t *wszUNICODE);
	void _fastcall UNICODEtoUTF8(wchar_t *wszUNICODE, char *szUTF8);

	int _fastcall wcsReplace(wchar_t* dest, size_t numberOfElements, const wchar_t* comp, const wchar_t* replace);

	char* _fastcall ltrim(char *string);
	char* _fastcall rtrim(char *string);
	char* _fastcall trim(char *string);

	char* _fastcall GetDNStoIPAddress(char *szDns);
	void _fastcall GetLocalIPAddress(char *szDest, int nDestLength);
	void _fastcall GetLocalIPAddress(wchar_t *wszDest, int nDestLength);

	void _fastcall Encrypt(char *source, char *destination, unsigned int length);
	void _fastcall Decrypt(char *source, char *destination, unsigned int length);

	void _fastcall Wait(DWORD dwT);
	int _fastcall HandleAllMessage();
	double _fastcall Clock_set();

	//int _fastcall DefectClassToIndex(int nOpticNo, int nDefectClass);
	wchar_t* _fastcall GetColumName(int nCol);
	wchar_t* _fastcall GetRollBaseColumName(int nCol);
	wchar_t* _fastcall GetRollBaseParamName(int nCol);

	BOOL _fastcall ExistFile(CString strPath);
	BOOL _fastcall ExistDirectory(CString strDirectory);

	int __inline ConvertHexCStringToDec(CString data)
	{
		USES_CONVERSION;
		int nDec = strtoul(CW2AEX<256>(data), NULL, 16); 
		return nDec;
	}

	bool _fastcall WriteToFile(const char* filename, const char* buffer, int len);
	bool _fastcall ReadFromFile(const char* filename, char* buffer, int len);
	void _fastcall MakeDirectory(CString strPath);
	BOOL _fastcall AutoCreateDirectoryAndFile(CString strPath);
	bool _fastcall CheckMarkStringBufferSize(char* _str);
	void _fastcall Swap(int& a, int& b);
	void _fastcall WriteLog(CString strFile, CString str);
	
	int extern Compare(const void* first, const void* second);
	double _fastcall CalcSeta(CPoint p1, CPoint p2);

	
};

#endif // CommonUtil_H_