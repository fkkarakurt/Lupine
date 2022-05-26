/**
 * File              : LinuxWrapper.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 26.05.2022
 * Last Modified Date: 26.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __CORE_LINUXWRAPPER_H__
#define __CORE_LINUXWRAPPER_H__
#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include "Core/Core.h"

CORE_API char *_strupr(char *s);
CORE_API char *strlwr(char *s);
CORE_API int _vscprintf(const char *format, va_list ap);

CORE_API int _vscwprintf(const wchar_t, *fmt, va_list ap);
CORE_API int _vsnwprintf(wchar_t *buf, size_t cnt, const wchar_t *fmt, va_list args);
CORE_API int _wtoi(const wchar_t *str);
CORE_API long _wtol(const wchar_t *str);
CORE_API float _wtof(const wchar_t *str);
CORE_API wchar_t *_wcsupr(const wchar_t *s);
CORE_API wchar_t *_wcslwr(wchar_t *s);

#if (ANDROID || APPLE)
	CORE_API int wcscasecmp(const wchar_t *s1, const wchar_t *s2);
	CORE_API int wcsncasecmp(const wchar_t *s1, const wchar_t *s2, size_t n);
	CORE_API uintmax_t wcstoumax(const wchar_t *nptr, wchar_t **endptr, int base);
#endif

#define stricmp(a, b) strcasecmp(a, b)
#define _stricmp(a, b) strcasecmp(a, b)
#define _strnicmp(a, b, n) strncasecmp(a, b, n)
#define strnicmp(a, b, n) strncasecmp(a, b, n)
#define _strlwr(a) strlwr(a)
#define _atoi64(a) atoll(a)
#define _snprintf snprintf
#define _wcsicmp(a, b) wcscasecmp(a, b)
#define _wcsnicmp(a, b, c) wcsncasecmp(a, b, c)
#undef vswprintf
#define vswprintf _vsnwprintf
#define _fdopen(a, b) fdopen(a, b)

#endif // __CORE_LINUXWRAPPER_H__
