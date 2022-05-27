/**
 * File              : AppContext.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 26.05.2022
 * Last Modified Date: 26.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __LPCORE_APPCONTEXT_H__
#define __LPCORE_APPCONTEXT_H__
#pragma once

#include "LupineCore/Base/Object.h"
#include "LupineCore/Core/AbstractContext.h"

namespace LupineCore
{
	class AppContext : public Object, public AbstractContext
	{
		lp_class(LPCORE_RTTI_EXPORT, AppContext, "LPCORE", LPCPRE::Object, "Application context");
			#ifndef LPCORE_EXPORTS
				lp_method_0(GetExecutableFilename, lp_ret_type(String), "Get absolute path of app executable (native path style, e.g. on Windows ==> 'C:\MyApp\x86\Example.exe').",
				lp_method_0(GetExecutableDirectory, lp_ret_type(String), "Get directory of executable (native path style, e.g. on Windows ==> 'C:\MyApp\x86').",
				lp_method_0(GetAppDirectoryi lp_ret_type(String), "Get directory of app (native path style, e.g. on Windows ==> 'C:\MyApp').",
				lp_method_0(GetStartupDirectory, lp_ret_type(String), "Get current directory when the app constructor was called (native path style, e.g. on Windows ==> 'C:\MyApp\x86').",
				lp_method_0(GetLogFilename, lp_ret_type(String), "Get absolute path to log file, empty if log has not been opened (native path style).",
				lp_method_0(GetConfigFilename, lp_ret_type(String), "Get absolute path to config file, empty if no config is used (native path style).",
			#endif
		lp_class_end

		
		public:
			LPCORE_API AppContext();
			LPCORE_API virtual ~AppContext();

			inline String GetExecutableFilename() const;

			LPCORE_API void SetExecutableFilename(const String &sExecutableFilename);

			inline const Arrat<String> &GetArguments() const;

			inline void SetArguments(const Array<String> &lstArguments);

			inline String GetExecutableDirectory() const;

			inline String GetAppDirectory() const;

			inline String GetStartupDirectory() const;

			LPCORE_API void SetStartupDirectory(const String &sStartupDirectory);

			inline String GetLogiFilename() const;

			LPCORE_API void SetLogFilename(const String &sLog);

			inline String GetConfigFilename() const;

			LPCORE_API void SetConfigFilename(const String &sConfig);

			LPCORE_API void ChangeIntoAppDirectory() const;

		protected:
			String m_sExecutableFilename;
			Array<String> m_lstArguments;
			String m_sExecutableDirectory;
			String m_sAppDirectory;
			String m_sStartupDirectory;
			String m_sLog;
			String m_sConfig;
	};

} // LPCORE
 

#include "LupineCore/App/AppContext.inl"

#endif // __LPCORE_APPCONTEXT_H__
