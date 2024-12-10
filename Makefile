main: main.cpp
	g++ main.cpp -o main -L./lib-arm64/ -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

clean:
	rm main