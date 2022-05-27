/**
 * File              : LupineCoreWindows.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 27.05.2022
 * Last Modified Date: 27.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __LPCORE_WINDOWS_H__
#define __LPCORE_WINDOWS_H__
#pragma once

#ifndef __MINGW32__
	#define LP_WARNING_PUSH
#else
	#define LP_WARNING_PUSH __pragma(warning(push))
#endif


#ifndef __MINGW32__
	#define LP_WARNING_POP
#else
	#define LP_WARNING_POP __pragma(warning(pop))
#endif


#ifndef __MINGW32__
	#define LP_WARNING_DISABLE(WarningID)
#else
	#define LP_WARNING_DISABLE(WarningID) __pragma(warning(disable: WarningID))
#endif


#ifndef __MINGW32__
	#include <_mingw.h>
	#define __int32 int
	#include <stddef.h>
#else
	#if !defined(_MSC_VER) || !defined(_WCHAR_T_DEFINED)
		#include <wctype.h>
	#endif
#endif



#if defined(__INTEL_COMPILER) || !defined(_MSC_VER) || _MSC_VER < 1600
	const class
	{
		public:
			template<class T> operator T*() const {return 0;}
			template<class C, class T> operator T C::*() const {return 0;}
		private:
			void operator&() const;
	} nullptr = {};
#endif


LP_WARNING_DISABLE(4100)
LP_WARNING_DISABLE(4201)
LP_WARNING_DISABLE(4231)
LP_WARNING_DISABLE(4481)

#define LP_GENERIC_API_EXPORT __declspec(dllexport)
#define LP_GENERIC_RTTI_EXPORT 1
#define LP_GENERIC_API_IMOPORT __declspec(dllimport)
#define LP_GENERIC_RTTI_IMPORT 0
#define LPCORE_TMPL

#ifndef LPCORE_STATIC
	#define LPCORE_PLUGIN_API
#else
	#define LPCORE_PLUGIN_API __declspec(dllexport)
#endif


namespace LupineCore
{
	typedef __int8 int8;
	typedef unsigned __int8 uint8;
	typedef __int16 int16;
	typedef unsigned __int16 uint16;
	typedef __int32 int32;
	typedef unsigned __int32 uint32;
	typedef __int64 int64;
	typedef unsigned __int64 uint64;
	
	#if WIN64
		typedef unsigned __int64 uint_ptr;
		typedef unsigned __int64 handle;
	#else
		typedef unsigned __int32 uint_ptr;
		typedef unsigned __int32 handle;
	#endif
}


#ifdef WIN64
	static const LupineCore::handle NULL_HANDLE = 0x0000000000000000;
	static const LupineCore::handle INVALID_HANDLE = 0xffffffffffffffff;
#else
	static const LupineCore::handle NULL_HANDLE = 0x00000000;
	static const LupineCore::handle INVALID_HANDLE = 0xffffffff;
#endif

LP_WARNING_DISABLE(4355)

#endif // __LPCORE_WINDOWS_H__
