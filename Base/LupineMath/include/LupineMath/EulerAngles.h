#ifndef __LPMATH_EULERANGLES_H__
#define __LPMATH_EULERANGLES_H__
#pragma once

#include "LupineMath/LupineMath.h"

namespace LupineMath
{
        class Matrix3x3;
        class Matrix3x4;
        class Matrix4x4;
        class Quaternion;
        class EulerAngles
        {
                public:
                        enum EOrder
                        {
                                XYZs = 0,
			                    XYXs = 2,
			                    XZYs = 4,
			                    XZXs = 6,
			                    YZXs = 8,
			                    YZYs = 10,
			                    YXZs = 12,
			                    YXYs = 14,
			                    ZXYs = 16,
                    			ZXZs = 18,
			                    ZYXs = 20,
			                    ZYZs = 22,
                    			ZYXr = 1,
		                    	XYXr = 3,
			                    YZXr = 5,
			                    XZXr = 7,
			                    XZYr = 9,
			                    YZYr = 11,
			                    ZXYr = 13,
			                    YXYr = 15,
			                    YXZr = 17,
			                    ZXZr = 19,
			                    XYZr = 21,
			                    ZYZr = 23	
                        };

                public:
                        		static LPMATH_API void ToQuaternion(float fAngleX, float fAngleY, float fAngleZ, Quaternion &qRotation, EOrder nOrder = XYZs);
                               	static LPMATH_API void FromQuaternion(const Quaternion &qRotation, float &fAngleX, float &fAngleY, float &fAngleZ, EOrder nOrder = XYZs);
                                static LPMATH_API void ToMatrix(float fAngleX, float fAngleY, float fAngleZ, Matrix3x3 &mRot, EOrder nOrder = XYZs);
                        		static LPMATH_API void ToMatrix(float fAngleX, float fAngleY, float fAngleZ, Matrix3x4 &mRot, EOrder nOrder = XYZs);
		                        static LPMATH_API void ToMatrix(float fAngleX, float fAngleY, float fAngleZ, Matrix4x4 &mRot, EOrder nOrder = XYZs);
                                static LPMATH_API void FromMatrix(const Matrix3x3 &mRot, float &fAngleX, float &fAngleY, float &fAngleZ, EOrder nOrder = XYZs);
                        		static LPMATH_API void FromMatrix(const Matrix3x4 &mRot, float &fAngleX, float &fAngleY, float &fAngleZ, EOrder nOrder = XYZs);
		                        static LPMATH_API void FromMatrix(const Matrix4x4 &mRot, float &fAngleX, float &fAngleY, float &fAngleZ, EOrder nOrder = XYZs);
        
        };
} // LupineMath

#endif // __LPMATH_EULERANGLES_H__


