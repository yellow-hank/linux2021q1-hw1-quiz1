CFLAGS := -O1 -g

r_qs_test: r_quick_sort_test.o r_quick_sort.o 
	gcc -o $@ $^
*.o: *.c *.h
	gcc -o $@ $(CFLAGS) -c $<

clean:
	rm *.o r_qs_test
	