#ifndef __LPCORE_CONSOLE_H__
#define __LPCORE_CONSOLE_H__
#pragma once

#include "LupineCore/LupineCore.h"

namespace LupineCore
{
  class String;

  class Console
  {
    public:
      virtual void Print(const String &sString) const = 0;
      virtual int IsKeyHit() const = 0;
      virtual int GetCharacter(bool bEcho = false) const = 0;
      virtual void ClearScreen() const = 0;
      virtual void GetCursorPosition(uint16 &nX, uint16 &nY) const = 0;
      virtual void SetCursorPosition(uint16 nX, uint16 nY) const = 0;

    protected:
      virtual ~Console();

    private:
      Console(const Console &cSource);
      Console &operator =(const Console &cSource);
  };

} // LupineCore

#endif // __LPCORE_CONSOLE_H__
