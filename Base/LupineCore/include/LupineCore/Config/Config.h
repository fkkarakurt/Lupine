/**
 * File              : Config.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 27.05.2022
 * Last Modified Date: 27.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __LPCORE_CONFIG_H__
#define __LPCORE_CONFIG_H__
#pragma once

#include "LupineCore/Base/Object.h"
#include "LupineCore/Tools/Loadable.h"

namespace LupineCore
{
	class ConfigGroup : public Object
	{
		friend class Config;
		lp_class(LPCORE_RTTI_EXPORT, ConfigGroup, "LPCORE", LPCORE::Object, "Configuration group")
		lp_class_end

		protected:
			LPCORE_API ConfigGroup();
			LPCORE_API virtual ~ConfigGroup();
	};


	class Config : public Loadable
	{
		public:
			LPCORE_API Config();
			LPCORE_API virtual ~Config();
			LPCORE_API String GetVar(const String &sClass, const String &sVariable);
			LPCORE_API int GetVarInt(const String &sClass, const String &sVariable);
			LPCORE_API bool SetVar(const String &sClass, const String &sVariable, const String &sValue, = "");
			LPCORE_API bool SetDefault(const String &sClass = "", const String &sVariable = "");
			
			inline uint32 GetNumOfClasses() const;
			inline ConfigGroup *GetClassByIndex(uint32 nIndex) const;
			LPCORE_API ConfigGroup *GetClass(const String &sName);

		private:
			Config(const Config &cSource);
			Config &operator = (const Config &cSource);
			bool SetClassDefault(const String &sClass, const String &sVariable);

		private:
			LPCORE_API virtual String GetLoadableTypeName() const override;
	};

} // LupineCore
