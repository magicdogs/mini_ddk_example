# mini_ddk_example


http://download.microsoft.com/download/0/7/5/0755898A-ED1B-4E11-BC04-6B9B7D82B1E4/VS2013_RTM_ULT_CHS.iso
https://download.microsoft.com/download/4/A/2/4A25C7D5-EFBE-4182-B6A9-AE6850409A78/GRMWDK_EN_7600_1.ISO



1.安装VS2010；官网下载WDK（就是早期的DDK），解压安装（GRMWDK_EN_7600_1）；

2.在VS2010中建立空项目，项目可以命名为“driver”；

3.配置解决方案，增加一个叫做driver的配置方案；


4.配置工程属性；


这个时候需要输入自己的WDK的安装路径，我的是这样的：

可执行文件目录： $(WDKPATH)\bin\x86

包含文件（3个）：

 $(WDKPATH)\inc\api

 $(WDKPATH)\inc\crt

 $(WDKPATH)\inc\ddk

引用目录: $(WDKPATH)\lib\wxp\i386
库目录：$(WDKPATH)\lib\wxp\i386

5. 新建一个C++文件；

6. 设置工程属性；

\

常规：目标文件扩展名 .sys

c/c++下拉菜单中：

预处理器
预处理器定义：WIN32=100;_X86_=1;WINVER=0x501;DBG=1 //必选

高级
调用约定 __stdcall(/Gz) //必选

常规选项卡
1 调试信息格式(C7 兼容(/Z7) //可选
2 警告等级 （2 级(/W2) //可选
3 将警告视为错误 (是(/wx) //可选

优化选项卡
优化(禁用/Od) //可选

代码生成
启用最小重新生成：否 //可选

基本运行时检查：默认值 //可选
运行时库：多线程调试(/MTd) 或 多线程(/MT) //建议选 <本人选择的是多线程调试(/MTd)>
缓冲区安全检查：否 //可选
(可避免出现 LINK : error LNK2001: 无法解析外部符号 __security_cookie)

链接器当中：

常规
启用增量链接：否(/INCREMENTAL:NO) //建议 选上
忽略导入库：是 // 可选
( 设置为此值时，必须在附加库目录中加： G:\WinDDK\7600.16385.1\lib\win7\i386 这样项目就不会依赖 IDE 环境的设 置)

如果否 ( 设置为此值时，将依赖 IDE 的环境的相关设置 )

输入
附加依赖项
ntoskrnl.lib; Hal.lib; wdm.lib; wdmsec.lib; wmilib.lib; ndis.lib; MSVCRT.LIB; LIBCMT.LIB //必选

//NT式驱动 ntoskrnl.lib WDM式驱动 wdm.lib
( HalXXX 函数在Hal.lib， WmiXXX 函数在 wmilib.lib ， NdisXXX函数在 ndis.lib )
( 必要时需要增加微软的标准库 MSVCRT.LIB MSVCRTD.LIB(调试库) LIBCMT.LIBIBCMTD.LIB(调试库) )
( 如果源码中有 source 文件，那么该文件的 TARGETLIBS 字段会列出该项 目需要的库 )

忽略所有默认库： 是(/NODEFAULTLIB) //必选

清单文件：
生成清单: 否 (/MANIFEST:NO)
启用用户账户控制（UAC） 否 //必选

不然会出现 >LINK : fatal error LNK1295: “/MANIFESTUAC”与“/DRIVER”规范不兼容；链接时不使用“/MANIFESTUAC”

调试：
生成调试信息 是(/DEBUG) //可选
生成映像文件：是(/MAP) //可选
映像文件名：$(TargetDir)$(TargetName).map //可选

系统(System)
子系统: 控制台(/SUBSYSTEM:CONSOLE) //必选
堆栈保留大小：4194304 //可选
堆栈提交大小： 4096 //可选
驱动程序: 驱动程序(/DRIVER) //必选

高级：
入口点：DriverEntry //必选
随机基址:清空 //把框里的数据删掉。（yes也不是no也不是就是要一个干干净净的文本框） //必选
不然会出现 e:\xxx.sys : fatal error LNK1295: “/DYNAMICBASE”与“/DRIVER”规范不兼容；链接时不使用“/DYNAMICBASE”

数据执行保护(DEP): 清空 //必选
不然会出现 e:\xxx.sys : fatal error LNK1295: “/NXCOMPAT:NO”与“/DRIVER”规范不兼容；链接时不使用“/NXCOMPAT:NO”

设置效应和：是(/RELEASE) //可选

基址：0x10000 //建议选上

命令行：

/SECTION:INIT,D /IGNORE:4078 （建议不要写进去，会报错！）




测试代码：

#include "ntddk.h"

NTSTATUS
DriverEntry(PDRIVER_OBJECT DriverObject,PUNICODE_STRING RegistryPath)
{
return STATUS_UNSUCCESSFUL;
}

参考文献：
http://www.cnblogs.com/xlhblog/archive/2011/03/22/1991785.html

http://www.cppblog.com/guojingjia2006/archive/2011/03/19/142211.html


