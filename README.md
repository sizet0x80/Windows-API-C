# Windows-API-C
Windows API stuff I've written in C/C++

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
System Information.

System information is a small program I wrote that utilizes the Windows API to display static and dynamic system information. 

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

Enumerate Processes - Lists PID, threads, session, process name, and the username that the process belongs to.

Run in command prompt, if you're running as administrator you will see special users, as this uses EnableDebugPrivilege.

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                            
                                                                                  
