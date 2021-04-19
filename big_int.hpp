//
// Created by Gilberto Dougal on 4/19/21.
//

#ifndef CT01_BIG_INT_HPP
#define CT01_BIG_INT_HPP
#include <deque>
#include <iostream>


struct big_int {
	typedef std::deque<uint64_t> bignum;
	bignum	big_data;
	const uint64_t len_second = 1e16;

	big_int() : big_data(1, 1) {};
	big_int(const uint64_t& ref) : big_data(1, ref) {};
	big_int(const big_int& ref) {
		if (&ref != this)
			this->big_data = ref.big_data;
	}
	big_int(const std::string& ref) {
		std::string tmp(ref);
		while(tmp.size() > 16) {
			big_data.push_front(std::stoull(&tmp[tmp.size() - 16]));
			tmp.assign(tmp.begin(), tmp.end() - 16);
		}
		big_data.push_front(std::stoull(tmp));
	}
	virtual ~big_int() {}

	big_int&	operator+(const big_int& other) {
		/// curent big_int must be bigger than other
		uint	s_cur = big_data.size();
		uint	s_other = other.big_data.size();
		uint64_t tmp;
		uint64_t tmp1 = 0;
		for (;; --s_other, --s_cur) {
			if (tmp1) {
				big_data[s_cur] += tmp1;
				tmp1 = 0;
			}
			tmp = big_data[s_cur] + other.big_data[s_other];
			big_data[s_cur] = tmp%len_second;
			if (tmp / len_second >= 1) {
				tmp1 = (tmp - (tmp%len_second))/len_second;
			}
			if (!s_cur) {
				if (tmp1)
					big_data.push_front(tmp1);
				break;
			}
		}
		if (s_other) {
			if (big_data.size() < other.big_data.size())
				big_data.push_front(other.big_data[0]);
			else
				big_data[0] += other.big_data[0];
		}
		return *this;
	}

	bool	operator<(const big_int& other) const{
		if (big_data.size() < other.big_data.size())
			return true;
		else if (big_data.size() > other.big_data.size())
			return false;
		for (uint i = 0; i < big_data.size(); ++i) {
			if (big_data[i] != other.big_data[i])
				return big_data[i] < other.big_data[i];
		}
		return false;
	}
	bool	operator>(const big_int& other) const{
		return !operator<(other);
	}
	bool	operator==(const big_int& other) const{
		return !operator<(other) && !operator>(other);
	}
	bool	operator!=(const big_int& other) const{
		return operator<(other) || operator>(other);
	}
};

struct cmp_big_int {
	bool operator()(const big_int& a, const big_int& b) const {
		return a < b;
	}
};
#endif //CT01_BIG_INT_HPP
