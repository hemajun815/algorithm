# windows
target = out.exe
cc = g++
libs = -lpthread
sourse = main.cpp

$(target): $(sourse)
	$(cc) $(sourse) -o $(target) $(libs)

clean:
	del $(target)
