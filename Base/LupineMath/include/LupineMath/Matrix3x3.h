#ifndef __LPMATH_MATRIX3X3_H__
#define __LPMATH_MATRIX3X3_H__
#pragma once

#include "LupineMath/Vector2.h"
#include "LupineMath/Vector4.h"

namespace LupineMath
{
  class Matrix3x3
  {
  public:
    static LPMATH_API const Matrix3x3 Zero;
    static LPMATH_API const Matrix3x3 Identity;

  public:
    union
    {
      float fM[9];

      struct
      {
        float xx, yx, zx;
        float xy, yy, zy;
        float xz, yz, zz;
      };

      struct
      {
        float fM33[3][3];
      };
    };

  public:
    inline Matrix3x3();
    inline Matrix3x3(const float fS[]);
    inline Matrix3x3(const Matrix3x3 &mM);
    LPMATH_API Matrix3x3(const Matrix3x4 &mM);
    LPMATH_API Matrix3x3(const Matrix4x4 &mM);

    inline Matrix3x3(float fXX, float fXY, float fXZ,
                     float fYX, float fYY, float fYZ,
                     float fZX, float fZY, float fZZ);

    inline ~Matrix3x3();

    LPMATH_API bool operator ==(const Matrix3x3 &mM) const;
    LPMATH_API bool operator !=(const Matrix3x3 &mM) const;

    LPMATH_API bool CompareScale(const Matrix3x3 &mM, float fEpsilon = Math::Epsilon) const;
    LPMATH_API bool CompareRotation(const Matrix3x3 &mM, float fEpsilon = Math::Epsilon) const;

    inline Matrix3x3 &operator =(const float fS[]);
    inline Matrix3x3 &operator =(const Matrix3x3 &mM);

    LPMATH_API Matrix3x3 &operator =(const Matrix3x4 &mM);
    LPMATH_API Matrix3x3 &operator =(const Matrix4x4 &mM);

    inline Matrix3x3 operator +(const Matrix3x3 &mM) const;
    inline void operator +=(const Matrix3x3 &mM);
    inline Matrix3x3 operator -() const;
    inline Matrix3x3 operator -(const Matrix3x3 &mM) const;
    inline void operator -=(const Matrix3x3 &mM);
    inline Matrix3x3 operator *(float fS) const;
    inline void operator *=(float fS);
    inline Vector2 operator *(const Vector2 &vV) const;
    inline Vector3 operator *(const Vector3 &vV) const;

    LPMATH_API Vector4 operator *(const Vector4 &vV) const;
    LPMATH_API Matrix3x3  operator *(const Matrix3x3 &mM) const;

    inline void operator *=(const Matrix3x3 &mM);
    inline Matrix3x3 operator /(float fS) const;
    inline void operator /=(float fS);
    inline float operator [](int nIndex) const;
    inline float &operator [](int nIndex);
    inline float operator ()(LupineCore::uint32 nRow = 0, LupineCore::uint32 nColumn = 0) const;
    inline float &operator ()(LupineCore::uint32 nRow = 0, LupineCore::uint32 nColumn = 0);
    inline operator float *();
    inline operator const float *() const;

    inline bool IsZero() const;
    inline bool IsTrueZero() const;
    inline void SetZero();
    inline bool IsIdentity() const;
    inline bool IsTrueIdentity() const;
    inline void SetIdentity();

    inline void Set(float fXX, float fXY, float fXZ,
                    float fYX, float fYY, float fYZ,
                    float fZX, float fZY, float fZZ);

    inline Vector3 GetRow(LupineCore::uint8 nRow) const;
    inline void SetRow(LupineCore::uint8 nRow, const Vector3 &vRow);

    inline Vector3 GetColumn(LupineCore::uint8 nColumn) const;
    inline void SetColumn(LupineCore::uint8 nColumn, const Vector3 &vColumn);

    inline bool IsSymmetric() const;
    inline bool IsOrthogonal() const;
    inline bool IsRotationMatrix() const;
    inline float GetTrace() const;
    inline float GetDeterminant() const;
    inline void Transpose();
    inline Matrix3x3 GetTransposed() const;

    LPMATH_API bool Invert();
    LPMATH_API Matrix3x3 GetInverted() const;
    LPMATH_API Vector3 RotateVector(float fX, float fY, float fZ, bool bUniformScale = false) const;
    LPMATH_API Vector3 RotateVector(const Vector3 &vV, bool bUniformScale = false) const;

    inline void SetScaleMatrix(float fX, float fY, float fZ);
    inline void SetScaleMatrix(const Vector3 &vV);

    LPMATH_API void GetScale(float &fX, float &fY, float &fZ) const;
    inline Vector3 GetScale() const;
    inline void GetScale(float fV[]) const;

    LPMATH_API void FromEulerAngleX(float fAngleX);
    LPMATH_API void FromEulerAngleY(float fAngleY);
    LPMATH_API void FromEulerAngleZ(float fAngleZ);
    LPMATH_API void ToAxisAngle(float &fX, float &fY, float &fZ, float &fAngle) const;
    LPMATH_API void FromAxisAngle(float fX, float fY, float fZ, float fAngle);

    inline Vector3 GetXAxis() const;
    inline Vector3 GetYAxis() const;
    inline Vector3 GetZAxis() const;

    LPMATH_API void ToAxis(Vector3 &vX, Vector3 &vY, Vector3 &vZ) const;
    LPMATH_API void FromAxis(const Vector3 &vX, const Vector3 &vY, const Vector3 &vZ);
    LPMATH_API Matrix3x3 &LookAt(const Vector3 &vEye, const Vector3 &vAt, const Vector3 &vUp);

    inline Matrix3x3 &SetShearing(float fShearXY, float fShearXZ,
                                  float fShearYX,float fShearYZ,
                                  float fShearZX, float fShearZY);
  };

} // LupineMath

#include "LupineMath/Matrix3x3.inl"

#endif // __LPMATH_MATRIX3X3_H__
