#ifndef Ini_H_
#define Ini_H_

//#include "../SingleTone.h"

class CIni
{
public:
	CIni();
	virtual ~CIni();

	void SetIniPath(char *szFilePath);
	
	wchar_t *GetStringW(const char *szSection, const char *szKey);
	void GetStringW(const char *szSection, const char *szKey, wchar_t *wszDest, int nDestSize);
	char *GetStringA(const char *szSection, const char *szKey);
	void GetStringA(const char *szSection, const char *szKey, char *szDest, int nDestSize);
	int  GetNumeric(const char *szSection, const char *szKey);

	bool SetValueA(const char *szSection, const char *szKey, const char *szValue);
	bool SetValueW(const char *szSection, const char *szKey, const wchar_t *wszValue);
	bool SetValue(const char *szSection, const char *szKey, const int &nValue);
	bool SetValueD(const char *szSection, const char *szKey, const double &dValue);
		
private:
	char m_szFileName[256];
};

//class CSingleToneIni : public CSingleTone<CIni> { };

#endif // Ini_H_
