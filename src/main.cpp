#include <iostream>
#include <chrono>		//时间相关的头文件
#include <thread>		//线程相关的头文件
#include <ctime>
#include <Windows.h>
#include <Psapi.h>

#include "FileMgr.h"

using namespace std;
using namespace std::chrono;		//时间相关的命名空间


int main()
{
	string str = FileMgr::GetExecutableFilePath();
	cout << str << endl;
	//char buf[MAX_PATH] = {};
	//GetModuleBaseNameA(GetCurrentProcess(), NULL, buf, MAX_PATH);
	//cout << buf << endl;
	//auto start = system_clock::now();
	//auto cTime = system_clock::to_time_t(start);
	///*auto tm = gmtime(cTime);
	//cout<<"UTC:"<<put_time()*/
	//std::this_thread::sleep_for(milliseconds(3000));
	//auto end = system_clock::now();
	//auto elapsedTime = duration_cast<milliseconds>(end - start);
	//cout << elapsedTime.count() << endl;
	return 0;
}
