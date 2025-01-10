# SpecChecker-Int
This repository hosts SpecChecker-Int, a tool that provides extensible, precise and efficient concurrent bugs detection for interrupt-driven embedded software.
SpecChecker-Int offers embedded software testers a bug warning report to enhance the efficiency of manual code inspection. 
Contributions to this tool are most welcome!
## Table of Contents
1. [Requirments](#requirments)  
2. [Using the Tool](#using-the-tool)  
3. [Inspecting the Output](#inspecting-the-output)  
4. [Contact](#contact)
***
***

## Requirments
* Runs on Windows  
* Install python3
    * https://docs.python.org/3/using/windows.html  
* Clone the bugs dectection tool:  
```
git clone https://github.com/wangilson/SpecChecker-Int
```

***
***

## Using the Tool
SpecChecker-Int accepts two input formats: `xxx.bc` | `file path`.  
  
You can use `xxx.bc` as input to the tool, but you need to have Clang on your device.  
* Install clang
    * https://releases.llvm.org/download.html#7.0.0  
  
Display the command line parameters using: 
  
```
cd SpecCheckerInt/bin  
SpecChecker-Int.exe ../example/test.bc -tasks=main,isr -priority=0,1 -reportFile=../SpecCheckerInt/example/result.json
```
If your subject is an entire project, then you can just use the folder as input to the tool.  
```
cd SpecCheckerISA/bin
SpecChecker-Int.exe ../example -tasks=main,isr -priority=0,1 -reportFile=../SpecCheckerInt/example/result.json
```
***

### SpecChecker-ISA Optional Command Line Parameters:

Parameter | Description
---- | ----
-tasks | List of program entry points (task or isr)
-priority | List of program priority
-reportFile | Output floder
-int-bof | Toggle to activate the out-of-bounds array access checker
-int-dbz | Toggle to activate the divided-by-zero checker
Additional checker options are available and can be viewed using the `--help` command.

***
***

## Inspecting the Output
You can view the output of SpecChecker-Int in a `json` file.  
Let's see the output of analyzing the `test.c` program (found under `example/test.c`)  

***
***

## Contact
If you experience any issues, please submit an issue or contact us at wangbx@sunwiseinfo.com, lichao@sunwiseinfo.com, chenrui@sunwiseinfo.com
