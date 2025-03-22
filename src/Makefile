CXX=g++
CFLAGS=-Wall -std=c++17
INCLUDES=
LIBS=
TARGET=main
OBJ=main.o Personne.o Election.o Candidat.o Bureau.o Bulletin.o Decharge.o Isoloir.o

all : $(TARGET)

clean :
	rm -f $(TARGET) $(OBJ)

$(TARGET) : $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ) $(LIBS)

%.o: %.cpp
	$(CXX) $(CFLAGS) $(INCLUDES) -o $@ -c $<
