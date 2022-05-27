/**
 * File              : AppCore.inl
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 27.05.2022
 * Last Modified Date: 27.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

namespace LupineCore
{
	inline AppCore *AppCore::GetApplication()
	{
		return g_pApplication;
	}

	inline const AppContext &AppCore::GetAppContext() const
	{
		return m_cAppContext;
	}

	inline String AppCore::GetName() const
	{
		return m_sName;
	}

	inline String AppCore::GetTitle() const
	{
		return m_sTitle;
	}

	inline void AppCore::SetTitle(const String &sTitle)
	{
		m_sTitle = sTitle;
	}

	inline const Version &AppCore::GetVersion() const
	{
		return m_cVersion;
	}

	inline void AppCore::SetVersion(const Version &cVersion)
	{
		m_cVersion = cVersion;
	}

	inline bool AppCore::GetMultiUser() const
	{
		return m_bMultiUser;
	}

	inline void AppCore::SetMultiUser(bool bMultiUser)
	{
		m_bMultiUser = bMultiUser;
	}

	inline String AppCore::GetConfigName() const
	{
		return m_sConfigName;
	}

	inline void AppCore::SetConfigName(const String &sConfigName)
	{
		m_sConfigName = sConfigName;
	}

	inline String AppCore::GetLogName() const
	{
		return m_sLogName;
	}

	inline void AppCore::SetLogName(const String &sLogName)
	{
		m_sLogName = sLogName;
	}

	inline String AppCore::GetAppDataSubdir() const
	{
		return m_sAppDataSubdir;
	}

	inline void AppCore::SetAppDataSubdir(const String &sSubdir)
	{
		m_sAppDataSubdir = sSubdir;
	}

	inline Config &AppCore::GetConfig()
	{
		return m_cConfig;
	}

	inline bool AppCore::IsRunning() const
	{
		return m_bRunning;
	}

	inline void AppCore::Exit(int nResult)
	{
		m_nResult = nResult;
		m_bRunning = false;
	}

} // LupineCore		
