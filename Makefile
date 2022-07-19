#CS530
#Jaylan Pierce
#RedID: 822644713
#cssc3652
#Disassembler
#Professor Ben Shen 
#April 1, 2021

CC=g++

all: dissem
	$(CC) dissem.cpp -o dissem
	export PATH="./:$PATH"

clean:
	rm -rf dissem
	rm -rf out.lst