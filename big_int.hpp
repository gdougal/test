//
// Created by Gilberto Dougal on 4/19/21.
//

#ifndef CT01_BIG_INT_HPP
#define CT01_BIG_INT_HPP
#include <deque>
#include <iostream>


struct big_int {
private:
	typedef std::deque<uint64_t> bignum;
	bignum	big_data;
	static const uint64_t len_second = 1e16;

public:
	big_int() : big_data(1, 1) {};
	explicit big_int(const uint64_t& ref) : big_data(1, ref) {};
	big_int(const big_int& ref);
	big_int(const std::string& ref);

	~big_int() {}

	big_int&	operator+(const big_int& other);
	bool	operator<(const big_int& other) const;
	bool	operator>(const big_int& other) const;
	bool	operator==(const big_int& other) const;
	bool	operator!=(const big_int& other) const;
};

struct cmp_big_int {
	bool operator()(const big_int& a, const big_int& b) const {
		return a < b;
	}
};

#endif //CT01_BIG_INT_HPP
