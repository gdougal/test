#include <iostream>
#include <vector>
//83621143489848422977 - 97
//83621143489848416212
//const uint64_t Quintus		= 83621143489848416212 : if (num < 22977 - 16212 (6765)) next = 97 else next = 98;
//const uint64_t Serenus		= 298611126818977066911787 : if (num < 8552 - 1787 (6765)) next = 114 else next = 115;
//298611126818977066918552 - 114
//298611126818977066911787
//const uint64_t Sammonicus	= 354224848179261908310 :  : if (num < 15075 - 8310 (6765)) next = 100 else next = 101;
//354224848179261915075 - 100
//354224848179261908310

struct big_int {
	typedef std::pair<uint64_t, uint64_t> bignum;
	bignum	big_data;
	const uint64_t len_second = 1e18;
	big_int() : big_data(0, 1) {};
	big_int(const bignum& ref) {
		big_data = ref;
	}
	big_int(const uint64_t& f, const uint64_t& s) : big_data(f, s) {};
	virtual ~big_int() {}

	big_int	operator+(const big_int& other) {
		big_int new_int(*this);
		uint64_t tmp = big_data.second + other.big_data.second;
		if (tmp / len_second < 1) {
			new_int.big_data.second = tmp;
		}
		else {
			new_int.big_data.first += (tmp - (tmp%len_second))/len_second;
			new_int.big_data.second = tmp%len_second;
		}
		new_int.big_data.first += other.big_data.first;
		return new_int;
	}
};

class bot_ugadun {
private:
	uint32_t							right_num;
	std::vector<uint32_t>	fib_num;
	std::vector<big_int>	fib_num2;
public:
	bot_ugadun() { std::cout << "Hi! I`am a not a human, but player, and i`am ready!" << std::endl; };

	void listen_answer(const int n_try = 0, uint32_t min = 0, uint32_t max = 0) {
		if (n_try == 0) {
			fib_fill();
			max = fib_num.size();
		}
		else if (n_try == 14) {
			std::cout << "My bad, I`am lost!" << std::endl;
			exit(0);
		}
		uint32_t pos = min + (max - min)/2;
		std::string	answer;
		std::cout << "Is right num " << std::string(std::to_string(fib_num[pos])) << " ?" << std::endl;
		std::getline(std::cin, answer);
		if (std::cin.eof())
			exit(0);
		else if (answer == "right") {
			right_num = fib_num[pos];
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
		fib_num.emplace_back(num2);
		fib_fill(num2, num1 + num2);
	}
	void	fib_fill2(big_int num1, const big_int& num2, const uint64_t iterator = 0) {
		if (iterator == 126)
			return;
		std::cout << std::to_string(num2.big_data.first) << std::to_string(num2.big_data.second) << std::endl;
		if (iterator >= 32)
		fib_num2.emplace_back(num2);
		fib_fill2(num2, num1 + num2, iterator + 1);
	}

	void generate_phrase() {
		const uint32_t	quintus		= right_num < 6765 ? 97 : 98;
		const uint32_t	serenus		= right_num < 6765 ? 114 : 115;
		const uint32_t	sammoniucs	= right_num < 6765 ? 100 : 101;
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
//	player.listen_answer();
	big_int a(0, 1);
	player.fib_fill2(a, a);
	return 0;
}
//bcsbdbebcsb
//abracadabra