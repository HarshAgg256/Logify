# Logify
A C/C++ based tool for constructing and evaluating parse trees of propositional logic formulas, including validation of logical proofs using predefined rules.

## Logic in Computer Science

This repository contains two projects focused on propositional logic and proof validation in computer science. Both projects are implemented in C/C++ and include tasks for constructing and evaluating parse trees and verifying logical proofs.

### Overview

**Propositional Logic:**  
Propositional logic, also known as propositional calculus or Boolean logic, is a branch of logic that deals with propositions that can be either true or false. Propositions are formed using logical connectives such as AND, OR, NOT, and IMPLIES. A propositional logic formula is a statement constructed from propositional variables and logical connectives that can be evaluated to a truth value (true or false).

**Proof Validation:**  
Proof validation is the process of verifying whether a given sequence of logical statements constitutes a valid proof for a conclusion based on a set of premises and logical rules. This involves checking the correctness of each step in the proof and ensuring that the conclusion follows logically from the premises.

### Project 1: Propositional Logic Parser and Evaluator

**Description:**  
A C/C++ tool for parsing and evaluating propositional logic formulas using structured logical rules.

**Tasks:**
1. **Infix to Prefix Conversion:**  
   Implemented an algorithm to convert an infix propositional logic expression (e.g., `(A + B) * C`) into a prefix propositional logic expression (e.g., `* + A B C`). Infix notation places the operator between operands, while prefix notation places the operator before its operands.
   
2. **Parse Tree Construction:**  
   Developed functionality to convert the prefix expression into a rooted binary parse tree. A parse tree is a tree representation of the syntactic structure of a propositional logic formula, where each internal node represents a logical operator and each leaf node represents a propositional variable.
   
3. **Infix Expression Output:**  
   Implemented a function to traverse the parse tree and output the infix expression via in-order traversal. This involves visiting the left subtree, the root node, and then the right subtree, to reconstruct the original infix expression.
   
4. **Parse Tree Height:**  
   Created a function to compute the height of the parse tree. The height of a tree is the length of the longest path from the root node to a leaf node.
   
5. **Truth Value Evaluation:**  
   Developed a method to evaluate the truth value of a propositional logic formula by traversing the tree in a bottom-up fashion. Given the truth values of each propositional atom (e.g., `A = true, B = false`), the function computes the truth value of the entire formula.
   
6. **Algorithm Analysis:**  
   Analyzed the algorithms in terms of output, efficiency, and memory usage. Ensured the code is well-indented and commented, and documented the assignment as HTML pages.

### Project 2: Proof Validation Tool

**Description:**  
A C/C++ tool for verifying the validity of logical proofs using a predefined set of proof rules.

**Proof Rules:**
1. **Premise:**  
   A statement that is assumed to be true.
   
2. **AND Introduction/Elimination:**  
   - AND Introduction (`∧i`): From `A` and `B`, infer `A ∧ B`.
   - AND Elimination (`∧e`): From `A ∧ B`, infer `A` or `B`.
   
3. **OR Introduction:**  
   - OR Introduction (`∨i`): From `A`, infer `A ∨ B`.
   
4. **IMPLIES Elimination:**  
   - IMPLIES Elimination (`→e`): From `A` and `A → B`, infer `B`.
   
5. **Modus Tollens (MT):**  
   - Modus Tollens (`MT`): From `A → B` and `¬B`, infer `¬A`.

**Tasks:**
1. **Input Handling:**  
   Designed a system to read the number of statements and the corresponding logical formulas or proof rules from the input.
   
2. **Proof Validation:**  
   Developed a mechanism to verify whether a given proof is valid based on the provided rules. This involves checking each step of the proof to ensure it follows logically from the previous steps and the premises. Implemented functionality to print "Valid Proof" or "Invalid Proof" based on the validation results.
   
3. **Documentation:**  
   Documented the code using Doxygen and provided detailed documentation of the algorithm, code design, example outputs, and future extension plans as HTML pages.

## Getting Started

### Prerequisites

- C/C++ compiler
- Doxygen for documentation

### Compilation and Execution

1. **Clone the Repository:**
   ```sh
   git clone https://github.com/HarshAgg256/Logify
   cd Logify
   ```

2. **Project - 1:**
   - Navigate to the `Logify` directory.
   - Compile and run the code:
     ```sh
     g++ Propositional_Formula_Evaluation.cpp -o logic_parser
     ./logic_parser
     ```

3. **Project - 2:**
   - Navigate to the `Logify` directory.
   - Compile and run the code:
     ```sh
     g++ Natural_Deduction_Proof_Validity.cpp -o proof_validator
     ./proof_validator
     ```

### Documentation

1. **Generate Documentation:**
   - Run Doxygen in the respective assignment directory to generate HTML documentation:
     ```sh
     doxygen Documentation-I 
     ```
     and
     ```sh
     doxygen Documentation-II
     ```
           

2. **View Documentation:**
   - Open the generated HTML files in a web browser to read the detailed documentation.

## Contact

For any queries or issues, please raise an issue on the GitHub repository or contact the maintainers directly.
