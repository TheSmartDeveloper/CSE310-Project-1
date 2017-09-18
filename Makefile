proj1	:main.o
				 g++ -std=c++11 main.cpp foreignsub.cpp -o proj1

clean			:
				 rm *.o
			
cleanAll		:
				 rm *.o run