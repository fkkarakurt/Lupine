/**
 * File              : String.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 28.05.2022
 * Last Modified Date: 28.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __LPCORE_STRING_H__
#define __LPCORE_STRING_H__
#pragma once

#include "LupineCore/LupineCore.h"

namespace LupineCore
{
    class StringBuffer;
    class String
    {
        public:
            enum EFormat
            {
                ASCII = 0,
                Unicode = 1,
                UTF8 = 2
            };

        public:
            static LPCORE_API String Format(const char *pszFormat, ...);
            static LPCORE_API String Format(const wchar_t *pszFormat, ...);
            static LPCORE_API String FromUTF8(const char *pszUTF8, int nLength = -1, uint32 nNumOfBytes = 0);


        public:
            inline String();
            LPCORE_API String(char nValue);
            LPCORE_API String(wchar_t nValue);
            LPCORE_API String(const char *pszString, bool bCopy = true, int nLength = -1);
            LPCORE_API String(const wchar_t *pszString, bool bCopy = true, int nLength = -1);
            LPCORE_API String(const String &sString);

            inline String(bool bValue);
            LPCORE_API String(int nValue);
            inline String(int64 nValue);
            inline String(uint8 nValue);
            inline String(uint32 nValue);
            inline String(uint64 nValue);
            inline String(float fValue);
            inline String(double fValue);
            inline String(void *pValue);

            String(StringBuffer *pStringBuffer);

            inline ~String();
            inline uint32 GetLength() const;
            inline EFormat GetFormat() const;
            LPCORE_API uint32 GetNumOfBytes(EFormat nFormat) const;
            inline char operator [](uint32 nIndex) const;
            inline const char *GetASCII() const;
            inline operator const char *() const;
            inline const wchar_t *GetUnicode() const;
            inline operator const wchar_t *() const;
            inline String &operator =(const String &sString);
          
            LPCORE_API String &operator =(const char *pszString);
            LPCORE_API String &operator =(const wchar_t *pszString);
          
            LPCORE_API String operator +(const String &sString) const;
            LPCORE_API String operator +(const char *pszString) const;
            LPCORE_API String operator +(const wchar_t *pszString) const;
          
            LPCORE_API friend String operator+(const char *pszString, const String &sString);
            LPCORE_API friend String operator+(const wchar_t *pszString, const String &sString);
          
            LPCORE_API String &operator +=(const String &sString);
            LPCORE_API String &operator +=(const char *pszString);
            LPCORE_API String &operator +=(const wchar_t *pszString);
          
            LPCORE_API bool operator <(const String &sString) const;
            LPCORE_API bool operator <(const char *pszString) const;
            LPCORE_API bool operator <(const wchar_t *pszString) const;
            
            LPCORE_API bool operator >(const String &sString) const;
            LPCORE_API bool operator >(const char *pszString) const;
            LPCORE_API bool operator >(const wchar_t *pszString) const;

            inline bool operator ==(const String &sString) const;
            inline bool operator ==(const char *pszString) const;
            inline bool operator ==(const wchar_t *pszString) const;

            inline bool operator !=(const String &sString) const;
            inline bool operator !=(const char *pszString) const;
            inline bool operator !=(const wchar_t *pszString) const;

            LPCORE_API bool Compare(const String &sString, uint32 nPos = 0, int nCount = -1) const;
            LPCORE_API bool Compare(const char *pszString, uint32 nPos = 0, int nCount = -1) const;
            LPCORE_API bool Compare(const wchar_t *pszString, uint32 nPos = 0, int nCount = -1) const;
            LPCORE_API bool CompareNoCase(const String &sString, uint32 nPos = 0, int nCount = -1) const;
            LPCORE_API bool CompareNoCase(const char *pszString, uint32 nPos = 0, int nCount = -1) const;
            LPCORE_API bool CompareNoCase(const wchar_t *pszString, uint32 nPos = 0, int nCount = -1) const;


            inline bool IsAlphabetic() const;
            inline bool IsAlphaNumeric() const;
            inline bool IsNumberic() const;

            LPCORE_API bool IsSubstring(const String &sString) const;
            LPCORE_API bool IsSubstring(const char *pszString) const;
            LPCORE_API bool IsSubstring(const wchar_t *pszString) const;
            LPCORE_API int IndexOf(const String &sString, uint32 nPos = 0) const;
            LPCORE_API int IndexOf(const char *pszString, uint32 nPos = 0) const;
            LPCORE_API int IndexOf(const wchar_t *pszString, uint32 nPos = 0) const;
            LPCORE_API int LastIndexOf(const String &sString, int nPos = -1) const;
            LPCORE_API int LastIndexOf(const char *pszString, int nPos = -1) const;
            LPCORE_API int LastIndexOf(const wchar_t *pszString, int nPos = -1) const;
            LPCORE_API String GetSubstring(uint32 nPos, int nCount = -1) const;

            inline String &ToLower();
            inline String &ToUpper();

            LPCORE_API String &Delete(uint32 nPos = 0, int nCount = -1);
            
            inline String &Insert(char nCharacter, uint32 nPos = 0);
            inline String &Insert(wchar_t nCharacter, uint32 nPos = 0);

            LPCORE_API String &Insert(const String &sString, uint32 nPos = 0, int nCount = -1);
            LPCORE_API String &Insert(const char *pszString, uint32 nPos = 0, int nCount = -1);
            LPCORE_API String &Insert(const wchar_t *pszString, uint32 nPos = 0, int nCount = -1);

            LPCORE_API String &Copy(const char *pszString, int nCount = -1);
            LPCORE_API String &Copy(const wchar_t *pszString, int nCount = -1);

            LPCORE_API uint32 Replace(char nOld, char nNew);
            LPCORE_API uint32 Replace(wchar_t nOld, wchar_t nNew);
            LPCORE_API uint32 Replace(const String &sOld, const String &sNew);
            LPCORE_API uint32 Replace(const char *pszOld, const char *pszNew);
            LPCORE_API uint32 Replace(const wchar_t *pszOld, const wchar_t *pszNew);

            LPCORE_API bool SetCharacter(uint32 nIndex, char nCharacter);
            LPCORE_API bool SetCharacter(uint32 nIndex, wchar_t nCharacter);

            inline String &TrimLeading();
            inline String &TrimTrailing();

            LPCORE_API String &Trim();

            inline String &RemoveLineEndings();

        public:
            inline const char *GetUTF8() const;
            LPCORE_API bool IsValidInteger() const;
            LPCORE_API bool IsValidFloat() const;
            LPCORE_API bool GetBool() const;
            LPCORE_API char GetChar() const;
            LPCORE_API wchar_t GetWideChar() const;
            LPCORE_API int GetInt() const;
            LPCORE_API int64 GetInt64() const;
            LPCORE_API uint8 GetUInt8() const;
            LPCORE_API uint16 GetUInt16() const;
            LPCORE_API uint32 GetUInt32() const;
            LPCORE_API uint64 GetUInt64() const;
            inline uint_ptr GetUIntPtr() const;
            LPCORE_API float GetFloat() const;
            LPCORE_API double GetDouble() const;
            inline String &operator=(bool bValue);
            LPCORE_API String &operator=(char nValue);
            LPCORE_API String &operator=(wchar_t nValue);
            LPCORE_API String &operator=(int nValue);
            LPCORE_API String &operator=(int64 nValue);
            LPCORE_API String &operator=(uint8 nValue);
            LPCORE_API String &operator=(uint32 nValue);
            LPCORE_API String &operator=(uint64 nValue);
            LPCORE_API String &operator=(float fValue);
            LPCORE_API String &operator=(double dValue);
            LPCORE_API String operator+(bool bValue) const;
            LPCORE_API String operator+(char nValue) const;
            LPCORE_API String operator+(wchar_t nValue) const;
            LPCORE_API String operator+(int nValue) const;
            inline String operator+(int64 nValue) const;
            inline String operator+(uint8 nValue) const;
            inline String operator+(uint32 nValue) const;
            inline String operator+(uint64 nValue) const;
            inline String operator+(float fValue) const;
            inline String operator+(double dValue) const;
            LPCORE_API friend String operator+(bool bValue, const String &sString);
            LPCORE_API friend String operator+(char nValue, const String &sString);
            LPCORE_API friend String operator+(wchar_t nValue, const String &sString);
            inline friend String operator+(int nValue, const String &sString);
            inline friend String operator+(int64 nValue, const String &sString);
            inline friend String operator+(uint8 nValue, const String &sString);
            inline friend String operator+(uint32 nValue, const String &sString);
            inline friend String operator+(uint64 nValue, const String &sString);
            inline friend String operator+(float fValue, const String &sString);
            inline friend String operator+(double dValue, const String &sString);
            LPCORE_API String &operator+=(bool bValue);
            LPCORE_API String &operator+=(char nValue);
            LPCORE_API String &operator+=(wchar_t nValue);
            inline String &operator+=(int nValue);
            inline String &operator+=(int64 nValue);
            inline String &operator+=(uint8 nValue);
            inline String &operator+=(uint32 nValue);
            inline String &operator+=(uint64 nValue);
            inline String &operator+=(float fValue);
            inline String &operator+=(double dValue);

        private:
            LPCORE_API void SetStringBuffer(StringBuffer *pStringBuffer);
            void ReleaseStringBuffer();

        private:
            StringBuffer *m_pStringBuffer;
    };

} //LupineCore

#include "LupineCore/String/String.inl"

#endif // __LPCORE_STRING_H__