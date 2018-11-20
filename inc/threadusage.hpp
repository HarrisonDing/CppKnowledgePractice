/*
 * threadtest.hpp
 *
 *  Created on: Nov 20, 2018
 *      Author: Harrison.Ding
 */

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;


class ThreadSample {
private:
	int tickets;
	mutex locker;

private:
	void startToSell() {
	  while(true) {
		  if(tickets > 0) {
			  this_thread::sleep_for(chrono::seconds(1));
			  locker.lock();
			  cout << "seller thread :: ID = " << this_thread::get_id() << ", remaining: " << -- tickets << endl;
			  locker.unlock();
		  }
		  else break;
	  }
	}

public:
	ThreadSample(int num) {
		tickets = num;
	}

	void init() {
		thread threada(&ThreadSample::startToSell, this);
		thread threadb(&ThreadSample::startToSell, this);

		if (threada.get_id() != threadb.get_id()) {
		    cout << "Both Threads have different IDs" << endl;
		}
		cout << "From Main Thread :: ID of Thread a = " << threada.get_id() << endl;
		cout << "From Main Thread :: ID of Thread b = " << threadb.get_id() << endl;

		threada.detach();
		threadb.detach();
	}

	int getTickets() {
		return this->tickets;
	}
};


