#include <iostream>
#include <string>
#include <functional>

int main()
{
    std::string favoriteFruit{ "grapes" };

    // explicitly the lambda can be declared as: std::function<void()> printFavoriteFruit;
    auto printFavoriteFruitValueCaptured{
      [=]() {
        std::cout << "in printFavoriteFruitValueCaptured: I like " << favoriteFruit << '\n';
      }
    };

    auto printFavoriteFruitReferenceCaptured{
      [&]() {
        std::cout << "in printFavoriteFruitReferenceCaptured: I like " << favoriteFruit << '\n';
      }
    };

    favoriteFruit = "bananas with chocolate";

    printFavoriteFruitValueCaptured();
    printFavoriteFruitReferenceCaptured();

    std::cout << "in main: I like " << favoriteFruit << '\n';

    return 0;
}