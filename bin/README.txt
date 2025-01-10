#启动
intAtomPlus directory -tasks=AppLoopTask,AppTask1 -priority=0,1 -reportFile=xxx -configFile=xxx
directory:工程代码目录
tasks和priority要一一对应
reportDirectory:输出目标文件夹

示例：intAtomPlus E:\testCode\Embedded\realCase\SPARCV8\sut -tasks=AppLoopTask,AppTask1 -priority=0,1 -reportFile=E:\tmp\cmp

#中断使能配置文件书写规则
File：使能语句所在文件
Line：使能语句所在行号
Type：不修改
Switches：是一个作用对象的数组，即可以控制哪些中断程序的使能
	isr/flag：中断程序名称,总开关名称填写all
	Value：0代表关闭，1代表打开
	
示例：
	[{
	"File":	"F:\\git-rep\\intAtom\\vfg\\cmake-build-debug\\testcases\\Benchmark\\DataAccessConflict\\svp_simple_003\\svp_simple_003_001.c",
	"Line":	"47",
	"Type":	"interrupt",
	"Switches":	[{
			"isr/flag":	"svp_simple_003_001_isr_1",
			"Value":	"1"
		}]
	}]
	
	
	
// RUN: %clang -S -c -O -g -emit-llvm -fno-discard-value-names -Xclang -disable-llvm-passes -Xclang -disable-O0-optnone %s -o %t.bc
// RUN: %opt -loops -lcssa -loop-unroll -unroll-count=3 -S -debugify %t.bc -o %t.ll
// RUN: %intAtomPlus -stat=false -int-data-access-conflict=false -bof=true -int-dbz=false %t.ll -tasks=simple_001_main -priority=0 -reportFile=%t.json > %t.txt
// RUN: %FileCheck -input-file=%t.txt %s
// -sparcV8 -c51 -c6x
intAtomPlus ./testCode -tasks=simple_001_main -priority=0 -includePath=./ -reportFile=./result.json -configFile=./InterruptEnableConfig.json