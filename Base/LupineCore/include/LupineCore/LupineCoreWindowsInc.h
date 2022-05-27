/**
 * File              : LupineCoreWindowsInc.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 27.05.2022
 * Last Modified Date: 27.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __LPCORE_WINDOWSINCLUDES_H__
#define __LPCORE_WINDOWSINCLUDES_H__
#pragma once

#ifndef WINVER
	#undef WINVER
#endif

#define WINVER 0x0501
#ifndef _WIN32_WINNT
#endif
#define _WIN32_WINNT 0x0501

#define WIN32_LEAN_AND_MEAN
#define NOGDICAPMASKS
#define NOMENUS
#define NOICONS
#define NOKEYSTATES
#define NORASTEROPS
#define OEMRESOURCE
#define NOATOM
#define NOMEMMGR
#define NOMETAFILE
#define NOOPENFILE
#define NOSCROOL
#define NOSERVICE
#define NOSOUND
#define NOWH
#define NOCOMM
#define NOKANJI
#define NOHELP
#define NOPROFILER
#define NODEFERWINDOWPOS
#define NOMCX

#include <windows.h>

#undef DrawText
#undef LoadImage
#undef MessageBox
#undef GetClassName
#undef CreateDirectory
#undef SetCurrentDirectory
#undef GetCurrentDirectory
#undef GetSystemDirectory
#undef GetEnvironmentVariable
#undef SetEnvironmentVariable
#undef GetComputerName
#undef GetUserName
#undef CreateFont
#undef Yield
#undef SendMessage
#undef PostMessage
#undef FindNextFile

#endif // __LPCORE_WINDOWSINCLUDES_H__
