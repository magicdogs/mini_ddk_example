//_stdcall
#include <ntddk.h>
#define INITCODE code_seg("INIT") 
#pragma  INITCODE
VOID DDK_Unload (IN PDRIVER_OBJECT pDriverObject); //前置说明 卸载例程
NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject,PUNICODE_STRING B) //TYPEDEF LONG NTSTATUS
{
KdPrint(("驱动成功被加载...OK++++++++"));
 pDriverObject->DriverUnload=DDK_Unload;
return (1);
}
VOID DDK_Unload (IN PDRIVER_OBJECT pDriverObject)
{
 KdPrint(("驱动成功被卸载...OK-----------")); //sprintf,printf
 DbgPrint("卸载成功");
}