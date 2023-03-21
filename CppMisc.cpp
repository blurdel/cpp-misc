#include <iostream>
#include <memory>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


auto adder(int x, int y) {
	return x + y;
}


int main() {
	cout << "Start ..." << endl;

	auto a = adder(3, 4);
	cout << "a=" << a << endl;

	// Shared print(vec)
	auto print = [](vector<int> vec) {
		for (const auto& n : vec) {
			cout << n << " ";
		}
		cout << endl;
	};

	int xxx = 33;
	auto add = [](auto x, auto y) { return x + y; };
	cout << "b=" << add(5, 3) << endl;


	auto square = [](auto n){ return n * n; };
	auto c = 9;
	cout << "c=" << c << ", squared=" << square(c) << endl;


	vector<int> numbers { 1, 2, 3, 4, 9, 8, 7, 6, 5, 1 };
	sort(numbers.begin(), numbers.end(), [](int a, int b){ return a < b; });
	print(numbers);

	auto removeLT3 = [&](int n){ return n <= 3; };
	auto it = std::remove_if(numbers.begin(), numbers.end(), removeLT3);
	numbers.erase(it, numbers.end());
	print(numbers);



	std::unique_ptr<int> ptr(new int(10));
	auto lambda = [value = std::move(ptr)] { return *value; };
	cout << "lambda() = " << lambda() << endl;

}
