namespace LupineMath
{
    inline Matrix3x3::Matrix3x3() : xx(1.0f), yx(0.0f), zx(0.0f),
                                    xy(0.0f), yy(1.0f), zy(0.0f),
                                    xz(0.0f), yz(1.0f), zz(1.0f)
    {
    }

    inline Matrix3x3::Matrix3x3(const float fS[])
    {
        LupineCore::MemoryManager::Copy(this->fM, fS, sizeof(float) * 9);
    }

    inline Matrix3x3::Matrix3x3(const Matrix3x3 &mM)
    {
        LupineCore::MemoryManager::Copy(this->fM, mM.fM, sizeof(float) * 9);
    }

    inline Matrix3x3::Matrix3x3(float fXX, float fXY, float fXZ,
                                float fYX, float fYY, float fYZ,
                                float fZX, float fZY, float fZZ) :

                                xx(fXX), yx(fYX), zx(fZX),
                                xy(fXY), yy(fYY), zy(fZY),
                                xz(fXZ), yz(fYZ), zz(fZZ)
    {
    }

    inline Matrix3x3::~Matrix3x3()
    {
    }

    inline Matrix3x3 &Matrix3x3::operator=(const float fS[])
    {
        LupineCore::MemoryManager::Copy(this->fM, fS, sizeof(float) * 9);
        return *this;
    }

    inline Matrix3x3 &Matrix3x3::operator=(const Matrix3x3 &mM)
    {
        LupineCore::MemoryManager::Copy(this->fM, mM.fM, sizeof(float) * 9);
        return *this;
    }

    inline Matrix3x3 Matrix3x3::operator+(const Matrix3x3 &mM) const
    {
        return Matrix3x3(xx + mM.xx, xy + mM.xy, xz + mM.xz,
                         yx + mM.yx, yy + mM.yy, yz + mM.yz,
                         zx + mM.zx, zy + mM.zy, zz + mM.zz);
    }

    inline void Matrix3x3::operator+=(const Matrix3x3 &mM)
    {
        xx += mM.xx;
        xy += mM.xy;
        xz += mM.xz;
        yx += mM.yx;
        yy += mM.yy;
        yz += mM.yz;
        zx += mM.zx;
        zy += mM.zy;
        zz += mM.zz;
    }

    inline Matrix3x3 Matrix3x3::operator-() const
    {
        return GetInverted();
    }

    inline Matrix3x3 Matrix3x3::operator-(const Matrix3x3 &mM) const
    {
        return Matrix3x3(xx - mM.xx, xy - mM.xy, xz - mM.xz,
                         yx - mM.yx, yy - mM.yy, yz - mM.yz,
                         zx - mM.zx, zy - mM.zy, zz - mM.zz);
    }

    inline void Matrix3x3::operator-=(const Matrix3x3 &mM)
    {
        xx -= mM.xx;
        xy -= mM.xy;
        xz -= mM.xz;
        yx -= mM.yx;
        yy -= mM.yy;
        yz -= mM.yz;
        zx -= mM.zx;
        zy -= mM.zy;
        zz -= mM.zz;
    }

    inline Matrix3x3 Matrix3x3::operator*(float fS) const
    {
        return Matrix3x3(xx * fS, xy * fS, xz * fS,
                         yx * fS, yy * fS, yz * fS,
                         zx * fS, zy * fS, zz * fS);
    }

    inline void Matrix3x3::operator*=(float fS)
    {
        xx *= fS;
        xy *= fS;
        xz *= fS;
        yx *= fS;
        yy *= fS;
        yz *= fS;
        zx *= fS;
        zy *= fS;
        zz *= fS;
    }

    inline Vector2 Matrix3x3::operator*(const Vector2 &vV) const
    {
        const float x = vV.x, y = vV.y;
        return Vector2(xx * x + xy * y,
                       yx * x + yy * y);
    }

    inline Vector3 Matrix3x3::operator*(const Vector3 &vV) const
    {
        const float x = vV.x, y = vV.y, z = vV.z;
        return Vector3(xx * x + xy * y + xz * z,
                       yx * x + yy * y + yz * z,
                       zx * x + zy * y + zz * z);
    }

    inline void Matrix3x3::operator*=(const Matrix3x3 &mM)
    {
        *this = *this * mM;
    }

    inline Matrix3x3 Matrix3x3::operator/(float fS) const
    {
        return Matrix3x3(xx / fS, xy / fS, xz / fS,
                         yx / fS, yy / fS, yz / fS,
                         zx / fS, zy / fS, zz / fS);
    }

    inline void Matrix3x3::operator/=(float fS)
    {
        xx /= fS;
        xy /= fS;
        xz /= fS;
        yx /= fS;
        yy /= fS;
        yz /= fS;
        zx /= fS;
        zy /= fS;
        zz /= fS;
    }

    inline float Matrix3x3::operator[](int nIndex) const
    {
        return fM[nIndex];
    }

    inline float &Matrix3x3::operator[](int nIndex)
    {
        return fM[nIndex];
    }

    inline float Matrix3x3::operator()(LupineCore::uint32 nRow, LupineCore::uint32 nColumn) const
    {
        return fM[nRow + 3 * nColumn];
    }

    inline float &Matrix3x3::operator()(LupineCore::uint32 nRow, LupineCore::uint32 nColumn)
    {
        return fM[nRow + 3 * nColumn];
    }

    inline Matrix3x3::operator float *()
    {
        return this->fM;
    }

    inline Matrix3x3::operator const float *() const
    {
        return this->fM;
    }

    inline bool Matrix3x3::IsZero() const
    {
        return (Math::AreEqual(xx, 0.0f) && Math::AreEqual(xy, 0.0f) && Math::AreEqual(xz, 0.0f) &&
                Math::AreEqual(yx, 0.0f) && Math::AreEqual(yy, 0.0f) && Math::AreEqual(yz, 0.0f) &&
                Math::AreEqual(zx, 0.0f) && Math::AreEqual(zy, 0.0f) && Math::AreEqual(zz, 0.0f));
    }

    inline bool Matrix3x3::IsTrueZero() const
    {
        return (LupineCore::MemoryManager::Compare(this->fM, Zero.fM, sizeof(float) * 9) == 0);
    }

    inline void Matrix3x3::SetZero()
    {
        LupineCore::MemoryManager::Set(this->fM, 0, sizeof(float) * 9);
    }

    inline bool Matrix3x3::IsIdentity() const
    {
        return (Math::AreEqual(xx, 1.0f) && Math::AreEqual(xy, 0.0f) && Math::AreEqual(xz, 0.0f) &&
                Math::AreEqual(yx, 0.0f) && Math::AreEqual(yy, 1.0f) && Math::AreEqual(yz, 0.0f) &&
                Math::AreEqual(zx, 0.0f) && Math::AreEqual(zy, 0.0f) && Math::AreEqual(zz, 1.0f));
    }

    inline bool Matrix3x3::IsTrueIdentity() const
    {
        return (LupineCore::MemoryManager::Compare(this->fM, Identity.fM, sizeof(float) * 9) == 0);
    }

    inline void Matrix3x3::SetIdentity()
    {
        LupineCore::MemoryManager::Copy(this->fM, Identity.fM, sizeof(float) * 9);
    }

    inline void Matrix3x3::Set(float fXX, float fXY, float fXZ,
                               float fYX, float fYY, float fYZ,
                               float fZX, float fZY, float fZZ)
    {
        xx = fXX;
        xy = fXY;
        xz = fXZ;
        yx = fYX;
        yy = fYY;
        yz = fYZ;
        zx = fZX;
        zy = fZY;
        zz = fZZ;
    }

    inline Vector3 Matrix3x3::GetRow(LupineCore::uint8 nRow) const
    {
        switch (nRow)
        {
        case 0:
            return Vector3(xx, xy, xz);
        case 1:
            return Vector3(yx, yy, yz);
        case 2:
            return Vector3(zx, zy, zz);
        default:
            return Vector3::Zero; // Error!
        }
    }

    inline void Matrix3x3::SetRow(LupineCore::uint8 nRow, const Vector3 &vRow)
    {
        switch (nRow)
        {
        case 0:
            xx = vRow.x;
            xy = vRow.y;
            xz = vRow.z;
            break;
        case 1:
            yx = vRow.x;
            yy = vRow.y;
            yz = vRow.z;
            break;
        case 2:
            zx = vRow.x;
            zy = vRow.y;
            zz = vRow.z;
            break;
        }
    }

    inline Vector3 Matrix3x3::GetColumn(LupineCore::uint8 nColumn) const
    {
        switch (nColumn)
        {
        case 0:
            return Vector3(xx, yx, zx);
        case 1:
            return Vector3(xy, yy, zy);
        case 2:
            return Vector3(xz, yz, zz);
        default:
            return Vector3::Zero; // Error!
        }
    }

    inline void Matrix3x3::SetColumn(LupineCore::uint8 nColumn, const Vector3 &vColumn)
    {
        switch (nColumn)
        {
        case 0:
            xx = vColumn.x;
            yx = vColumn.y;
            zx = vColumn.z;
            break;
        case 1:
            xy = vColumn.x;
            yy = vColumn.y;
            zy = vColumn.z;
            break;
        case 2:
            xz = vColumn.x;
            yz = vColumn.y;
            zz = vColumn.z;
            break;
        }
    }

    inline bool Matrix3x3::IsSymmetric() const
    {
        return (Math::AreEqual(xy, yx) && Math::AreEqual(xz, zx) && Math::AreEqual(yz, zy));
    }

    inline bool Matrix3x3::IsOrthogonal() const
    {
        return (GetTransposed() == GetInverted());
    }

    inline bool Matrix3x3::IsRotationMatrix() const
    {
        return (GetTransposed() == GetInverted() && Math::AreEqual(GetDeterminant(), 1.0f));
    }

    inline float Matrix3x3::GetTrace() const
    {
        return xx + yy + zz;
    }

    inline float Matrix3x3::GetDeterminant() const
    {
        return xx * (yy * zz - yz * zy) - yx * (xy * zz - xz * zy) + zx * (xy * yz - xz * yy);
    }

    inline void Matrix3x3::Transpose()
    {
        float fT = xy;
        xy = yx;
        yx = fT;

        fT = xz;
        xz = zx;
        zx = fT;

        fT = yz;
        yz = zy;
        zy = fT;
    }

    inline Matrix3x3 Matrix3x3::GetTransposed() const
    {
        return Matrix3x3(xx, yx, zx,
                         xy, yy, zy,
                         xz, yz, zz);
    }

    inline void Matrix3x3::SetScaleMatrix(float fX, float fY, float fZ)
    {
        xx = fX;
        xy = 0.0f;
        xz = 0.0f;
        yx = 0.0f;
        yy = fY;
        yz = 0.0f;
        zx = 0.0f;
        zy = 0.0f;
        zz = fZ;
    }

    inline void Matrix3x3::SetScaleMatrix(const Vector3 &vV)
    {
        xx = vV.x;
        xy = 0.0f;
        xz = 0.0f;
        yx = 0.0f;
        yy = vV.y;
        yz = 0.0f;
        zx = 0.0f;
        zy = 0.0f;
        zz = vV.z;
    }

    inline Vector3 Matrix3x3::GetScale() const
    {
        Vector3 vScale;
        GetScale(vScale.x, vScale.y, vScale.z);
        return vScale;
    }

    inline void Matrix3x3::GetScale(float fV[]) const
    {
        GetScale(fV[0], fV[1], fV[2]);
    }

    inline Vector3 Matrix3x3::GetXAxis() const
    {
        return Vector3(xx, yx, zx);
    }

    inline Vector3 Matrix3x3::GetYAxis() const
    {
        return Vector3(xy, yy, zy);
    }

    inline Vector3 Matrix3x3::GetZAxis() const
    {
        return Vector3(xz, yz, zz);
    }

    inline Matrix3x3 &Matrix3x3::SetShearing(float fShearXY, float fShearXZ, float fShearYX, float fShearYZ,
                                             float fShearZX, float fShearZY)
    {
        xx = 1.0f;
        xy = fShearYX;
        xz = fShearZX;
        yx = fShearXY;
        yy = 1.0f;
        yz = fShearZY;
        zx = fShearXZ;
        zy = fShearYZ;
        zz = 1.0f;
        return *this;
    }

} // LupineMath
