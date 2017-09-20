#include <iostream>
#include <string.h>

class Strategy;

/* client */
class Context
{
  public:
    enum StrategyType
    {
        Dummy, Left, Right
    };
    Context()
    {
        strategy_ = NULL;
    }
    void setStrategy(int type, int width);
    void doIt();
  private:
    Strategy *strategy_;
};

class Strategy
{
  public:
    void runAlgorithm()
    {
      /*call doSpecific */
    }
    Strategy(int width): width_(width){}
  protected:
    int width_; /* inherit to subclass */
  private:
    virtual void doSpecific(char *line) = 0;
};

class LeftStrategy: public Strategy
{
  private:
    void doSpecific(char *line)
    {
    }
  public:
    LeftStrategy(int width): Strategy(width){}
};

class RightStrategy: public Strategy
{
  public:
    RightStrategy(int width): Strategy(width){}
  private:
    void doSpecific(char *line)
    {
    }
};

/* concrete strategy dynamic binding */
void Context::setStrategy(int type, int width)
{
  delete strategy_;
  if (type == Left)
    strategy_ = new LeftStrategy(width);
  else if (type == Right)
    strategy_ = new RightStrategy(width);
}

void Context::doIt()
{
  strategy_->runAlgorithm(); // or strategy_->doSpecific()
}

int main()
{
  Context test;
  int answer, width;
  std::cout << "Exit(0) Left(1) Right(2) : ";
  std::cin >> answer;
  while (answer)
  {
    std::cout << "Width: ";
    std::cin >> width;
    test.setStrategy(answer, width);
    test.doIt();
    std::cout << "Exit(0) Left(1) Right(2) : ";
    std::cin >> answer;
  }
  return 0;
}