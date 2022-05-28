/**
 * File              : Math.inl
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 28.05.2022
 * Last Modified Date: 28.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#include <math.h>
#include <float.h>
#include <stdlib.h>

#ifdef APPLE
#define _isnan isnan
#define _finite isfinite
#elif LINUX
#define _isnan isnan
#define _finite finite
#endif

namespace LupineMath
{
    bool Math::IsNotANumber(float fValue)
    {
        return (_isnan(fValue) != 0);
    }

    bool Math::IsNotANumber(double dValue)
    {
        return (_isnan(dValue) != 0);
    }

    bool Math::IsFinite(float fValue)
    {
        return (_finite(fValue) != 0);
    }

    bool Math::IsFinite(double dValue)
    {
        return (_finite(dValue) != 0);
    }

    /***
     *
     *
     * */

    inline bool Math::IsPowerOfTwo(LupineCore::uint32 nNumber)
    {
        return (nNumber == 0) ? false : ((nNumber & (nNumber - 1)) = 0);
    }

    LupineCore::uint32 Math::GetNearestPowerOfTwo(LupineCore::uint32 nNumber, bool bLower)
    {
        if (nNumber == 0)
        {
            return bLower ? 0 : 1;
        }
        else
        {
            if (!IsPowerOfTwo(nNumber))
            {
                LupineCore::uint32 nPreviousNumber = 1;
                for (LupineCore::uint32 i = 1; i < 32; i++)
                {
                    const LupineCore::uint32 nCurrentNumber = static_cast<LupineCore::uint32>(powf(2.0f, static_cast<float>(i)));
                    if (nNumber < nCurrentNumber)
                        return bLower ? nPreviousNumber : nCurrentNumber;
                    nPreviousNumber = nCurrentNumber;
                }
            }

            return nNumber;
        }
    }

    LupineCore::uint32 Math::GetRand()
    {
        return rand();
    }

    inline int Math::GetRandNeg()
    {
        return (GetRand() % 2) ? GetRand() : -static_cast<int>(GetRand());
    }

    float Math::GetRandFloat()
    {
        return rand() / static_cast<float>(RAND_MAX);
    }

    inline float Math::GetRandNegFloat()
    {
        return (GetRand() % 2) ? GetRandFloat() : -GetRandFloat();
    }

    float Math::GetRandMinMaxFloat(float fMin, float fMax)
    {
        return fMin + GetRandFloat() * (fMax - fMin);
    }

    inline bool Math::AreEqual(float f1, float f2, float fEpsilon)
    {
        return (f2 >= f1 - fEpsilon && f2 <= f1 + fEpsilon);
    }

    inline bool Math::AreEqual(double d1, double d2, double dEpsilon)
    {
        return (d2 >= d1 - dEpsilon && d2 <= d1 + dEpsilon);
    }

    inline float Math::Min(float a, float b)
    {
        return (a < b) ? a : b;
    }

    inline int Math::Min(int a, int b)
    {
        return (a < b) ? a : b;
    }

    inline LupineCore::uint32 Math::Min(LupineCore::uint32 a, LupineCore::uint32 b)
    {
        return (a < b) ? a : b;
    }

    inline float Math::Max(float a, float b)
    {
        return (a > b) ? a : b;
    }

    inline int Math::Max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    inline LupineCore::uint32 Math::Max(LupineCore::uint32 a, LupineCore::uint32 b)
    {
        return (a > b) ? a : b;
    }

    inline float Math::Min(float a, float b, float c, float d)
    {
        if (a < b)
        {
            if (a < c)
            {
                if (a < d)
                    return a;
                else
                    return d;
            }
            else
            {
                if (c < d)
                    return c;
                else
                    return d;
            }
        }
        else
        {
            if (b < c)
            {
                if (b < d)
                    return b;
                else
                    return d;
            }
            else
            {
                if (c < d)
                    return c;
                else
                    return d;
            }
        }
    }

    inline int Math::Min(int a, int b, int c, int d)
    {
        if (a < b)
        {
            if (a < c)
            {
                if (a < d)
                    return a;
                else
                    return d;
            }
            else
            {
                if (c < d)
                    return c;
                else
                    return d;
            }
        }
        else
        {
            if (b < c)
            {
                if (b < d)
                    return b;
                else
                    return d;
            }
            else
            {
                if (c < d)
                    return c;
                else
                    return d;
            }
        }
    }

    inline LupineCore::uint32 Math::Min(LupineCore::uint32 a, LupineCore::uint32 b, LupineCore::uint32 c, LupineCore::uint32 d)
    {
        if (a < b)
        {
            if (a < c)
            {
                if (a < d)
                    return a;
                else
                    return d;
            }
            else
            {
                if (c < d)
                    return c;
                else
                    return d;
            }
        }
        else
        {
            if (b < c)
            {
                if (b < d)
                    return b;
                else
                    return d;
            }
            else
            {
                if (c < d)
                    return c;
                else
                    return d;
            }
        }
    }

    inline float Math::Max(float a, float b, float c, float d)
    {
        if (a > b)
        {
            if (a > c)
            {
                if (a > d)
                    return a;
                else
                    return d;
            }
            else
            {
                if (c > d)
                    return c;
                else
                    return d;
            }
        }
        else
        {
            if (b > c)
            {
                if (b > d)
                    return b;
                else
                    return d;
            }
            else
            {
                if (c > d)
                    return c;
                else
                    return d;
            }
        }
    }

    inline int Math::Max(int a, int b, int c, int d)
    {
        if (a > b)
        {
            if (a > c)
            {
                if (a > d)
                    return a;
                else
                    return d;
            }
            else
            {
                if (c > d)
                    return c;
                else
                    return d;
            }
        }
        else
        {
            if (b > c)
            {
                if (b > d)
                    return b;
                else
                    return d;
            }
            else
            {
                if (c > d)
                    return c;
                else
                    return d;
            }
        }
    }

    inline LupineCore::uint32 Math::Max(LupineCore::uint32 a, LupineCore::uint32 b, LupineCore::uint32 c, LupineCore::uint32 d)
    {
        if (a > b)
        {
            if (a > c)
            {
                if (a > d)
                    return a;
                else
                    return d;
            }
            else
            {
                if (c > d)
                    return c;
                else
                    return d;
            }
        }
        else
        {
            if (b > c)
            {
                if (b > d)
                    return b;
                else
                    return d;
            }
            else
            {
                if (c > d)
                    return c;
                else
                    return d;
            }
        }
    }

    inline float Math::Sign(float x)
    {
        return (x < 0.0f) ? -1.0f : 1.0f;
    }

    float Math::ClampToInterval(float fValue, float fMin, float fMax)
    {
        if (fMin < fMax)
        {
            if (fValue > fMax)
                return fMax;
            else if (fValue < fMin)
                return fMin;
            else
                return fValue;
        }
        else
        {
            if (fValue > fMin)
                return fMin;
            else if (fValue < fMax)
                return fMax;
            else
                return fValue;
        }
    }

    float Math::WrapToInterval(float fValue, float fMin, float fMax)
    {
        const float fInterval = (fMax - fMin);
        return fInterval ? (fValue - floor((fValue - fMin) / fInterval) * (fMax - fMin)) : fMin;
    }

    inline int Math::Abs(int x)
    {
        return (x > 0.0f) ? x : -x;
    }

    inline float Math::Abs(float x)
    {
        return (x > 0.0f) ? x : -x;
    }

    inline double Math::Abs(double x)
    {
        return (x > 0.0) ? x : -x;
    }

    inline void Math::Swap(float &a, float &b)
    {
        const float fTemp = a;
        a = b;
        b = fTemp;
    }

    inline float Math::Saturate(float fValue)
    {
        if (fValue < 0.0f)
            return 0.0f;
        if (fValue > 1.0f)
            return 1.0f;
        return fValue;
    }

    float Math::Floor(float fValue)
    {
        return floor(fValue);
    }

    float Math::Ceil(float fValue)
    {
        return ceil(fValue);
    }

    float Math::Round(float fValue, LupineCore::uint32 nPrecision)
    {
        const float fMultiplier = powf(10.0f, static_cast<float>(nPrecision));
        return floor(fValue * fMultiplier + 0.5f) / fMultiplier;
    }

    float Math::Sin(float fAngle)
    {
        return sinf(fAngle);
    }

    double Math::Sin(double dAngle)
    {
        return sin(dAngle);
    }

    float Math::ASin(float fValue)
    {
        return asinf(fValue);
    }

    double Math::ASin(double dValue)
    {
        return asin(dValue);
    }

    float Math::Cos(float fAngle)
    {
        return cosf(fAngle);
    }

    double Math::Cos(double dAngle)
    {
        return cos(dAngle);
    }

    float Math::ACos(float fValue)
    {
        return acosf(fValue);
    }

    double Math::ACos(double dValue)
    {
        return acos(dValue);
    }

    float Math::Tan(float fAngle)
    {
        return tanf(fAngle);
    }

    double Math::Tan(double dAngle)
    {
        return tan(dAngle);
    }

    float Math::ATan(float fValue)
    {
        return atanf(fValue);
    }

    double Math::ATan(double dValue)
    {
        return atan(dValue);
    }

    float Math::ATan2(float fX, float fY)
    {
        return atan2f(fX, fY);
    }

    double Math::ATan2(double dX, double dY)
    {
        return atan2(dX, dY);
    }

    float Math::Sqrt(float fValue)
    {
        return sqrtf(fValue);
    }

    double Math::Sqrt(double dValue)
    {
        return sqrt(dValue);
    }

    float Math::FastInvSqrt(float fValue)
    {
        const float fThreeHalfs = 1.5f;
        float x2 = fValue * 0.5f;
        float y = fValue;
        long i = *reinterpret_cast<long *>(&y);
        i = 0x5f3759df - (i >> 1);
        y = *reinterpret_cast<float *>(&i);
        y = y * (fThreeHalfs - (x2 * y * y));
        return y;
    }

    float Math::Pow(float x, float y)
    {
        return powf(x, y);
    }

    double Math::Pow(double x, double y)
    {
        return pow(x, y);
    }

    double Math::Pow(int x, int y)
    {
        return pow(static_cast<float>(x), y);
    }

    float Math::Log(float x)
    {
        return log(x);
    }

    double Math::Log(double x)
    {
        return log(x);
    }

    float Math::Log2(float x)
    {
        return static_cast<float>(log(x) / Log2Const);
    }

    double Math::Log2(double x)
    {
        return log(x) / Math::Log2Const;
    }

    float Math::Exp(float x)
    {
        return exp(x);
    }

    double Math::Exp(double x)
    {
        return exp(x);
    }

} // LupineMath