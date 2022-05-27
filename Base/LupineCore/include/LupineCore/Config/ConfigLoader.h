/**
 * File              : ConfigLoader.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 27.05.2022
 * Last Modified Date: 27.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __LPCORE_CONFIGLOADER_H__
#define __LPCORE_CONFIFLOADER_H__
#pragma once

#include "LupineCore/Tools/LoaderImpl.h"

namespace LupineCore
{
	class ConfigLoader : public LoaderImpl
	{
		friend class Config;
		lp_class(LPCORE_RTTI_EXPORT, ConfigLoader, "LupineCore", LupineCore::LoaderImpl, "Abstract config loader base class")
			lp_properties
				lp_property("Type", "Config")
			lp_properties_end
		lp_class_end

		protected:
			LPCORE_API ConfigLoader();
			LPCORE_API virtual ~ConfigLoader();

	};

} // LupineCore
 
#endif // __LPCORE_CONFIGLOADER_H__
