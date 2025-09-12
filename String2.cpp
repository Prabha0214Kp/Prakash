#include <iostream>
#include <cstring>
#include <string>   // for safe std::string usage
using namespace std;

class String {
	int len;
	char *res;
	public:
	// Default constructor
	String() : len(0), res(nullptr) {}

	// Parameterized constructor
	String(const char *str) {
		len = strlen(str);
		res = new char[len + 1];
		strcpy(res, str);
	}

	// Copy constructor
	String(const String &str) {
		len = str.len;
		res = new char[len + 1];
		strcpy(res, str.res);
	}

	// Copy assignment
	String& operator=(const String &str) {
		if (this != &str) {
			delete[] res;
			len = str.len;
			res = new char[len + 1];
			strcpy(res, str.res);
		}
		return *this;
	}

	// Move constructor
	String(String&& str) noexcept {
		res = str.res;
		len = str.len;
		str.res = nullptr;
		str.len = 0;
	}

	// ✅ Move assignment
	String& operator=(String&& str) noexcept {
		if (this != &str) {
			delete[] res;
			res = str.res;
			len = str.len;
			str.res = nullptr;
			str.len = 0;
		}
		return *this;
	}

	// Length
	unsigned int length() const {
		return len;
	}

	// Destructor
	~String() {
		delete[] res;
	}

	// Input operator (word only, stops at space)
	friend istream& operator>>(istream& in, String& s) {
		string temp;
		in >> temp;   // reads single word
		delete[] s.res;
		s.len = temp.size();
		s.res = new char[s.len + 1];
		for (int i = 0; i < s.len; i++) {
			s.res[i] = temp[i];
		}
		s.res[s.len] = '\0';  // null terminator
		return in;
	}

	// Input function for full line (with spaces)
	friend void getline(istream& in, String& s) {
		string temp;
		std::getline(in, temp);  // reads whole line
		delete[] s.res;
		s.len = temp.size();
		s.res = new char[s.len + 1];
		for (int i = 0; i < s.len; i++) {
			s.res[i] = temp[i];
		}
		s.res[s.len] = '\0';  // null terminator
	}

	// Output operator
	friend ostream& operator<<(ostream& out, const String& s) {
		if (s.res != nullptr)
			out << s.res;
		return out;
	}

	// Concatenation operator
	friend String operator+(const String& lhs, const String& rhs) {
		int newLen = lhs.len + rhs.len;
		char* buffer = new char[newLen + 1];

		// copy lhs
		for (int i = 0; i < lhs.len; i++) {
			buffer[i] = lhs.res[i];
		}
		// copy rhs
		for (int i = 0; i < rhs.len; i++) {
			buffer[lhs.len + i] = rhs.res[i];
		}
		buffer[newLen] = '\0';

		String result(buffer);
		delete[] buffer; // free temp buffer

		return result;
	}
};

int main() {
	String str1;
	String str2 = "Hello";
	String str3 = "World";

	cout << "Initial str2: " << str2 << endl;
	cout << "Initial str3: " << str3 << endl;

	// Concatenation
	String str4 = str2 + str3;
	cout << "Concatenated: " << str4 << endl;

	// Word input
	cout << "Enter a word: ";
	cin >> str2;
	cout << "You entered (word): " << str2 << endl;

	cin.ignore();  // clear newline from buffer

	// Full line input
	cout << "Enter a full line: ";
	getline(cin, str2);
	cout << "You entered (line): " << str2 << endl;

	// Move constructor
	String str5 = move(str2);
	cout << "After move constructor, str5: " << str5 << endl;
	cout << "After move constructor, str2: " << str2 << endl;

	// ✅ Move assignment operator demo
	String a = "First";
	String b = "Second";
	cout << "\nBefore move assignment:" << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	a = move(b);   // move assignment happens here

	cout << "After move assignment:" << endl;
	cout << "a: " << a << endl;   // "Second"
	cout << "b: " << b << endl;   // empty

	return 0;
}

