/*
 * threadtest.hpp
 *
 *  Created on: Nov 20, 2018
 *      Author: Harrison.Ding
 */

#include <iostream>
#include <thread>

using namespace std;

void thread_function() {
  cout << "inside thread :: ID = " << this_thread::get_id() << endl;
}

int threadTest() {
  thread thread1(thread_function);
  thread thread2(thread_function);

  if (thread1.get_id() != thread2.get_id()) {
    cout << "Both Threads have different IDs" << endl;
  }
  cout << "From Main Thread :: ID of Thread 1 = " << thread1.get_id() << endl;
  cout << "From Main Thread :: ID of Thread 2 = " << thread2.get_id() << endl;

  thread1.join();
  thread2.join();

  return 0;
}


/*class ThreadSample {

public:
	void start(){
		thread t(bind1st(&ThreadSample::run,this));
		t.detach();
	}


	void run(){
		while (true){
			cout << "test thread id:" << std::this_thread::get_id()<<endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		}
	}
};*/


