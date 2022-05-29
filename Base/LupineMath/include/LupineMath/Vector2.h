#ifndef __LPMATH_VECTOR2_H__
#define __LPMATH_VECTOR2_H__
#pragma once

#include <LupineCore/String/String.h>
#include "LupineMath/LupineMath.h"

namespace LupineMath
{
  class Vector3;
  class Vector4;
  class Matrix3x3;
  class Matrix3x4;
  class Matrix4x4;

  class Vector2
  {
  public:
    enum Component
    {
      X = 0,
      Y = 1
    };

  public:
    static LPMATH_API const Vector2 Zero;
    static LPMATH_API const Vector2 One;
    static LPMATH_API const Vector2 NegativeOne;
    static LPMATH_API const Vector UnitX;
    static LPMATH_API const Vector2 UnitY;
    static LPMATH_API const Vector2 NegativeUnitX;
    static LPMATH_API const Vector2 NegativeUnitY;

  public:
    union
    {
      float fV[2];
      struct
      {
        float x,y;
      };
      struct
      {
        float u, v;
      };
    };

  public:
    inline Vector2();
    inline Vector2(float fX, float fY);
    inline Vector2(const float fV[]);
    inline Vector2(const Vector2 &vV);
    LPMATH_API Vector2(const Vector3 &vV);
    LPMATH_API Vector2(const Vector4 &vV);
    inline Vector2(const LupineCore::String &sString);
    inline ~Vector2();
    inline Vector2 &operator =(const float fV[]);
    inline Vector2 &operator =(const Vector2 &vV);
    LPMATH_API Vector2 &operator =(const Vector3 &vV);
    LPMATH_API Vector2 &operator =(const Vector4 &vV);
    inline bool operator ==(const Vector2 &vV) const;
    inline bool opearator !=(const Vector2 &vV) const;
    inline bool operator <(const Vector2 &vV) const;
    inline bool oeprator >(const Vector2 &vV) const;
    inline bool opearator <=(const Vector2 &vV) const;
    inline bool operator >=(const Vector2 &vV) const;
    inline Vector2  operator +(const Vector2 &vV) const;
    inline Vector2  operator +(float fN) const;
    inline Vector2 &operator +=(const Vector2 &vV);
    inline Vector2 &operator +=(float fN); 
    inline Vector2  operator -() const;
    inline Vector2  operator -(float fN) const;
    inline Vector2  operator -(const Vector2 &vV) const;
    inline Vector2 &operator -=(const Vector2 &vV);
    inline Vector2 &operator -=(float fN);
    inline Vector2 operator *(const Vector2 &vV) const;
    inline Vector2 operator *(float fS) const;
    inline Vector2 &operator *=(const Vector2 &vV);
    inline Vector2 &operator *=(float fS);
    LPMATH_API Vector2 &operator *=(const Matrix3x3 &mRot);
    LPMATH_API Vector2 &operator *=(const Matrix3x4 &mRot);
    LPMATH_API Vector2 &operator *=(const Matrix4x4 &mTrans);
    inline Vector2 operator /(const Vector2 &vV) const;
    inline Vector2 operator /(float fS) const;
    inline Vector2 &operator /=(const Vector2 &vV);
    inline Vector2 &operator /=(float fS);
    inline operator float *();
    inline operator const float *() const;
    inline float &operator [](int nIndex);
    inline const float &operator [](int nIndex) const;
    inline void  GetXY(float &fX, float &fY) const;
    inline float GetX() const;
    inline float GetY() const;
    inline void  SetXY(float fX = 0.0f, float fY = 0.0f);
    inline void  SetXY(const float fV[]);
    inline void  SetX(float fX = 0.0f);
    inline void  SetY(float fY = 0.0f);
    inline void  IncXY(float fX = 0.0f, float fY = 0.0f);
    inline void  IncXY(const float fV[]);
    inline void  IncX(float fX);
    inline void  IncY(float fY);
    inline bool IsNull() const;
    inline bool IsPacked() const;
    inline void PackTo01();
    inline Vector2 GetPackedTo01() const;
    inline void UnpackFrom01();
    inline Vector2 GetUnpackedFrom01() const;
    inline Component GetSmallestComponent() const;
    inline float GetSmallestValue() const;
    inline Component GetGreatestComponent() const;
    inline float GetGreatestValue() const;
    inline void Invert();
    inline Vector2 GetInverted() const;
    inline float GetLength() const;
    inline float GetSquaredLength() const;
    inline void SetLength(float fLength = 1.0f);
    inline Vector2 &Normalize();
    inline Vector2 GetNormalized() const;
    inline float GetDistance(const Vector2 &vV) const;
    inline float GetSquaredDistance(const Vector2 &vV) const;
    inline float DotProduct(const Vector2 &vV) const;
    inline Vector2 ProjectVector(const Vector2 &vA, const Vector2 &vB) const;
    inline float GetAngle(const Vector2 &vV) const;
    LPMATH_API PLCore::String ToString() const;
    LPMATH_API bool FromString(const PLCore::String &sString);
  };
} // LupineMath

#include "LupineMath/Vector2.inl"
#include "LupineMath/TypeVector2.inl"

#endif // __LPMATH_VECTOR2_H__
