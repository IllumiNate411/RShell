# CS 100 Programming Project

## Project Info

- Winter 2020 
- Steven Joseph - 862083506 - sjose007@ucr.edu
- Nathanael Holmes - 862010704 - nholm002@ucr.edu

## Introduction

The goal of this program is to create a CLI Shell that can execute programs and commands as well as identify whether or not they succeed or fail. We will also incorporate logical connectors like &&, ||, and ; that rely on this knowledge of whether or not a particular command executes properly. The main design pattern we will be implementing is the Composite Pattern. We will have a base class from which several child classes will inherit from. When user input is recieved we will determine what class each portion belongs to. These children will be a command class and a logical connector class, as well as an argument and execute class potentially.

## Diagram



## Classes



## Prototypes/Research



## Development and Testing Roadmap

- Create TOKENIZER class to seperate user input string into individual strings
- Unit Test TOKENIZER class
- Create a parser to parse user input
- Unit Test Parser
- Integration Test TOKENIZER with parser
- Make AND class
- Unit Test AND class
- Integration Test AND with user input
- Make OR class
- Unit Test OR class
- Integration Test OR with user input and AND
- Make SEMICOLON class
- Unit Test SEMICOLON class
- Integration Test SEMICOLON with OR, AND, and user input
- Make COMMENT class
- Unit Test COMMENT class
- Integration Test COMMENT with OR, AND, SEMICOLON, and user input
