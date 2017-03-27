template<class Element>
void replacementSelection(Element *A, int n, const char *in, const, char* out) {
	Elem min;//存放最小堆的最小值
	Elem r;//存放从输入缓冲区读入的元素
	FILE *inputFile;
	FILE *outputFile;
	Buffer<Element> input;
	Buffer<Element> output;
	initFiles(inputFile, outputFile, in, out);
	initMinHeapArray(inputFile, n, A);//build heap
	MinHeap<Element> H(A, n, n);
	initInputBuffer(input, inputFile);
}