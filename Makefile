all: testsAleatorios

testsAleatorios: common.o dyv.o iterativo.o testsAleatorios.o
	g++ common.o dyv.o iterativo.o testsAleatorios.o

common.o: common.cpp common.hpp
	g++ -c common.cpp

dyv.o: dyv.cpp dyv.hpp common.hpp
	g++ -c dyv.cpp

iterativo.o: iterativo.cpp iterativo.hpp common.hpp
	g++ -c iterativo.cpp

testsAleatorios.o: testsAleatorios.cpp dyv.hpp iterativo.hpp common.hpp
	g++ -c testsAleatorios.cpp

clean:
	rm -f common.o dyv.o iterativo.o testsAleatorios.o a.out
