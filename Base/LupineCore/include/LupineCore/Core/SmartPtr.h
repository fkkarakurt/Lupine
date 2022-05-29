#ifndef __LPCORE_SMARTPTR_H__
#define __LPCORE_SMARTPTR_H__
#pragma once

namespace LupineCore
{
  template <class AType> class RefCount;
  template <class AType>

  class SmartPtr
  {
    public:
      SmartPtr();
      SmartPtr(AType *pPtr);
      SmartPtr(const SmartPtr<AType> &pPtr);
      ~SmartPtr();
      SmartPtr<AType> &operator =(AType *pPtr);
      SmartPtr<AType> &operator =(const SmartPtr<AType> &cPtr);
      AType *GetPointer() const;
      AType *operator ->() const;
      operator AType*() const;
      bool operator !() const;
      bool operator ==(AType *pPtr) const;
      bool operator ==(const SmartPtr<AType> &cPtr) const;
      bool operator !=(AType *pPtr) const;
      bool operator !=(const SmartPtr<AType> &cPtr) const;

    private:
      void SetPtr(void *pPtr);
      void SetPtr(RefCount<AType> *pPtr);
      RefCount<AType> *GetPtr() const;

    private:
      RefCount<AType> *m_pPtr;
  };
} // LupineCore

#include "LupineCore/Core/SmartPtr.inl"

#endif // __LPCORE_SMARTPTR_H__
