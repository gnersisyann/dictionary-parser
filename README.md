# Number to Words Parser

A C program that converts numeric input to written words using dictionary files.

## Description

This program takes a number as input and converts it to its written representation (e.g., "123" becomes "one hundred twenty three"). It supports custom dictionaries and can handle numbers up to 39 digits long.

## Features

- Convert numbers to written words
- Support for custom dictionary files
- Handle large numbers (up to 39 digits)
- Built-in default dictionary for English numbers
- Memory-safe implementation with proper error handling

## Usage

```bash
# Using default dictionary
./parser <number>

# Using custom dictionary
./parser <dictionary_file> <number>
```

### Examples

```bash
./parser 123
# Output: one hundred twenty three

./parser ./dictionaries/numbers.dict 456
# Output: four hundred fifty six
```

## Building

```bash
make
```

## Dictionary Format

Dictionary files should follow this format:
```
0: zero
1: one
2: two
...
1000: thousand
1000000: million
```

## Error Handling

- Invalid arguments return error messages
- Numbers longer than 39 digits are rejected
- Missing or corrupted dictionary files are handled gracefully

## Files Structure

- `main.c` - Main program entry point
- `source/` - Source code files
- `headers/ft_lib.h` - Header file with function declarations
- `dictionaries/` - Dictionary files
- `Makefile` - Build configuration
