#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main()
{
    string path;
    path = "C:\\Users\\aggar\\Desktop\\Coding\\GithubProjects\\CompetetiveProgramming\\takeuforward\\Step1\\Step1.1\\InputBasics.cpp";
    string command = "g++ " + path + " -o output && output.exe < input.txt > output.txt";
    while (true)
    {
        system(command.c_str());
        Sleep(1000);
    }
    return 0;
}
