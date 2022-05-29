#include "LupineCore/Core/MemoryManager.h"

inline void *operator new(size_t nNumOfBytes)
{
    if (!nNumOfBytes)
        nNumOfBytes = 1;
    for (;;)
    {
        void *pAddress = LupineCore::MemoryManager::Allocator(LupineCore::MemoryManager::New, nNumOfBytes, "?", 0);
        if (pAddress)
            return pAddress;
    }
}

inline void *operator new[](size_t nNumOfBytes)
{
    if (!nNumOfBytes)
        nNumOfBytes = 1;
    for (;;)
    {
        void *pAddress = LupineCore::MemoryManager::Allocator(LupineCore::MemoryManager::NewArray, nNumOfBytes, "?", 0);
        if (pAddress)
            return pAddress;
    }
}

inline void operator delete(void *pAddress)
{
    if (pAddress)
        LupineCore::MemoryManager::Deallocator(LupineCore::MemoryManager::Delete, pAddress, "?", 0);
}

inline void operator delete[](void *pAddress)
{
    if (pAddress)
        LupineCore::MemoryManager::Deallocator(LupineCore::MemoryManager::DeleteArray, pAddress, "?", 0);
}

inline void *operator new(size_t nNumOfBytes, const char *pszSourceFile, int nSourceLine)
{
    if (!nNumOfBytes)
        nNumOfBytes = 1;

    for (;;)
    {
        void *pAddress = LupineCore::MemoryManager::Allocator(LupineCore::MemoryManager::New, nNumOfBytes, pszSourceFile, nSourceLine);
        if (pAddress)
            return pAddress;
    }
}

inline void *operator new[](size_t nNumOfBytes, const char *pszSourceFile, int nSourceLine)
{
    if (!nNumOfBytes)
        nNumOfBytes = 1;

    for (;;)
    {
        void *pAddress = LupineCore::MemoryManager::Allocator(LupineCore::MemoryManager::New, nNumOfBytes, pszSourceFile, nSourceLine);
        if (pAddress)
            return pAddress;
    }
}

inline void operator delete(void *pAddress, const char *pszSourceFile, int nSourceLine)
{
    if (pAddress)
        LupineCore::MemoryManager::Deallocator(LupineCore::MemoryManager::Delete, pAddress, pszSourceFile, nSourceLine);
}

inline void operator delete[](void *pAddress, const char *pszSourceFile, int nSourceLine)
{
    if (pAddress)
        LupineCore::MemoryManager::Deallocator(LupineCore::MemoryManager::Delete, pAddress, pszSourceFile, nSourceLine);
}
