/**
 * File              : Line.h
 * Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 * Date              : 29.05.2022
 * Last Modified Date: 29.05.2022
 * Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
 */

#ifndef __LPMATH_LINE_H__
#define __LPMATH_LINE_H__
#pragma once

#include "LupineMath/Vector3.h"

namespace LupineMath
{
    class Line
    {
        public:
            Vector3 vStart;
            Vector3 vEnd;
        public:
            inline Line();
            inline Line(const Line &cSource);
            inline Line(const Vector3 &vStartPoint, const Vector3 &vEndPoint);
            inline ~Line();
            inline Line &operator=(const Line &cSource);
            inline void Set(const Vector3 &vStart, const Vector3 &vEnd);
            LPMATH_API Line operator*(const Matrix3x3 &mRot) const;
            LPMATH_API Line operator*(const Matrix3x4 &mTrans) const;
            LPMATH_API Line operator*(const Matrix4x4 &mTrans) const;
            LPMATH_API Line &operator*=(const Matrix3x3 &mRot);
            LPMATH_API Line &operator*=(const Matrix3x4 &mTrans);
            LPMATH_API Line &operator*=(const Matrix4x4 &mTrans);
    };

} // LupineMath

// .inl

#endif // __LPMATH_LINE_H__