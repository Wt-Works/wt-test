all:
	g++ -DBOOST_SIGNALS_NO_DEPRECATION_WARNING -o hello hello.cc -lwthttp -lwt -lboost_signals
