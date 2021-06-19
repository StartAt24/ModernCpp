#include <iostream>

class MyContainer{
  public:
    [[nodiscard]] bool empty() const noexcept{
      return true;
    }
};


void foo(int val, [[maybe_unused]] std::string msg){
  #ifdef DEBUG
    std::cout << msg << std::endl;
  #endif
}

void commentPlace(int place){
  switch(place){
    case 1:
      std::cout << "very";
      [[fallthrough]];
    case 2:
      std::cout << "well\n";
      break;
    default:
      std::cout << "OK\n";
      break;
  }
}
