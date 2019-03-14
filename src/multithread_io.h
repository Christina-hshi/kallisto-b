#pragma once
#include <iostream>
#include <string>
#include <mutex>

#define mt_log multithread_io::log

using std::string;
class multithread_io{
  public:
    static std::mutex mtx;
    static void log(string m){
      std::unique_lock<std::mutex> locker(mtx);
      std::cout<<m<<std::flush;
      locker.unlock();
    }
};
