all:tcp_cli tcp_thread
tcp_thread:tcp_thread.cpp
	g++ $^ -o $@ -lpthread
tcp_process:tcp_process.cpp
	g++ $^ -o $@
tcp_cli:tcp_cli.cpp
	g++ $^ -o $@
tcp_srv:tcp_srv.cpp
	g++ $^ -o $@
udp_cli:udp_cli.cpp
	g++ $^ -o $@
udp_srv:udp_srv.cpp
	g++ $^ -o $@
