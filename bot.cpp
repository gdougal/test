//
// Created by Gilberto Dougal on 4/20/21.
//

#include "bot.hpp"

bot_ugadun::bot_ugadun() {
	fibonnachi_fill(1, 1);
	std::cout << "Hi! I`am a not a human, but player, and i`am ready!" << std::endl;
}

bot_ugadun::~bot_ugadun() {}

void bot_ugadun::listen_answer(size_t n_try, size_t min, size_t max) {
	if (n_try == 0) {
		++n_try;
		max = fib_small.size();
	}
	else if (n_try == 14) {
		std::cout << "My bad, I`am lost!" << std::endl;
		exit(0);
	}
	size_t pos = min + (max - min)/2;
	std::string	answer;
	std::cout << "Is right num " << std::string(std::to_string(fib_small.at(pos))) << " ?" << std::endl;
	std::cout << "(commands: right/bigger/less) : ";
	std::getline(std::cin, answer);
	if (std::cin.eof())
		exit(0);
	else if (answer == "right" || max == min) {
		if (max == min) {
			std::cout << "U tried lie to me..." << std::endl;
		}
		right_num = fib_small.at(pos);
		std::cout << "Yaaahy! Congratulation on me!" << std::endl;
		generate_phrase();
		return ;
	}
	else if (answer == "less") {
		listen_answer(n_try + 1, min, pos);
	}
	else if (answer == "bigger") {
		listen_answer(n_try + 1, pos, max);
	}
	else {
		std::cout << "Please, try to right answer" << std::endl;
		listen_answer(n_try, min, max);
	}
}

void bot_ugadun::emplace(const uint32_t &second, ...) {
	if (second < 9999) {
		fib_small.emplace_back(second);
	}
}

void bot_ugadun::emplace(const big_int &second, const uint64_t iterator) {
	if (iterator > 31) {
		fib_large.insert(std::pair<big_int, uint>(second, iterator));
	}
}

void bot_ugadun::generate_phrase() {
	const size_t	quintus		= fib_large.upper_bound(big_int("83621143489848416212") + big_int(right_num))->second;
	const size_t	serenus		= fib_large.upper_bound(big_int(right_num) + big_int("298611126818977066911787"))->second;
	const size_t	sammoniucs	= fib_large.upper_bound(big_int(right_num) + big_int("354224848179261908310"))->second;
	std::string			pizza_ticket(11, '0');
	for (size_t i = 0; i < pizza_ticket.size(); ++i) {
		if (i == 0 || i == 3 || i == 5 || i == 7 || i == 10) {
			pizza_ticket[i] = (char)quintus;
		}
		else if (i == 1 || i == 8) {
			pizza_ticket[i] = (char)(quintus + 1);
		}
		else if (i == 2 || i == 9) {
			pizza_ticket[i] = (char)(serenus);
		}
		else if (i == 4) {
			pizza_ticket[i] = (char)(sammoniucs - 1);
		}
		else if (i == 6) {
			pizza_ticket[i] = (char)(sammoniucs);
		}
	}
	std::cout << "Your code phrase for free pizza: " << pizza_ticket << std::endl;
}
