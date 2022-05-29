#ifndef __LPCORE_XML_BASE_H__
#define __LPCORE_XML_BASE_H__
#pragma once

#include "LupineCore/String/String.h"

namespace LupineCore
{
  class File;
  class XmlParsingData;

  class XmlBase
  {
    friend class XmlParsingData;

    public:
      enum
      {
        NoError,
        Error,
        ErrorOpeningFile,
        ErrorParsingElement,
        ErrorFailedToReadElementName,
        ErrorReadingElementValue,
        ErrorReadingAttributes,
        ErrorParsingEmpty,
        ErrorReadingEndTag,
        ErrorParsingUnknown,
        ErrorParsingComment,
        ErrorParsingDeclaration,
        ErrorDocumentEmpty,
        ErrorEmbeddedNull,
        ErrorParsingCData,
        ErrorDocumentTopOnly,
        ErrorStringCount
      };

      enum EQueryResult
      {
        Success,
        NoAttribute,
        WrongType
      };

      enum EEncoding
      {
        EncodingUnknown,
        EncodingUTF8,
        EncodingLegacy
      };

    public:
      static inline bool IsWhiteSpaceCondensed();
      static inline void SetCondenseWhiteSpace(bool bCondense);

    public:
      LPCORE_API virtual ~XmlBase();
      inline int GetRow() const;
      inline int GetColumn() const;
      inline void *GetUserData() const;
      inline void SetUserData(void *pUser);

    public:
      virtual bool Save(File &cFile, uint32 nDepth = 0) = 0;
      virtual String ToString(uint32 nDepth = 0) const = 0;
      virtual const char *Parse(const char *pszData, XmlParsingData *pData = nullptr, EEncoding nEncoding = EncodingUnknown) = 0;

    protected:
      struct Cursor
      {
        Cursor()
        {
          nRow = nColumn = -1;
        }
        void Clear()
        {
          nRow = nColumn = -1;
        }
        int nRow;
        int nColumn;
      };

      static const unsigned char UTF_LEAD_0 = 0xefU;
      static const unsigned char UTF_LEAD_1 = 0xbbU;
      static const unsigned char UTF_LEAD_2 = 0xbfU;

    protected:
      static const char *SkipWhiteSpace(const char *pszData, EEncoding nEncoding);
      static bool IsWhiteSpace(char c);
      static bool IsWhiteSpace(int c);
      static const char *ReadName(const char *pszData, String &sName, EEncoding nEncoding);
      static const char *ReadText(const char *pszData, String &sText, bool bTrimWhiteSpace, const char *pszEndTag, bool bCaseInsensitive, EEncoding nEncoding);
      static const char *GetEntity(const char *pszData, char *pszValue, int &nLength, EEncoding nEncoding);
      static const char *GetChar(const char *pszData, char *pszValue, int &nLength, EEncoding nEncoding);
      static bool StringEqual(const char *pszData, const char *pszTag, bool bIgnoreCase, EEncoding nEncoding);
      static int IsAlpha(unsigned char nByte);
      static int IsAlphaNum(unsigned char nByte);
      static int ToLower(int nValue, EEncoding nEncoding);
      static void ConvertUTF32ToUTF8(unsigned long nInput, char *pszOutput, int &nLength);
      static void EncodeString(const String &sInString, String &sOutString);

    protected:
      XmlBase();

    protected:
      void   *m_pUserData;
      Cursor  m_cCursor;

    private:
      XmlBase(const XmlBase &cSource);
      XmlBase &operator =(const XmlBase &cSource);

    private:
      static const int utf8ByteTable[256];
      struct Entity
      {
        String sString;
        char nCharacter;
      };
      enum
      {
        NumOfEntities = 5
      };
      static Entity sEntity[NumOfEntities];
      static LPCORE_API bool bCondenseWhiteSpace;
  };
} // LupineCore

#include "LupineCore/Xml/XmlBase.inl"

#endif // __LPCORE_XML_BASE_H__
