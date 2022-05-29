namespace LupineCore
{
  template <class AType>
  RefCountPtr<AType>::RefCountPtr(AType *pPointer) : m_pPointer(pPointer)
  {

  }

  template <class AType>
  RefCountPtr<AType>::~RefCountPtr()
  {
    if(m_pPointer)
      delete m_pPointer;
  }

  template <class AType>
  const AType *RefCountPtr<AType>::GetPointer() const
  {
    return m_pPointer;
  }

  template <class AType>
  AType *RefCountPtr<AType>::GetPointer()
  {
    return m_pPointer;
  }
} // LupineCore
