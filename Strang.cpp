#include <cstring>
#include <iostream>
#include <stdexcept>
#include <utility>


class Strang {

public:
	Strang(size_t max_size) :
			mMaxLen { max_size },
			mLen {} {
		if (mMaxLen == 0) {
			throw std::runtime_error { "max size must be at least 1!" };
		}
		mBuffer = new char[mMaxLen];
		mBuffer[0] = 0;
	}

	~Strang() {
		delete[] mBuffer;
	}

	// Copy Constructor
	Strang(const Strang& other) :
			mMaxLen { other.mMaxLen },
			mBuffer { new char[other.mMaxLen] },
			mLen { other.mLen } {
		std::cout << "::Strang(const Strang& other)" << std::endl;
		std::strncpy(mBuffer, other.mBuffer, mMaxLen);
	}

	// Move Constructor
	Strang(Strang&& other) noexcept :
			mMaxLen(other.mMaxLen),
			mBuffer(other.mBuffer),
			mLen(other.mLen) {
		std::cout << "::Strang(Strang&& other)" << std::endl;
		other.mLen = 0;
		other.mBuffer = nullptr;
		other.mMaxLen = 0;
	}

	// Copy assignment operator
	Strang& operator=(const Strang& other) {
		std::cout << "::Strang& operator=(const Strang& other)" << std::endl;
		if (this == &other) {
			return *this;
		}
		const auto newBuf = new char[other.mMaxLen];
		delete[] mBuffer;
		mBuffer = newBuf;
		mLen = other.mLen;
		mMaxLen = other.mMaxLen;
		std::strncpy(mBuffer, other.mBuffer, mMaxLen);
		return *this;
	}

	// Move assignment operator
	Strang& operator=(Strang&& other) noexcept {
		std::cout << "::Strang& operator=(Strang&& other)" << std::endl;
		if (this == &other) {
			return *this;
		}
		delete[] mBuffer;
		mBuffer = other.mBuffer;
		mLen = other.mLen;
		mMaxLen = other.mMaxLen;
		other.mBuffer = nullptr;
		other.mLen = 0;
		other.mMaxLen = 0;
		return *this;
	}

	void print(const char *tag) const {
		if (mBuffer != nullptr) {
			printf("%s: %s", tag, mBuffer);
		} else {
			printf("%s: null\n", tag);
		}
	}

	bool appendLine(const char *x) {
		const auto xlen = strlen(x);
		if (xlen + mLen + 2 > mMaxLen) {
			return false;
		}
		std::strncpy(mBuffer + mLen, x, mMaxLen - mLen);
		mLen += xlen;
		mBuffer[mLen++] = '\n';
		mBuffer[mLen] = 0;
		return true;
	}


private:
	size_t mMaxLen;
	char *mBuffer;
	size_t mLen;
};

int main() {

	Strang a { 50 };
	a.appendLine("We apologize");
	a.appendLine("for the");

	Strang b { 50 };
	b.appendLine("Last");
	b.appendLine("message");

	a.print("a");
	b.print("b");

	std::cout << std::endl << "moving a to b" << std::endl;
	b = std::move(a); // a is moved from
	a.print("a");
	b.print("b");

	std::cout << std::endl << "moving b to c" << std::endl;
	Strang c { std::move(b) };
	c.appendLine("mixup");
	b.print("b");
	c.print("c");
}
