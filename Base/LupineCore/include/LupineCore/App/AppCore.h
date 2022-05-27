/**
 * File              : AppCore.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 27.05.2022
 * Last Modified Date: 27.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __LPCORE_CONSOLE_APPLICATION_H__
#define __LPCORE_CONSOLE_APPLICATION_H__
#pragma once

#include "LupineCore/Base/Object.h"
#include "LupineCore/Tools/Version.h"
#include "LupineCore/Tools/Commandline.h"
#include "LupineCore/Core/AbstractLifeCycle.h"
#include "LupineCore/App/AppContext.h"
#include "LupineCore/Config/Config.h"

namespace LupineCore
{
	class AppCore : public Object, protected AbstractLifeCycle
	{
		lp_class(LPCORE_RTTI_EXPORT, AppCore, "LPCORE", LPCORE::Object, "Application Class")
				#ifdef LPCORE_EXPORTS
					lp_constructor_0(DefaultConstructor, "Default Constructor", "")
					lp_method_0(GetAppContext, lp_ret_type(const AppContext&), 
					lp_method_1(Exit, lp_ret_type(void),
				#endif

						
		lp_class_end

		public:
			enum ESignal
			{
				SignalInterrupt = 1,
				SignalTerm
			};

		public:
			static inline AppCore *GetApplication();

		private:
			static LPCORE_API AppCore *g_pApplication;
		
		public:
			LPCORE_API AppCore();
			LPCORE_API virtual ~AppCore();
			inline const AppContext &GetAppContext() const;
			inline String GetName() const;
			LPCORE_API void SetName(const String &sName);
			inline String GetTitle() const;
			inline void SetTitle(const String &sTitle);
			inline const Version &GetVersion() const;
			inline void SetVersion(const Version &cVersion);
			inline bool GetMultiUser() const;
			inline void SetMultiUser(bool bMultiUser);
			inline String GetConfigName() const;
			inline void SetConfigName(const String &sConfigName);
			inline String GetLogName() const;
			inline void SetLogName(const String &sLogName);
			inline String GetAppDataSubdir() const;
			inline void SetAppDataSubdir(const String &sSubdir);
			inline Config &GetConfig();
			inline bool IsRunning() const;
			inline void Exit(int nResult);
			LPCORE_API int Run(const String &sExecutableFilename, const Array<String>, &lstArguments);

		protected:
			LPCORE_API virtual void OnCreate() override;
			LPCORE_API virtual void OnRestart() override;
			LPCORE_API virtual bool OnStart() override;
			LPCORE_API virtual void OnResume() override;
			LPCORE_API virtual void OnPause() override;
			LPCORE_API virtual void OnStop() override;
			LPCORE_API virtual void OnDestroy() override;

		protected:
			LPCORE_API virtual void Main();
			LPCORE_API virtual void OnInitLog();
			LPCORE_API virtual void OnInitCmdLine();
			LPCORE_API virtual void OnInitConfig();
			LPCORE_API virtual void OnInitPlugins();
			LPCORE_API virtual void OnInitData();
			LPCORE_API virtual void OnInit();
			LPCORE_API virtual void OnDeInit();
			LPCORE_API virtual void OnFirstProgramStart();
			LPCORE_API virtual void OnPrintHelp();
			LPCORE_API virtual void OnPrintVersion();
			LPCORE_API virtual bool OnSigma(ESignal nSignal);

		private:
			static void SignalHandler(int nSignal);

		protected:
			AppContext m_cAppContext;
			String m_sName;
			String m_sTitle;
			Version m_cVersion;
			bool m_bMultiUser;
			String m_sConfigName;
			String m_sLogName;
			String m_sAppDataSubdir;
			Config m_cConfig;
			Commandline m_cCommandline;
			bool m_bRunning;
			int m_nResult;
	};

} // LupineCore

#include "LupineCore/App/AppCore.inl"

#endif // __LPCORE_CONSOLE_APPLICATION_H__
