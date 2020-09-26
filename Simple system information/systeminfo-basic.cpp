// Author: size_t

#include <windows.h>
#include <stdio.h>


int main() {

    SYSTEM_INFO si;
    ::GetNativeSystemInfo(&si);

    WCHAR path[MAX_PATH];
    ::GetSystemDirectory(path, MAX_PATH);

    WCHAR pcName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = MAX_COMPUTERNAME_LENGTH + 1;
    ::GetComputerNameW(pcName, &size);

    auto sharedUserData = (BYTE*)0x7FFE0000;
    printf("Version: %d.%d.%d\n\n",
        *(ULONG*)(sharedUserData + 0x26c),
        *(ULONG*)(sharedUserData + 0x270),
        *(ULONG*)(sharedUserData + 0x260));

    printf("System directory: %ws\n\n", path);
    printf("The number of logical processors: %d\n\n", si.dwNumberOfProcessors);
    printf("The page size: %d Bytes\n\n", si.dwPageSize);
    printf("The processor mask: 0x%p\n\n", (PVOID)si.dwActiveProcessorMask);
    printf("The minimum process address: 0x%p\n", si.lpMinimumApplicationAddress);
    printf("The maximum process address: 0x%p\n\n", si.lpMaximumApplicationAddress);
    printf("Computer name: %ws\n", pcName);


    return 0;
}
