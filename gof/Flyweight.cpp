#include <iostream>
#include <map>
#include <vector>

using namespace std;

/* Examples of Flyweight.
 * Charactors (charactor code, font) in a text editor
 * Icons and images in a web browser.
 */


class Flyweight
{
  public:
    /* extrinsicState is context information 
     * client must give extrinsicState.
     */
    void operation(int extrinsicState) 
    { cout << intrinsicState <<" "<< extrinsicState << '\n'; }

    Flyweight(int is) : intrinsicState(is) {}

  private:
    /* Sharable state */
    int intrinsicState; /* The bigger intrinsicState size, the better memory saving. */
    /* never have ID(non-sharable state) here */
};


class FlyweightFactory
{
  public:
    /*can be static */
    Flyweight *getFlyWeight(int key)
    {
      if (poolOfFlyweight.find(key) == poolOfFlyweight.end()){
        int intrinsicState = createIntrinsicSateByKey(key);
        poolOfFlyweight[key] = new Flyweight(intrinsicState);
      }
      return poolOfFlyweight[key]; /* Share */
    }

    FlyweightFactory(){ /* Eagarly initialize Flyweight pool, if you want. */ }

  private:
    std::map<int, Flyweight*> poolOfFlyweight;
    int createIntrinsicSateByKey(int key){ return key; }
};

/* client */
int main()
{
  FlyweightFactory factory; 
  /* Client can maintain the reference to Flyweight */
  std::vector<Flyweight*> flyweights;

  /* Should not create or access Flyweight directly.
   * Always get Flyweight via FlyweightFactory.
   */

  for (int fwIdx = 0; fwIdx < 2; ++fwIdx)
    for (int i = 0; i < 3; ++i)
      factory.getFlyWeight(fwIdx)->operation(i+fwIdx);  /* extrinsicState can be calculated. */
}