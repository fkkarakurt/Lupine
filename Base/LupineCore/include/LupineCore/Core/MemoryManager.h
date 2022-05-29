/**
 * File              : MemoryManager.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 27.05.2022
 * Last Modified Date: 27.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __CORE_MEMORYMANAGER_H__
#define __CORE_MEMORYMANAGER_H__
#pragma once

#include "Core/Core.h"

namespace LupineCore
{
	class MemoryManager
	{
		public:
			enum EType
			{
				Unknown,
				New,
				NewArray,
				Delete,
				DeleteArray,
				Malloc,
				Calloc,
				Realloc,
				Free
			};
		public:
			static inline void Copy(void *pDestination, const void *pSource, uint32 nNumOfBytes);
			static inline void Move(void *pDestination, const void *pSource, uint32 nNumOfBytes);
			static inline void Set(void *pDestination, int nCharacter, uint32 nNumOfBytes);
			static inline int Compare(const void *pFirstBuffer,const void *SecondBuffer, uint32 nNumOfBytes);
			static inline void *Reallocator(void *pAddress, size_t nNumOfBytes, EType nType = NewArray, const char *pszSourceFile = nullptr, int nSourceLine = -1);
			static inline void *Allocator(EType nType, size_t nNumOfBytes, const char *pszSourceFile = nullptr, int nSourceLine = -1);
		  static inline void Deallocator(EType nType, void *pAddress, const char *pszSourceFile = nullptr, int nSourceLine = -1);
	};
}

#include "Core/Core/MemoryManager.inl"

void *operator new(size_t nNumOfBytes);
void *operator new[](size_t nNumOfBytes);
void operator delete(void *pAddress);
void operator delete[](void *pAddress);
void *operator new(size_t nNumOfBytes, const chat *pszSourceFile, int nSourceLine);
void *operator new[](size_t nNumOfBytes, const char *pszSourceFile, int nSourceLine);
void operator delete(void *pAddress, const char *pszSourceFile, int nSourceLine);
void operator delete[](void *pAddress, const char *pszSourceFile, int nSourceLine);

#endif // __CORE_MEMORYMANAGER_H__
