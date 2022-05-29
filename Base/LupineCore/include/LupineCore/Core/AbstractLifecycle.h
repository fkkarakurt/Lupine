#ifndef __LPCORE_ABSTRACTLIFECYCLE_H__
#define __LPCORE_ABSTRACTLIFECYCLE_H__
#pragma once

namespace LupineCore
{
  class AbsractLifecycle
  {
    public:
      virtual void OnCreate() = 0;
      virtual void OnRestart() = 0;
      virtual bool OnStart() = 0;
      virtual void OnResume() = 0;
      virtual void OnPause() = 0;
      virtual void OnStop() = 0;
      virtual void OnDestroy() = 0;

    protected:
      AbstractLifecycle();
      virtual ~AbsractLifecycle();

    private:
      AbstractLifecycle(const AbstractLifecycle &cSource);
      AbstractLifecycle &operator =(const AbstractLifecycle &cSource);
  };
} // LupineCore

#endif // __LPCORE_ABSTRACTLIFECYCLE_H__
