namespace LupineCore
{
  template <class AType>
  RefCount<AType>::RefCount() : m_nRefCount(0)
  {

  }

  template <class AType>
  RefCount<AType>::~RefCount()
  {

  }

  template <class AType>
  const AType *RefCount<AType>::GetPointer() const
  {
    return reinterpret_cast<const AType*>(this);
  }

  template <class AType>
  AType *RefCount<AType>::GetPointer()
  {
    return reinterpret_cast<AType*>(this);
  }

  template <class AType>
  uint32 RefCount<AType>::AddReference()
  {
    m_nRefCount++;
    return m_nRefCount;
  }

  template <class AType>
  uint32 RefCount<AType>::Release()
  {
    if(m_nRefCount > 1)
    {
        m_nRefCount--;
        return m_nRefCount;
    } else {
        delete this;
        return 0;
    }
  }

  template <class AType>
  uint32 RefCount<AType>::GetRefCount() const
  {
    return m_nRefCount;
  }

} // LupineCore
