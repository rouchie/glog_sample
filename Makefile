
objs := main.o 

TARGET := run

LIBS := `pkg-config --libs libglog`
CCFLAGS := `pkg-config --cflags libglog`

CCFLAGS += -std=c++11

$(TARGET):$(objs)
	g++ -o $@ $^ $(LIBS)

%.o:%.cpp
	g++ -c $< $(CCFLAGS) 

clean:
	rm *.o $(TARGET)

