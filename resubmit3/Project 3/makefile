project3.exe: project3.o printChooseMenu.o RowColumnClass.o ImageClass.o ColorClass.o MessageClass.o constants.h 
	g++ project3.o printChooseMenu.o RowColumnClass.o ImageClass.o ColorClass.o MessageClass.o  constants.h -o project3.exe

project3.o: project3.cpp printChooseMenu.h RowColumnClass.h ImageClass.h ColorClass.h MessageClass.h constants.h 
	g++ -c project3.cpp -o project3.o

printChooseMenu.o: printChooseMenu.cpp printChooseMenu.h constants.h
	g++ -c printChooseMenu.cpp -o printChooseMenu.o

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h ColorClass.h constants.h
	g++ -c RowColumnClass.cpp -o RowColumnClass.o

ImageClass.o: ImageClass.cpp ImageClass.h RowColumnClass.h ColorClass.h MessageClass.h constants.h
	g++ -c ImageClass.cpp -o ImageClass.o

ColorClass.o: ColorClass.cpp ColorClass.h constants.h
	g++ -c ColorClass.cpp -o ColorClass.o

MessageClass.o: MessageClass.cpp MessageClass.h constants.h
	g++ -c MessageClass.cpp -o MessageClass.o

clean:
	rm -f *.o *.exe