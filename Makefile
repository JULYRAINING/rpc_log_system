all:
	make s.o
	make c.o
s.o: main_server.cpp socket_tool_server.cpp mq.cpp process.cpp log_buffer.cpp protobuf_tool.cpp server.cpp logger.cpp log.pb.cc;
	g++ -o ./bin/s.o -std=c++11 -pthread -I /usr/local/include -I include -L /usr/local/lib  main_server.cpp socket_tool_server.cpp mq.cpp process.cpp log_buffer.cpp  protobuf_tool.cpp server.cpp logger.cpp log.pb.cc -lprotobuf;
c.o: main_client.cpp socket_tool_client.cpp  log_buffer.cpp client.cpp logger.cpp  log.pb.cc;
	g++ -o ./bin/c.o -std=c++11 -pthread -I /usr/local/include -I include -L /usr/local/lib  main_client.cpp socket_tool_client.cpp log_buffer.cpp client.cpp logger.cpp log.pb.cc -lprotobuf;