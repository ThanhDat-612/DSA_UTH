#include "Cau3.h"


double Cau3::giaiThua(int n) {
	double s = 1;
	for (int i = 1;i <= n;i ++) {
		s *= i;
	}
	return s;
}
double Cau3::S_DeQuy(int n) {
	if (n ==0) return 0;
	double sum = 0;
	sum = giaiThua(n) / sqrt(n + 1);
	return sum + S_DeQuy(n-1);
}
double Cau3::S_KhongDeQuy(int n) {
	double sum = 0;
	for (int i = 1;i <= n;i++) {
		double tu=1;
		for (int j = 1;j <= i;j++) {
			tu *= j;
		}
		sum += tu / sqrt(i + 1);
	}
	return sum;
}

double Cau3::sumDivideByK_DQ(int N, int k) {
	if (N == 0) { return 0; }
	int digit = N % 10;
	int sum = 0;

	if (digit % k == 0) {
		sum = digit;
	}
	return sum+sumDivideByK_DQ(N / 10, k);
}
double Cau3::sumDivideByK_KDQ(int N, int k) {
	int temp = N;
	int sum = 0;
	while (temp > 0) {
		int digit = temp % 10;
		if (temp % k == 0) {
			sum += digit;
		}
		temp /= 10;
	}
	return sum;
}

long long Cau3::getFibonacci(int n) {
	if (n < dp.size()) return dp[n];
	for (int i = dp.size();i <= n;i++) {
		dp.push_back(dp[i - 1] + dp[i - 2]);
	}
	return dp[n];
}
vector<long long> Cau3::getFibInRange(int a, int b) {
	getFibonacci(b);
	vector<long long> result;
	for (int i : dp) {
		if (i >= a && i <= b) {
			result.push_back(i);
		}
		if (i > b) break;
	}
	return result;
}