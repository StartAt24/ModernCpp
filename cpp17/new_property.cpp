#include <iostream>

class MyContainer{
  public:
    [[nodiscard]] bool empty() const noexcept{
      return true;
    }
}
