# Windows-API-C
Windows API stuff I've written in C/C++ aimed at the information security community.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Enumerate Processes - Lists all PID, threads, session, process names, and the username that the process belongs to. (static, not dynamic)

Execute from command prompt, if you're running as administrator you will see special users, as this uses EnableDebugPrivilege.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

System information is a small program I wrote that utilizes the Windows API to display static and dynamic system information. Execute from command prompt.

   Static Information:  
   
            Windows version info
            
            Computer name
            
            Current user (whoami)
            
            System Directory path
            
            Logical processor count
            
            Page size
            
            Processor mask
            
            Minimum process address
            
            Maximum process address
            
            
   Dynamic Information:
   
            Number of Processes currently "running"
            
            Number of Threads currently running
            
            Number of handles currently running
            
            Commited memory
            
            Commited memory limit
            
            Total amount of physical memory
            
            Physical memory currently available
            
            Kernel paged 
            
            Kernel non-paged
            
            Kernel pool total
            
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                            
   Check Token Privileges
   
   Takes the name of a window and gets a handle to the process' access token, and then checks to see if x token privilege is enabled. (SEDebugPrivilege unless manually changed in the header file)
   
   ![image](https://user-images.githubusercontent.com/62064338/168439796-046e9d02-2094-4a39-b568-2171e09dfef1.png)
   
   Compile with ``g++ Check-Token-Privs.cpp -o whatever``

   In most cases you will need to be in an elevated command prompt (admin) to check things like Task Manager. Most 3rd party apps should be fine without this.
