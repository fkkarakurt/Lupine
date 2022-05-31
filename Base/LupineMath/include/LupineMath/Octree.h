#ifndef __LPMATH_OCTREE_H__
#define __LPMATH_OCTREE_H__
#pragma once

#include "LupineMath/BoundingBox.h"

namespace LupineCore
{
  class Bitset;
} // LupineCore

namespace LupineMath
{
  class PlaneSet;
} // LupineMath

namespace LupineMath
{
  class Octree
  {
    public:
      LPMATH_API Octree();
      LPMATH_API virtual ~Octree();
      LPMATH_API bool IsBuild() const;
      LPMATH_API void Init(Octree *pParent = nullptr, int nSubdivide = -1, LupineCore::uint32 nMinGeometries = 0, LupineCore::uint32 nIDOffset = 0);
      LPMATH_API void Destroy();
      LPMATH_API LupineCore::uint32 GetLevel() const;
      LPMATH_API bool IsVisible() const;
      LPMATH_API void SetVisible(bool bVisible = true);
      LPMATH_API const BoundingBox &GetBoundingBox() const;
      LPMATH_API int GetSubdivide() const;
      LPMATH_API LupineCore::uint32 GetMinGeometries() const;
      LPMATH_API const Vector3 &GetPos() const;
      LPMATH_API void SetPos(const Vector3 &vPos);
      LPMATH_API const Vector3 &GetScale() const;
      LPMATH_API void SetScale(const Vector3 &vScale);
      LPMATH_API const Matrix3x3 &GetRot() const;
      LPMATH_API void SetRot(const Matrix3x3 &mRot);
      LPMATH_API void UpdateVisibility(const PlaneSet &cPlaneSet, LupineCore::Bitset *pBitset = nullptr);
      LPMATH_API void CheckSphere(const Vector3 &vPos, float fRadius);
      LPMATH_API void CheckBox(const BoundingBox &cBox);

    protected:
      LupineCore::uint32 m_nIDOffset;
      LupineCore::uint32 m_nID;
      Octree *m_pTopmost;
      Octree *m_pParent;
      LupineCore::uint32 m_nLevel;
      LupineCore::uint32 m_nNumOfChildren;
      Octree **m_ppChild;
      BoundingBox m_cBoundingBox;
      Vector3 m_vPos;
      Vector3 m_vBBCenter;
      bool m_bVisible;
      bool m_bBuild;
      int m_nSubdivide;
      LupineCore::uint32 m_nMinGeometries;

    private:
      Octree(const Octree &cSource);
      Octree &operator =(const Octree &cSource);

    private:
      LPMATH_API virtual void CustomVisible(LupineCore::Bitset *pBitset = nullptr);
      LPMATH_API virtual void CustomInvisible(LupineCore::Bitset *pBitset = nullptr);
  };
} // LupineMath

#endif // __LPMATH_OCTREE_H__
