/**
 * File              : LupineCore.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 27.05.2022
 * Last Modified Date: 27.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __LPCORE_H__
#define __LPCORE_H__
#pragma once


// For Windows Platform
#ifdef WIN32
		#include "LupineCore/LupineCoreWindows.h"
#endif //WIN32


// For Linux Platform
#ifdef LINUX
	#include "LupineCore/LupineCoreLinux.h"
#endif //LINUX


#ifdef LPCORE_STATIC
	#define LPCORE_API
	#define LPCORE_RTTI_EXPORT 1
#elif defined(LPCORE_EXPORTS)
	#define LPCORE_API LP_GENERIC_API_EXPORT
	#define LPCPORE_RTTI_EXPORT LP_GENERIC_RTTI_EXPORT
#else
	#define LPCORE_API LP_GENERIC_API_IMPORT
	#define LPCORE_RTTI_EXPORT LP_GENERIC_RTTI_IMPORT
#endif

#endif //__LPCORE_H__