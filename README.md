# SpecChecker-ISA
This repository hosts SpecChecker-ISA, a tool that provides sound and precise data sharing analysis for interrupt-driven embedded software. 
SpecChecker-ISA can aid embedded software testers during manual code inspection for concurrency bugs. Researchers and developers can also use it as a solid front-end of concurrency bug detection tool for interrupt-driven embedded software.
SpecChecker-ISA is built on top of LLVM. Contributions to this tool are most welcome!
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
* Clone the shared data analyzer :  
```
git clone https://github.com/wangilson/SpecChecker-ISA
```

***
***

## Using the Tool
SpecChecker-ISA supports two kinds of files as input：`xxx.c` | `xxx.bc`.  
  
You can use `xxx.bc` as input to the tool, but you need to have Clang on your device.  
* Install clang
    * https://releases.llvm.org/download.html#7.0.0  
  
Display the command line parameters using: 
  
```
cd SpecCheckerISA/bin  
clang -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone ../example/test.c -o ../example/test.bc
SpecChecker-ISA.exe ../example/test.bc -t-e=main -t-p=0 -i-e=isr -i-p=1 -o=../SpecCheckerISA/example
```
You can use `xxx.c` directly as input to the tool.  
```
cd SpecCheckerISA/bin
SpecChecker-ISA.exe ../example/test.c -t-e=main -t-p=0 -i-e=isr -i-p=1 -o=../SpecCheckerISA/example
```
***

### SpecChecker-ISA Optional Command Line Parameters:

Parameter | Description
---- | ----
-e | List of program entry points
-t-e | List of program task entry points
-t-p | List of program task priority
-i-e | List of program isr entry points
-i-p | List of program isr priority
--globals-int | Policy of initialzation for global variables
-o | Output floder

***
***

## Inspecting the Output
You can view the output of SpecChecker-ISA in 2 different formats : `json` and `csv`.  
Let's see the output of analyzing the `test.c` program (found under `example/test.c`)  

Base | Offset | Size | R/W	| Entry	| Fun	| File | Line | Column
---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ----
upload_data	 | 4	| 4	| R	| isr	| IOOutClr	| ..\example\test.c	| 33	| 11
| | | 4 | W	| main	| IOOutSet	| ..\example\test.c	| 25	| 18
absolute_zero	| ff00	| 4	| R	| isr	| IOOutClr	| ..\example\test.c	| 30	| 24
| | | 4	| W	| isr	| IOOutClr | ..\example\test.c | 32 | 37
| | | 4	| R| 	main | IOOutSet | ..\example\test.c	| 21	| 24
| | | 4	| W	| main | IOOutSet | ..\example\test.c	| 23	| 37
g_v	| 0	| 4	| W	| isr	| IOOutClr | ..\example\test.c	| 33	| 9
| | | 4	| R	| main | IOOutSet | ..\example\test.c	| 25	| 20

***
***

## Contact
If you experience any issues, please submit an issue or contact us at wangbx@sunwiseinfo.com , chenrui@sunwiseinfo.com
