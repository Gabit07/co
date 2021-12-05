#include "../pch.h"
#include "../common/CommonDefine.h"
#include "Lock.h"

CLock::CLock()
{
	InitializeCriticalSection(&m_cs);
}

CLock::~CLock()
{
	DeleteCriticalSection(&m_cs);
}

void CLock::Lock()
{
	EnterCriticalSection(&m_cs);
}

void CLock::UnLock()
{
	LeaveCriticalSection(&m_cs);
}

bool CLock::TryLock()
{
	return TryEnterCriticalSection(&m_cs) ? true : false;
}

bool CLock::IsLock()
{
	return (GetLockCount() != INVALID_VALUE) ? true : false;
}

unsigned long CLock::GetOwnerThreadID()
{
	return (DWORD)(DWORD_PTR)m_cs.OwningThread;
}

int CLock::GetLockCount()
{
	return (int)m_cs.LockCount;
}
