#include "LupineCore/Core/RefCountPtr.h"

namespace LupineCore
{
  template <class AType>
  SmartPtr<AType>::SmartPtr() : m_pPtr(nullptr)
  {

  }

  template <class AType>
  SmartPtr<AType>::SmartPtr(AType *pPtr) : m_pPtr(nullptr)
  {
    SetPtr(pPtr);
  }

  template <class AType>
  SmartPtr<AType>::SmartPtr(const SmartPtr<AType> &pPtr) : m_pPtr(nullptr)
  {
    SetPtr(pPtr.GetPtr());
  }

  template <class AType>
  SmartPtr<AType>::~SmartPtr()
  {
	  SetPtr(static_cast<RefCount<AType>*>(nullptr));
  }

  template <class AType>
  SmartPtr<AType> &SmartPtr<AType>::operator =(AType *pPtr)
  {
    if(GetPointer() != pPtr)
      SetPtr(pPtr)
    return *this;
  }

  template <class AType>
  SmartPtr<AType> &SmartPtr<AType>::operator =(const SmartPtr<AType> &cPtr)
  {
    if(GetPointer() != cPtr.GetPointer())
      SetPtr(cPtr.GetPtr());
    return *this;
  }

  template <class AType>
  AType *SmartPtr<AType>::GetPointer() const
  {
    return m_pPtr ? m_pPtr->GetPointer() : nullptr;
  }

  template <class AType>
  AType *SmartPtr<AType>::operator ->() const
  {
    return GetPointer();
  }

  template <class AType>
  SmartPtr<AType>::operator AType*() const
  {
    return GetPointer();
  }

  template <class AType>
  bool SmartPtr<AType>::operator !() const
  {
    return (GetPointer() == nullptr);
  }

  template <class AType>
  bool SmartPtr<AType>::operator ==(AType *pPtr) const
  {
    return (GetPointer() == pPtr);
  }

  template <class AType>
  bool SmartPtr<AType>::operator ==(const SmartPtr<AType> &cPtr) const
  {
	  return (GetPointer() == cPtr.GetPointer());
  }

  template <class AType>
  bool SmartPtr<AType>::operator !=(AType *pPtr) const
  {
	  return (GetPointer() != pPtr);
  }

  template <class AType>
  bool SmartPtr<AType>::operator !=(const SmartPtr<AType> &cPtr) const
  {
	  return (GetPointer() != cPtr.GetPointer());
  }

  template <class AType>
  void SmartPtr<AType>::SetPtr(void *pPtr)
  {
	  SetPtr(pPtr ? new RefCountPtr<AType>(static_cast<AType*>(pPtr)) : static_cast<RefCount<AType>*>(nullptr));
  }

  template <class AType>
  void SmartPtr<AType>::SetPtr(RefCount<AType> *pPtr)
  {
	  if (m_pPtr)
		  m_pPtr->Release();
	  if (pPtr)
		  pPtr->AddReference();
	  m_pPtr = pPtr;
  }

  template <class AType>
  RefCount<AType> *SmartPtr<AType>::GetPtr() const
  {
	  return m_pPtr;
  }

} // LupineCore
