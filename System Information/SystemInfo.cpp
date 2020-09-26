// author: size_T
#include <windows.h>
#include <stdio.h>
#include <strsafe.h>
#include <Psapi.h>
int main() {

    SYSTEM_INFO si;
    ::GetNativeSystemInfo(&si);

    WCHAR path[MAX_PATH];
    ::GetSystemDirectory(path, MAX_PATH);
    printf("--------------- system info by size_t ----------------\n\n");
    printf("------Static Info------\n");
    auto sharedUserData = (BYTE*)0x7FFE0000;
    printf("\nWindows Version: %d.%d.%d\n\n",
        *(ULONG*)(sharedUserData + 0x26c),
        *(ULONG*)(sharedUserData + 0x270),
        *(ULONG*)(sharedUserData + 0x260));
  
    WCHAR name[64];
    DWORD size = _countof(name);
    if (::GetComputerName(name, &size))
        printf("Computer Name is: %ws\n\n", name);

    size = _countof(name);
    if (::GetUserName(name, &size))
        printf("Whoami: %ws\n\n", name);

    printf("System directory: %ws\n\n", path);
    printf("The number of logical processors: %d\n\n", si.dwNumberOfProcessors);
    printf("The page size: %d Bytes\n\n", si.dwPageSize);
    printf("The processor mask: 0x%p\n\n", (PVOID)si.dwActiveProcessorMask);
    printf("The minimum process address: 0x%p\n", si.lpMinimumApplicationAddress);
    printf("The maximum process address: 0x%p\n\n", si.lpMaximumApplicationAddress);

    printf("------Dynamic Info------\n");
    CONSOLE_CURSOR_INFO hide_cursor;
    if (::GetConsoleCursorInfo(::GetStdHandle(STD_OUTPUT_HANDLE), &hide_cursor)) {
        hide_cursor.bVisible = FALSE;
        ::SetConsoleCursorInfo(::GetStdHandle(STD_OUTPUT_HANDLE), &hide_cursor);
    }

    PERFORMANCE_INFORMATION perf_info;
    printf("\n");
    for (;;) {
        if (!::GetPerformanceInfo(&perf_info, sizeof(perf_info)))
            break;
        printf("The number of Processes: %4u\n", perf_info.ProcessCount);
        printf("The number of Threads: %5u\n", perf_info.ThreadCount);
        printf("The number of Handles: %7u KB\n", perf_info.HandleCount);
        printf("Committed memory: %7zu KB\n", perf_info.CommitTotal >> 10);
        printf("Committed memory limit: %7zu KB\n", perf_info.CommitLimit >> 10);
        printf("Total amount of Physical Memory: %7zu KB\n", perf_info.PhysicalTotal >> 10);
        printf("Physical memory currently available: %7zu KB\n", perf_info.PhysicalAvailable >> 10);
        printf("Kernel paged: %5zu KB\n", perf_info.KernelPaged >> 10);
        printf("Kernel non-paged: %5zu KB\n", perf_info.KernelNonpaged >> 10);
        printf("Kernel Pool Total: %5zu KB\n", perf_info.KernelTotal >> 10);
        ::Sleep(1000);
        printf("\r\033[10A");
    }
    return 0;
