#include <iostream>
#include <chrono>		//ʱ����ص�ͷ�ļ�
#include <thread>		//�߳���ص�ͷ�ļ�
#include <ctime>
#include <Windows.h>
#include <Psapi.h>

#include "FileMgr.h"

using namespace std;
using namespace std::chrono;		//ʱ����ص������ռ�


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
