/**
 * File              : ConfigLoaderLP.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 27.05.2022
 * Last Modified Date: 27.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __LPCORE_CONFIGLOADER_LP_H__
#define __LPCORE_CONFIGLOADER_LP_H__
#pragma once

#include "LupineCore/Config/ConfigLoader.h"

namespace LupineCore
{
	class Config;
	class XmlElement;
	class ConfigGroup;
	class ConfigLoaderLP : public ConfigLoader
	{
		lp_class(LPCORE_RTTI_EXPORT, ConfigLoaderLP, "LupineCore", LupineCore::ConfigLoader, "Config loader implementation for the Lupine config XML file format")
			lp_properties
				lp_property("Formats", "cfg,CFG")
				lp_property("Load", "1")
				lp_property("Save", "1")
			lp_properties_end

			lp_constructor_0(DefaultConstructor, "Default constructor", "")
			
			lp_method_2(Load, lp_ret_type(bool), Config&, File&, "Load method", "")
			lp_method_2(Save, lp_ret_type(bool), const Config&, File&, "Save method. Saves all configuration group and includes default values, too.", "")
			lp_method_4(SaveParams, lp_ret_type(bool), const Config&, File&, String, bool, "Save method. Parameters: Configuration group to save as 'String', no default values as 'bool'.", "")
		lp_class_end

		

		public:
			LPCORE_API bool Load(Config &cConfig, File &cFile);
			LPCORE_API bool Save(const Config &cConfig, File, &cFile);
			LPCORE_API bool SaveParams(const Config &cConfig, File &cFile, String sGroup, bool bNoDefault);

		public:
			LPCORE_API ConfigLoaderLP();
			LPCORE_API virtual ~ConfigLoaderLP();

		private:
			bool LoadV1(Config &cConfig, const XmlElement &cConfigElement) const;
			bool SaveGroup(XmlElement &cConfigElement, const ConfigGroup &cGroup, bool bNoDefault = false) const;
	};

} // LupineCore

#endif // __LPCORE_CONFIGLOADER_LP_H__
