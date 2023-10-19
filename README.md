# tcp_communication_console

## TCP Server Feature
1. Listen on port 8080
2. Echo every message received from client with "Server Echo:[CLIENT_MESSAGE]" format


##  TCP Client Feature
1. The Client will send a message on every 1 seconds.
2. The message format is "ClientSend_MESSAGECOUNT"

## Build
```
# For both server and client program
make all

#For server program only
make server

#For client program only
make client
```

## Program Execution
```
#server
./tcp_server

# Client
# e.g. ./tcp_client 127.0.0.1 8080
./tcp_client [Server IP] [Server Port]

```
