//_stdcall
#include <ntddk.h>
#define INITCODE code_seg("INIT") 
#pragma  INITCODE
VOID DDK_Unload (IN PDRIVER_OBJECT pDriverObject); //ǰ��˵�� ж������
NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject,PUNICODE_STRING B) //TYPEDEF LONG NTSTATUS
{
KdPrint(("�����ɹ�������...OK++++++++"));
 pDriverObject->DriverUnload=DDK_Unload;
return (1);
}
VOID DDK_Unload (IN PDRIVER_OBJECT pDriverObject)
{
 KdPrint(("�����ɹ���ж��...OK-----------")); //sprintf,printf
 DbgPrint("ж�سɹ�");
}