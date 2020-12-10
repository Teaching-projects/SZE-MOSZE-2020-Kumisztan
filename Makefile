OBJS := Fighters.o json.o main.o
CGFLAGS := -std=c++17 -Wall
CC := g++-9

add: $(OBJS)
	$(CC) $(CGFLAGS) -o add $(OBJS)

Fighters.o: Fighters.cpp Fighters.h json.h
	$(CC) $(CGFLAGS) -c Fighters.cpp

json.o: json.h
	$(CC) $(CGFLAGS) -c json.cpp

main.o: Fighters.h
	$(CC) $(CGFLAGS) -c main.cpp

clean:
	rm -rf *.o add *.out ./docs 

fight_and_diff:
	bash -c "chmod +x run_test.sh"
	bash -c "./run_test.sh main"
	bash -c "diff output.txt good_output.txt"

cppcheck:
	cppcheck *.cpp --enable=all --output-file=cppcheck_output.txt && chmod +x warning.sh && ./warning.sh && chmod +x error.sh && ./error.sh

check_memoryleak:
	valgrind --leak-check=full --error-exitcode=1 ./a.out Petyero.json Vargussen.json
	chmod +x run_test.sh && ./run_test.sh

doc:
	doxygen doxconf
