all: server client

clean:
	rm -f tcp_server tcp_client

server:
	g++ tcp_server_main.cpp tcp_server.cpp -o tcp_server
client:
	g++ tcp_client.cpp -o tcp_client