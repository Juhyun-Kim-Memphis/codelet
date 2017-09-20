#include <iostream>
#include <string.h>

class Strategy;

/* client. static binding of strategy */
template <class AStrategy>
class Context
{
  public:
    void doIt(); // call strategy
  private:
    AStrategy strategy;
};

class LeftStrategy
{
  public:
    void doSpecific(){ std::cout <<"Left\n"; }
};

class RightStrategy
{
  public:
    void doSpecific(){ std::cout <<"Right\n"; }
};

template <class T>
void Context<T>::doIt()
{
  strategy.doSpecific();
}

int main()
{
  Context<RightStrategy> ctxt;
  ctxt.doIt();
  return 0;
}