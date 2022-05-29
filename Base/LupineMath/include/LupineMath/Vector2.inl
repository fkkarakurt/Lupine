#include "LupineMath/Math.h"

namespace LupineMath
{
    inline Vector2 operator*(float fS, const Vector2 &vV)
    {
        return Vector2(vV.x * fS, vV.y * fS);
    }

    inline Vector2::Vector2() : x(0.0f), y(0.0f)
    {
    }

    inline Vector2::Vector2(float fX, float fY) : x(fX), y(fY)
    {
    }

    inline Vector2::Vector2(const float fV[]) : x(fV[0]), y(fV[1])
    {
    }

    inline Vector2::Vector2(const Vector2 &vV) : x(vV.x), y(vV.y)
    {
    }

    inline Vector2::Vector2(const PLCore::String &sString)
    {
        FromString(sString);
    }

    inline Vector2::~Vector2()
    {
    }

    inline Vector2 &Vector2::operator=(const float fV[])
    {
        x = fV[0];
        y = fV[1];
        return *this;
    }

    inline Vector2 &Vector2::operator=(const Vector2 &vV)
    {
        x = vV.x;
        y = vV.y;
        return *this;
    }

    inline bool Vector2::operator==(const Vector2 &vV) const
    {
        return (x == vV.x && y == vV.y);
    }

    inline bool Vector2::operator!=(const Vector2 &vV) const
    {
        return (x != vV.x || y != vV.y);
    }

    inline bool Vector2::operator<(const Vector2 &vV) const
    {
        return (x != vV.x) ? (x < vV.x) : (y < vV.y);
    }

    inline bool Vector2::operator>(const Vector2 &vV) const
    {
        return (x != vV.x) ? (x > vV.x) : (y > vV.y);
    }

    inline bool Vector2::operator<=(const Vector2 &vV) const
    {
        return (x != vV.x) ? (x <= vV.x) : (y <= vV.y);
    }

    inline bool Vector2::operator>=(const Vector2 &vV) const
    {
        return (x != vV.x) ? (x >= vV.x) : (y >= vV.y);
    }

    inline Vector2 Vector2::operator+(const Vector2 &vV) const
    {
        return Vector2(x + vV.x, y + vV.y);
    }

    inline Vector2 Vector2::operator+(float fN) const
    {
        return Vector2(x + fN, y + fN);
    }

    inline Vector2 &Vector2::operator+=(const Vector2 &vV)
    {
        x += vV.x;
        y += vV.y;
        return *this;
    }

    inline Vector2 &Vector2::operator+=(float fN)
    {
        x += fN;
        y += fN;
        return *this;
    }

    inline Vector2 Vector2::operator-() const
    {
        return Vector2(-x, -y);
    }

    inline Vector2 Vector2::operator-(float fN) const
    {
        return Vector2(x - fN, y - fN);
    }

    inline Vector2 Vector2::operator-(const Vector2 &vV) const
    {
        return Vector2(x - vV.x, y - vV.y);
    }

    inline Vector2 &Vector2::operator-=(const Vector2 &vV)
    {
        x -= vV.x;
        y -= vV.y;
        return *this;
    }

    inline Vector2 &Vector2::operator-=(float fN)
    {
        x -= fN;
        y -= fN;
        return *this;
    }

    inline Vector2 Vector2::operator*(const Vector2 &vV) const
    {
        return Vector2(x * vV.x, y * vV.y);
    }

    inline Vector2 Vector2::operator*(float fS) const
    {
        return Vector2(x * fS, y * fS);
    }

    inline Vector2 &Vector2::operator*=(const Vector2 &vV)
    {
        x *= vV.x;
        y *= vV.y;
        return *this;
    }

    inline Vector2 &Vector2::operator*=(float fS)
    {
        x *= fS;
        y *= fS;
        return *this;
    }

    inline Vector2 Vector2::operator/(const Vector2 &vV) const
    {
        return Vector2(x / vV.x, y / vV.y);
    }

    inline Vector2 Vector2::operator/(float fS) const
    {
        return Vector2(x / fS, y / fS);
    }

    inline Vector2 &Vector2::operator/=(const Vector2 &vV)
    {
        x /= vV.x;
        y /= vV.y;
        return *this;
    }

    inline Vector2 &Vector2::operator/=(float fS)
    {
        x /= fS;
        y /= fS;
        return *this;
    }

    inline Vector2::operator float *()
    {
        return &x;
    }

    inline Vector2::operator const float *() const
    {
        return &x;
    }

    inline float &Vector2::operator[](int nIndex)
    {
        return fV[nIndex];
    }

    inline const float &Vector2::operator[](int nIndex) const
    {
        return fV[nIndex];
    }

    inline void Vector2::GetXY(float &fX, float &fY) const
    {
        fX = x;
        fY = y;
    }

    inline float Vector2::GetX() const
    {
        return x;
    }

    inline float Vector2::GetY() const
    {
        return y;
    }

    inline void Vector2::SetXY(float fX, float fY)
    {
        x = fX;
        y = fY;
    }

    inline void Vector2::SetXY(const float fV[])
    {
        x = fV[0];
        y = fV[1];
    }

    inline void Vector2::SetX(float fX)
    {
        x = fX;
    }

    inline void Vector2::SetY(float fY)
    {
        y = fY;
    }

    inline void Vector2::IncXY(float fX, float fY)
    {
        x += fX;
        y += fY;
    }

    inline void Vector2::IncXY(const float fV[])
    {
        x += fV[0];
        y += fV[1];
    }

    inline void Vector2::IncX(float fX)
    {
        x += fX;
    }

    inline void Vector2::IncY(float fY)
    {
        y += fY;
    }

    inline bool Vector2::IsNull() const
    {
        return (!x && !y);
    }

    inline bool Vector2::IsPacked() const
    {
        return (x >= 0.0f && x <= 1.0f && y >= 0.0f && y <= 1.0f);
    }

    inline void Vector2::PackTo01()
    {
        Normalize();
        x = x * 0.5f + 0.5f;
        y = y * 0.5f + 0.5f;
    }

    inline Vector2 Vector2::GetPackedTo01() const
    {
        Vector2 vTemp(x, y);
        vTemp.Normalize();
        vTemp.x = vTemp.x * 0.5f + 0.5f;
        vTemp.y = vTemp.y * 0.5f + 0.5f;
        return vTemp;
    }

    inline void Vector2::UnpackFrom01()
    {
        x = x * 2 - 1;
        y = y * 2 - 1;
    }

    inline Vector2 Vector2::GetUnpackedFrom01() const
    {
        return Vector2(x * 2 - 1, y * 2 - 1);
    }

    inline Vector2::Component Vector2::GetSmallestComponent() const
    {
        return (x < y) ? X : Y;
    }

    inline float Vector2::GetSmallestValue() const
    {
        return (x < y) ? x : y;
    }

    inline Vector2::Component Vector2::GetGreatestComponent() const
    {
        return (x > y) ? X : Y;
    }

    inline float Vector2::GetGreatestValue() const
    {
        return (x > y) ? x : y;
    }

    inline void Vector2::Invert()
    {
        x = -x;
        y = -y;
    }

    inline Vector2 Vector2::GetInverted() const
    {
        return Vector2(-x, -y);
    }

    inline float Vector2::GetLength() const
    {
        return Math::Sqrt(x * x + y * y);
    }

    inline float Vector2::GetSquaredLength() const
    {
        return x * x + y * y;
    }

    inline void Vector2::SetLength(float fLength)
    {
        float fU = x * x + y * y;
        if (fU)
        {
            fU = Math::Sqrt(fU);
            if (fU)
            {
                const float fScale = fLength / fU;
                x *= fScale;
                y *= fScale;
            }
        }
    }

    inline Vector2 &Vector2::Normalize()
    {
        float fU = x * x + y * y;
        if (fU)
        {
            fU = Math::Sqrt(fU);
            if (fU)
            {
                const float fScale = 1.0f / fU;
                x *= fScale;
                y *= fScale;
            }
        }

        return *this;
    }

    inline Vector2 Vector2::GetNormalized() const
    {
        float fU = x * x + y * y;
        if (fU)
        {
            fU = Math::Sqrt(fU);
            if (fU)
            {
                const float fScale = 1.0f / fU;
                return Vector2(x * fScale, y * fScale);
            }
        }
        return Vector2::Zero;
    }

    inline float Vector2::GetDistance(const Vector2 &vV) const
    {
        const float fDX = vV.x - x;
        const float fDY = vV.y - y;
        return Math::Sqrt(fDX * fDX + fDY * fDY);
    }

    inline float Vector2::GetSquaredDistance(const Vector2 &vV) const
    {
        const float fDX = vV.x - x;
        const float fDY = vV.y - y;    
        return fDX * fDX + fDY * fDY;
    }

    inline float Vector2::DotProduct(const Vector2 &vV) const
    {
        return x * vV.x + y * vV.y;
    }

    inline Vector2 Vector2::ProjectVector(const Vector2 &vA, const Vector2 &vB) const
    {
        return vB * (vA.DotProduct(vB) / vB.DotProduct(vB));
    }

    inline float Vector2::GetAngle(const Vector2 &vV) const
    {
        return Math::ACos(DotProduct(vV) / (GetLength() * vV.GetLength()));
    }

} // LupineMath
