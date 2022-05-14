#include <iostream>
#include <Windows.h>

class API{
	public:
	
	std::string input;
	HWND hwnd = FindWindowA(NULL, input.c_str());
	DWORD pid = 0;
	DWORD response = GetWindowThreadProcessId(hwnd, &pid);
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	HANDLE hToken = NULL;
	BOOL token = OpenProcessToken(hProc, TOKEN_ALL_ACCESS, &hToken );
	PRIVILEGE_SET tp;
	LUID luid;
	
	//change to the privilege you want to check
	std::string lpName = "SEDebugPrivilege";
	
	BOOL lpva = LookupPrivilegeValueA(NULL, lpName.c_str(), &luid);
	BOOL bResult;

};
void privcheck() {
	API api;
	api.tp.PrivilegeCount = 1; 
	api.tp.Privilege[0].Luid = api.luid;
	api.tp.Privilege[0].Attributes = SE_PRIVILEGE_ENABLED;
	
	BOOL privcheck = PrivilegeCheck(api.hToken, &api.tp, &api.bResult);
	
}


void check() {
	API api;
	
	if (api.hwnd == 0) {
		std::cout << "[ERROR] Could not get handle! Error Code : " << GetLastError();
	
	}else{
		std::cout << "[INFO] Got handle..." << std::endl;
	}
	if (api.response == 0) {
		std::cout << "[ERROR] Could not get PID from handle! Error Code: " << GetLastError();
	}else{
		std::cout << "[INFO] Found PID..." << std::endl;
	}
	if (api.hProc == NULL) {
		std::cout << "[ERROR] Could not grab a privileged handle! Error code: " << GetLastError();
	}else{
		std::cout << "[INFO] Privileged handle opened..." << std::endl;
	}
	
	if(api.token) {
		std::cout << "[INFO] Handle to process token Created... " << std::endl;
	}else {
		std::cout << "[Error] Could  not grab handle to token! Error code: " << GetLastError();
	}
	if(api.lpva) {
		std::cout << "[INFO] Found LUID...." << std::endl;
	}else{
		std::cout << "[Error] Could  not grab handle to token! Error code: " << GetLastError();
	}
	privcheck();
	if(privcheck != 0) {
		std::cout << "[INFO] Ran priv check..." << std::endl;
	}else{
		std::cout << "[ERROR] Could not run privilege check! Error code : " << GetLastError();
	}
	if (api.bResult) {
		std::cout << "Privilege enabled: "  << api.lpName << std::endl;
	}else{
		std::cout << "Privilege not enabled";
	}
}