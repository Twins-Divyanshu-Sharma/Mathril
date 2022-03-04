prog =mathril
classes =$(shell find incsrc -name *.cpp)
objects =$(patsubst incsrc/%, bld/%, $(classes:.cpp=.o))

all: directories $(prog)

directories:
	@mkdir -p bld
	@mkdir -p bin

$(prog): $(objects)
	@echo " ____|-----|____"
	@echo " |:: | ::: | :: | "
	@echo " |:: | ::: | :: |"
	@echo " |   |     |    |"
	@echo "     BUILDING "
	g++ -o bin/$@ $^ -Iincsrc 


bld/%.o:  incsrc/%.cpp
	@echo " <<<<<<<<<<<<<<< COMPILING >>>>>>>>>>>>> "
	g++ -o $@ -c $<

clean:
	@rm -rf bld
	
purge: clean
	@rm -rf bin
	
	
