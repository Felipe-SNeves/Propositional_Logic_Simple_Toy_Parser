all: stack lexicalParser main.c
	gcc syntaticParser.c lexicalParser.c lexicalToken.c node.c stack.c main.c -o test

lexicalParser: lexicalToken lexicalParser.c stack syntaticParser
	gcc -c lexicalParser.c -o lexicalParser

syntaticParser: syntaticParser.c
	gcc -c syntaticParser.c -o syntaticParser

stack: node stack.c
	gcc -c stack.c -o stack

node: node.c
	gcc -c node.c -o node

lexicalToken: lexicalToken.c
	gcc -c lexicalToken.c -o lexicalToken

clear:
	rm stack test lexicalParser node lexicalToken syntaticParser