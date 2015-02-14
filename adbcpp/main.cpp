//
//  main.cpp
//  adbcpp
//
//  Created by 한민수 on 2015. 2. 14..
//  Copyright (c) 2015년 한민수. All rights reserved.
//

#include <iostream>
#include <thread>

#define NUM_THREADS 10

using namespace std;

void task()
{
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell input tap 165 247");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    thread t[NUM_THREADS];
    
    for (int i = 0; i < NUM_THREADS; ++i) {
        t[i] = std::thread(task);
    }
    
    for (int i = 0; i < NUM_THREADS; ++i) {
        t[i].join();
    }
    
    std::cout << "GoodBye, World!\n";
    
    return 0;
}
