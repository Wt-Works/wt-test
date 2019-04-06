all: dropdown

dropdown: main.cpp View.o
	g++ -std=c++14 -DBOOST_SIGNALS_NO_DEPRECATION_WARNING -o $@ main.cpp View.o -lwthttp -lwt -lboost_signals

View.o: View.cpp View.h
	g++ -std=c++14 -DBOOST_SIGNALS_NO_DEPRECATION_WARNING -c View.cpp


clean:
	- rm main.o
	- rm View.o
	- rm dropdown

run-local: dropdown
	./dropdown  --docroot . --http-address 0.0.0.0 --http-port 9090
