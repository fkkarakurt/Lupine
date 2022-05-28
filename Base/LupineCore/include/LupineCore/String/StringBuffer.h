/**
 * File              : StringBuffer.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 28.05.2022
 * Last Modified Date: 28.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __LPCORE_STRINGBUFFER_H__
#define __LPCORE_STRINGBUFFER_H__
#pragma once

#include "LupineCore/String/StringBufferManager.h"

namespace LupineCore
{
    class StringBuffer
    {
        friend class String;
        friend class StringBufferManager;

        protected:
            static LPCORE_API StringBufferManager Manager;
        
        protected:
            StringBuffer(uint32 nLength, uint32 nMaxLength, uint8 nType);
            virtual ~StringBuffer();
            LPCORE_API uint32 GetLength() const;
            uint32 AddReference();
            uint32 Release();
            uint32 GetRefCount() const;

        public:
            virtual uint32 GetFormat() const = 0;
            virtual StringBufferASCII *GetASCII() = 0;
            virtual StringBufferUnicode *GetUnicode() = 0;
            virtual StringBufferUTF8 *GetUTF8() = 0;
            virtual uint32 GetNumOfBytes() const = 0;
            virtual StringBuffer *Clone() const = 0;
            virtual StringBuffer *Duplicate() = 0;
            virtual bool IsLessThan(const char szString[], uint32 nLength) const = 0;
            virtual bool IsLessThan(const wchar_t szString[], uint32 nLength) const = 0;
            virtual bool IsGreaterThan(const char szString[], uint32 nLength) const = 0;
            virtual bool IsGreaterThan(const wchar_t szString[], uint32 nLength) const = 0;
            virtual bool Compare(const char szString[], uint32 nLength, uint32 nPos, uint32 nCount) const = 0;
            virtual bool Compare(const wchar_t szString[], uint32 nLength, uint32 nPos, uint32 nCount) const = 0;
            virtual bool CompareNoCase(const char szString[], uint32 nLength, uint32 nPos, uint32 nCount) const = 0;
            virtual bool CompareNoCase(const wchar_t szString[], uint32 nLength, uint32 nPos, uint32 nCount) const = 0;
            virtual bool IsAlphabetic() const = 0;
            virtual bool IsAlphaNumeric() const = 0;
            virtual bool IsNumeric() const = 0;
            virtual bool IsSubstring(const char szString[], uint32 nLength) const = 0;
            virtual bool IsSubstring(const wchar_t szString[], uint32 nLength) const = 0;
            virtual int IndexOf(const char szString[], uint32 nPos, uint32 nLength) const = 0;
            virtual int IndexOf(const wchar_t szString[], uint32 nPos, uint32 nLength) const = 0;
            virtual int LastIndexOf(const char szString[], int nPos, uint32 nLength) const = 0;
            virtual int LastIndexOf(const wchar_t szString[], int nPos, uint32 nLength) const = 0;
            virtual StringBuffer *GetSubstring(uint32 nPos, uint32 nCount) const = 0;
            virtual StringBuffer *ToLower() = 0;
            virtual StringBuffer *ToUpper() = 0;
            virtual StringBuffer *Delete(uint32 nPos, uint32 nCount) = 0;
            virtual StringBuffer *Append(const char szString[], uint32 nCount) = 0;
            virtual StringBuffer *Append(const wchar_t szString[], uint32 nCount) = 0;
            virtual StringBuffer *Insert(const char szString[], uint32 nPos, uint32 nCount) = 0;
            virtual StringBuffer *Insert(const wchar_t szString[], uint32 nPos, uint32 nCount) = 0;
            virtual StringBuffer *Replace(char nOld, char nNew, uint32 &nReplaced) = 0;
            virtual StringBuffer *Replace(wchar_t nOld, wchar_t nNew, uint32 &nReplaced) = 0;
            virtual StringBuffer *Replace(const char szOld[], uint32 nOldLength, const char szNew[], uint32 nNewLength, uint32 &nReplaced) = 0;
            virtual StringBuffer *Replace(const wchar_t szOld[], uint32 nOldLength, const wchar_t szNew[], uint32 nNewLength, uint32 &nReplaced) = 0;
            virtual StringBuffer *SetCharacter(uint32 nIndex, char nCharacter) = 0;
            virtual StringBuffer *SetCharacter(uint32 nIndex, wchar_t nCharacter) = 0;
            virtual StringBuffer *TrimLeading() = 0;
            virtual StringBuffer *TrimTrailing() = 0;
            virtual StringBuffer *RemoveLineEndings() = 0;

        protected:
            uint32 m_nRefCount;
            uint32 m_nLength;
            uint32 m_nMaxLength;
            uint8 m_nType;
    };

} // LupineCore

#include "LupineCore/String/StringBufferUTF8.h"
#include "LupineCore/String/StringBufferASCII.h"
#include "LupineCore/String/StringBufferUnicode.h"

#endif // __LPCORE_STRINGBUFFER_H__