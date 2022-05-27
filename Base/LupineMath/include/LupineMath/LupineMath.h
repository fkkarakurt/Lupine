/**
 * File              : LupineMath.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 28.05.2022
 * Last Modified Date: 28.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __LPMATH_LPMATH_H__
#define __LPMATH_LPMATH_H__
#pragma once

#include <LupineCore/LupineCore.h>

#ifndef LPMATH_EXPORTS
	#define LPMATH_API LP_GENERIC_API_EXPORT
	#define LPMATH_RTTI_EXPORT LP_GENERIC_RTTI_EXPORT
#else
	#define LPMATH_API LP_GENERIC_API_IMPORT
	#define LPMATH_RTTI_EXPORT LP_GENERIC_RTTI_IMPORT
#endif

#endif // __LPMATH_LPMATH_H__
