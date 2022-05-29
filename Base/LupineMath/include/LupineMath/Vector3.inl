/**
 * File              : Vector3.inl
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 28.05.2022
 */

#include "LupineMath/Math.h"

namespace LupineMath
{
    inline Vector3 operator*(float fS, const Vector3 &vV)
    {
        return Vector3(vV.x * fS, vV.y * fS, vV.z * fS);
    }

    inline Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f)
    {
    }

    inline Vector3::Vector3(float fX, float fY, float fZ) : x(fX),
                                                            y(fY),
                                                            z(fZ)
    {
    }

    inline Vector3::Vector3(const float fV[]) : x(fV[0]),
                                                y(fV[1]),
                                                z(fV[2])
    {
    }

    inline Vector3::Vector3(const Vector3 &vV) : x(vV.x),
                                                 y(vV.y),
                                                 z(vV.z)
    {
    }

    inline Vector3::Vector3(const PLCore::String &sString)
    {
        FromString(sString);
    }

    inline Vector3::~Vector3()
    {
    }

    inline Vector3 &Vector3::operator=(const float fV[])
    {
        x = fV[0];
        y = fV[1];
        z = fV[2];
        return *this;
    }

    inline Vector3 &Vector3::operator=(const Vector3 &vV)
    {
        x = vV.x;
        y = vV.y;
        z = vV.z;
        return *this;
    }

    inline bool Vector3::operator==(const Vector3 &vV) const
    {
        return (x == vV.x && y == vV.y && z == vV.z);
    }

    inline bool Vector3::operator!=(const Vector3 &vV) const
    {
        return (x != vV.x || y != vV.y || z != vV.z);
    }

    inline bool Vector3::operator<(const Vector3 &vV) const
    {
        if (x != vV.x)
            return (x < vV.x);
        else
            return (y != vV.y) ? (y < vV.y) : (z < vV.z);
    }

    inline bool Vector3::operator>(const Vector3 &vV) const
    {
        if (x != vV.x)
            return (x > vV.x);
        else
            return (y != vV.y) ? (y > vV.y) : (z > vV.z);
    }

    inline bool Vector3::operator<=(const Vector3 &vV) const
    {
        if (x != vV.x)
            return (x <= vV.x);
        else
            return (y != vV.y) ? (y <= vV.y) : (z <= vV.z);
    }

    inline bool Vector3::operator>=(const Vector3 &vV) const
    {
        if (x != vV.x)
            return (x >= vV.x);
        else
            return (y != vV.y) ? (y >= vV.y) : (z >= vV.z);
    }

    inline Vector3 Vector3::operator+(const Vector3 &vV) const
    {
        return Vector3(x + vV.x, y + vV.y, z + vV.z);
    }

    inline Vector3 Vector3::operator+(float fN) const
    {
        return Vector3(x + fN, y + fN, z + fN);
    }

    inline Vector3 &Vector3::operator+=(const Vector3 &vV)
    {
        x += vV.x;
        y += vV.y;
        z += vV.z;
        return *this;
    }

    inline Vector3 &Vector3::operator+=(float fN)
    {
        x += fN;
        y += fN;
        z += fN;
        return *this;
    }

    inline Vector3 Vector3::operator-() const
    {
        return Vector3(-x, -y, -z);
    }

    inline Vector3 Vector3::operator-(const Vector3 &vV) const
    {
        return Vector3(x - vV.x, y - vV.y, z - vV.z);
    }

    inline Vector3 Vector3::operator-(float fN) const
    {
        return Vector3(x - fN, y - fN, z - fN);
    }

    inline Vector3 &Vector3::operator-=(const Vector3 &vV)
    {
        x -= vV.x;
        y -= vV.y;
        z -= vV.z;
        return *this;
    }

    inline Vector3 &Vector3::operator-=(float fN)
    {
        x -= fN;
        y -= fN;
        z -= fN;
        return *this;
    }

    inline Vector3 Vector3::operator*(const Vector3 &vV) const
    {
        return Vector3(x * vV.x, y * vV.y, z * vV.z);
    }

    inline Vector3 Vector3::operator*(float fS) const
    {
        return Vector3(x * fS, y * fS, z * fS);
    }

    inline Vector3 &Vector3::operator*=(const Vector3 &vV)
    {
        x *= vV.x;
        y *= vV.y;
        z *= vV.z;
        return *this;
    }

    inline Vector3 &Vector3::operator*=(float fS)
    {
        x *= fS;
        y *= fS;
        z *= fS;
        return *this;
    }

    inline Vector3 Vector3::operator/(const Vector3 &vV) const
    {
        return Vector3(x / vV.x, y / vV.y, z / vV.z);
    }

    inline Vector3 Vector3::operator/(float fS) const
    {
        return Vector3(x / fS, y / fS, z / fS);
    }

    inline Vector3 &Vector3::operator/=(const Vector3 &vV)
    {
        x /= vV.x;
        y /= vV.y;
        z /= vV.z;
        return *this;
    }

    inline Vector3 &Vector3::operator/=(float fS)
    {
        x /= fS;
        y /= fS;
        z /= fS;
        return *this;
    }

    inline Vector3::operator float *()
    {
        return &x;
    }

    inline Vector3::operator const float *() const
    {
        return &x;
    }

    inline float &Vector3::operator[](int nIndex)
    {
        return fV[nIndex];
    }

    inline const float &Vector3::operator[](int nIndex) const
    {
        return fV[nIndex];
    }

    inline void Vector3::GetXYZ(float &fX, float &fY, float &fZ) const
    {
        fX = x;
        fY = y;
        fZ = z;
    }

    inline float Vector3::GetX() const
    {
        return x;
    }

    inline float Vector3::GetY() const
    {
        return y;
    }

    inline float Vector3::GetZ() const
    {
        return z;
    }

    inline void Vector3::SetXYZ(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }

    inline void Vector3::SetXYZ(const float fV[])
    {
        x = fV[0];
        y = fV[1];
        z = fV[2];
    }

    inline void Vector3::SetX(float fX)
    {
        x = fX;
    }

    inline void Vector3::SetY(float fY)
    {
        y = fY;
    }

    inline void Vector3::SetZ(float fZ)
    {
        z = fZ;
    }

    inline void Vector3::IncXYZ(float fX, float fY, float fZ)
    {
        x += fX;
        y += fY;
        z += fZ;
    }

    inline void Vector3::IncXYZ(const float fV[])
    {
        x += fV[0];
        y += fV[1];
        z += fV[2];
    }

    inline void Vector3::IncX(float fX)
    {
        x += fX;
    }

    inline void Vector3::IncY(float fY)
    {
        y += fY;
    }

    inline void Vector3::IncZ(float fZ)
    {
        z += fZ;
    }

    inline bool Vector3::IsNull() const
    {
        return (!x && !y && !z);
    }

    inline bool Vector3::IsPacked() const
    {
        return (x >= 0.0f && x <= 1.0f && y >= 0.0f && y <= 1.0f && z >= 0.0f && z <= 1.0f);
    }

    inline void Vector3::PackTo01()
    {
        Normalize();
        x = x * 0.5f + 0.5f;
        y = y * 0.5f + 0.5f;
        z = z * 0.5f + 0.5f;
    }

    inline Vector3 Vector3::GetPackedTo01() const
    {
        Vector3 vTemp(x, y, z);
        vTemp.Normalize();
        vTemp.x = vTemp.x * 0.5f + 0.5f;
        vTemp.y = vTemp.y * 0.5f + 0.5f;
        vTemp.z = vTemp.z * 0.5f + 0.5f;
        return vTemp;
    }

    inline void Vector3::UnpackFrom01()
    {
        x = x * 2 - 1;
        y = y * 2 - 1;
        z = z * 2 - 1;
    }

    inline Vector3 Vector3::GetUnpackedFrom01() const
    {
        return Vector3(x * 2 - 1, y * 2 - 1, z * 2 - 1);
    }

    inline Vector3::Component Vector3::GetSmallestComponent() const
    {
        if (x < y)
        {
            if (x < z)
                return X;
            else
                return Z;
        }
        else
        {
            if (y < z)
                return Y;
            else
                return Z;
        }
    }

    inline float Vector3::GetSmallestValue() const
    {
        if (x < y)
        {
            if (x < z)
                return x;
            else
                return z;
        }
        else
        {
            if (y < z)
                return y;
            else
                return z;
        }
    }

    inline Vector3::Component Vector3::GetGreatestComponent() const
    {
        if (x > y)
        {
            if (x > z)
                return X;
            else
                return Z;
        }
        else
        {
            if (y > z)
                return Y;
            else
                return Z;
        }
    }

    inline float Vector3::GetGreatestValue() const
    {
        if (x > y)
        {
            if (x > z)
                return x;
            else
                return z;
        }
        else
        {
            if (y > z)
                return y;
            else
                return z;
        }
    }

    inline void Vector3::Invert()
    {
        x = -x;
        y = -y;
        z = -z;
    }

    inline Vector3 Vector3::GetInverted() const
    {
        return Vector3(-x, -y, -z);
    }

    inline float Vector3::GetLength() const
    {
        return Math::Sqrt(x * x + y * y + z * z);
    }

    inline float Vector3::GetSquaredLength() const
    {
        return x * x + y * y + z * z;
    }

    inline void Vector3::SetLength(float fLength)
    {
        float fU = x * x + y * y + z * z;
        if (fU)
        {
            fU = Math::Sqrt(fU);
            if (fU)
            {
                const float fScale = fLength / fU;
                x *= fScale;
                y *= fScale;
                z *= fScale;
            }
        }
    }

    inline Vector3 &Vector3::Normalize()
    {
        float fU = x * x + y * y + z * z;
        if (fU)
        {
            fU = Math::Sqrt(fU);
            if (fU)
            {
                const float fScale = 1.0f / fU;
                x *= fScale;
                y *= fScale;
                z *= fScale;
            }
        }

        return *this;
    }

    inline Vector3 Vector3::GetNormalized() const
    {
        float fU = x * x + y * y + z * z;
        if (fU)
        {
            fU = Math::Sqrt(fU);
            if (fU)
            {
                const float fScale = 1.0f / fU;
                return Vector3(x * fScale, y * fScale, z * fScale);
            }
        }

        return Vector3::Zero;
    }

    inline float Vector3::GetDistance(const Vector3 &vV) const
    {
        const float fDX = vV.x - x;
        const float fDY = vV.y - y;
        const float fDZ = vV.z - z;
        return Math::Sqrt(fDX * fDX + fDY * fDY + fDZ * fDZ);
    }

    inline float Vector3::GetSquaredDistance(const Vector3 &vV) const
    {
        const float fDX = vV.x - x;
        const float fDY = vV.y - y;
        const float fDZ = vV.z - z;
        return fDX * fDX + fDY * fDY + fDZ * fDZ;
    }

    inline float Vector3::DotProduct(const Vector3 &vV) const
    {
        return x * vV.x + y * vV.y + z * vV.z;
    }

    inline Vector3 Vector3::ProjectVector(const Vector3 &vA, const Vector3 &vB) const
    {
        return vB * (vA.DotProduct(vB) / vB.DotProduct(vB));
    }

    inline float Vector3::GetAngle(const Vector3 &vV) const
    {
        return Math::ACos(DotProduct(vV) / (GetLength() * vV.GetLength()));
    }

    inline Vector3 Vector3::CrossProduct(const Vector3 &vV) const
    {
        return Vector3(y * vV.z - z * vV.y,
                       z * vV.x - x * vV.z,
                       x * vV.y - y * vV.x);
    }

    inline Vector3 &Vector3::CrossProduct(const Vector3 &vV1, const Vector3 &vV2)
    {
        x = vV1.y * vV2.z - vV1.z * vV2.y;
        y = vV1.z * vV2.x - vV1.x * vV2.z;
        z = vV1.x * vV2.y - vV1.y * vV2.x;
        return *this;
    }

    inline void Vector3::GetFaceNormal(const Vector3 &vV1, const Vector3 &vV2, const Vector3 &vV3)
    {
        CrossProduct(vV1 - vV2, vV1 - vV3);
        Normalize();
    }

} // LupineMath
