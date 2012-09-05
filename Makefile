.PHONY: all compile run

all: compile

compile:
	clang++ -o main main.cc

run:
	./main

