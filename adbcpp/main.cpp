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

void *thread_function(void *arg)
{
    string message = (char*) arg;
    copy(message.begin(), message.end(), (char*) arg);
    string command = PATH_OF_ADB + message;
    system(command.c_str());

    pthread_exit(NULL);
}

void cmd(string message)
{
//    int state = 0;
//    pthread_t t_id;
    
//    state = pthread_create(&t_id, NULL, thread_function, (void*) message.c_str());
    
    string command = PATH_OF_ADB + message;
    system(command.c_str());
}

void logging(string message)
{
    cout << message << endl;
//    sleep(1);
}

void PosionInitialize()
{
    //첫번째 pointer의 ABS_MT_TRACKING_ID를 1로 설정한다.
    
    logging("화면 축소");
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
    cmd("adb shell sendevent /dev/input/event2 3 53 780");
    cmd("adb shell sendevent /dev/input/event2 3 54 470");
    cmd("adb shell sendevent /dev/input/event2 3 58 8");
    cmd("adb shell sendevent /dev/input/event2 0 0 0");
    
    
    //여기서 ABS_MT_POSITION_X(53), ABS_MT_POSITION_Y(54), 그리고 SYN_REPORT를 한 묶음으로 이동하고 싶은 만큼 반복한다.
    cmd("adb shell sendevent /dev/input/event2 3 53 420");
    cmd("adb shell sendevent /dev/input/event2 3 54 220");
    cmd("adb shell sendevent /dev/input/event2 3 58 8");
    cmd("adb shell sendevent /dev/input/event2 0 0 0");
    
    
    cmd("adb shell sendevent /dev/input/event2 3 57 461");
    cmd("adb shell sendevent /dev/input/event2 3 53 400");
    cmd("adb shell sendevent /dev/input/event2 3 54 200");
    //ABS_MT_PRESSURE 8정도의 값을 보내서 press 되었다고 알려 줍니다.
    cmd("adb shell sendevent /dev/input/event2 3 58 8");
    //한 pointer에 대한 EV_SYN, SYN_REPORT를 보낸다.
    cmd("adb shell sendevent /dev/input/event2 0 0 0");
    
    
    
    //첫번째 pointer의 ABS_MT_TR두ACKING_ID를 -1을 초기화 한다.
    cmd("adb shell sendevent /dev/input/event2 3 57 -1");
    cmd("adb shell sendevent /dev/input/event2 0 0 0");
    //ABS_MT_SLOT(47)은 0,1로 번갈아 입력된다. 앞에서 1로 보냈으니 0으로 보낸다.
    cmd("adb shell sendevent /dev/input/event2 3 47 0");
    //두번째 pointer의 ABS_MT_TRACKING_ID를 -1을 초기화 한다.
    cmd("adb shell sendevent /dev/input/event2 3 57 -1");
    cmd("adb shell sendevent /dev/input/event2 0 0 0");
    
    
    cmd("adb shell input swipe 10 10 10 300");
    
    // 아무데나 클릭
    logging("아무대나 클릭");
    cmd("adb shell input tap 10 10");

}

void GetResources()
{
    // 자원 걷기
    
    logging("자원1");
    cmd("adb shell input tap 365 174");
    
    logging("자원2");
    cmd("adb shell input tap 439 174");
    
    logging("자원3");
    cmd("adb shell input tap 220 300");
    
    logging("자원4");
    cmd("adb shell input tap 264 337");
    
    logging("자원5");
    cmd("adb shell input tap 576 294");
    
    logging("자원6");
    cmd("adb shell input tap 530 340"); //
    
    
    logging("자원7");
    cmd("adb shell input tap 484 154");
    
    logging("자원8");
    cmd("adb shell input tap 215 234");
    
    logging("자원9");
    cmd("adb shell input tap 181 270");
    
    logging("자원10");
    cmd("adb shell input tap 217 345");
    
    logging("자원11");
    cmd("adb shell input tap 627 260"); //
    
    logging("자원12");
    //    cmd("adb shell input tap 10 10");
    cmd("adb shell input tap 624 321");
    
    logging("자원13");
    //    cmd("adb shell input tap 10 10");
    cmd("adb shell input tap 560 255");
    
    logging("자원14");
    //    cmd("adb shell input tap 10 10");
    cmd("adb shell input tap 238 257");
    //    cmd("adb shell input tap 10 10");

}

void MakeUnit()
{
    // 훈련소 클릭
    
    logging("훈련소 클릭");
    cmd("adb shell input tap 550 196");

    // 훈련 클릭
    
    logging("훈련 클릭");
    cmd("adb shell input tap 536 420");
    
    // 바바리안 롱클릭
    
    logging("바바리안 뽑기");
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
    
    // 아처 롱클릭
    
    logging("아쳐 뽑기");
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
    
    // 바바리안 롱클릭
    //    logging("바바리안 뽑기");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	409");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	53	252");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	54	174");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	48	43");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	58	5");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	3	57	4294967295");
    //    sleep(SLEEP_COUNT);
    //    system("/Users/utoxiz/Downloads/adt-bundle-mac-x86_64-20131030/sdk/platform-tools/adb shell sendevent	/dev/input/event2	0	0	0");
    
    // 다음 훈련소 클릭
    //    cmd("adb shell input tap 43 253");
    
    // 아처 롱클릭
    
    logging("아쳐 뽑기");
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
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Start!!!\n";

    PosionInitialize();
    
    while(1)
    {
        GetResources();
        MakeUnit();
        sleep(120);
    }
    
    // 클랜성 클릭
    logging("클랜 유닛 요청");
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
