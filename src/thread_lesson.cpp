#include <iostream>
#include <thread>
#include <memory>
#include <vector>
#include <chrono>
#include <mutex>
#include <shared_mutex>

using std::cout;
using std::endl;
using std::thread;
using std::unique_ptr;
using std::vector;

int sharedValue=0;
std::mutex mtx;
std::shared_mutex smtx;

void func1(int num)
{
    cout << "func1 : num = " << num << endl;
    cout << "thread id : " << std::this_thread::get_id() << endl;;
}

void func2()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    sharedValue++;
    cout << "sharedValue : " << sharedValue << endl;
}

void func3()
{
    std::lock_guard<std::mutex> lock(mtx);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    sharedValue++;
    cout << "sharedValue : " << sharedValue << endl;
}

void func4()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    {
        std::lock_guard<std::shared_mutex> writeLock(smtx);
        sharedValue++;
    }
    {
        std::shared_lock<std::shared_mutex> readLock(smtx);
        cout << "sharedValue : " << sharedValue << endl;
    }
}

int main()
{
    cout << "execute 1 thread" << endl;
    thread th1(func1, 1);
    cout << th1.get_id() << endl;
    th1.join();

    cout << "##################" <<endl << endl;

    cout << "execute multi thread" << endl;
    vector<unique_ptr<thread>> threadVec;
    for(int i=0;i<5;i++)
    {
        auto pThread = std::make_unique<thread>(thread(func1, i));
        threadVec.push_back(std::move(pThread));
    }

    for(auto& pThread: threadVec)
    {
        pThread->join();
    }

    cout << "##################" <<endl << endl;

    cout << "execute access to shared value" << endl;
    vector<unique_ptr<thread>> threadVecSharedValue;
    for(int i=0;i<5;i++)
    {
        auto pThread = std::make_unique<thread>(thread(func2));
        threadVecSharedValue.push_back(std::move(pThread));
    }

    for(auto& pThread: threadVecSharedValue)
    {
        pThread->join();
    }




    cout << "##################" <<endl << endl;

    cout << "execute locked access to shared value" << endl;
    vector<unique_ptr<thread>> threadVecSharedValueMutex;
    for(int i=0;i<5;i++)
    {
        auto pThread = std::make_unique<thread>(thread(func3));
        threadVecSharedValueMutex.push_back(std::move(pThread));
    }

    for(auto& pThread: threadVecSharedValueMutex)
    {
        pThread->join();
    }

    cout << "##################" <<endl << endl;

    cout << "execute shared_mutex locked access to shared value" << endl;
    vector<unique_ptr<thread>> threadVecSharedValueSharedMutex;
    for(int i=0;i<5;i++)
    {
        auto pThread = std::make_unique<thread>(thread(func4));
        threadVecSharedValueSharedMutex.push_back(std::move(pThread));
    }

    for(auto& pThread: threadVecSharedValueSharedMutex)
    {
        pThread->join();
    }

    return 0;
}