//
// Created by Gilberto Dougal on 4/19/21.
//

#include "big_int.hpp"


big_int::big_int(const big_int &ref) {
	if (&ref != this)
		this->big_data = ref.big_data;
}

big_int::big_int(const std::string &ref) {
	std::string tmp(ref);
	while(tmp.size() > 16) {
		big_data.push_front(std::stoull(&tmp.at(tmp.size() - 16)));
		tmp.assign(tmp.begin(), tmp.end() - 16);
	}
	big_data.push_front(std::stoull(tmp));
}


big_int &big_int::operator+(const big_int &other) {
	uint	s_cur = big_data.size() - 1;
	uint	s_other = other.big_data.size() - 1;
	uint64_t tmp;
	uint64_t tmp1 = 0;
	for ( ; ; --s_other, --s_cur) {
		if (tmp1) {
			big_data.at(s_cur) += tmp1;
			tmp1 = 0;
		}
		tmp = big_data.at(s_cur) + other.big_data.at(s_other);
		big_data.at(s_cur) = tmp%len_second;
		if (tmp / len_second >= 1) {
			tmp1 = (tmp - (tmp%len_second))/len_second;
		}
		if (!s_cur || !s_other) {
			if (tmp1)
				big_data.push_front(tmp1);
			break;
		}
	}
	if (s_other) {
		if (big_data.size() < other.big_data.size())
			big_data.push_front(other.big_data.at(0));
		else
			big_data.at(0) += other.big_data.at(0);
	}
	return *this;
}

bool big_int::operator<(const big_int &other) const {
	if (big_data.size() < other.big_data.size())
		return true;
	else if (big_data.size() > other.big_data.size())
		return false;
	for (uint i = 0; i < big_data.size(); ++i) {
		if (big_data.at(i) != other.big_data.at(i))
			return big_data.at(i) < other.big_data.at(i);
	}
	return false;
}

bool big_int::operator>(const big_int &other) const {
	return !operator<(other);
}

bool big_int::operator==(const big_int &other) const {
	return !operator<(other) && !operator>(other);
}

bool big_int::operator!=(const big_int &other) const {
	return operator<(other) || operator>(other);
}
