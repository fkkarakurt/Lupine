#ifndef __LPMATH_TYPE_VECTOR3_INL__
#define __LPMATH_TYPE_VECTOR3_INL__
#pragma once

#include <LupineCore/Base/Var/Var.h>

namespace LupineCore
{
  template <>
  class Type<LupineMath::Vector3>
  {
  public:
    typedef LupineMath::Vector3 _Type;
    typedef LupineMath::Vector3 _StorageType;
    static const int TypeID = 1001;

    static String GetTypeName()
    {
      return "vector3";
    }

    static LupineMath::Vector3 ConvertFromVar(const DynVar &cDynVar)
		{
			return (cDynVar.GetTypeID() == TypeID) ? static_cast<const Var<LupineMath::Vector3>&>(cDynVar).Get() : cDynVar.GetString();
		}

    static bool ConvertToBool(const LupineMath::Vector3 &vVector)
		{
			return vVector.IsNull();
		}

    static LupineMath::Vector3 ConvertFromBool(bool bValue)
		{
			const float fValue = bValue ? 1.0f : 0.0f;
			return LupineMath::Vector3(fValue, fValue, fValue);
		}

    static int ConvertToInt(const LupineMath::Vector3 &vVector)
		{
			return vVector.IsNull();
		}

    static LupineMath::Vector3 ConvertFromInt(int nValue)
		{
			return LupineMath::Vector3(static_cast<float>(nValue), static_cast<float>(nValue), static_cast<float>(nValue));
		}

    static int8 ConvertToInt8(const LupineMath::Vector3 &vVector)
		{
			return static_cast<int8>(ConvertToInt(vVector));
		}

    static LupineMath::Vector3 ConvertFromInt8(int8 nValue)
		{
			return LupineMath::Vector3(static_cast<float>(nValue), static_cast<float>(nValue), static_cast<float>(nValue));
		}

    static int16 ConvertToInt16(const LupineMath::Vector3 &vVector)
		{
			return static_cast<int16>(ConvertToInt(vVector));
		}

    static LupineMath::Vector3 ConvertFromInt16(int16 nValue)
		{
			return LupineMath::Vector3(static_cast<float>(nValue), static_cast<float>(nValue), static_cast<float>(nValue));
		}

    static int32 ConvertToInt32(const LupineMath::Vector3 &vVector)
		{
			return static_cast<int32>(ConvertToInt(vVector));
		}

    static LupineMath::Vector3 ConvertFromInt32(int32 nValue)
		{
			return LupineMath::Vector3(static_cast<float>(nValue), static_cast<float>(nValue), static_cast<float>(nValue));
		}

    static int64 ConvertToInt64(const LupineMath::Vector3 &vVector)
		{
			return static_cast<int64>(ConvertToInt(vVector));
		}

    static LupineMath::Vector3 ConvertFromInt64(int64 nValue)
		{
			return LupineMath::Vector3(static_cast<float>(nValue), static_cast<float>(nValue), static_cast<float>(nValue));
		}

    static uint8 ConvertToUInt8(const LupineMath::Vector3 &vVector)
		{
			return static_cast<uint8>(ConvertToInt(vVector));
		}

    static LupineMath::Vector3 ConvertFromUInt8(uint8 nValue)
		{
			return LupineMath::Vector3(static_cast<float>(nValue), static_cast<float>(nValue), static_cast<float>(nValue));
		}

    static uint16 ConvertToUInt16(const LupineMath::Vector3 &vVector)
		{
			return static_cast<uint16>(ConvertToInt(vVector));
		}

    static LupineMath::Vector3 ConvertFromUInt16(uint16 nValue)
		{
			return LupineMath::Vector3(static_cast<float>(nValue), static_cast<float>(nValue), static_cast<float>(nValue));
		}

    static uint32 ConvertToUInt32(const LupineMath::Vector3 &vVector)
		{
			return static_cast<uint32>(ConvertToInt(vVector));
		}

    static LupineMath::Vector3 ConvertFromUInt32(uint32 nValue)
		{
			return LupineMath::Vector3(static_cast<float>(nValue), static_cast<float>(nValue), static_cast<float>(nValue));
		}

    static uint64 ConvertToUInt64(const LupineMath::Vector3 &vVector)
		{
			return static_cast<uint64>(ConvertToInt(vVector));
		}

    static LupineMath::Vector3 ConvertFromUInt64(uint64 nValue)
		{
			return LupineMath::Vector3(static_cast<float>(nValue), static_cast<float>(nValue), static_cast<float>(nValue));
		}

    static uint_ptr ConvertToUIntPtr(const LupineMath::Vector3 &vVector)
		{
			return static_cast<uint_ptr>(ConvertToInt(vVector));
		}

    static LupineMath::Vector3 ConvertFromUIntPtr(uint_ptr nValue)
		{
			return LupineMath::Vector3(static_cast<float>(nValue), static_cast<float>(nValue), static_cast<float>(nValue));
		}

    static float ConvertToFloat(const LupineMath::Vector3 &vVector)
		{
			return static_cast<float>(ConvertToInt(vVector));
		}

    static LupineMath::Vector3 ConvertFromFloat(float fValue)
		{
			return LupineMath::Vector3(fValue, fValue, fValue);
		}

    static double ConvertToDouble(const LupineMath::Vector3 &vVector)
		{
			return static_cast<double>(ConvertToInt(vVector));
		}

    static LupineMath::Vector3 ConvertFromDouble(double dValue)
		{
			return LupineMath::Vector3(static_cast<float>(dValue), static_cast<float>(dValue), static_cast<float>(dValue));
		}

    static String ConvertToString(const LupineMath::Vector3 &vVector)
		{
			return vVector.ToString();
		}

    static LupineMath::Vector3 ConvertFromString(const String &sString)
		{
			LupineMath::Vector3 vVector;
			vVector.FromString(sString);
			return vVector;
		}

    static LupineMath::Vector3 &ConvertRealToStorage(LupineMath::Vector3 &vValue)
		{
			return vValue;
		}

    static LupineMath::Vector3 &ConvertStorageToReal(LupineMath::Vector3 &vValue)
		{
			return vValue;
		}
  };

} // LupineCore

#endif // __LPMATH_TYPE_VECTOR3_INL__
