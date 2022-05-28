/**
 * File              : StringBufferManager.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 28.05.2022
 * Last Modified Date: 28.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __LPCORE_STRINGBUFFERMANAGER_H__
#define __LPCORE_STRINGBUFFERMANAGER_H__
#pragma once

#include "LupineCore/LupineCore.h"

namespace LupineCore
{
    class StringBuffer;
    class StringBufferUTF8;
    class StringBufferASCII;
    class StringBufferUnicode;

    class StringBufferManager
    {
        friend class String;
        friend class StringBuffer;
        friend class StringBufferUTF8;
        friend class StringBufferASCII;
        friend class StringBufferUnicode;

        private:
            static const uint32 NumOfReservedCharacters = 64;
            static const uint32 MaxStringReuseLength = 256;
            static const uint32 MaxStringsPerReuseLength = 4;

        private:
            StringBufferManager();
            ~StringBufferManager();
            StringBufferASCII *GetStringBufferASCII(uint32 nLength);
            StringBufferUnicode *GetStringBufferUnicode(uint32 nLength);
            LPCORE_API void ReleaseStringBuffer(StringBuffer &cStringBuffer);

        private:
            StringBufferASCII **m_pStringBufferASCII;
            StringBufferUnicode **m_pStringBufferUnicode;
    };

} // LupineCore

#endif // _LPCORE_STRINGBUFFERMANAGER_H__