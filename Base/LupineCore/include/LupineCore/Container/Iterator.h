/**
 * File              : Iterator.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 27.05.2022
 * Last Modified Date: 27.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __LPCORE_CONTAINER_ITERATOR_H__
#define __LPCORE_CONTAINER_ITERATOR_H__
#pragma once

namespace LupineCore
{
	template <class ValueType> class IteratorImpl;

	template <class ValueType>
		class Iterator
		{
			public:
				Iterator(IteratorImpl<ValueType> &cIteratorImpl);
				Iterator(const Iterator<ValueType> &cIterator);
				~Iterator<ValueType>();
				Iterator<ValueType> &operator = (const Iterator<ValueType> &cIterator);
				bool HasNext() const;
				ValueType &Next();
				ValueType &operator ++();
				bool HasPrevious() const;
				ValueType &Previous();
				ValueType &operator --();

			private:
				void UniqueImplementation();

			private:
				IteratorImpl<ValueType> *m_pIteratorImpl;
		};

} // LupineCore


#include "LupineCore/Container/Iterator.inl"

#endif // __LPCORE_CONTAINER_ITERATOR_H__
