#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool isOdd(int n) { return n % 2 == 0; }

void showSort() {
	vector<int> arr{ 0, 1, 8, 13, 5, 2, 3 };

	arr[0] = 21;
	arr.push_back(1);
	sort(arr.begin(), arr.end());

	cout << "Printing " << arr.size() << " Fibonacci numbers" << endl;
	for (auto x : arr) {
		cout << x << " ";
	}

	auto numEvens = count_if(arr.begin(), arr.end(), [](auto num){ return num % 2 == 0; });
	cout << endl << "Number of evens: " << numEvens << endl;

	cout << endl << "Remove evens..." << endl;
	auto it = std::remove_if(arr.begin(), arr.end(), isOdd);
	arr.erase(it, arr.end());
	for (auto x : arr) {
		cout << x << " ";
	}
}

constexpr int isqrt(int n) {
	int i = 1;
	while (i*i < n) ++i;
	return i-(i*i != n);
}

int main() {
	auto i{ 0x01B99644 };
	string x{ " DFaeeillnor" };
	while (i--) std::next_permutation(x.begin(), x.end());
	cout << x << endl << endl;


	string s = "aba";
	sort(s.begin(), s.end());
	do {
		cout << s << endl;
	} while (next_permutation(s.begin(), s.end()));


	// constexpr
	constexpr int isq = isqrt(1764);
	cout << endl << "sqrt(1764)=" << isq << endl << endl;

	showSort();

}
