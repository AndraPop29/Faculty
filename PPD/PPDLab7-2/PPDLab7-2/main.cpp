//
//  main.cpp
//  PPDLab7-2
//
//  Created by Andra on 28/11/2017.
//  Copyright © 2017 andrapop. All rights reserved.
//

#include <iostream>
#include "Queue.cpp"
#include <thread>

using namespace std;
using namespace std::chrono;
std::condition_variable cv;
std::mutex mutex;
void sumNBigNumbers(vector<int>& v, int begin, int end, Queue<int>& q, int nrThreads) {
    if(nrThreads == 1) {
        int val2;
        int val = v[begin];
        //cout<<"BEGIN: "<<begin<<endl;
        if (begin != end) {
             val2 = v[end];
        } else {
             val2 = 0;
        }
//        while(val != 0 || val2 != 0) {
//            int s = (val % 10 + val2 % 10) % 10;
//            int c = (val % 10 + val2 % 10) / 10;
            cout<<val<<endl;
        q.push(val%10);
            val = val / 10;
           // cout<<val2<<endl;
//            val = val / 10;
//            val2 = val2 / 10;

            //std::unique_lock<std::mutex> lock(mutex);
          //  q.push(s);
            std::this_thread::sleep_for(1000000000ns);
            //cout<<"The sum is: "<<s<<", and the c is "<<c;
            //cv.wait(lock);
            //cout<<"puuuut";
     //       s = c;
      //  }
    } else {
        int mid = (begin + end) / 2; // 0 - 1 => 0, 0 ; 0, 1
        int s1;
       // cout<<q.size()<<endl;
       // cout<<begin<<" ";
        thread t1([&v, begin, mid, &q, nrThreads, &s1](){sumNBigNumbers(v, begin, mid, q, nrThreads/2); });  // 0 - 2, 0 - 1
        s1 = s1 + q.pop();
        
         thread t2([&v, end, mid, &q, nrThreads](){sumNBigNumbers(v, mid , end, q, nrThreads - nrThreads/2); }); // 2 - 4, 1 - 2
       // cout<<q.size()<<endl;
       
        int s2 = q.pop();
      //  cout << s1<<endl;
      //  cout<<s2<<endl;
        t1.join();
        t2.join();
        q.push((s1+s2)%10);
        s1 = (s1 + s2) /10;
    
    }
}

void generate(vector<int>& v, size_t n)
{
    v.clear();
    v.reserve(n);
    for(size_t i=0 ; i<n ; ++i) {
        v.push_back(rand());
    }
}

void print(vector<int>& v, size_t n)
{
    v.clear();
    v.reserve(n);
    for(size_t i=0 ; i<n ; ++i) {
        cout<<v[i]<<" ";
    }
}

bool checkSum(vector<int> const& a, int s)
{
    int sum = 0;
    for(size_t i = 0 ; i<a.size() ; ++i){
        sum = sum + a[i];
    }
    return sum == s;
}

int main(int argc, const char * argv[]) {
    unsigned n = 4;
    Queue<int> *q = new Queue<int>();
    
    vector<int> a;
    generate(a, n);
    print(a, n);
    
    chrono::high_resolution_clock::time_point const beginTime = chrono::high_resolution_clock::now();
    sumNBigNumbers(a, 0, n, *q, n);
    chrono::high_resolution_clock::time_point const endTime = chrono::high_resolution_clock::now();
    
    printf("Result %s, time=%ldms\n", (checkSum(a, 1000) ? "ok" : "FAIL"),
           (chrono::duration_cast<chrono::milliseconds>(endTime-beginTime)).count());
    
    while(!q->isEmpty()) {
        cout<<q->pop()<<" ";
    }
    return 0;
}
