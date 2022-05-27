/**
 * File              : AppContext.inl
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 27.05.2022
 * Last Modified Date: 27.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

namespace LupineCore
{

	inline String AppContext::GetExecutableFilename() const
	{
		return m_sExecutableFilename;
	}

	inline const Array<String> &AppContext::GetArguments() const
	{
		return m_lstArguments;
	}

	inline void AppContext::SetArguments(const Array<String> &lstArguments)
	{
		m_lstArguments = lstArguments;
	}

	inline String AppContext::GetExecutableDirectory() const
	{
		return m_sExecutableDirectory;
	}

	inline String AppContext::GetAppDirectory() const
	{
		return m_sAppDirectory;
	}

	inline String AppContext::GetStartupDirectory() const
	{
		return m_sStartupDirectory;
	}

	inline String AppContext::GetLogFilename() const
	{
		return m_sLog;
	}

	inline String AppContext::GetConfigFilename() const
	{
		return m_sConfig;
	}

} // LupineCore
