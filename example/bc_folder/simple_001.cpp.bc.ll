; ModuleID = 'F:\git-rep\IDAC\trialVersion\testCode\bc_folder\simple_001.cpp.bc'
source_filename = "F:\\git-rep\\IDAC\\trialVersion\\testCode\\simple_001.cpp"
target datalayout = "e-m:w-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-w64-windows-gnu"

@simple_001_global_array = dso_local global [10 x i32] zeroinitializer, align 16, !dbg !0

; Function Attrs: mustprogress uwtable
define dso_local void @_Z15simple_001_mainv() #0 !dbg !17 {
entry:
  %local_size = alloca i32, align 4
  %0 = bitcast i32* %local_size to i8*, !dbg !23
  call void @llvm.lifetime.start.p0i8(i64 4, i8* %0) #4, !dbg !23
  call void @llvm.dbg.declare(metadata i32* %local_size, metadata !21, metadata !DIExpression()), !dbg !24
  %call = call i32 @_Z19simple_001_getIndexv(), !dbg !25
  store i32 %call, i32* %local_size, align 4, !dbg !24, !tbaa !26
  %1 = load i32, i32* %local_size, align 4, !dbg !30, !tbaa !26
  %idxprom = zext i32 %1 to i64, !dbg !32
  %arrayidx = getelementptr inbounds [10 x i32], [10 x i32]* @simple_001_global_array, i64 0, i64 %idxprom, !dbg !32
  %2 = load i32, i32* %arrayidx, align 4, !dbg !32, !tbaa !26
  %cmp = icmp sgt i32 %2, 1, !dbg !33
  br i1 %cmp, label %if.then, label %if.end, !dbg !34

if.then:                                          ; preds = %entry
  %3 = load i32, i32* %local_size, align 4, !dbg !35, !tbaa !26
  %idxprom1 = zext i32 %3 to i64, !dbg !37
  %arrayidx2 = getelementptr inbounds [10 x i32], [10 x i32]* @simple_001_global_array, i64 0, i64 %idxprom1, !dbg !37
  store i32 0, i32* %arrayidx2, align 4, !dbg !38, !tbaa !26
  br label %if.end, !dbg !39

if.end:                                           ; preds = %if.then, %entry
  store i32 10, i32* %local_size, align 4, !dbg !40, !tbaa !26
  call void @_Z19simple_001_setIndexRj(i32* nonnull align 4 dereferenceable(4) %local_size), !dbg !41
  %4 = load i32, i32* %local_size, align 4, !dbg !42, !tbaa !26
  %idxprom3 = zext i32 %4 to i64, !dbg !43
  %arrayidx4 = getelementptr inbounds [10 x i32], [10 x i32]* @simple_001_global_array, i64 0, i64 %idxprom3, !dbg !43
  store i32 0, i32* %arrayidx4, align 4, !dbg !44, !tbaa !26
  %5 = bitcast i32* %local_size to i8*, !dbg !45
  call void @llvm.lifetime.end.p0i8(i64 4, i8* %5) #4, !dbg !45
  ret void, !dbg !45
}

; Function Attrs: argmemonly nofree nosync nounwind willreturn
declare void @llvm.lifetime.start.p0i8(i64 immarg, i8* nocapture) #1

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #2

; Function Attrs: mustprogress nounwind uwtable
define dso_local i32 @_Z19simple_001_getIndexv() #3 !dbg !46 {
entry:
  ret i32 11, !dbg !49
}

; Function Attrs: mustprogress nounwind uwtable
define dso_local void @_Z19simple_001_setIndexRj(i32* nonnull align 4 dereferenceable(4) %index) #3 !dbg !50 {
entry:
  %index.addr = alloca i32*, align 8
  store i32* %index, i32** %index.addr, align 8, !tbaa !56
  call void @llvm.dbg.declare(metadata i32** %index.addr, metadata !55, metadata !DIExpression()), !dbg !58
  %0 = load i32*, i32** %index.addr, align 8, !dbg !59, !tbaa !56
  %1 = load i32, i32* %0, align 4, !dbg !59, !tbaa !26
  %add = add i32 %1, 1, !dbg !60
  %2 = load i32*, i32** %index.addr, align 8, !dbg !61, !tbaa !56
  store i32 %add, i32* %2, align 4, !dbg !62, !tbaa !26
  ret void, !dbg !63
}

; Function Attrs: argmemonly nofree nosync nounwind willreturn
declare void @llvm.lifetime.end.p0i8(i64 immarg, i8* nocapture) #1

attributes #0 = { mustprogress uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { argmemonly nofree nosync nounwind willreturn }
attributes #2 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #3 = { mustprogress nounwind uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nounwind }

!llvm.dbg.cu = !{!2}
!llvm.module.flags = !{!11, !12, !13, !14, !15}
!llvm.ident = !{!16}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(name: "simple_001_global_array", scope: !2, file: !6, line: 11, type: !7, isLocal: false, isDefinition: true)
!2 = distinct !DICompileUnit(language: DW_LANG_C_plus_plus_14, file: !3, producer: "clang version 13.0.0 (http://gitlab.sunwiseinfo.com/wangsheng/llvm-13.git bbe81d3375e0be7051cca483f35f3c32b4f477b9)", isOptimized: true, runtimeVersion: 0, emissionKind: FullDebug, enums: !4, globals: !5, splitDebugInlining: false, nameTableKind: None)
!3 = !DIFile(filename: "F:\\git-rep\\IDAC\\trialVersion\\testCode\\simple_001.cpp", directory: "F:\\git-rep\\IDAC\\trialVersion")
!4 = !{}
!5 = !{!0}
!6 = !DIFile(filename: "testCode\\simple_001.cpp", directory: "F:\\git-rep\\IDAC\\trialVersion")
!7 = !DICompositeType(tag: DW_TAG_array_type, baseType: !8, size: 320, elements: !9)
!8 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!9 = !{!10}
!10 = !DISubrange(count: 10)
!11 = !{i32 7, !"Dwarf Version", i32 4}
!12 = !{i32 2, !"Debug Info Version", i32 3}
!13 = !{i32 1, !"wchar_size", i32 2}
!14 = !{i32 7, !"PIC Level", i32 2}
!15 = !{i32 7, !"uwtable", i32 1}
!16 = !{!"clang version 13.0.0 (http://gitlab.sunwiseinfo.com/wangsheng/llvm-13.git bbe81d3375e0be7051cca483f35f3c32b4f477b9)"}
!17 = distinct !DISubprogram(name: "simple_001_main", linkageName: "_Z15simple_001_mainv", scope: !6, file: !6, line: 15, type: !18, scopeLine: 15, flags: DIFlagPrototyped | DIFlagAllCallsDescribed, spFlags: DISPFlagDefinition | DISPFlagOptimized, unit: !2, retainedNodes: !20)
!18 = !DISubroutineType(types: !19)
!19 = !{null}
!20 = !{!21}
!21 = !DILocalVariable(name: "local_size", scope: !17, file: !6, line: 16, type: !22)
!22 = !DIBasicType(name: "unsigned int", size: 32, encoding: DW_ATE_unsigned)
!23 = !DILocation(line: 16, column: 3, scope: !17)
!24 = !DILocation(line: 16, column: 16, scope: !17)
!25 = !DILocation(line: 16, column: 29, scope: !17)
!26 = !{!27, !27, i64 0}
!27 = !{!"int", !28, i64 0}
!28 = !{!"omnipotent char", !29, i64 0}
!29 = !{!"Simple C++ TBAA"}
!30 = !DILocation(line: 17, column: 30, scope: !31)
!31 = distinct !DILexicalBlock(scope: !17, file: !6, line: 17, column: 6)
!32 = !DILocation(line: 17, column: 6, scope: !31)
!33 = !DILocation(line: 17, column: 42, scope: !31)
!34 = !DILocation(line: 17, column: 6, scope: !17)
!35 = !DILocation(line: 18, column: 29, scope: !36)
!36 = distinct !DILexicalBlock(scope: !31, file: !6, line: 17, column: 46)
!37 = !DILocation(line: 18, column: 5, scope: !36)
!38 = !DILocation(line: 18, column: 41, scope: !36)
!39 = !DILocation(line: 19, column: 3, scope: !36)
!40 = !DILocation(line: 20, column: 14, scope: !17)
!41 = !DILocation(line: 21, column: 3, scope: !17)
!42 = !DILocation(line: 22, column: 27, scope: !17)
!43 = !DILocation(line: 22, column: 3, scope: !17)
!44 = !DILocation(line: 22, column: 39, scope: !17)
!45 = !DILocation(line: 23, column: 1, scope: !17)
!46 = distinct !DISubprogram(name: "simple_001_getIndex", linkageName: "_Z19simple_001_getIndexv", scope: !6, file: !6, line: 25, type: !47, scopeLine: 25, flags: DIFlagPrototyped | DIFlagAllCallsDescribed, spFlags: DISPFlagDefinition | DISPFlagOptimized, unit: !2, retainedNodes: !4)
!47 = !DISubroutineType(types: !48)
!48 = !{!22}
!49 = !DILocation(line: 26, column: 3, scope: !46)
!50 = distinct !DISubprogram(name: "simple_001_setIndex", linkageName: "_Z19simple_001_setIndexRj", scope: !6, file: !6, line: 29, type: !51, scopeLine: 29, flags: DIFlagPrototyped | DIFlagAllCallsDescribed, spFlags: DISPFlagDefinition | DISPFlagOptimized, unit: !2, retainedNodes: !54)
!51 = !DISubroutineType(types: !52)
!52 = !{null, !53}
!53 = !DIDerivedType(tag: DW_TAG_reference_type, baseType: !22, size: 64)
!54 = !{!55}
!55 = !DILocalVariable(name: "index", arg: 1, scope: !50, file: !6, line: 29, type: !53)
!56 = !{!57, !57, i64 0}
!57 = !{!"any pointer", !28, i64 0}
!58 = !DILocation(line: 29, column: 40, scope: !50)
!59 = !DILocation(line: 29, column: 57, scope: !50)
!60 = !DILocation(line: 29, column: 63, scope: !50)
!61 = !DILocation(line: 29, column: 49, scope: !50)
!62 = !DILocation(line: 29, column: 55, scope: !50)
!63 = !DILocation(line: 29, column: 68, scope: !50)
