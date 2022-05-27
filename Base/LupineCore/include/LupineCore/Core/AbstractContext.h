/**
 * File              : AbstractContext.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 26.05.2022
 * Last Modified Date: 26.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __CORE_ABSTRACTCONTEXT_H__
#define __CORE_ABSTRACTCONTEXT_H__
#pragma once

#include "Core/Core.h"

namespace LupineCore
{
	class AbstractContext
	{
		protected:
			LUPINECORE_API AbstractContext();
			LUPINECORE_API ~AbstractContext();
		private:
			AbstractContext(const AbstractContext &cSource);
			AbstractContext &operator = (const AbstractContext &cSource);
	};
}

#endif //__CORE_ABSTRACTCONTEXT_H__
