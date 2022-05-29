#ifndef __LPCORE_REFCOUNT_PTR_H__
#define __LPCORE_REFCOUNT_PTR_H__
#pragma once

#include "LupineCore/Core/RefCount.h"

namespace LupineCore
{
  template <class AType>
  class RefCountPtr : public RefCount<AType>
  {
    public:
      RefCountPtr(AType *pPointer);
      virtual ~RefCountPtr();
      virtual const AType *GetPointer() const override;
		  virtual AType *GetPointer() override;

    private:
      AType *m_pPointer;
  };
} // LupineCore

#include "LupineCore/Core/RefCountPtr.inl"

#endif // __LPCORE_REFCOUNT_PTR_H__
