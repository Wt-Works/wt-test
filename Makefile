all: KanBanUi

KanBanUi: KanBanUiTest.cc View.o
	g++ -DBOOST_SIGNALS_NO_DEPRECATION_WARNING -o $@ KanBanUiTest.cc View.o -lwthttp -lwt -lboost_signals

View.o: View.cc View.h
	g++ -DBOOST_SIGNALS_NO_DEPRECATION_WARNING -c View.cc

hello: hello.cc
	g++ -DBOOST_SIGNALS_NO_DEPRECATION_WARNING -o hello hello.cc -lwthttp -lwt -lboost_signals

clean:
	- rm hello
	- rm KanBanUi
	- rm View.o
