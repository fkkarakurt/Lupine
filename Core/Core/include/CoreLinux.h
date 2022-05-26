/**
 * File              : Linux.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 26.05.2022
 * Last Modified Date: 26.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __CORE_LINUX_H__
#define __CORE_LINUX_H__
#pragma once

#define LP_WARNING_PUSH
#define LP_WARNING_POP
#define LP_WARNING_DISABLE(WarningID)

#include <stddef.h>
#include <stdint.h>

#if (__GNUC__ == 4 && __GNUC_MINOR__ == 5 && __GNUC_PATCHLEVEL__ < 3)
	#error "Please use a newer or older GCC version instead."
#elif ((__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 6)) && !defined(__clang__))

const class
{
	public:
		template<class T> operator T*() const {return 0;}
		template<class C, class T> operator T C::*() const {return 0;}
	private:
		void operator&() const;
} nullptr = {};

#endif

#if ((__GNUC__ < 4 || __GNUC_MINOR__ < 7) && !defined(__clang__))
	#define override
#endif

#if defined(HAVE_VISIBILITY_ATTR)
	#define LP_GENERIC_API_EXPORT __attribute__((visibility("default")))
#else
	#define LP_GENERIC_API_EXPORT
#endif


#define LP_GENERIC_RTTI_EXPORT 1
#define LP_GENERIC_API_IMPORT

#if defined(HAVE_VISIBILITY_ATTR) && !defined(ALWAYS_RTTI_EXPORT)
	#define LP_GENERIC_RTTI_IMPORT 0
#else
	#define LP_GENERIC_RTTI_IMPORT 1
#endif



#if defined(HAVE_VISIBILITY_ATTR) && !defined(CORE_STATIC)
	#define CORE_TMPL __attribute__ ((visibility("default")))
	#define CORE_PLUGIN_API __attribute__ ((visibility("define")))
#else
	#define CORE_TMPL
	#define CORE_PLUGIN_API
#endif




namespace LupiceCore
{
	typedef char int8;
	typedef unsigned char uint8;
	typedef short int16;
	typedef unsigned short uint16;
	typedef int int32;
	typedef unsigned int uint32;
	typedef int64_t int64;
	typedef uint64_t uint64;

	#if X64_ARCHITECTURE
		typedef uint64_t uint_ptr;
		typedef uint64_t handle;
	#else
		typedef unsigned int uint_ptr;
		typedef unsigned int handle;
	#endif
}


static const Core::handle NULL_HANDLE = 0;
static const Core::handle INVALID_HANDLE = -1;

#endif // __CORE_LINUX_H__
