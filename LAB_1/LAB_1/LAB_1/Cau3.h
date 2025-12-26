#pragma once
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
class Cau3
{
	private:
		vector<int> dp = { 0,1 };
	public:
		double giaiThua(int);
		double S_DeQuy(int);
		double S_KhongDeQuy(int);


		// 12345 / 2 = 6  (2&4)
		double sumDivideByK_DQ(int,int); 
		double sumDivideByK_KDQ(int,int);
		long long getFibonacci(int);

		vector<long long> getFibInRange(int, int);
};

