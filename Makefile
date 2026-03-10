all: testsAleatorios testsUnitarios tiempos

tiempos: common.cpp dyv.cpp iterativo.cpp tiempos.cpp common.hpp dyv.hpp iterativo.hpp
	g++ common.cpp dyv.cpp iterativo.cpp tiempos.cpp -o tiempos

testsAleatorios: common.cpp dyv.cpp iterativo.cpp testsAleatorios.cpp common.hpp dyv.hpp iterativo.hpp
	g++ common.cpp dyv.cpp iterativo.cpp testsAleatorios.cpp -o testsAleatorios

testsUnitarios: common.cpp dyv.cpp iterativo.cpp testsUnitarios.cpp common.hpp dyv.hpp iterativo.hpp
	g++ common.cpp dyv.cpp iterativo.cpp testsUnitarios.cpp -o testsUnitarios

clean:
	rm -f testsAleatorios testsUnitarios tiempos resultados.csv *.pdf