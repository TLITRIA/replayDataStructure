# test01:main.o dynamicArray.o
# 	gcc main.o dynamicArray.o -o test01

# main.o:main.c
# 	gcc -c main.c -o main.o

# dynamicArray.o:dynamicArray.c
# 	gcc -c dynamicArray.c -o dynamicArray.o

# clean:
# 	@rm -rf *.o test01

test02:myTest.o myDynamicArray.o
	gcc myTest.o myDynamicArray.o -o test02

myTest.o:myTest.c
	gcc -c myTest.c -o myTest.o

myDynamicArray.o:myDynamicArray.c
	gcc -c myDynamicArray.c -o myDynamicArray.o

clean:
	@rm -rf *.o test02