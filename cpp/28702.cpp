#include <iostream>
#include <string>
using namespace std;

bool is_three(string n) {
	int sum = 0;

	for (char c : n)
		sum += c - '0';

	if (sum % 3 == 0)
		return true;
	else
		return false;
}

bool is_five(string n) {
	if (n.back() == '0' || n.back() == '5')
		return true;
	else
		return false;
}

void answer(string n) {
	if (is_three(n) && is_five(n))
		cout << "FizzBuzz";
	else if (is_three(n) && !is_five(n))
		cout << "Fizz";
	else if (!is_three(n) && is_five(n))
		cout << "Buzz";
	else
		cout << n;
}

int main() {
	string nums[3];
	string next;
	int lastNumIdx;
	
	for (int i = 0; i < 3; i++) {
		getline(cin, nums[i]);
		if (nums[i] == "Fizz" || 
			nums[i] == "Buzz" || 
			nums[i] == "FizzBuzz")
			continue;
		else
			lastNumIdx = i;
	}

	next = to_string(stoi(nums[lastNumIdx]) + (3 - lastNumIdx));
	answer(next);

	return 0;
}