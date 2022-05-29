#ifndef __LPCORE_CONSOLE_LINUX_H__
#define __LPCORE_CONSOLE_LINUX_H__
#pragme once

#include "LupineCore/System/Console.h"

namespace LupineCore
{
  class ConsoleLinux : public Console
  {
    friend class SystemLinux;

    public:
      virtual void Print(const String &sString) const override;
		  virtual int IsKeyHit() const override;
		  virtual int GetCharacter(bool bEcho = false) const override;
		  virtual void ClearScreen() const override;
		  virtual void GetCursorPosition(uint16 &nX, uint16 &nY) const override;
		  virtual void SetCursorPosition(uint16 nX, uint16 nY) const override;

    protected:
      ConsoleLinux();
      virtual ~ConsoleLinux();
  };
} // LupineCore

#endif // __LPCORE_CONSOLE_LINUX_H__
