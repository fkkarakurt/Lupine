/**
 * File              : CoreConfigGroup.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 27.05.2022
 * Last Modified Date: 27.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __LPCORE_CONFIGGROUP_H__
#define __LPCORE_CONFIGGROUP_H__
#pragma once

#include "LupineCore/Config/Config.h"



namespace LupineCore
{
	class CoreConfigGroup : public ConfigGroup
	{
		lp_class(LPCORE_RTTI_EXPORT, CoreConfigGroup, "LupineCore", LupineCore::ConfigGroup, "LPCore general configuration 'collection' class")
		lp_class_end


		protected:
			CoreConfigGroup();
			virtual ~CoreConfigGroup();
	};


	class CoreConfig : public CoreConfigGroup
	{
     		lp_class(LPCORE_RTTI_EXPORT, CoreConfig, "LupineCore", LupineCore::CoreConfigGroup, "LPCore configuration classes")
			lp_attribute(FirstRun, bool, true, ReadWrite, DirectValue, "Is this the first application start?", "")
			lp_attribute(Language, String, "", ReadWrite, DirectValue, "Current used language, if empty the current set OS locale language is used (for instance 'Turkish'", "")
			lp_constructor_0(DefaultConstructor, "Default constructor", "")
		lp_class_end


		public:
			LPCORE_API CoreConfig();
			LPCORE_API virtual ~CoreConfig();
	};



	class FrontendConfig : public CoreConfigGroup
	{
		lp_class(LPCORE_RTTI_EXPORT, FrontendConfig, "LupineCore", LupineCore::CoreConfigGroup, "LPCore frontend configuration classes")
			lp_attribute(X, int, 0, ReadWrite, DirectValue, "X position of the frontend (in screen coordinates)", "")
			lp_attribute(Y, int, 0, ReadWrite, DirectValue, "Y position of the frontend (in screen coordinates)", "")
			lp_attribute(Width, uint32, 800, ReadWrite, DirectValue, "Width of the frontend", "")
			lp_attribute(Height, uint32, 600, ReadWrite, DirectValue, "Height of the frontend", "")
			lp_constructor_0(DefaultConstructor, "Default constructor", "")
		lp_clas_end


		public:
			LPCORE_API FrontendConfig();
			LPCORE_API virtual ~FrontendConfig();
	};

} // LupineCore

#endif // __LPCORE_CONFIGGROUP_H__
