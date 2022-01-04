// glog_test1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include <libloaderapi.h>
#include "glog/logging.h"

#pragma comment(lib, "glogd.lib")

using namespace google;

void InitLog()
{
    char path[MAX_PATH+1] = {0};
    HMODULE module = GetModuleHandleA(NULL);
    GetModuleFileNameA(module, path, MAX_PATH);

    char *cursor = strrchr(path, '\\');
    *(cursor+1) = '\0';

    google::InitGoogleLogging("MyTest App");
    google::SetLogDestination(GLOG_INFO, path);     //path should has tail "\\"
    google::SetLogDestination(GLOG_WARNING, path);
    google::SetLogDestination(GLOG_ERROR, path);
}

int main(int argc, char* argv[])
{
    InitLog();
    google::LogAtLevel(GLOG_INFO, "test1");
    google::LogAtLevel(GLOG_WARNING, "test2");
    google::LogAtLevel(GLOG_ERROR, "test3");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
