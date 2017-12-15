default: Serves_up.c array_sort.c MergeSort.c
	gcc -g -Wall -pthread -c Serves_up.c sorter.c mergesort.c MergeSort.c
	gcc -g -Wall -pthread Serves_up.o sorter.o mergesort.o MergeSort.o -o sort_server
	rm Serves_up.o 
	rm sorter.o 
	rm mergesort.o 
	rm MergeSort.o

proc: Sorter.c handle_csv.c MergeSort.c
	gcc -g -Wall -c Sorter.c handle_csv.c MergeSort.c
	gcc -g -Wall Sorter.o handle_csv.o MergeSort.o -o sort_proc
	rm Sorter.o 
	rm handle_csv.o 
	rm MergeSort.o
clean:
	rm sort_server
