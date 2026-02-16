# Compiler Construction Lab Course

## Overview

This repository contains laboratory assignments for the **Compiler Construction** course. Compiler construction is a fundamental course in computer science that teaches students how to build compilers and interpreters. It covers the entire process of transforming high-level source code into executable machine code or intermediate representations.

## Course Objectives

The Compiler Construction course aims to:

1. **Understand Compilation Phases**: Learn each phase of the compilation process
2. **Design Programming Languages**: Understand syntax and semantics of programming languages
3. **Implement Core Compiler Components**: Build lexical analyzers, parsers, and code generators
4. **Learn Language Theory**: Apply concepts from formal language theory and automata theory
5. **Optimize Code**: Understand code optimization techniques
6. **Debug Complex Systems**: Learn to work with and debug large compiler systems

## Compiler Construction Fundamentals

### What is a Compiler?

A compiler is a software program that translates source code written in a high-level programming language into machine code, bytecode, or another programming language. The compilation process involves multiple phases:

```
Source Code → Lexical Analysis → Syntax Analysis → Semantic Analysis 
    → Intermediate Code Generation → Optimization → Code Generation → Executable
```

### Key Phases of Compilation

#### 1. **Lexical Analysis (Scanning)**
- **Goal**: Break source code into tokens (basic units)
- **Input**: Raw source code (characters)
- **Output**: Stream of tokens (keywords, identifiers, operators, literals, etc.)
- **Tools**: Lexical analyzers (scanners) using regular expressions and finite automata
- **Lab Reference**: Lab_02, Lab_03

#### 2. **Syntax Analysis (Parsing)**
- **Goal**: Check if tokens follow grammatical rules
- **Input**: Stream of tokens from lexer
- **Output**: Parse tree or abstract syntax tree (AST)
- **Methods**: LL parsing, LR parsing, recursive descent parsing
- **Tools**: Parser generators (yacc, bison)
- **Concepts**: Context-free grammars (CFG), BNF notation

#### 3. **Semantic Analysis**
- **Goal**: Check for semantic errors (type mismatches, undefined variables, etc.)
- **Input**: Parse tree/AST
- **Output**: Annotated parse tree with type information
- **Activities**: 
  - Type checking
  - Symbol table management
  - Scope resolution

#### 4. **Intermediate Code Generation**
- **Goal**: Generate intermediate representation independent of target machine
- **Input**: Annotated parse tree
- **Output**: Intermediate code (three-address code, bytecode, etc.)
- **Advantages**: Machine-independent, easier to optimize

#### 5. **Code Optimization**
- **Goal**: Improve program efficiency (speed, memory usage)
- **Optimization Types**:
  - **Local optimizations**: Within a basic block
  - **Global optimizations**: Across multiple blocks
  - **Machine-dependent optimizations**: Target-specific improvements
- **Techniques**: Dead code elimination, constant folding, loop optimization, inlining

#### 6. **Code Generation**
- **Goal**: Translate optimized intermediate code to target machine code
- **Input**: Optimized intermediate code
- **Output**: Assembly or machine code
- **Activities**: Register allocation, instruction selection, instruction scheduling

#### 7. **Linking and Loading**
- **Goal**: Combine object files and load into memory
- **Activities**: Symbol resolution, address binding, library linking

### Supporting Components

#### **Symbol Table**
- Maintains information about identifiers (variables, functions, classes)
- Tracks scope, type, and other attributes
- Used throughout compilation phases

#### **Error Handling**
- Detects and reports syntax and semantic errors
- Provides meaningful error messages
- Attempts error recovery for continued compilation

## Lab Assignments Overview

### Lab 01: Control Flow and Basic Programming
**Topics**: Flow control structures, conditional statements, loops
- **Practice Tasks**: Even/Odd examples, conditional logic
- **Task 1**: goto vs switch implementations
- **Task 2**: Even number handling with multiple conditions
- **Skills**: Understanding program control flow, comparison of different control mechanisms

**Learning Goals**:
- Master conditional execution (if-else, switch)
- Understand loop structures (while, for)
- Learn about goto statements and why they're discouraged
- Diagram program flow

### Lab 02: Lexical Analysis (Lexer/Scanner)
**Topics**: Tokenization, regular expressions, finite automata
- **Input**: `.tiny` source files (sample language)
- **Output**: Tokenized output with token types
- **Components**: 
  - Recognize keywords, identifiers, operators, literals
  - Handle whitespace and comments
  - Report lexical errors

**Skills Developed**:
- Build a lexical analyzer from scratch
- Understand token patterns using regular expressions
- Implement state machines for lexical analysis
- Handle input/output for compiler phases

**What You'll Build**:
- Lexer that processes source code character by character
- Token classification system
- Error detection for invalid characters/tokens

### Lab 03: Syntax Analysis (Scanner/Parser Foundation)
**Topics**: Grammar, parse trees, parsing strategies
- **Components**:
  - Scanner refinement from Lab 02
  - Parser foundation for syntax checking
  - Abstract syntax tree generation

**Skills Developed**:
- Understand context-free grammars (CFG)
- Implement recursive descent parser
- Build parse trees or AST
- Handle syntax errors with meaningful messages

**What You'll Build**:
- Enhanced scanner with better token recognition
- Basic parser for simple language
- Syntax error handling

### Future Labs (Coming)

The course will expand to include:

#### **Lab 04: Semantic Analysis**
- Type checking
- Symbol table implementation
- Scope and binding analysis
- Semantic error detection

#### **Lab 05: Intermediate Code Generation**
- Three-address code generation
- Quadruple/Triple representation
- Abstract machine design
- Code linearization

#### **Lab 06: Code Optimization**
- Constant folding
- Dead code elimination
- Common subexpression elimination
- Loop optimizations
- Peephole optimization

#### **Lab 07: Code Generation**
- Target code selection
- Register allocation
- Assembly code generation
- Jump optimization

#### **Lab 08: Complete Compiler Project**
- Integrate all components
- Build complete compiler for custom language
- Performance analysis
- Compiler testing and validation

## Technologies & Tools Used

### Programming Language
- **C++** (C++20 standard)
  - Modern C++ features for efficient compiler implementation
  - Strong type system for AST representation
  - Standard Library containers (vectors, maps, sets)

### Build System
- **CMake**: Cross-platform build configuration
- **Ninja**: Fast build system
- **CLion IDE**: JetBrains C++ development environment

### Sample Language
- **TINY Language**: A simple language for compiler construction
  - Minimal syntax for educational purposes
  - Used in "Crafting a Compiler" textbook
  - Files: `.tiny` extension

## Project Structure

```
CompilerConstruction_Lab/
├── CMakeLists.txt              # Build configuration
├── README.md                   # This file
├── .gitignore                  # Git ignore rules
├── Lab/
│   ├── Lab_01/                 # Control Flow & Basic Programming
│   │   ├── Practice Task/      # Practice exercises
│   │   ├── Task1/              # Assignment 1
│   │   ├── Task2/              # Assignment 2
│   │   └── Diagram/            # Flow diagrams
│   ├── Lab_02/                 # Lexical Analysis (Lexer)
│   │   └── Task/               # Lexer implementation
│   ├── Lab_03/                 # Syntax Analysis (Parser)
│   │   └── Task/               # Scanner/Parser implementation
│   └── (More labs coming...)
└── cmake-build-debug/          # Build artifacts (ignored in .gitignore)
```

## Compilation Process for This Project

### Building the Project

```bash
# Create build directory
mkdir build
cd build

# Configure with CMake
cmake .. -G "Ninja" -DCMAKE_BUILD_TYPE=Debug

# Build
ninja
```

### Running Programs

```bash
# Run the main executable
./CompilerConstruction_Lab

# Run Lab 02 lexer with input file
./lexer.exe < input.tiny > output.tiny

# Run Lab 03 scanner with input file
./scanner.exe < input.tiny > output.tiny
```

## Input/Output Format

### TINY Language Files (`.tiny`)
Sample TINY language syntax:
```
read x;
if x > 0 then
  write x;
  write y
else
  write 0
end
```

### Lexer Output
```
Reserved: read
ID: x
Reserved: ;
Reserved: if
ID: x
OP: >
NUM: 0
Reserved: then
...
```

## Key Concepts to Master

### Regular Expressions
- Pattern matching for tokens
- Character classes, quantifiers, alternation
- Used in lexical analysis

### Finite Automata
- Deterministic Finite Automaton (DFA)
- Nondeterministic Finite Automaton (NFA)
- Epsilon transitions
- DFA from NFA conversion

### Context-Free Grammars
- Production rules
- Derivation trees
- Left/right recursion
- Ambiguity resolution

### Parsing Techniques
- **Top-down parsing**: Recursive descent, LL parsing
- **Bottom-up parsing**: Shift-reduce, LR parsing
- **Error recovery**: Panic mode, phrase-level recovery

### Abstract Syntax Trees (AST)
- Tree representation of program structure
- Separates syntax from semantics
- Intermediate representation for analysis/optimization

### Symbol Tables
- Hash tables for fast identifier lookup
- Scope management with linked structures
- Attribute storage (type, address, value)

## References & Resources

### Recommended Textbooks
1. **Compilers: Principles, Techniques, and Tools** - Aho, Lam, Sethi, Ullman (The "Dragon Book")
2. **Crafting a Compiler** - Fischer, Cytron, LeBlanc
3. **Engineering a Compiler** - Cooper, Torczon
4. **Modern Compiler Implementation in C** - Appel

### Online Resources
- **ANTLR Parser Generator**: https://www.antlr.org/
- **Lex & Yacc Tutorials**: Traditional compiler tools
- **Regular Expression Tester**: https://regex101.com/
- **Parse Tree Visualizer**: Online tools for understanding grammar

## Important Notes

### Code Quality
- Write clear, well-documented code
- Use meaningful variable and function names
- Follow C++ best practices
- Test with multiple inputs

### Testing Strategy
- Test with valid inputs
- Test edge cases (empty input, single token, etc.)
- Test error cases (invalid tokens, malformed syntax)
- Create test files for verification

### Debugging Tips
- Use print statements to trace token generation
- Visualize parse trees
- Step through code with debugger
- Verify grammar rules thoroughly

## Learning Outcomes

By completing this course, students will:
- ✓ Understand the complete compilation pipeline
- ✓ Implement lexical and syntactic analyzers
- ✓ Design and implement parsing algorithms
- ✓ Work with formal language theory in practice
- ✓ Build error detection and reporting systems
- ✓ Develop large, complex software systems
- ✓ Apply optimization techniques
- ✓ Understand target code generation

## Course Progress Tracking

- [x] **Lab 01**: Control Flow & Basic Programming
- [x] **Lab 02**: Lexical Analysis
- [x] **Lab 03**: Syntax Analysis
- [ ] **Lab 04**: Semantic Analysis (Coming)
- [ ] **Lab 05**: Intermediate Code Generation (Coming)
- [ ] **Lab 06**: Code Optimization (Coming)
- [ ] **Lab 07**: Code Generation (Coming)
- [ ] **Lab 08**: Complete Compiler Project (Coming)

## Getting Started

1. **Clone the Repository**
   ```bash
   git clone <repository-url>
   cd CompilerConstruction_Lab
   ```

2. **Set Up Development Environment**
   - Install CMake
   - Install a C++20 compatible compiler (MSVC, GCC, Clang)
   - Open in CLion or configure in your preferred IDE

3. **Study the Theory**
   - Review compiler construction concepts
   - Understand the specific lab's focus area
   - Consult references as needed

4. **Examine Existing Code**
   - Read and understand provided starting code
   - Review input/output examples
   - Study any provided test cases

5. **Implement Requirements**
   - Write code according to specifications
   - Test thoroughly with various inputs
   - Handle edge cases and errors

6. **Debug and Optimize**
   - Use compiler warnings to catch issues
   - Profile code for performance
   - Refactor for clarity and efficiency

## Troubleshooting

### Build Issues
- Ensure CMake version is 3.20 or higher
- Check that C++20 compiler is available
- Clear build directory and rebuild if needed

### Runtime Issues
- Verify input files are in correct format
- Check file encoding (UTF-8 recommended)
- Test with simple inputs first
- Use debugging output to trace execution

### Logic Issues
- Verify grammar rules are correctly implemented
- Print tokens/parse tree for inspection
- Test edge cases systematically
- Compare with expected output

## Contributing & Questions

For questions about the course material:
1. Review the course slides and textbook references
2. Check provided examples and documentation
3. Consult with instructors during office hours
4. Discuss with classmates in study groups

## License

This course material and code are provided for educational purposes.

---

**Last Updated**: February 2026  
**Course**: Compiler Construction  
**Institution**: [Your Institution Name]  
**Instructor**: [Your Instructor Name]

