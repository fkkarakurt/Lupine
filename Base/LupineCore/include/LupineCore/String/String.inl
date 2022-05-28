/**
 * File              : String.inl
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 28.05.2022
 * Last Modified Date: 28.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */


#include "LupineCore/String/StringBuffer.h"

namespace LupineCore
{
    inline String::String() : m_pStringBuffer(nullptr){}
    inline String::String(bool bValue) : m_pStringBuffer(nullptr){*this = bValue;}
    inline String::String(int64 nValue) : m_pStringBuffer(nullptr){*this = nValue;}
    inline String::String(uint8 nValue) : m_pStringBuffer(nullptr){*this = nValue;}
    inline String::String(uint32 nValue) : m_pStringBuffer(nullptr){*this = nValue;}
    inline String::String(uint64 nValue) : m_pStringBuffer(nullptr){*this = nValue;}
    inline String::String(float fValue) : m_pStringBuffer(nullptr){*this = fValue;}
    inline String::String(double fValue) : m_pStringBuffer(nullptr){*this = fValue;}
    inline String::String(void *pValue) : m_pStringBuffer(nullptr){*this = reinterpret_cast<uint_ptr>(pValue);}
    inline String::~String(){
        if(m_pStringBuffer)
            StringBuffer::Manager.ReleaseStringBuffer(*m_pStringBuffer);
    }
    inline uint32 String::GetLength() const{return m_pStringBuffer ? m_pStringBuffer->GetLength() : 0;}
    inline String::EFormat String::GetFormat() const{return m_pStringBuffer ? static_cast<String::EFormat>(m_pStringBuffer->GetFormat()) : ASCII;}
    inline char String::operator [](uint32 nIndex) const{return(nIndex < GetLength()) ? GetASCII()[nIndex] : '\0';}
    inline const char *String::GetASCII() const{return m_pStringBuffer ? m_pStringBuffer->GetASCII()->m_pszString : "";}
    inline String::operator const char *() const{return m_pStringBuffer ? m_pStringBuffer->GetASCII()->m_pszString : "";}
    inline const wchar_t *String::GetUnicode() const{return m_pStringBuffer ? m_pStringBuffer->GetUnicode()->m_pszString :L"";}
    inline String::operator const wchar_t *() const{return m_pStringBuffer ? m_pStringBuffer->GetUnicode()->m_pszString : L"";}
    inline String &String::operator =(const String &sString){
        SetStringBuffer(sString.m_pStringBuffer);
        return *this;
    }
    inline bool String::operator ==(const String &sString) const{return Compare(sString);}
    inline bool String::opearator ==(const char *pszString) const{return Compare(pszString);}
    inline bool String::operator ==(const wchar_t *pszString) const{return Compare(pszString);}
    inline bool String::operator !=(const String &sString) const{return !Compare(sString);}
    inline bool String::operator !=(const char *pszString) const{return !Compare(pszString);}
    inline bool String::operator !=(const wchar_t *pszString) const{return !Compare(pszString);}
    inline bool String::IsAlphabetic() const{return (m_pStringBuffer && m_pStringBuffer->IsAlphabetic());}
    inline bool String::IsAlphaNumeric() const{return(m_pStringBuffer && m_pStringBuffer->IsAlphaNumeric());}
    inline bool String::IsNumeric() const{return(m_pStringBuffer && m_pStringBuffer->IsNumeric());}
    inline String &String::ToLower(){
        if(m_pStringBuffer){
            SetStringBuffer(m_pStringBuffer->ToLower());
        }
        return *this;
    }
    inline String &String::ToUpper(){
        if(m_pStringBuffer){
            SetStringBuffer(m_pStringBuffer->ToUpper());
        }
        return *this;
    }
    inline String &String::Insert(char nCharacter, uint32 nPos){
        if(nPos == GetLength()){
            *this += nCharacter;
            return *this;
        } else {
            return Insert(&nCharacter, nPos, 1);
        }
    }
    inline String &String::Insert(wchar_t nCharacter, uint32 nPos){
        if(nPos == GetLength()){
            *this += nCharacter;
            return *this;
        } else {
            return Insert(&nCharacter, nPos, 1);
        }
    }
    inline String &String::TrimLeading(){
        if(m_pStringBuffer){
            SetStringBuffer(m_pStringBuffer->TrimLeading());
        }
        return *this;
    }
    inline String &String::TrimTrailing()
    {
        if(m_pStringBuffer){
            SetStringBuffer(m_pStringBuffer->TrimTrailing());
        }
        return *this;
    }
    inline String &String::RemoveLineEndings(){
        if(m_pStringBuffer)
        {
            SetStringBuffer(m_pStringBuffer->RemoveLineEndings());
        }
        return *this;
    }


    /**
     * 
     **/


    inline const char *String::GetUTF8() const{
        return m_pStringBuffer ? m_pStringBuffer->GetUTF8()->m_pszString: "";
    }
    inline uint_ptr String::GetUIntPtr() const{
        #ifdef X64_ARCHITECTURE
            return GetUInt64();
        #else
            return GetUInt32();
        #endif
    }
    inline String &String::operator =(bool bValue){
        *this = bValue ? '1' : '0';
        return *this;
    }
    inline String &String::operator =(int64 nValue){
        #ifdef WIN32
            *this = Format("%I64", nValue);
        #else
            *this = Format("%ll", nValue);
        #endif

        return *this;
    }
    inline String &String::operator =(uint8 nValue){
        #ifdef WIN32
            *this = Format("%I32u", static_cast<uint32>(nValue));
        #else
            *this = Format("%u", static_cast<uint32>(nValue));
        #endif

        return *this;
    }
    inline String &String::operator =(uint32 nValue){
        #ifdef WIN32
            *this = Format("%I32u", nValue);
        #else
            *this = Format("%u", nValue);
        #endif

        return *this;
    }
    inline String &String::operator =(uint64 nValue){
        #ifdef WIN32
            *this = Format("%I64u", nValue);
        #else
            *this = Format("%llu", nValue);
        #endif

        return *this;
    }
    inline String &String::operator =(float fValue){
        *this = Format("%g", fValue);
        return *this;
    }
    inline String &String::operator =(double dValue){
        *this = Format("%g", dValue);
        return *this;
    }
    inline String String::operator +(int nValue) const{
        return *this + String(nValue);
    }
    inline String String::operator +(int64 nValue) const{
        #ifdef WIN32
            return (GetFormat() == Unicode) ? *this + Format(L"%I64", nValue) : *this + Format("%I64", nValue);
        #else
            return (GetFormat() == Unicode) ? *this + Format(L"%ll", nValue) : *this + Format("%ll", nValue);
        #endif
    }
    inline String String::operator +(uint8 nValue) const
    {
        #ifdef WIN32
            return (GetFormat() == Unicode) ? *this + Format(L"%I32u", static_cast<uint32>(nValue)) : *this + Format("%I32u", static_cast<uint32>(nValue));
        #else
            return (GetFormat() == Unicode) ? *this + Format(L"%u", static_cast<uint32>(nValue)) : *this + Format("%u", static_cast<uint32>(nValue));
        #endif
    }
    inline String String::operator +(uint32 nValue) const
    {
        #ifdef WIN32
            return (GetFormat() == Unicode) ? *this + Format(L"%I32u", nValue) : *this + Format("%I32u", nValue);
        #else
            return (GetFormat() == Unicode) ? *this + Format(L"%u", nValue) : *this + Format("%u", nValue);
        #endif
    }
    inline String String::operator +(uint64 nValue) const
    {
        #ifdef WIN32
            return (GetFormat() == Unicode) ? *this + Format(L"%I64u", nValue) : *this + Format("%I64u", nValue);
        #else
            return (GetFormat() == Unicode) ? *this + Format(L"%llu", nValue) : *this + Format("%llu", nValue);
        #endif
    }
    inline String String::operator +(float fValue) const
    {
        return (GetFormat() == Unicode) ? *this + Format(L"%g", fValue) : *this + Format("%g", fValue);        
    }
    inline String String::operator +(double dValue) const
    {
        return (GetFormat() == Unicode) ? *this + String::Format(L"%g", dValue) : *this + String::Format("%g", dValue);
    }
    inline String operator +(int nValue, const String &sString)
    {
        return (sString.GetFormat() == String::Unicode) ? String::Format(L"%d", nValue) + sString : String::Format("%d", nValue) + sString;
    }
    inline String operator +(int64 nValue, const String &sString)
    {
        #ifdef WIN32
            return (sString.GetFormat() == String::Unicode) ? String::Format(L"%I64", nValue) + sString : String::Format("%I64", nValue) + sString;
        #else
            return (sString.GetFormat() == String::Unicode) ? String::Format(L"%ll", nValue) + sString : String::Format("%ll", nValue) + sString;
        #endif
    }
    inline String operator +(uint8 nValue, const String &sString)
    {
        #ifdef WIN32
            return (sString.GetFormat() == String::Unicode) ? String::Format(L"%I32u", static_cast<uint32>(nValue)) + sString : String::Format("%I32u", static_cast<uint32>(nValue)) + sString;
        #else
            return (sString.GetFormat() == String::Unicode) ? String::Format(L"%u", static_cast<uint32>(nValue)) + sString : String::Format("%u", static_cast<uint32>(nValue)) + sString;
        #endif
    }
    inline String operator +(uint32 nValue, const String &sString)
    {
        #ifdef WIN32
            return (sString.GetFormat() == String::Unicode) ? String::Format(L"%I32u", nValue) + sString : String::Format("%I32u", nValue) + sString;
        #else
            return (sString.GetFormat() == String::Unicode) ? String::Format(L"%u", nValue) + sString : String::Format("%u", nValue) + sString;
        #endif
    }
    inline String operator +(uint64 nValue, const String &sString)
    {
        #ifdef WIN32
            return (sString.GetFormat() == String::Unicode) ? String::Format(L"%I64u", nValue) + sString : String::Format("%I64u", nValue) + sString;
        #else
            return (sString.GetFormat() == String::Unicode) ? String::Format(L"%llu", nValue) + sString : String::Format("%llu", nValue) + sString;
        #endif
    }
    inline String operator +(float fValue, const String &sString)
    {
        return (sString.GetFormat() == String::Unicode) ? String::Format(L"%g", fValue) + sString : String::Format("%g", fValue) + sString;
    }
    inline String operator +(double dValue, const String &sString)
    {
        return (sString.GetFormat() == String::Unicode) ? String::Format(L"%g", dValue) + sString : String::Format("%g", dValue) + sString;
    }
    inline String &String::operator +=(int nValue)
    {
        *this += String(nValue);
        return *this;
    }
    inline String &String::operator +=(int64 nValue)
    {
        #ifdef WIN32
            if(GetFormat() == Unicode)
                *this += Format(L"%I64", nValue);
            else
                *this += Format("%I64", nValue);
        #else
            if(GetFormat() == Unicode)
                *this += Format(L"%ll", nValue);
            else
                *this += Format("%ll", nValue);
        #endif

        return *this;
    }
    inline String &String::operator +=(uint8 nValue)
    {
        #ifdef WIN32
            if(GetFormat() == Unicode)
                *this += Format(L"%I32u", static_cast<uint32>(nValue));
            else
                *this += Format("%I32u", static_cast<uint32>(nValue));
        #else
            if(GetFormat() == Unicode)
                *this += Format(L"%u", static_cast<uint32>(nValue));
            else
                *this += Format("%u", static_cast<uint32>(nValue));
        #endif
        
        return *this;
    }
    inline String &String::operator +=(uint32 nValue)
    {
        #ifdef WIN32
            if(GetFormat() == Unicode)
                *this += Format(L"%I32u", nValue);
            else
                *this += Format("%I32u", nValue);
        #else
            if(GetFormat() == Unicode)
                *this += Format(L"%u", nValue);
            else
                *this += Format("%u", nValue);
        #endif

        return *this;        
    }
    inline String &String::operator +=(uint64 nValue)
    {
        #ifdef WIN32
            if(GetFormat() == Unicode)
                *this += Format(L"%I64u", nValue);
            else
                *this += Format("%I64u", nValue);
        #else
            if(GetFormat() == Unicode)
                *this += Format(L"%llu", nValue);
            else
                *this += Format("%llu", nValue);
        #endif

        return *this;
    }
    inline String &String::operator +=(float fValue)
    {
        if(GetFormat() == Unicode)
            *this += Format(L"%g", fValue);
        else
            *this += Format("%g", fValue);
        return *this;        
    }
    inline String &String::operator +=(double dValue)
    {
        if(GetFormat() == Unicode)
            *this += Format(L"%g", dValue);
        else
            *this += Format("%g", dValue);
        return *this;
    }

} // LupineCore