#create final executable file exe
exe: spider.o spidermain.c
	gcc -o exe spidermain.c spider.o
#create object file for function
spider.o: spidermanSpy.c
	gcc -c spidermanSpy.c -o spider.o
