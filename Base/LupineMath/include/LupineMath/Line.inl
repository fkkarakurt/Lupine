namespace LupineMath
{
  inline Line::Line()
  {

  }

  inline Line::Line(const Line &cSource) : vStart(cSource.vStart), vEnd(cSource.vEnd)
  {

  }

  inline Line::Line(const Vector3 &vStartPoint, const Vector3 &vEndPoint) :	vStart(vStartPoint), vEnd(vEndPoint)
  {

  }

  inline Line::~Line()
  {

  }

  inline Line &Line::operator =(const Line &cSource)
  {
    vStart = cSource.vStart;
    vEnd = cSource.vEnd;
    return *this;
  }

  inline void Line::Set(const Vector3 &vStart, const Vector3 &vEnd)
  {
	  this->vStart = vStart;
	  this->vEnd   = vEnd;
  }

} // LupineMath
