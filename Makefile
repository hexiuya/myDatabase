all: myDataBase

myDataBase: main.o tTraderBase.o  tMyDataBase.o
	g++ -I. -I/usr/include/cppconn main.o tMyDataBase.o tTraderBase.o -o myDataBase -L/usr/lib -lmysqlcppconn

tTraderBase.o: tTraderBase.cpp
	g++ -c -I. -I/usr/include/cppconn  tTraderBase.cpp -L/usr/lib -lmysqlcppconn

tMyDataBase.o: tMyDataBase.cpp
	g++ -c -I. -I/usr/include/cppconn  tMyDataBase.cpp -L/usr/lib -lmysqlcppconn

main.o: main.cpp
	g++ -c -I. -I/usr/include/cppconn  main.cpp -L/usr/lib -lmysqlcppconn

clean:
	rm *.o myDataBase


