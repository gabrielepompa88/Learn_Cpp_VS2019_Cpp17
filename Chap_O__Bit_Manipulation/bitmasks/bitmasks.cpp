#include "options.h"
#include <cstdint>
#include <iostream>

int main()
{

    std::cout << "Using bit-masks:\n";

    std::uint_fast8_t myArticleFlags{};


    myArticleFlags |= options_fast_t::option_viewed; // set as viewed and check it
    std::cout << "Is myArticle viewed? " << ((myArticleFlags & options_fast_t::option_viewed) ? "yes!\n" : "no...\n");

    // check if it is deleted
    std::cout << "Is myArticle deleted? " << ((myArticleFlags & options_fast_t::option_deleted) ? "yes!\n" : "no...\n");

    // set as favorited
    myArticleFlags |= options_fast_t::option_favorited;
    std::cout << "Is myArticle originally favorited? " << ((myArticleFlags & options_fast_t::option_favorited) ? "yes!\n" : "no...\n");

    // clear it as a favorited (if it is)
    myArticleFlags &= ~options_fast_t::option_favorited;
    std::cout << "Is myArticle now favorited? " << ((myArticleFlags & options_fast_t::option_favorited) ? "yes!\n" : "no...\n");
       
    std::cout << "Using bitset:\n";

    std::bitset<8> myArticleBitset{};

    myArticleBitset |= options_bitset::option_viewed; // set as viewed and check it
    std::cout << "Is myArticle viewed? " << ((myArticleBitset & options_bitset::option_viewed).any() ? "yes!\n" : "no...\n");

    // check if it is deleted
    std::cout << "Is myArticle deleted? " << ((myArticleBitset & options_bitset::option_deleted).any() ? "yes!\n" : "no...\n");

    // set as favorited
    myArticleBitset |= options_bitset::option_favorited;
    std::cout << "Is myArticle originally favorited? " << ((myArticleBitset & options_bitset::option_favorited).any() ? "yes!\n" : "no...\n");

    // clear it as a favorited (if it is)
    myArticleBitset &= ~options_bitset::option_favorited;
    std::cout << "Is myArticle now favorited? " << ((myArticleBitset & options_bitset::option_favorited).any() ? "yes!\n" : "no...\n");

    return 0;
}