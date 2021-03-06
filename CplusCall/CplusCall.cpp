// CplusCall.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include "mscoree.h"       //
#include <wchar.h>
#include "CoreHost.h"
#include "windows.h"
using namespace std;
struct Test
{
    int a;
    char b[12];
};
typedef  void HelloWorld(const char*);
typedef  void StructTest(Test* t);

typedef  void StructTest(const Test* t);
int main() 
{
    Test t{0,"helloword"};
    CoreHost coreHost(LR"(C:\Users\fdq15\Downloads\coreclr-master\bin\obj\CplusCall\x64\Debug)",L"MyTest"); //appDll扫描路径，host名称
    auto helloFunc = coreHost.GetFunctionPointer<HelloWorld>(L"CplusCalled", L"CplusCalled.Class1",L"HelloWorld");//appDll名称不带后缀，type，函数名
    auto structFunc = coreHost.GetFunctionPointer<StructTest>(L"CplusCalled", L"CplusCalled.Class1", L"TestStruct");//appDll名称不带后缀，type，                                                                                                              //函数名

    auto structFunc2 = coreHost.GetFunctionPointer<StructTest>(L"CplusCalled", L"CplusCalled.Class1", L"TestStruct");
    helloFunc("hello world");
    structFunc(&t);
    return 0;
}
