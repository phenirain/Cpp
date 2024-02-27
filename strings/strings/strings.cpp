#include <iostream>
#include <string>
#include <random>

using namespace std;
char vowels[6] = {'a', 'e', 'i', 'y', 'u', 'o'};
string reverse(string& any);
string removeVowels(string& any);
string removeConsonants(string& any);
string shuffle(string& any);


int main()
{
	string anyString;
	cout << "Let input any word: ";
	cin >> anyString;
	cout << reverse(anyString) << endl;
	cout << removeVowels(anyString) << endl;
	cout << removeConsonants(anyString) << endl;
	cout << shuffle(anyString) << endl;
}

string reverse(string& any) {
	string newstring;
	for (int i = any.length(); i >= 0; i--) {
		newstring += any[i];
	}
	return newstring;
}

string removeVowels(string& any) {
	string newstring;
	for (int i = 0; i < any.length(); i++) {
		if (find(begin(vowels), end(vowels), tolower(any[i])) == end(vowels)) {
			newstring += any[i];
		}
	}
	return newstring;
}

string removeConsonants(string& any) {
	string newstring;
	for (int i = 0; i < any.length(); i++) {
		if (!(find(begin(vowels), end(vowels), tolower(any[i])) == end(vowels))) {
			newstring += any[i];
		}
	}
	return newstring;
}

string shuffle(string& any) {
	string newstring = any;
	random_device rd;
	mt19937 g(rd());
	shuffle(newstring.begin(), newstring.end(), g);
	return newstring;
}
