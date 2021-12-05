
#include "../pch.h"
#include "Ini.h"
#include "CommonUtil.h"
#include "CommonDefine.h"

CIni::CIni()
{
	ZeroMemory(m_szFileName, sizeof(m_szFileName));
}

CIni::~CIni()
{
}

//------------------------------------------------------------------------
/**
	@brief ini 경로 저장
*///----------------------------------------------------------------------
void CIni::SetIniPath(char *szFilePath)
{
	ZeroMemory(m_szFileName, sizeof(m_szFileName));
	strcpy_s(m_szFileName, sizeof(m_szFileName), szFilePath);
}

//------------------------------------------------------------------------
/**
	@brief 문자열을 얻어온다
*///----------------------------------------------------------------------
wchar_t *CIni::GetStringW(const char *szSection, const char *szKey)
{
	wchar_t *wszPath = CommonUtil::ANSItoUNICODE(m_szFileName);
	wchar_t *wszSection = CommonUtil::ANSItoUNICODE(const_cast<char*>(szSection));
    wchar_t *wszKey = CommonUtil::ANSItoUNICODE(const_cast<char*>(szKey));

	wchar_t wszResult[256] = {0,};
	GetPrivateProfileStringW(wszSection, wszKey, L"", wszResult, 256, wszPath);	
	CommonUtil::wcsReplace(wszResult, _countof(wszResult), L"\\r\\n", L"\r\n");

	SAFE_MEM_DELETE(wszPath);
	SAFE_MEM_DELETE(wszSection);
	SAFE_MEM_DELETE(wszKey);
	
	return _wcsdup(wszResult);
}

void CIni::GetStringW(const char *szSection, const char *szKey, wchar_t *wszDest, int nDestSize)
{
	wchar_t *wszPath = CommonUtil::ANSItoUNICODE(m_szFileName);
	wchar_t *wszSection = CommonUtil::ANSItoUNICODE(const_cast<char*>(szSection));
	wchar_t *wszKey = CommonUtil::ANSItoUNICODE(const_cast<char*>(szKey));

	wchar_t wszResult[256] = {0,};
	GetPrivateProfileStringW(wszSection, wszKey, L"", wszResult, 256, wszPath);	
	CommonUtil::wcsReplace(wszResult, _countof(wszResult), L"\\r\\n", L"\r\n");

	SAFE_MEM_DELETE(wszPath);
	SAFE_MEM_DELETE(wszSection);
	SAFE_MEM_DELETE(wszKey);

	wcscat_s(wszDest, nDestSize, wszResult);
}

char *CIni::GetStringA(const char *szSection, const char *szKey)
{
	char szResult[256] = {0,};
	GetPrivateProfileStringA(szSection, szKey, "", szResult, 256, m_szFileName);	
	
	return _strdup(szResult);
}

void CIni::GetStringA(const char *szSection, const char *szKey, char *szDest, int nDestSize)
{
	char szResult[256] = {0,};
	GetPrivateProfileStringA(szSection, szKey, "", szResult, 256, m_szFileName);
	strcat_s(szDest, nDestSize, szResult);
}

//------------------------------------------------------------------------
/**
	@brief ini 섹션 키에 대한 숫자 정보를 얻어온다
*///----------------------------------------------------------------------
int CIni::GetNumeric(const char *szSection, const char *szKey)
{
	return GetPrivateProfileIntA(szSection, szKey, 0, m_szFileName);
}

//------------------------------------------------------------------------
/**
	@brief ini값 설정 문자
*///----------------------------------------------------------------------
bool CIni::SetValueA(const char *szSection, const char *szKey, const char *szValue)
{
	return WritePrivateProfileStringA(szSection, szKey, szValue, m_szFileName) ? true : false;
}

//------------------------------------------------------------------------
/**
	@brief ini값 설정 유니코드문자
*///----------------------------------------------------------------------
bool CIni::SetValueW(const char *szSection, const char *szKey, const wchar_t *wszValue)
{
	wchar_t wszFilePath[256] = {0,};
	wchar_t wszSection[32] = {0,};
	wchar_t wszKey[32] = {0,};

	CommonUtil::ANSItoUNICODE(m_szFileName, wszFilePath);
	CommonUtil::ANSItoUNICODE(const_cast<char*>(szSection), wszSection);
	CommonUtil::ANSItoUNICODE(const_cast<char*>(szKey), wszKey);
	return WritePrivateProfileStringW(wszSection, wszKey, wszValue, wszFilePath) ? true : false;
}

//------------------------------------------------------------------------
/**
	@brief ini값 설정 숫자
*///----------------------------------------------------------------------
bool CIni::SetValue(const char *szSection, const char *szKey, const int &nValue)
{
	char szValue[64] = {0,};
	sprintf_s(szValue, sizeof(szValue), "%d", nValue);
	return WritePrivateProfileStringA(szSection, szKey, szValue, m_szFileName) ? true : false;
}

bool CIni::SetValueD(const char *szSection, const char *szKey, const double &dValue)
{
	char szValue[64] = {0,};
	sprintf_s(szValue, sizeof(szValue), "%lf", dValue);
	return WritePrivateProfileStringA(szSection, szKey, szValue, m_szFileName) ? true : false;
}
