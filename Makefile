all: server client

clean:
	rm -f tcp_server tcp_client

server:
	g++ tcp_server_main.cpp tcp_server.cpp conn_handler.cpp -o tcp_server -lpthread
client:
	g++ tcp_client_main.cpp -o tcp_client