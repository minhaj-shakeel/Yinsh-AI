# CXX = g++ -std=c++11
# LFLAGS        = -m64
# CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES) -Wno-sign-compare -Wno-unused-result-Wno-unused-variable-Wno-parameter -L /lib64

# new_main : new_main.o player.o board.o  
# 		$(CXX) $(LFLAGS) -o new_main new_main.o player.o board.o

# new_main.o : new_main.cpp board.h player.h
# 		$(CXX) $(CXXFLAGS) -c new_main.cpp 

# player.o : player.cpp player.h board.h
# 		$(CXX) $(CXXFLAGS) -c player.cpp 

# board.o : board.cpp board.h
# 	$(CXX) $(CXXFLAGS) -c board.cpp

# .PHONY: clean
# clean: 
# 	$(RM) new_main *.o *~ 

 # new_main: new_main.o player.o board.o  
# 		$(CXX)  -o new_main new_main.o player.o board.o
 # new_main.o: new_main.cpp board.h player.h
# 		$(CXX)  -c new_main.cpp 
 # player.o: player.cpp player.h board.h
# 		$(CXX)  -c player.cpp 
 # board.o: board.cpp board.h
# 	$(CXX) -c board.cpp
 # .PHONY: clean
# clean: 
# 	$(RM) new_main *.o *~ 

CXX = g++ -std=c++11 -O3
server_main: server_main.o player.o board.o  
		$(CXX)  -o server_main server_main.o player.o board.o

server_main.o: server_main.cpp board.h player.h
		$(CXX)  -c server_main.cpp 

player.o: player.cpp player.h board.h
		$(CXX)  -c player.cpp 

board.o: board.cpp board.h
	$(CXX) -c board.cpp


.PHONY: clean
clean: 
	$(RM) server_main *.o *~


# new_main: new_main.o player.o board.o  
# 		$(CXX)  -o new_main new_main.o player.o board.o

# new_main.o: new_main.cpp board.h player.h
# 		$(CXX)  -c new_main.cpp 

# player.o: player.cpp player.h board.h
# 		$(CXX)  -c player.cpp 

# board.o: board.cpp board.h
# 	$(CXX) -c board.cpp


# .PHONY: clean
# clean: 
# 	$(RM) new_main *.o *~


