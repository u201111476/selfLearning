#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;


int main()
{
	auto start = system_clock::now();
	std::this_thread::sleep_for(milliseconds(60000));
	auto end = system_clock::now();
	auto elapsedTime = duration_cast<milliseconds>(end - start);
	cout << elapsedTime.count() << endl;
	return 0;
}
