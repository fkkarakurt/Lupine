/**
 * File              : StringBufferUnicode.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 29.05.2022
 * Last Modified Date: 29.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __LPCORE_STRINGBUFFER_UNICODE_H__
#define __LPCORE_STRINGBUFFER_UNICODE_H__
#pragma once

#include "LupineCore/String/StringBuffer.h"

namespace LupineCore
{
    class StringBufferUnicode : public StringBuffer
    {
        friend class String;
        friend class StringBufferManager;
        friend class StringBufferASCII;
        friend class StringBufferUTF8;

    private:
        StringBufferUnicode(wchar_t szString[], uint32 nLength, uint32 nMaxLength);
        StringBufferUnicode(const char szString[], uint32 nLength, uint32 nMaxLength);
        virtual ~StringBufferUnicode();
        void SetString(wchar_t szString[], uint32 nLength);
        void SetNewStringLength(uint32 nLength);
        void SetCharacter(wchar_t nCharacter);

    private:
        wchar_t *m_pszString;
        StringBufferASCII *m_pASCII;
        StringBufferUTF8 *m_pUTF8;

    public:
        virtual uint32 GetFormat() const override;
        virtual StringBufferASCII *GetASCII() override;
        virtual StringBufferUnicode *GetUnicode() override;
        virtual StringBufferUTF8 *GetUTF8() override;
        virtual uint32 GetNumOfBytes() const override;
        virtual StringBuffer *Clone() const override;
        virtual StringBuffer *Duplicate() override;
        virtual bool IsLessThan(const char szString[], uint32 nLength) const override;
        virtual bool IsLessThan(const wchar_t szString[], uint32 nLength) const override;
        virtual bool IsGreaterThan(const char szString[], uint32 nLength) const override;
        virtual bool IsGreaterThan(const wchar_t szString[], uint32 nLength) const override;
        virtual bool Compare(const char szString[], uint32 nLength, uint32 nPos, uint32 nCount) const override;
        virtual bool Compare(const wchar_t szString[], uint32 nLength, uint32 nPos, uint32 nCount) const override;
        virtual bool CompareNoCase(const char szString[], uint32 nLength, uint32 nPos, uint32 nCount) const override;
        virtual bool CompareNoCase(const wchar_t szString[], uint32 nLength, uint32 nPos, uint32 nCount) const override;
        virtual bool IsAlphabetic() const override;
        virtual bool IsAlphaNumeric() const override;
        virtual bool IsNumeric() const override;
        virtual bool IsSubstring(const char szString[], uint32 nLength) const override;
        virtual bool IsSubstring(const wchar_t szString[], uint32 nLength) const override;
        virtual int IndexOf(const char szString[], uint32 nPos, uint32 nLength) const override;
        virtual int IndexOf(const wchar_t szString[], uint32 nPos, uint32 nLength) const override;
        virtual int LastIndexOf(const char szString[], int nPos, uint32 nLength) const override;
        virtual int LastIndexOf(const wchar_t szString[], int nPos, uint32 nLength) const override;
        virtual StringBuffer *GetSubstring(uint32 nPos, uint32 nCount) const override;
        virtual StringBuffer *ToLower() override;
        virtual StringBuffer *ToUpper() override;
        virtual StringBuffer *Delete(uint32 nPos, uint32 nCount) override;
        virtual StringBuffer *Append(const char szString[], uint32 nCount) override;
        virtual StringBuffer *Append(const wchar_t szString[], uint32 nCount) override;
        virtual StringBuffer *Insert(const char szString[], uint32 nPos, uint32 nCount) override;
        virtual StringBuffer *Insert(const wchar_t szString[], uint32 nPos, uint32 nCount) override;
        virtual StringBuffer *Replace(char nOld, char nNew, uint32 &nReplaced) override;
        virtual StringBuffer *Replace(wchar_t nOld, wchar_t nNew, uint32 &nReplaced) override;
        virtual StringBuffer *Replace(const char szOld[], uint32 nOldLength, const char szNew[], uint32 nNewLength, uint32 &nReplaced) override;
        virtual StringBuffer *Replace(const wchar_t szOld[], uint32 nOldLength, const wchar_t szNew[], uint32 nNewLength, uint32 &nReplaced) override;
        virtual StringBuffer *SetCharacter(uint32 nIndex, char nCharacter) override;
        virtual StringBuffer *SetCharacter(uint32 nIndex, wchar_t nCharacter) override;
        virtual StringBuffer *TrimLeading() override;
        virtual StringBuffer *TrimTrailing() override;
        virtual StringBuffer *RemoveLineEndings() override;
    };

} // LupineCore

#endif // __LPCORE_STRINGBUFFER_UNICODE_H__