/**
 * File              : Iterator.inl
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 27.05.2022
 * Last Modified Date: 27.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

namespace LupineCore
{
	template <class ValueType>
		Iterator<ValueType>::Iterator(IteratorImpl<ValueType> &cIteratorImpl) : m_pIteratorImpl(&cIteratorImpl)
			{
				m_pIteratorImpl->AddReference();
			}

	template <class ValueType>
		Iterator<ValueType>::Iterator(const Iterator<ValueType> &cIterator) : m_pIteratorImpl(cIterator.m_pIteratorImpl)
	{
		m_pIteratorImpl->AddReference();
	}

	template <class ValueType>
		Iterator<ValueType>::~Iterator()
		{
			m_pIteratorImpl->Release();
		}

	template <class ValueType>
		Iterator<ValueType> &Iterator<ValueType>::operator = (const Iterator<ValueType> &cIterator)
		{
			if(&cIterator != this)
			{
				m_pIteratorImpl->Release();
				m_pIteratorImpl =  cIterator.m_pIteratorImpl;
				m_pIteratorImpl->AddReference();
			}
		
			return *this;
		}


	template <class ValueType>
		bool Iterator<ValueType>::HasNext() const
		{
			return m_pIteratorImpl->HasNext();
		}

	template <class ValueType>
		ValueType &Iterator<ValueType>::Next()
		{
			UniqueImplementation();
			return m_pIteratorImpl->Next();
		}

	template <class ValueType>
		ValueType &Iterator<ValueType>::operator ++()
		{
			UniqueImplementation();
			return m_pIteratorImpl->Next();
		}


	template <class ValueType>
		bool Iterator<ValueType>::HasPrevious() const
		{
			return m_pIteratorImpl->HasPrevious();
		}


	template <class ValueType>
		ValueType &Iterator<ValueType>::Previous()
		{
			UniqueImplementation();
			return m_pIteratorImpl->Previous();
		}


	template <class ValueType>
		ValueType &Iterator<ValueType>::operator --()
		{
			UniqueImplementation();
			return m_pIteratorImpl->Previous();
		}


	template <class ValueType>
		void Iterator<ValueType>::UniqueImplementation()
		{
			if(m_pIteratorImpl->GetRefCount() > 1)
			{
				m_pIteratorImpl->Release();
				m_pIteratorImpl = m_pIteratorImpl->Clone();
				m_pIteratorImpl->AddReference();
			}
		}

} // LupineCore	
