#ifndef __LPCORE_REFCOUNT_H__
#define __LPCORE_REFCOUNT_H__
#pragma once

#include "LupineCore/LupineCore.h"

namespace LupineCore
{
  template <class AType>
  class RefCount
  {
    public:
      RefCount();
      virtual ~RefCount();
      virtual const AType *GetPointer() const;
      virtual AType *GetPointer();
      uint32 AddReference();
      uint32 Release();
      uint32 GetRefCount() const;

    private:
      uint32 m_nRefCount;
  };
} // LupineCore

#include "LupineCore/Core/RefCount.inl"

#endif // __LPCORE_REFCOUNT_H__
