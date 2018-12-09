TypeChecker Implementation

Please implement in Ocaml a typechecker for CoreJava language

Your typechecker takes as input a CoreJava program (that you have to manually represent as an AST), does pattern matching over the AST root and calls recursivelly itself for the AST children. For expressions, it returns the computed type of that expression or throws specific exceptions for the encountered errors. For classes/methods definitions it returns true/false (or throws specific exceptions for the encountered errors).
