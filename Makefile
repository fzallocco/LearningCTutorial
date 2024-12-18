.PHONY: test test_obj test_obj_exe_run test2 clean

GCC = gcc
NVCC = nvcc
CUDA_FLAGS = -arch=sm_86

test:
	@$(GCC) -o test test.c


# just compiles to object file
test_obj:
	@$(GCC) -c test.c -o test.o

# compiles and runs the object file (ensure 01_obj is up to 
# date by running 01_obj first if it hasn't been run yet)
test_obj_exe_run: test_obj
	@$(GCC) test.o -o test
	@./test

test2:
	@$(GCC) -o test2 test2.c

test3: 
	@$(NVCC) $(CUDA_FLAGS) -o test_cu test.cu

#rm -f test test2 test_cu *.o this is for Linux
#del test test2 test_cu *.exe *.o this is for Windows
clean:
	rm -f test test2 *.o