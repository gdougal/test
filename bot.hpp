//
// Created by Gilberto Dougal on 4/20/21.
//

#ifndef CT01_BOT_HPP
#define CT01_BOT_HPP
#include "big_int.hpp"
#include <vector>
#include <list>
#include <map>

class bot_ugadun {
private:
	uint32_t															right_num;
	std::vector<uint32_t>									fib_small;
	std::map<big_int, uint32_t, cmp_big_int>	fib_large;
public:
	bot_ugadun();
	~bot_ugadun();

	void listen_answer(size_t n_try = 0, size_t min = 0, size_t max = 0);
	void generate_phrase();

	void emplace(const uint32_t& second ...);
	void emplace(const big_int& second, uint64_t iterator);

	template<class T>
	void	fibonnachi_fill(T first, const T& second, const uint32_t iterator = 2) {
		if (iterator == 126)
			return;
		emplace(second, iterator);
		if (iterator == 31) {
			fibonnachi_fill(big_int(second), big_int(first + second), iterator + 1);
		}
		fibonnachi_fill(second, first + second, iterator + 1);
	}
};

#endif //CT01_BOT_HPP
