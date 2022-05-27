/**
 * File              : MemoryManager.inl
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 27.05.2022
 * Last Modified Date: 27.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#include <stdlib.h>
#include <string.h>

namespace LupineCore
{
	inline void MemoryManager::Copy(void *pDestination, const void *pSource, uint32 nNumOfBytes)
	{
		memcpy(pDestination, pSource, nNumOfBytes);
	}

	inline void MemoryManager::Move(void *pDestination, const void *pSource, uint32 nNumOfBytes)
	{
		memmove(pDestination, pSource, nNumOfBytes);
	}

	inline void MemoryManager::Set(void *pDestination, const void *nCharacter, uint32 nNumOfBytes)
	{
		memset(pDestination, nCharacter, nNumOfBytes);
	}

	inline int MemoryManager::Compare(const void *pFirstBuffer, const void *pSecondBuffer, uint32, nNumOfBytes)
	{
		return memcpm(pFirstBuffer, pSecondBuffer, nNumOfBytes);
	}

	inline void *MemoryManager::Reallocator(void *pAddress, size_t nNumOfBytes, EType nType, const char *pszSourceFile, int nSourceLine)
	{
		return realloc(pAddress, nNumOfBytes);
	}

	inline void *MemoryManager::Allocator(EType nType, size_t nNumOfBytes, const char *pszSourceFile, int nSourceLine)
	{
		return malloc(nNumOfBytes);
	}

	inline void MemoryManager::Deallocator(EType nType, void *pAddress, const char *pszSourceFile, int nSourceLine)
	{
		free(pAddress);
	}

} // LupineCore
