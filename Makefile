PROGS = merge-sort insert-sort priority-queue heap-sort quick-sort cocktail-sort bubble-sort shell-sort select-sort radix-sort bucket-sort count-sort

all :	${PROGS}
	rm *.o -f

merge-sort:merge-sort.c
	gcc -o merge-sort merge-sort.c

priority-queue:priority-queue.c
	gcc -o priority-queue priority-queue.c

insert-sort:insert-sort.c
	gcc -o insert-sort insert-sort.c

heap-sort:heap-sort.c
	gcc -o heap-sort heap-sort.c

quick-sort:quick-sort.c
	gcc -o quick-sort quick-sort.c

cocktail-sort:cocktail-sort.c
	gcc -o cocktail-sort cocktail-sort.c

bubble-sort:bubble-sort.c
	gcc -o bubble-sort bubble-sort.c

shell-sort:shell-sort.c
	gcc -o shell-sort shell-sort.c

select-sort:select-sort.c
	gcc -o select-sort select-sort.c

radix-sort:radix-sort.c
	gcc -o radix-sort radix-sort.c

bucket-sort:bucket-sort.c
	gcc -o bucket-sort bucket-sort.c

count-sort:count-sort.c
	gcc -o count-sort count-sort.c
