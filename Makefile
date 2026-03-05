all: testsAleatorios testsUnitarios

testsAleatorios: common.cpp dyv.cpp iterativo.cpp testsAleatorios.cpp common.hpp dyv.hpp iterativo.hpp
	g++ common.cpp dyv.cpp iterativo.cpp testsAleatorios.cpp -o testsAleatorios

testsUnitarios: common.cpp dyv.cpp iterativo.cpp testsUnitarios.cpp common.hpp dyv.hpp iterativo.hpp
	g++ common.cpp dyv.cpp iterativo.cpp testsUnitarios.cpp -o testsUnitarios

clean:
	rm -f testsAleatorios testsUnitarios a.out