namespace LupineCore
{
  template <class AType> typename Singleton<AType>::__Destruction_Guard Singleton<AType>::__Guard;
  template <class AType> AType *Singleton<AType>::__Instance  = nullptr;
  template <class AType> bool   Singleton<AType>::__Destroyed = false;

  template <class AType> AType *Singleton<AType>::GetInstance()
  {
    __Guard.init();
    if(!__Instance && !__Destroyed)
    {
      return new AType();
    } else {
      return __Instance;
    }
  }

  template <class AType> bool Singleton<AType>::HasInstance()
  {
	   return (__Instance != nullptr);
  }

  template <class AType> Singleton<AType>::Singleton()
  {
    __Instance = static_cast<AType*>(this);
  }

  template <class AType> Singleton<AType>::~Singleton()
  {
    if(__Instance == this)
    {
      __Instance = nullptr;
      __Destroyed = true;
    }
  }
} // LupineCore
