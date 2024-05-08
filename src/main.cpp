#include <iostream>
#include <chrono>		//ʱ����ص�ͷ�ļ�
#include <thread>		//�߳���ص�ͷ�ļ�
#include <ctime>
#include <Windows.h>
#include <Psapi.h>
#include <vector>

#include "FileMgr.h"

using namespace std;
using namespace std::chrono;		//ʱ����ص������ռ�


class A
{
public:
	A() {
		cout << "A's cons!" << endl; 
		m_ptr = new char[1024 * 1024 * 4];
	}
	A(const A& a) {
		cout << "A's copy cons!" << endl;
		m_ptr = new char[1024 * 1024 * 4];
		if (m_ptr)
			memcpy_s(m_ptr, 1024 * 1024 * 4, a.m_ptr, 1024 * 1024 * 4);
	}
	A(A&& a) noexcept {	//vector��������ʱҪʹ���ƶ�����Ļ����ƶ����캯��������noexcept
		cout << "A's move cons!" << endl; 
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
	}			
	A& operator=(const A& a) {
		cout << "A's operator=!" << endl;
		memcpy_s(m_ptr, 1024 * 1024 * 4, a.m_ptr, 1024 * 1024 * 4);
	}
	~A() {
		cout << "A's decons!" << endl;
		delete[] m_ptr;
	}
private:
	void* m_ptr{ nullptr };
};

int main()
{
	//string str = FileMgr::GetExecutableFilePath();
	//cout << str << endl;
	vector<A> vec;
	//vec.reserve(20);
	A a1;
	vec.push_back(std::move(a1));
	for (int i = 1; i < 10; ++i)
	{
		A tmp;
		vec.emplace_back(std::move(tmp));
		//vec.push_back(std::move(tmp));
	}

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
