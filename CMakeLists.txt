cmake_minimum_required(VERSION 3.17)
project(408_Data_Structure)

set(CMAKE_CXX_STANDARD 20)

add_executable(SqList List/SqList/SqList.h List/SqList/SqList.c List/SqList/SqListMain.c)
add_executable(LkList List/LkList/LkList.h List/LkList/LkList.c List/LkList/LkListMain.c)
add_executable(CrList List/CrList/CrList.h List/CrList/CrList.c List/CrList/CrListMain.c)
add_executable(DuList List/DuList/DuList.h List/DuList/DuList.c List/DuList/DuListMain.c)
add_executable(SqStack Stack/SqStack/SqStack.h Stack/SqStack/SqStack.c Stack/SqStack/SqStackMain.c)
add_executable(LkStack Stack/LkStack/LkStack.c Stack/LkStack/LkStack.h Stack/LkStack/LkStackMain.c)
add_executable(SqQueue Queue/SqQueue/SqQueue.c Queue/SqQueue/SqQueue.h Queue/SqQueue/SqQueueMain.c)
add_executable(LkQueue Queue/LkQueue/LkQueue.c Queue/LkQueue/LkQueue.h Queue/LkQueue/LkQueueMain.c)
add_executable(3_28Queue Queue/3_28Queue/3_28Queue.c Queue/3_28Queue/3_28Queue.h Queue/3_28Queue/3_28QueueMain.c)
add_executable(3_30Queue Queue/3_30Queue/3_30Queue.c Queue/3_30Queue/3_30Queue.h Queue/3_30Queue/3_30QueueMain.c)
add_executable(3_31QnS Stack/3_31Q&S/3_31Q&SMain.c Stack/3_31Q&S/LkStack.h Stack/3_31Q&S/LkStack.c Stack/3_31Q&S/LkQueue.h Stack/3_31Q&S/LkQueue.c)
add_executable(3_32Queue Queue/3_32Queue/3_32Queue.c Queue/3_32Queue/3_32Queue.h Queue/3_32Queue/3_32QueueMain.c)
add_executable(SqString String/SqString/SqString.c String/SqString/SqString.h String/SqString/SqStringMain.c)
add_executable(LkString String/LkString/LkString.c String/LkString/LkString.h String/LkString/LkStringMain.c)
add_executable(PatternConform String/PatternConform/SqString.c String/PatternConform/SqString.h String/PatternConform/PatternConform.c)
add_executable(BinaryTree Tree/BinaryTree/BinaryTree.c Tree/BinaryTree/BinaryTree.h Tree/BinaryTree/BinaryTreeMain.c)
add_executable(BinaryThreadTree Tree/BinaryThreadTree/BinaryThreadTree.c Tree/BinaryThreadTree/BinaryThreadTree.h Tree/BinaryThreadTree/BinaryThreadTreeMain.c)
add_executable(TreeStoreStructure Tree/TreeStoreStructure/TreeStoreStructure.c Tree/TreeStoreStructure/TreeStoreStructure.h Tree/TreeStoreStructure/TreeStoreStructureMain.c)
add_executable(TreeConversion Tree/TreeConversion/TreeConversion.c Tree/TreeConversion/TreeConversion.h Tree/TreeConversion/TreeConversionMain.c)
add_executable(TreeTraversing Tree/TreeTraversing/TreeTraversing.c Tree/TreeTraversing/TreeTraversing.h Tree/TreeTraversing/TreeTraversingMain.c)
add_executable(HuffmanTree Tree/HuffmanTree/HuffmanTree.c Tree/HuffmanTree/HuffmanTree.h Tree/HuffmanTree/HuffmanTreeMain.c)
add_executable(BinarySearchTree Tree/BinarySearchTree/BinarySearchTree.c Tree/BinarySearchTree/BinarySearchTree.h Tree/BinarySearchTree/BinarySearchTreeMain.c)
add_executable(GraphStorage Graph/GraphStorage/GraphStorage.c Graph/GraphStorage/GraphStorage.h Graph/GraphStorage/GraphStorageMain.c)
add_executable(GraphTraverse Graph/GraphTraverse/GraphTraverse.c Graph/GraphTraverse/GraphTraverse.h Graph/GraphTraverse/GraphTraverseMain.c)
add_executable(MinSpanningTree Graph/MinSpanningTree/MinSpanningTree.c Graph/MinSpanningTree/MinSpanningTree.h Graph/MinSpanningTree/MinSpanningTreeMain.c)
add_executable(MinDistance Graph/MinDistance/MinDistance.c Graph/MinDistance/MinDistance.h Graph/MinDistance/MinDistanceMain.c)
add_executable(BinarySearch Search/BinarySearch/BinarySearch.c Search/BinarySearch/BinarySearch.h Search/BinarySearch/BinarySearchMain.c)
add_executable(InsertSort Sort/InsertSort/InsertSort.c Sort/InsertSort/InsertSort.h Sort/InsertSort/InsertSortMain.c)
add_executable(ShellSort Sort/ShellSort/ShellSort.c Sort/ShellSort/ShellSort.h Sort/ShellSort/ShellSortMain.c)
add_executable(BubbleSort Sort/BubbleSort/BubbleSort.c Sort/BubbleSort/BubbleSort.h Sort/BubbleSort/BubbleSortMain.c)
add_executable(QuickSort Sort/QuickSort/QuickSort.c Sort/QuickSort/QuickSort.h Sort/QuickSort/QuickSortMain.c)
add_executable(SelectSort Sort/SelectSort/SelectSort.c Sort/SelectSort/SelectSort.h Sort/SelectSort/SelectSortMain.c)
add_executable(HeapSort Sort/HeapSort/HeapSort.c Sort/HeapSort/HeapSort.h Sort/HeapSort/HeapSortMain.c)
add_executable(MergeSort Sort/MergeSort/MergeSort.c Sort/MergeSort/MergeSort.h Sort/MergeSort/MergeSortMain.c)
add_executable(Expr Expr.c)