#include <stdio.h>
#include <stdlib.h>

#define WINVER 0x0500
#include <vector>
#include <iostream>

using namespace std;

void keyPress(INPUT&, int);
vector<int> extractDigits(int);

int main()
{
	//Begin, prompt user for starting number
	int value;
	cout << "Enter starting value: ";
	cin >> value;

	// This structure will be used to create the keyboard
	// input event.
	INPUT ip;

	// Pause for 5 seconds.
	cout << "Beginning in 5...\n";
	Sleep(1000);
	cout << "4...\n";
	Sleep(1000);
	cout << "3...\n";
	Sleep(1000);
	cout << "2...\n";
	Sleep(1000);
	cout << "1...\n";
	Sleep(1000);

	while (true) {
		value++;
		vector<int> digits = extractDigits(value);
		int length = digits.size();

		for (int i = 0; i < length; i++) {
			keyPress(ip, 0x30 + digits.back());
			digits.pop_back();
			Sleep(10);
		}

		//Press Enter
		keyPress(ip, 0xD);

		Sleep(rand() % 2001);
	}

	return 0;
}

void keyPress(INPUT& ip, int keyCode) {
	// Set up a generic keyboard event.
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	ip.ki.wVk = keyCode; // virtual-key code for the key
	ip.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &ip, sizeof(INPUT));

	// Release the key
	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
}

vector<int> extractDigits(int value) {
	int val = value;
	vector<int> digits;

	do {
		digits.push_back(val % 10);
		val = val / 10;
	} while (val > 0);

	return digits;
}
