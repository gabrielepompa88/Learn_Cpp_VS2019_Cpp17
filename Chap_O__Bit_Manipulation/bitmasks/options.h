#ifndef OPTIONS_H
#define OPTIONS_H

#include <cstdint>
#include <bitset>

namespace options_fast_t
{
	inline constexpr std::uint_fast8_t option_viewed    { 1 << 0 };   // bit 0
	inline constexpr std::uint_fast8_t option_edited    { 1 << 1 };   // bit 1
	inline constexpr std::uint_fast8_t option_favorited { 1 << 2 };   // bit 2
	inline constexpr std::uint_fast8_t option_shared    { 1 << 3 };   // bit 3
	inline constexpr std::uint_fast8_t option_deleted   { 1 << 7 };   // bit 7
}

namespace options_bitset
{
	inline constexpr std::bitset<8> option_viewed    { 0b0000'0001 };  // bit 0
	inline constexpr std::bitset<8> option_edited    { 0b0000'0010 };  // bit 1
	inline constexpr std::bitset<8> option_favorited { 0b0000'0100 };  // bit 2
	inline constexpr std::bitset<8> option_shared    { 0b0000'1000 };  // bit 3
	inline constexpr std::bitset<8> option_deleted   { 0b1000'0000 };  // bit 7
}

#endif
