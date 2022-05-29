namespace LupineCore
{
  inline bool XmlBase::IsWhiteSpaceCondensed()
  {
    return bCondenseWhiteSpace;
  }

  inline void XmlBase::SetCondenseWhiteSpace(bool bCondense)
  {
    bCondenseWhiteSpace = bCondense;
  }

  inline int XmlBase::GetRow() const
  {
    return m_cCursor.nRow + 1;
  }

  inline int XmlBase::GetColumn() const
  {
    return m_cCursor.nColumn + 1;
  }

  inline void *XmlBase::GetUserData() const
  {
    return m_pUserData;
  }

  inline void XmlBase::SetUserData(void *pUser)
  {
    m_pUserData = pUser;
  }
} // LupineCore
