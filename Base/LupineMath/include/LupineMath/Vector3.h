/**
 * File              : Vector3.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 28.05.2022
 * Last Modified Date: 28.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __LPMATH_VECTOR3_H__
#define __LPMATH_VECTOR3_H__
#pragma once

#include <LupineCore/String/String.h>
#include "LupineMath/LupineMath.h"

namespace LupineCore
{
    class Vector2;
    class Vector4;
    class Matrix3x3;
    class Matrix4x4;
    class Rectangle;
    class Quaternion;

    class Vector3
    {
        public:
            enum Component
            {
                X = 0,
                Y = 1,
                Z = 2
            };

        public:
            static LPMATH_API const Vector3 Zero;
            static LPMATH_API const Vector3 One;
            static LPMATH_API const Vector3 NegativeOne;
            static LPMATH_API const Vector3 UnitX;
            static LPMATH_API const Vector3 UnitY;
            static LPMATH_API const Vector3 UnitZ;
            static LPMATH_API const Vector3 NegativeUnitX;
            static LPMATH_API const Vector3 NegativeUnitY;
            static LPMATH_API const Vector3 NegativeUnitZ;

        public:
            union
            {
                float fV[3];

                struct
                {
                    float x,y,z;
                };

                struct
                {
                    float u,v,w;
                };

                struct
                {
                    float fPitch, fYaw, fRoll;
                };
            };


            public:
                inline Vector3();
                inline Vector3(float fX, float fY, float fZ = 0.0f);
                inline Vector3(const float fV[]);
                LPMATH_API Vector3(const Vector2 &vV, float fZ = 0.0f);
                inline Vector3(const Vector3 &vV);
                LPMATH_API Vector3(const Vector4 &vV);
                inline Vector3(const PLCore::String &sString);
                inline ~Vector3();
                inline Vector3 &operator=(const float fV[]);
                LPMATH_API Vector3 &operator=(const Vector2 &vV);
                inline Vector3 &operator=(const Vector3 &vV);
                LPMATH_API Vector3 &operator=(const Vector4 &vV);
                inline bool operator ==(const Vector3 &vV) const;
                inline bool operator !=(const Vector3 &vV) const;
                inline bool operator <(const Vector3 &vV) const;
                inline bool operator >(const Vector3 &vV) const;
                inline bool operator <=(const Vector3 &vV) const;
                inline bool operator >=(const Vector3 &vV) const;
                inline Vector3 operator+(const Vector3 &vV) const;
                inline Vector3 operator+(float fN) const;
                inline Vector3 &operator+=(const Vector3 &vV);
                inline Vector3 &operator+=(float fN);
                inline Vector3 operator-() const;
                inline Vector3 operator-(const Vector3 &vV) const;
                inline Vector3 operator-(float fN) const;
                inline Vector3 &operator-=(const Vector3 &vV);
                inline Vector3 &operator-=(float fN);
                inline Vector3 operator*(const Vector3 &vV) const;
                inline Vector3 operator*(float fS) const;
                inline Vector3 &operator*=(const Vector3 &vV);
                inline Vector3 &operator*=(float fS);
                LPMATH_API Vector3 &operator*=(const Matrix3x3 &mRot);
                LPMATH_API Vector3 &operator*=(const Matrix3x4 &mTrans);
                LPMATH_API Vector3 &operator*=(const Matrix4x4 &mTrans);
                LPMATH_API Vector3 &operator*=(const Quaternion &qQ);
                inline Vector3 operator/(const Vector3 &vV) const;
                inline Vector3 operator/(float fS) const;
                inline Vector3 &operator/=(const Vector3 &vV);
                inline Vector3 &operator/=(float fS);
                inline operator float *();
                inline operator const float *() const;
                inline float &operator[](int nIndex);
                inline const float &operator[](int nIndex) const;
                inline void GetXYZ(float &fX, float &fY, float &fZ) const;
                inline float GetX() const;
                inline float GetY() const;
                inline float GetZ() const;
                inline void SetXYZ(float fX = 0.0f, float fY = 0.0f, float fZ = 0.0f);
                inline void SetXYZ(const float fV[]);
                inline void SetX(float fX = 0.0f);
                inline void SetY(float fY = 0.0f);
                inline void SetZ(float fZ = 0.0f);
                inline void IncXYZ(float fX = 0.0f, float fY = 0.0f, float fZ = 0.0f);
                inline void IncXYZ(const float fV[]);
                inline void IncX(float fX);
                inline void IncY(float fY);
                inline void IncZ(float fZ);
                inline bool IsNull() const;
                inline bool IsPacked() const;
                inline void PackTo01();
                inline Vector3 GetPackedTo01() const;
                inline void UnpackFrom01();
                inline Vector3 GetUnpackedFrom01() const;
                inline Component GetSmallestComponent() const;
                inline float GetSmallestValue() const;
                inline Component GetGreatestComponent() const;
                inline float GetGreatestValue() const;
                inline void Invert();
                inline Vector3 GetInverted() const;
                inline float GetLength() const;
                inline float GetSquaredLength() const;
                inline void SetLength(float fLength = 1.0f);
                inline Vector3 &Normalize();
                inline Vector3 GetNormalized() const;
                inline float GetDistance(const Vector3 &vV) const;
                inline float GetSquaredDistance(const Vector3 &vV) const;
                inline float DotProduct(const Vector3 &vV) const;
                inline Vector3 ProjectVector(const Vector3 &vA, const Vector3 &vB) cons
                inline float GetAngle(const Vector3 &vV) const;
                inline Vector3 CrossProduct(const Vector3 &vV) const;
                inline Vector3 &CrossProduct(const Vector3 &vV1, const Vector3 &vV2);
                LPMATH_API void GetRightUp(Vector3 &vRight, Vector3 &vUp) const;
                LPMATH_API void GetRightUp(float fRight[], float fUp[]) const;
                inline void GetFaceNormal(const Vector3 &vV1, const Vector3 &vV2, const Vector3 &vV3);
                LPMATH_API Vector3 &RotateAxis(Vector3 &vV, float fAngle);
                LPMATH_API Quaternion GetRotationTo(const Vector3 &vDest) const;
                LPMATH_API Vector3 &GetProjection(const Vector3 &vX, const Vector3 &vN);
                LPMATH_API Vector3 &ProjectPlane(const Vector3 &vV1, const Vector3 &vV2);
                LPMATH_API Vector3 &Reflect(const Vector3 &vIncidentNormal, const Vector3 &vNormal);
                LPMATH_API Vector3 &Refract(const Vector3 &vIncidentNormal, const Vector3 &vNormal, float fEtaRatio);
                LPMATH_API Vector3 ClosestPointOnLine(const Vector3 &vV1, const Vector3 &vV2) const;
                LPMATH_API bool IsPointInTriangle(const Vector3 &vV1, const Vector3 &vV2, const Vector3 &vV3) const;
                LPMATH_API Vector3 ClosestPointOnTriangle(const Vector3 &vV1, const Vector3 &vV2, const Vector3 &vV3) const;
                LPMATH_API bool ClosestPointOnTriangle(const Vector3 &vV1, const Vector3 &vV2, const Vector3 &vV3, float fRadius, Vector3 &vClosest) const;
                LPMATH_API Vector3 To2DCoordinate(const Matrix4x4 &mWorldViewProjection, const Rectangle &cViewportRectangle, float fDepthRangeMin = 0.0f, float fDepthRangeMax = 1.0f, float *pfHomogeneousDivide = nullptr) const;
                LPMATH_API Vector3 To3DCoordinate(const Matrix4x4 &mClipSpaceToObjectSpace, const Rectangle &cViewportRectangle) const;
                LPMATH_API PLCore::String ToString() const;
                LPMATH_API bool FromString(const PLCore::String &sString);
    };


} // LupineCore

#include "LupineMath/Vector3.inl"
#include "LupineMath/TypeVector3.inl"

#endif // __LPMATH_VECTOR3_H__