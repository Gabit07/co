#ifndef Lock_H_
#define Lock_H_

#include <afxwin.h>

class  CLock
{
public:
	CLock();
	~CLock();

	void Lock();
	void UnLock();
	bool TryLock();
	bool IsLock();

	unsigned long GetOwnerThreadID();
	int GetLockCount();

protected:
	CRITICAL_SECTION m_cs;
};

template < class TElement >
class CLockTemplate : public CLock
{
public:
	void Set(TElement element) { m_element = element; }
	TElement Get() { return m_element; }

protected:
	TElement m_element;
};

#endif // Lock_H_