/*
 * threadtest.hpp
 *
 *  Created on: Nov 20, 2018
 *      Author: Harrison.Ding
 */

#include <iostream>
#include <thread>

using namespace std;


class ThreadSample {

private:
	void thread_function() {
	  cout << "inside thread :: ID = " << this_thread::get_id() << endl;
	}

public:
	int threadTest() {
	  thread thread1(&ThreadSample::thread_function, this);
	  thread thread2(&ThreadSample::thread_function, this);

	  if (thread1.get_id() != thread2.get_id()) {
	    cout << "Both Threads have different IDs" << endl;
	  }
	  cout << "From Main Thread :: ID of Thread 1 = " << thread1.get_id() << endl;
	  cout << "From Main Thread :: ID of Thread 2 = " << thread2.get_id() << endl;

	  thread1.join();
	  thread2.join();

	  return 0;
	}
};


