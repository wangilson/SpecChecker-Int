# SpecChecker-Int
This repository hosts SpecChecker-Int, a tool that provides extensible, precise and efficient concurrent bugs detection for interrupt-driven embedded software.
SpecChecker-Int offers embedded software testers a bug warning report to enhance the efficiency of manual code inspection. 
Contributions to this tool are most welcome!

**Also, our video demonstration is presented at https://youtu.be/KW88ZS7LD3s.**
## Table of Contents
1. [Requirments](#requirments)  
2. [Using the Tool](#using-the-tool)  
3. [Inspecting the Output](#inspecting-the-output)  
4. [Contact](#contact)
***
***

## Requirments
* Runs on Windows  
* Clone the bugs dectection tool:  
```
git clone https://github.com/wangilson/SpecChecker-Int
```

***
***

## Using the Tool
Display the command line parameters using: 
  
If your subject is an entire project, then you can just use the folder as input to the tool.  
```
cd SpecCheckerInt/bin
SpecChecker-Int.exe ../example -int-bof=true -tasks=main,Int0ISR -priority=0,1 -reportFile=../result/result.json
```
***

### SpecChecker-Int Optional Command Line Parameters:

Parameter | Description
---- | ----
-tasks | List of program entry points (task or isr)
-priority | List of program priority
-reportFile | Output floder
-int-dac | Toggle to activate the atomicity violations checker
-int-bof | Toggle to activate the out-of-bounds array access checker
-int-dbz | Toggle to activate the divided-by-zero checker
Additional checker options are available and can be viewed using the `--help` command.

***
***

## Inspecting the Output
You can view the output of SpecChecker-Int in a `json` file.  
Let's see the output of analyzing the `example` program
### Bug Report Details

| Key               | Value |
| ----------------- | ----- |
| **BugType**       | `int-bof` |
| **Confidence**    | `1` |
| **ConfidenceMessage** | `` |
| **Line**          | `28` |
| **Column**        | `5` |
| **File**          | `D:\SpecChecker-Int\bin\..\example\simple_001.c` |
| **VarName**       | `receive_buffer_B` |
| **Message**       | `Buffer Over Flow` |
| **interruptPoint**        | `23` |

***
***

## Contact
If you experience any issues, please submit an issue or contact us at wangbx@sunwiseinfo.com, lichao@sunwiseinfo.com, chenrui@sunwiseinfo.com
