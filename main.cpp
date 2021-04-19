#include <vector>
#include <list>
#include <map>
#include "big_int.hpp"



class bot_ugadun {
private:
	uint32_t															right_num;
	std::vector<uint32_t>									fib_small;
	std::map<big_int, uint, cmp_big_int>	fib_large;
public:
	bot_ugadun() { std::cout << "Hi! I`am a not a human, but player, and i`am ready!" << std::endl; };

	void listen_answer(const int n_try = 0, uint32_t min = 0, uint32_t max = 0) {
		if (n_try == 0) {
			fib_fill();
			max = fib_small.size();
		}
		else if (n_try == 14) {
			std::cout << "My bad, I`am lost!" << std::endl;
			exit(0);
		}
		uint32_t pos = min + (max - min)/2;
		std::string	answer;
		std::cout << "Is right num " << std::string(std::to_string(fib_small[pos])) << " ?" << std::endl;
		std::getline(std::cin, answer);
		if (std::cin.eof())
			exit(0);
		else if (answer == "right") {
			right_num = fib_small[pos];
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
			std::cout << "Please, try to right answer";
			listen_answer();
		}
	};

	void	fib_fill(const uint32_t num1 = 1, const uint32_t num2 = 1) {
		if (num2 > 9999)
			return;
		fib_small.emplace_back(num2);
		fib_fill(num2, num1 + num2);
	}
	void	fib_fill2(big_int num1, const big_int& num2, const uint iterator = 2) {
		if (iterator == 126)
			return;
		if (iterator >= 32)
			fib_large.insert(std::pair<big_int, uint>(num2, iterator));
		fib_fill2(num2, num1 + num2, iterator + 1);
	}

	void generate_phrase() {
		const uint32_t	quintus		= fib_large.upper_bound(big_int(right_num) + big_int("83621143489848416212"))->second;
		const uint32_t	serenus		= fib_large.upper_bound(big_int(right_num) + big_int("298611126818977066911787"))->second;
		const uint32_t	sammoniucs	= fib_large.upper_bound(big_int(right_num) + big_int("354224848179261908310"))->second;
		std::string			pizza_ticket(11, '0');
		for (int i = 0; i < pizza_ticket.size(); ++i) {
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
	virtual ~bot_ugadun() {}
};



int main() {
	bot_ugadun player;
	big_int a;
	player.fib_fill2(a, a);
	player.listen_answer();
//	big_int he("354224848179261908310");
	return 0;
}
//bcsbdbebcsb
//abracadabra