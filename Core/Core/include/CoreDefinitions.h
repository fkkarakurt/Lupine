/**
 * File              : CoreDefinitions.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 26.05.2022
 * Last Modified Date: 26.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __CORE_DEFINITIONS_H__
#define __CORE_DEFINITIONS_H__
#pragma once

#include "Core/Core.h"

namespace LupineCore
{
	enum ETypeID
	{
		TypeInvalid = -1,
		TypeNull = 0,
		TypeVoid,
		TypeBool,
		TypeInt,
		TypeFloat,
		TypeDouble,
		TypeInt8,
		TypeInt16,
		TypeInt32,
		TypeInt64,
		TypeUInt8,
		TypeUInt16,
		TypeUInt32,
		TypeUInt64,
		TypeString,
		TypePtr,
		TypeRef,
		TypeObjectPtr
	};

	enum EMemberType
	{
		MemberAttribute = 0,
		MemberMethod,
		MemberConstructor,
		MemberEvent,
		MemberEventHandler
	};

	enum EDefaultValue
	{
		WithDefault = 0,
		NoDefault
	};

	enum ERecursive
	{
		NonRecursive = 0,
		Recursive
	};

	enum EIncludeBase
	{
		IncludeBase = 0,
		NoBase
	};

	enum EIncludeAbstract
	{
		IncludeAbstract = 0,
		NoAbstract
	};

}

#endif //__CORE_DEFINITIONS_H__
