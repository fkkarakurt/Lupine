/**
 * File              : Math.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 28.05.2022
 * Last Modified Date: 28.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __LPMATH_MATH_H__
#define __LPMATH_MATH_H__
#pragma once

#include "LupineMath/LupineMath.h"

namespace LupineMath
{
    class Math
    {
    public:
        static LPMATH_API const double Pi;
        static LPMATH_API const double Pi2;
        static LPMATH_API const double PiHalf;
        static LPMATH_API const double DegToRad;
        static LPMATH_API const double RadToDeg;
        static LPMATH_API const double Epsilon;
        static LPMATH_API const double Log2Const;
        static LPMATH_API const int RandMax;

    public:
        static inline bool IsNotANumber(float fValue);
        static inline bool IsNotANumber(double dValue);
        static inline bool IsFinite(float fValue);
        static inline bool IsFinite(double dValue);
        static inline bool IsPowerOfTwo(LupineCore::uint32 nNumber);
        static inline LupineCore::uint32 GetNearestPowerOfTwo(LupineCore::uint32 nNumber, bool bLower = true);
        static inline Lupinecore::uint32 GetRand();
        static inline int GetRandNeg();
        static inline float GetRandFloat();
        static inline float GetRandNegFloat();
        static inline float GetRandMinMaxFloat(float fMin, float fMax);
        static inline bool AreEqual(float f1, float f2, float fEpsilon = Math::Epsilon);
        static inline bool AreEqual(double d1, double d2, double dEpsilon = Math::Epsilon);
        static inline float Min(float a, float b);
        static inline int Min(int a, int b);
        static inline LupineCore::uint32 Min(LupineCore::uint32 a, LupineCore::uint32 b);
        static inline float Max(float a, float b);
        static inline int Max(int a, int b);
        static inline LupineCore::uint32 Max(LupineCore::uint32 a, LupineCore::uint32 b);
        static inline float Min(float a, float b, float c, float d);
        static inline int Min(int a, int b, int c, int d);
        static inline LupineCore::uint32 Min(LupineCore::uint32 a, LupineCore::uint32 b, LupineCore::uint32 c, LupineCore::uint32 d);
        static inline float Max(float a, float b, float c, float d);
        static inline int Max(int a, int b, int c, int d);
        static inline LupineCore::uint32 Max(LupineCore::uint32 a, LupineCore::uint32 b, LupineCore::uint32 c, LupineCore::uint32 d);
        static inline float Sign(float x);
        static inline float ClampToInterval(float fValue, float fMin, float fMax);
        static inline float WrapToInterval(float fValue, float fMin, float fMax);
        static inline int Abs(int x);
        static inline float Abs(float x);
        static inline double Abs(double x);
        static inline void Swap(float &a, float &b);
        static inline float Saturate(float fValue);
        static inline float Floor(float fValue);
        static inline float Ceil(float fValue);
        static inline float Round(float fValue, LupineCore::uint32 nPrecision = 0);
        static inline float Sin(float fAngle);
        static inline double Sin(double dAngle);
        static inline float ASin(float fValue);
        static inline double ASin(double dValue);
        static inline float Cos(float fAngle);
        static inline double Cos(double dAngle);
        static inline float ACos(float fValue);
        static inline double ACos(double dValue);
        static inline float Tan(float fAngle);
        static inline double Tan(double dAngle);
        static inline float ATan(float fValue);
        static inline double ATan(double dValue);
        static inline float ATan2(float fX, float fY);
        static inline double ATan2(double dX, double dY);
        static inline float Sqrt(float fValue);
        static inline double Sqrt(double dValue);
        static inline float FastInvSqrt(float fValue);
        static inline float Pow(float x, float y);
        static inline double Pow(double x, double y);
        static inline double Pow(int x, int y);
        static inline float Log(float x);
        static inline double Log(double x);
        static inline float Log2(float x);
        static inline double Log2(double x);
        static inline float Exp(float x);
        static inline double Exp(double x);
    };

} // LupineMath

#include "LupineMath/Math.inl"

#endif // __LPMATH_MATH_H__