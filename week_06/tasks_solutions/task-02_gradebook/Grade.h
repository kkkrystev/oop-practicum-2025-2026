#pragma once

struct Grade
{
private:
	static constexpr int FN_LEN = 10;

public:
	char fn[FN_LEN];
	double grade;
};