//
//  main.cpp
//  adbcpp
//
//  Created by 한민수 on 2015. 2. 14..
//  Copyright (c) 2015년 한민수. All rights reserved.
//

#include <unistd.h>
#include <iostream>
#include <thread>
#include <pthread.h>
#include <string.h>

#define NUM_THREADS 10
#define PATH_OF_ADB "/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/"
#define SLEEP_COUNT 3

using namespace std;

struct Position
{
    int x;
    int y;
};

void cmd(string message)
{
    string command = "/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/" + message;
    system(command.c_str());
    sleep(1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    // 혹시모를 종료 클릭
//    cmd("adb shell input tap 721 48");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	412");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	53	443");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	54	721");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	48	43");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	58	5");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	4294967295");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");
    
    string sendevent = "adb shell sendevent /dev/input/event2 ";
/*

    //첫번째 pointer의 ABS_MT_TRACKING_ID를 1로 설정한다.
    cmd("adb shell sendevent /dev/input/event2 3 57 461");
    cmd("adb shell sendevent /dev/input/event2 3 53 100");
    cmd("adb shell sendevent /dev/input/event2 3 54 100");
    //ABS_MT_PRESSURE 8정도의 값을 보내서 press 되었다고 알려 줍니다.
    cmd("adb shell sendevent /dev/input/event2 3 58 8");
    //한 pointer에 대한 EV_SYN, SYN_REPORT를 보낸다.
    cmd("adb shell sendevent /dev/input/event2 0 0 0");
    
    
    //두번째 pointer 입력 전에 ABS_MT_SLOT을 보낸다.
    cmd("adb shell sendevent /dev/input/event2 3 47 1");
    
    
    //두번째 pointer
    //첫번째 pointer의 ABS_MT_TRACKING_ID를 2로 설정한다.
    cmd("adb shell sendevent /dev/input/event2 3 57 462");
    cmd("adb shell sendevent /dev/input/event2 3 53 360");
    cmd("adb shell sendevent /dev/input/event2 3 54 360");
    cmd("adb shell sendevent /dev/input/event2 3 58 8");
    cmd("adb shell sendevent /dev/input/event2 0 0 0");
    
    
    //여기서 ABS_MT_POSITION_X(53), ABS_MT_POSITION_Y(54), 그리고 SYN_REPORT를 한 묶음으로 이동하고 싶은 만큼 반복한다.
    cmd("adb shell sendevent /dev/input/event2 3 53 120");
    cmd("adb shell sendevent /dev/input/event2 3 54 120");
    cmd("adb shell sendevent /dev/input/event2 0 0 0");
    
    
    //첫번째 pointer의 ABS_MT_TR두ACKING_ID를 -1을 초기화 한다.
    cmd("adb shell sendevent /dev/input/event2 3 57 -1");
    cmd("adb shell sendevent /dev/input/event2 0 0 0");
    //ABS_MT_SLOT(47)은 0,1로 번갈아 입력된다. 앞에서 1로 보냈으니 0으로 보낸다.
    cmd("adb shell sendevent /dev/input/event2 3 47 0");
    //두번째 pointer의 ABS_MT_TRACKING_ID를 -1을 초기화 한다.
    cmd("adb shell sendevent /dev/input/event2 3 57 -1");
    cmd("adb shell sendevent /dev/input/event2 0 0 0");
*/


    cmd("adb shell input swipe 10 10 10 300");

    
    // 아무데나 클릭
    cmd("adb shell input tap 10 10");
    
    // 자원 걷기
    cmd("adb shell input tap 496 159");
    cmd("adb shell input tap 427 181");
    cmd("adb shell input tap 526 195");
    cmd("adb shell input tap 363 161");
    cmd("adb shell input tap 620 290");
    cmd("adb shell input tap 565 272"); //
    cmd("adb shell input tap 533 345");
    cmd("adb shell input tap 192 246");
    cmd("adb shell input tap 165 340");
    cmd("adb shell input tap 261 337");
    cmd("adb shell input tap 236 272"); //
    
    cmd("adb shell input tap 10 10");
    cmd("adb shell input tap 246 394");
    cmd("adb shell input tap 10 10");
    cmd("adb shell input tap 281 425");
    cmd("adb shell input tap 10 10");
    cmd("adb shell input tap 323 459");
    cmd("adb shell input tap 10 10");
    
    // 훈련소 클릭
    cmd("adb shell input tap 572 220");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	407");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	53	572");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	54	220");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	48	43");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	58	5");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	4294967295");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");

    // 훈련 클릭
    cmd("adb shell input tap 536 420");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	408");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	53	536");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	54	420");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	48	43");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	58	5");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	4294967295");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");

    
    // 바바리안 롱클릭
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	409");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	53	252");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	54	174");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	48	43");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	58	5");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	4294967295");
    sleep(SLEEP_COUNT);
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");

    // 다음 훈련소 클릭
    cmd("adb shell input tap 43 253");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	410");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	53	43");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	54	253");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	48	43");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	58	5");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	4294967295");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");

    // 아처 롱클릭
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	411");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	53	239");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	54	289");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	48	43");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	58	5");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	4294967295");
    sleep(SLEEP_COUNT);
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");

    // 다음 훈련소 클릭
    cmd("adb shell input tap 43 253");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	410");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	53	43");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	54	253");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	48	43");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	58	5");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	4294967295");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");

    // 바바리안 롱클릭
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	409");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	53	252");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	54	174");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	48	43");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	58	5");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	4294967295");
    sleep(SLEEP_COUNT);
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");
    
    // 다음 훈련소 클릭
    cmd("adb shell input tap 43 253");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	410");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	53	43");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	54	253");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	48	43");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	58	5");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	4294967295");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");
    
    // 아처 롱클릭
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	411");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	53	239");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	54	289");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	48	43");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	58	5");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	4294967295");
    sleep(SLEEP_COUNT);
    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");

    // 종료 클릭
    cmd("adb shell input tap 721 48");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	412");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	53	443");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	54	721");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	48	43");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	58	5");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	4294967295");
//    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");

    
    // 클랜성 클릭
    cmd("adb shell input tap 432 267");
    cmd("adb shell input tap 398 427");
    cmd("adb shell input tap 570 241");
    cmd("adb shell input tap 586 144");
    
    
    // 공격
    cmd("adb shell input tap 52 410");
    cmd("adb shell input tap 160 367");
    
    // 아무데나 클릭
    //cmd("adb shell input tap 10 10");

    std::cout << "GoodBye, World!\n";
    
    return 0;
}
