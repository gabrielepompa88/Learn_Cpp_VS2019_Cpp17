#include <cstdint>
#include <iostream>

int main()
{
    constexpr std::uint_fast8_t option_viewed{ 0b0000'0001 };       // bit 0
    constexpr std::uint_fast8_t option_edited{ 0b0000'0010 };       // bit 1
    constexpr std::uint_fast8_t option_favorited{ 0b0000'0100 };    // bit 2
    constexpr std::uint_fast8_t option_shared{ 0b0000'1000 };       // bit 3
    constexpr std::uint_fast8_t option_deleted{ 0b1000'0000 };      // bit 7

    std::uint_fast8_t myArticleFlags{};

    myArticleFlags |= option_viewed; // set as viewed and check it
    std::cout << "My Article is viewed? " << ((myArticleFlags & option_viewed) ? "yes!\n" : "no...\n");

    // check if it is deleted
    std::cout << "My Article is deleted? " << ((myArticleFlags & option_deleted) ? "yes!\n" : "no...\n");

    // clear it as a favorited (if it is)
    std::cout << "My Article is originally favorited? " << ((myArticleFlags & option_favorited) ? "yes!\n" : "no...\n");
    myArticleFlags &= ~option_favorited;
    std::cout << "My Article is now favorited? " << ((myArticleFlags & option_favorited) ? "yes!\n" : "no...\n");
       
    return 0;
}