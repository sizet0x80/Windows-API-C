#include <Windows.h>
#include <iostream>
#include <String>

int main() {
    
    std::string window_name;
    std::cout << "Enter Window Name To Kill: ";
    std::getline(std::cin, window_name);

    // Grab a Handle to the Process
    HWND hwnd = FindWindowA(nullptr, window_name.c_str());

    // Check to see if we have the Handle
    if (hwnd == NULL) {
        std::cerr << "[ERROR] Could Not Grab Handle! Error Code: " << GetLastError() << std::endl;
        return 1;
    }
    else {
        std::cout << "[INFO] Grabbed Handle..." << std::endl;
    }

    // Get the PID of the process at the handle
    DWORD pid;
    GetWindowThreadProcessId(hwnd, &pid);

    // Check to see if the call Completed
    if (pid == 0) {
        std::cerr << "[ERROR] Could Not Get PID from Handle! Error Code: " << GetLastError() << std::endl;
        return 1;
    }
    else {
        std::cout << "[INFO] Found PID..." << std::endl;
    }

    // Opening the Process by PID with Specific Access
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

    // Check to see if we have a valid Handle to the process
    if (hProcess == NULL) {
        std::cerr << "[ERROR] Could Not Grab Privileged Handle! Error Code: " << GetLastError() << std::endl;
        return 1;
    }
    else {
        std::cout << "[INFO] Privileged Handle Opened..." << std::endl;
    }

    // Send Kill to the process
    UINT uExitCode = 0x1;
    BOOL response = TerminateProcess(hProcess, uExitCode);

    if (response == 0) {
        std::cerr << "[ERROR] Could Not Kill Process! Error Code: " << GetLastError() << std::endl;
        return 1;
    }
    else {
        std::cout << "[INFO] Process Killed..." << std::endl;
    }

    return 0;
}
