#ifndef __LPCORE_SINGLETON_H__
#define __LPCORE_SINGLETON_H__
#pragma once

#include "LupineCore/LupineCore.h"

LP_WARNING_PUSH
LP_WARNING_DISABLE(4251)

namespace LupineCore
{
  template <class AType> class LPCORE_TMPL Singleton
  {
    public:
      static AType *GetInstance();
      static bool HasInstance();

    protected:
      Singleton();
      virtual ~Singleton();

    private:
      class __Destruction_Guard
      {
        public:
          __Destruction_Guard()
          {

          }
          ~__Destruction_Guard()
          {
            if(Singleton<AType>::__Instance)
            {
              delete static_cast<Singleton<AType>*>(Singleton<AType>::__Instance);
            }
          }
          inline void init()
          {

          }
      };

      static __Destruction_Guard __Guard;
      static AType *__Instance;
      static bool __Destroyed;

      Singleton(const Singleton&);
      Singleton& operator =(Singleton);

  };
} // LupineCore

#include "LupineCore/Singleton.inl"

LP_WARNING_POP

#endif // __LPCORE_SINGLETON_H__
