baslat: cpp_derle o_bagla calistir


cpp_derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/SatirListesi.cpp -o ./lib/SatirListesi.o
	g++ -c -I "./include" ./src/YoneticiListesi.cpp -o ./lib/YoneticiListesi.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/YoneticiDugum.cpp -o ./lib/YoneticiDugum.o

o_bagla:
	g++ ./lib/main.o ./lib/SatirListesi.o ./lib/YoneticiListesi.o ./lib/YoneticiDugum.o ./lib/Dugum.o -o ./bin/program

calistir: 
	./bin/program