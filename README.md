# Genomic Sequence Alignment Tool

## Overview

The **Genomic Sequence Alignment Tool** is a C++ program designed to compute the **edit distance** between two DNA sequences using a **dynamic programming** approach. The tool helps in bioinformatics by determining how closely related two DNA sequences are by calculating the minimum number of operations (insertions, deletions, or substitutions) required to transform one sequence into the other.

This tool is particularly useful for tasks such as:
- **Sequence matching**
- **Bioinformatics analysis**
- **Gene sequencing**
- **DNA alignment**

## Features

- Calculates the **edit distance** between two DNA sequences.
- Provides the **optimal alignment** of the sequences.
- Optimized for performance using a 2D dynamic programming matrix.
- Prints the aligned sequences along with the minimum edit distance.
- Measures execution time for large datasets.

## Key Concepts

- **Edit Distance**: The minimum number of operations (insertions, deletions, or substitutions) required to transform one string into another.
- **Dynamic Programming**: A method used to solve problems by breaking them down into simpler subproblems and storing the results to avoid redundant calculations.
- **Sequence Alignment**: A way of arranging two sequences (usually DNA or protein sequences) to identify similarities, such as evolutionary relationships.

## Installation

### Requirements
- **C++11 or later** compiler

### Steps

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/username/GenomicSequenceAlignment.git
    cd GenomicSequenceAlignment
    ```

2. Compile the program:

    ```bash
    g++ -std=c++11 -o sequence_alignment main.cpp EDistance.cpp
    ```

## Usage

To run the program and compute the **edit distance** and **sequence alignment** between two DNA sequences, use the following command:

```bash
./sequence_alignment <sequence1> <sequence2>
