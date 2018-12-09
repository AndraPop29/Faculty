open Printf
exception Exception of string

type tPrim = Tint | Tfloat | Tbool| Tvoid;;
type typ = Tprim of tPrim | Tclass of string | Tbot | Tnone;;
type fldDecl = FldDecl of typ * string;;
type fldDeclList = FldDeclList of fldDecl list;;
type fPrm = (typ*string);; 
type fPrmList = fPrm list;;
type valu = Vnull | Int of int | Float of float | Bool of bool | Vvoid ;;
type var = Var of string | Value of valu;;
type varList = VarList of var list;;
type exp = 
    Value of valu
  | Var of string 
  | Vfld of string*string
  | AsgnV of string*exp
  | AsgnF of string*string*exp 
  | Blk of blkExp 
  | Seq of exp*exp
  | If of string*blkExp*blkExp 
  | AddInt of exp*exp
  | MulInt of exp*exp
  | DivInt of exp*exp
  | SubInt of exp*exp
  | AddFloat of exp*exp
  | MulFloat of exp*exp
  | DivFloat of exp*exp
  | SubFloat of exp*exp
  | And of exp*exp
  | Or of exp*exp 
  | Not of exp 
  | LessThan of exp*exp
  | LessEqualThan of exp*exp 
  | GreaterThan of exp*exp 
  | GreaterEqualThan of exp*exp 
  | Equal of exp*exp 
  | Different of exp*exp
  | MethCall of string*string*varList
  | NewInstance of string*varList
  | InstanceOf of string*string
  | WhileVar of string*exp
  | Cast of string*string
and blkExp = Bvar of typ*string*exp | Bnvar of exp
and mthDecl = MethDecl of (typ*string * fPrmList * blkExp)
and mthDeclList = MethDeclList of mthDecl list
and classDecl = ClassDecl of (string * string * fldDeclList * mthDeclList);;
type progr = Progr of (string * classDecl) list;; 

(* OCAML ASTs *)

let program  = 
  Progr([("A",
          (* 1 *)
          (ClassDecl("A","Object",
                     (FldDeclList([(FldDecl(Tprim(Tint), "f1"))])), 
                     (MethDeclList([
                          (MethDecl(Tprim(Tint), "m1", ([(Tprim(Tint), "a"); (Tprim(Tint), "b")]),
                                    (Bvar (Tprim(Tint), "c",
                                           (Seq (
                                               (AsgnV("c", AddInt(Var "a", Var "b"))),
                                               (
                                                 Seq(
                                                   (AsgnF("this","f1", AddInt(Vfld("this", "f1"), Var "c"))), 
                                                   (Var "c")
                                                 )
                                               )
                                             )
                                           )
                                          ))
                                   ))]
                        ))))
         );

         (* 2 *)
         ("B",
          (ClassDecl("B","A",
                     (FldDeclList([(FldDecl(Tclass("A"), "f2"))])),
                     (MethDeclList([(MethDecl(Tclass("A"), "m2",([(Tclass("A"),"x"); (Tclass("A"), "y")]),
                                              (Bvar(Tclass("A"), "z",
                                                    (Seq
                                                       ( 
                                                         (Seq(
                                                             (
                                                               Blk(
                                                                 Bvar(
                                                                   Tprim(Tint), "n",(
                                                                     AsgnV("n", (
                                                                         AsgnV(
                                                                           "n", SubInt(
                                                                             MethCall(
                                                                               "x", "m1", (
                                                                                 VarList(
                                                                                   [Value(Int 1); Value(Int 2)]
                                                                                 )
                                                                               )
                                                                             ), MethCall(
                                                                               "y", "m1", (
                                                                                 VarList(
                                                                                   [Value(Int 1); Value(Int 2)]
                                                                                 )
                                                                               )
                                                                             )
                                                                           )))))
                                                                 )
                                                               )), (
                                                               Blk(
                                                                 Bvar(
                                                                   Tprim(Tbool), "m",
                                                                   (Seq(
                                                                       (AsgnV(
                                                                           "m", (GreaterThan(SubInt(
                                                                               (Vfld("x","f1")), (Vfld("y","f1"))), (Var "n")))
                                                                         )
                                                                       ), 
                                                                       (If ("m",
                                                                            (Bnvar (AsgnV ("z", (NewInstance ("A", VarList([(Var "m")])))))),
                                                                            (Bnvar (AsgnV ("z", (NewInstance ("A", VarList([(Var "n")])))))) 
                                                                           ))
                                                                     )) 
                                                                 ))
                                                             )
                                                           )), 
                                                         (Seq((AsgnF("this", "f2", (Var "z"))),(Var "z") ))
                                                       )

                                                    )
                                                   )) 
                                             ))]))))
         );

         (* 3 *)
         ("Main",(ClassDecl(
              "Main", "Object",(FldDeclList([])), 
              (MethDeclList
                 (
                   [(MethDecl
                       (
                         Tprim(Tvoid), "main", ([]), 
                         (
                           Bvar(Tclass("B"), "o1", 
                                (Seq(
                                    AsgnV("o1", NewInstance("B", (VarList([(Value (Int 0)); (Value Vnull)])))),
                                    (Blk(Bvar(Tclass("A"), "o2", 
                                              (Seq(
                                                  AsgnV("o2", NewInstance("A", (VarList([(Value (Int 2))])))), 
                                                  (Blk(Bvar(Tclass("A"), "o3", 
                                                            (Seq(
                                                                AsgnV("o3", NewInstance("A", (VarList([(Value (Int 3))])))), 
                                                                (AsgnV("o2", (MethCall("o1", "m2", VarList([(Var "o2"); (Var "o3")])))))
                                                              ))
                                                           )))
                                                ))
                                             )))
                                  )) 
                               )
                         )
                       ))]
                 )
              )
            ))
         )
        ]);;

(* HELPER FUNCTIONS *)

(* Field list *)

let rev_list l =
  let rec rev_acc acc = function
    | Progr([]) -> Progr(acc)
    | Progr(hd::tl) -> rev_acc (hd::acc) (Progr(tl))
  in 
  rev_acc [] l

let rec print_fields lista = 
  match lista with 
    []-> ()
  | FldDecl(_,i)::tl -> print_string i ; print_string " " ; print_fields tl;;

let size l = List.fold_left (fun acc _ -> acc + 1) 0 l;;

(* Exchanges the positions of elements in a list of pairs *)

let rec inverse_tuple list =
  match list with
    [] -> [] 
  | (s,i)::tl -> (i,s)::(inverse_tuple tl);;

(* Checks if the two lists of parameters match (they have the same length and types in the same order)*)

let rec match_prms l1 l2 =
  match (l1, l2) with
    ([],[]) -> true
  | ((t1,n1)::tr, (t2,n2)::tl) -> if t1 = t2 then match_prms tr tl else false
  | _ -> false;;

(* Returns the class inherited by class1, if it exists
   and Tclass("") otherwise
*)

let rec inherits class1 program = 
  match program with
    (Progr([])) -> Tclass("")
  |Progr((_,(ClassDecl(s, i,_,_)))::tl) -> if Tclass(s) = class1 then Tclass(i)
    else inherits class1 (Progr(tl));; 

(* 1) Subtype *)

(* Checks if x is a primitive subtype of y*)

let rec primitive_subtype x y = 
  match (x, y) with 
    (Tprim(Tint), Tprim(Tint)) -> true
  |(Tprim(Tfloat), Tprim(Tfloat)) -> true
  |(Tprim(Tvoid), Tprim(Tvoid)) -> true
  |(Tprim(Tbool), Tprim(Tbool)) -> true
  | _ -> false;;

(*
 x - type
 y - type 
 p - program
 returns: true - if x is a subtype of y, 
          false - otherwise
*)

let rec subtype x y p =
  match (x, y, p) with
    (x, y, _) when (primitive_subtype x y) -> true
  |(classA, classB, _) when classA = classB -> true 
  |(classA, classB, _) when inherits classA p = classB -> true (* Inheritance *)
  |(classA, _, _) when inherits classA p <> Tclass("") -> subtype (inherits classA p) y p (* Transitivity *)
  |(classA,classB,_) when inherits classA p <> Tclass("") && classB = Tclass("Object") -> true 
  |(classA, classB,_) when inherits classB p <> Tclass("") && classA = Tbot -> true 
  | _     -> false;;

(* 
2) Field list: computes the fields of a class
*)

(*
obj - class
returns the list of fields of the class obj 
*)

let rec fieldList program obj = 
  match program with  
    Progr([]) -> []
  |(Progr((_,ClassDecl(classB,classA,FldDeclList(fields),_))::tl)) when Tclass(classB) = obj -> (fields)@(fieldList (Progr(tl)) (Tclass(classA))) (* B extends A*)
  |(Progr((_,_)::tl)) -> fieldList (Progr(tl)) obj;;

(* returns list of pairs (type, name), representing field declarations *)

let rec fieldsFromFldDeclList list =
  match list with
    [] -> [] 
  | (FldDecl(s,i)::tl) -> (i,s)::(fieldsFromFldDeclList tl);;

(* Returns the class fields in a list of pairs (type, name *)

let class_fields program obj = 
  (fieldsFromFldDeclList (fieldList (rev_list program) obj));;

(* search list of pairs (name, type) and return a type*)

let rec find_tuple string_name tuples_list =
  match tuples_list with
    [] -> Tnone
  |(s, i)::tl -> if s = string_name then i
    else find_tuple string_name tl

(* Print the type of an expression*)

let printType t =
  match t with 
    Tclass(x) -> print_string x
  | Tprim(y) -> print_string "Not a class"
  | _ -> print_string "Not good";;

(* P|-t1<:t and P|- t2<:t and
   (t is the least maximum type of t1 and t2) *)

let rec leastMaximum t1 t2 progr =
  match (t1, t2, progr) with
    (Tprim(Tint), Tprim(Tint), _) -> Tprim(Tint)
  |(Tprim(Tfloat), Tprim(Tfloat), _) -> Tprim(Tfloat)
  |(Tprim(Tvoid), Tprim(Tvoid), _) -> Tprim(Tvoid)
  |(Tprim(Tbool), Tprim(Tbool), _) -> Tprim(Tbool)
  |(classA, classB, _) when classA = classB -> classA
  |(classA, classB, _) when (subtype classA classB progr) = true -> classB
  |(classA, classB, _) when (subtype classB classA progr) = true -> classA
  |(classA, classB, _) when (inherits classA progr) = (inherits classB progr) -> (inherits classA progr)
  |(classA, classB, _) when (subtype (inherits classA progr) (inherits classB progr) progr) = true -> (inherits classB progr)
  |(classA, classB, _) when (subtype (inherits classB progr) (inherits classA progr) progr) = true -> (inherits classA progr)
  |(classA, classB, _) when (leastMaximum classA (inherits classB progr) progr) = Tclass("Object") -> (leastMaximum classB (inherits classA progr) progr)
  |(classA, classB, _) when (leastMaximum classB (inherits classA progr) progr) = Tclass("Object") -> (leastMaximum classA (inherits classB progr) progr)
  | _ -> Tclass("Object");;

(* Finds the the type of the expression expCrt and 
   - returns: type - if found
             Tnone - if not found 
*)

let rec well_typed_expression progr env expCrt =
  match expCrt with
    Value(Vnull) -> Tbot

  | Value(Int(_)) -> Tprim(Tint)

  | Value(Float(_)) -> Tprim(Tfloat)

  | Value(Bool(_)) -> Tprim(Tbool) 

  | Value(Vvoid) -> Tprim(Tvoid)

  | Var(s) when (find_tuple s env) != Tnone -> find_tuple s env

  | Vfld(v, f) when (find_tuple v env) <> Tnone && (* type of variable*)
                    (inherits (find_tuple v env) progr) <> Tclass("") && (* check if class exists*)
                    (find_tuple f (class_fields progr (find_tuple v env))) <> Tbot ->
    (find_tuple f (class_fields progr (find_tuple v env)))

  | AsgnV(v, e) when (find_tuple v env) <> Tnone && (subtype (well_typed_expression progr env e) (find_tuple v env) progr) = true
    -> Tprim(Tvoid)

  | AsgnF(v, f, e) when (well_typed_expression progr env (Vfld(v,f))) <> Tbot && (well_typed_expression progr env e) <> Tnone && (subtype (well_typed_expression progr env e) (well_typed_expression progr env (Vfld(v,f))) progr) = true
    -> Tprim(Tvoid)

  | Blk(Bvar(typ, v, e)) when (find_tuple v env) = typ && (well_typed_expression progr env e) <> Tnone -> (well_typed_expression progr env e)

  | Blk(Bnvar(e)) when (well_typed_expression progr env e) <> Tnone -> (well_typed_expression progr env e)

  | Seq(e1, e2) when (well_typed_expression progr env e2) <> Tnone && (well_typed_expression progr env e2) <> Tnone -> (well_typed_expression progr env e2)

  | If(v, blk1, blk2) when (subtype (find_tuple v env) (Tprim(Tbool)) progr) && (well_typed_expression progr env (Blk(blk1))) <> Tbot && 
                           (well_typed_expression progr env (Blk(blk2))) <> Tbot -> (leastMaximum (well_typed_expression progr env (Blk(blk1))) (well_typed_expression progr env (Blk(blk2))) progr)

  | AddInt(e1, e2) | MulInt(e1, e2) | DivInt(e1, e2) | SubInt(e1, e2) when (subtype (well_typed_expression progr env e1) (Tprim(Tint)) progr) && 
                                                                           (subtype (well_typed_expression progr env e1) (Tprim(Tint)) progr)
    -> Tprim(Tint)

  | And(e1, e2) | Or(e1, e2) when (subtype (well_typed_expression progr env e1) (Tprim(Tbool)) progr) && (subtype (well_typed_expression progr env e1) (Tprim(Tbool)) progr)
    -> Tprim(Tbool)

  | Not(e) when (subtype (well_typed_expression progr env e) (Tprim(Tbool)) progr) = true -> Tprim(Tbool) 

  | LessThan(e1, e2) | LessEqualThan(e1, e2) | GreaterThan(e1, e2) | GreaterEqualThan(e1, e2) | Equal(e1, e2) | Different(e1, e2) 
    when (primitive_subtype (well_typed_expression progr env e1) (well_typed_expression progr env e2)) &&
         (primitive_subtype (well_typed_expression progr env e2) (well_typed_expression progr env e1)) -> Tprim(Tbool)

  | Cast(cls, v) when (inherits (Tclass(cls)) progr) <> Tclass("") && ((subtype (find_tuple v env) (Tclass(cls)) progr) = true 
                                                                       || (subtype (Tclass(cls)) (find_tuple v env) progr) = true) -> Tclass(cls)

  | InstanceOf(v, cls) when (inherits (Tclass(cls)) progr) <> Tclass("") && ((subtype (find_tuple v env) (Tclass(cls)) progr) = true 
                                                                             || (subtype (Tclass(cls)) (find_tuple v env) progr) = true) -> Tprim(Tbool)

  | NewInstance(cls, VarList(varList)) when (inherits (Tclass(cls)) progr) <> Tclass("") && 
                                            (match_var_fields progr env varList (class_fields progr (Tclass(cls)))) 
    -> Tclass(cls)

  | WhileVar(v, e) when (subtype (find_tuple v env) (Tprim(Tbool)) progr) && (well_typed_expression progr env e) <> Tbot -> Tprim(Tvoid)

  | MethCall(cls, methName, vars) -> (check_method_call (find_tuple cls env) (MethCall(cls, methName, vars)) progr env)  

  | _ -> Tnone
and 
  match_var_fields p env varList fieldList =  (* Returns true if the types of the variables match the types of the fields*)
  match (varList, fieldList) with 
    ([],[]) -> true 
  | ((Var(v)::tr), (s,i)::tl) when (subtype (well_typed_expression p env (Var(v))) i p) = true -> match_var_fields p env tr tl
  | ((Value(v)::tr), (s,i)::tl) when (subtype (well_typed_expression p env (Value(v))) i p) = true -> match_var_fields p env tr tl
  | _ -> false

and check_method_call_aux methods meth env p = (* Checks if method call is made properly for a method from the list : methods *)
  match (methods, meth) with 
    MethDeclList([]), MethCall(_) -> Tnone
  |(MethDeclList((MethDecl(tr,currentName,currentParams,_))::tl), MethCall(v,name,VarList(vars))) -> if currentName = name && 
                                                                                                        (size currentParams) = size vars &&
                                                                                                        (match_var_fields p env vars (inverse_tuple currentParams)) = true
    then tr 
    else 
      check_method_call_aux (MethDeclList(tl)) meth env p
  | _ -> Tnone

and check_method_call cls meth p env = (* Checks if a method call is made properly for the class cls *)
  match p with 
    (Progr([])) -> Tnone
  | Progr((_, ClassDecl(clasa,_,_,methods))::tr) -> if Tclass(clasa) = cls then check_method_call_aux methods meth env p
    else check_method_call cls meth (Progr(tr)) env;;

let rec wellTypedMethod progr env meth = 
  match meth with
    MethDecl(t,s,prmList,exp) when (subtype (well_typed_expression progr ((inverse_tuple prmList)@env) (Blk(exp))) t progr) -> (well_typed_expression progr env (Blk(exp)))
  | _ -> Tnone;;

(* Checks if the list of methods is well typed for the program `p` and environment `env` *)

let rec wellTypedMethods progr env methods = 
  match methods with
    MethDeclList([]) -> true
  | MethDeclList(m::tr) -> if (wellTypedMethod progr env m) <> Tnone then wellTypedMethods progr env (MethDeclList(tr))
    else false;;

(* Checks if a class is well typed *)

let rec wellTypedClass progr env cls = 
  match cls with
    ClassDecl(_,_,_,methods) -> (wellTypedMethods progr env methods);;

(* Checks if there are no duplicate class definitions in program 
   classesParsed - represents the classes already checked*)

let rec noDuplicateClasses progr classesParsed = 
  match progr with 
    Progr([]) -> true
  | Progr((clasa, ClassDecl(_))::tr) -> if List.mem clasa classesParsed = false 
    then (noDuplicateClasses (Progr(tr)) (classesParsed@[clasa])) 
    else false;;

(* Checks if there are no duplicate method definitions in a class
   methodsParsed - represents the methods already checked*)

let rec noDuplicateMethods methList methodsParsed = 
  match methList with 
    MethDeclList([]) -> true 
  | MethDeclList(MethDecl(t,s,_,_)::tr) -> if List.mem s methodsParsed then false else (noDuplicateMethods (MethDeclList(tr)) (methodsParsed@[s]))


(* Checks if there are no duplicate field declarations in a class
   methodsParsed - represents the fields already checked*)

let rec noDuplicateFields fieldList fieldsParsed = 
  match fieldList with 
    FldDeclList([]) -> true 
  | FldDeclList(FldDecl(t,s)::tr) -> if List.mem s fieldsParsed = false then (noDuplicateFields (FldDeclList(tr)) (fieldsParsed@[s])) else false;;

let rec no_duplicate_methods_or_fields_in_class cls =
  match cls with 
    (ClassDecl(_,_,fields,methods)) -> noDuplicateMethods methods [] && noDuplicateFields fields [];;

(* Searches for a method with the name: methodName in the list of methods *)

let rec method_name_in_method_list methods methodName = 
  match methods with 
    MethDeclList([]) -> false
  | (MethDeclList((MethDecl(tr,currentName,_,_))::tl)) -> if currentName = methodName then true else (method_name_in_method_list (MethDeclList(tl)) methodName)

(* Searches for the method `main` in the last class of the program p *)

let main_method_in_last_class p = 
  match (rev_list p) with
    Progr([]) -> false
  | Progr((_,ClassDecl(_,_,_,methods))::tl) -> (method_name_in_method_list methods "main");;

let successors n edges =
  let matching (s,_) = s = n in
  List.map snd (List.filter matching edges);;

(*
DFS approach for finding cycles in graph

edges: list of pairs representing graph edges
visited: list of visited nodes 
recStack: recursive stack - nodes visited before backtracking
graph: nodes which need to be visited  
*)

let rec hasCycle edges visited recStack graph = 
  match graph with
    [] -> false
  | n::nodes when List.mem n recStack = false ->
    if List.mem n visited then
      hasCycle edges visited [] nodes
    else 
    if (successors n edges) = [] then
      hasCycle edges (n::visited) [] nodes
    else 
      hasCycle edges (n::visited) (n::recStack) ((successors n edges) @ nodes)
  | _ -> true;;

(* creates a list of pairs from a program's classes - If class A inherits B, the pair will be: (A, B)*)

let rec create_class_tuple_list p tupleList =
  match p with
    Progr([]) -> tupleList
  | Progr((_,ClassDecl(a,b,_,methods))::tl)  -> create_class_tuple_list (Progr(tl)) ((a,b)::tupleList);;

(* checks for cycles in class hierarchy *)

let rec cycles_in_hierarchy allClasses classesNotTraversed = 
  match classesNotTraversed with 
    [] -> false
  | (a,b)::tr -> if hasCycle allClasses [] [] [a] then true else (cycles_in_hierarchy allClasses tr);;

(* WellFoundedClasses: no duplicate definitions of the clases, no cycle in the class hierarchy and last class contains the main method *)

let well_founded_classes progr = 
  (noDuplicateClasses progr []) && (main_method_in_last_class progr) && 
  ((cycles_in_hierarchy (create_class_tuple_list progr []) (create_class_tuple_list progr []) = false));;

(* Checks if `meth1` overrides `meth2` ok *)

let rec overrides_ok meth1 meth2 p = 
  match (meth1,meth2) with 
    (MethDecl(t1,n1,prms1,_), MethDecl(t2,n2,prms2,_)) -> if subtype t1 t2 p && n1 = n2 && match_prms prms1 prms2 = true then true else false;;

let rec method_names_match meth1 meth2 =
  match (meth1,meth2) with
    (MethDecl(_,n1,_,_), MethDecl(_,n2,_,_)) -> if n1 = n2 then true else false;;

(* Checks if the methods from the list `methods1` override the ones from `methods2` properly *)

let rec check_method_overriding methods1 methods2NotTraversed methods2 p = 
  match (methods1, methods2NotTraversed) with
    [],_ -> true
  | ((method1::tr), (method2::tl)) -> if method_names_match method1 method2 
    then if (overrides_ok method1 method2 p) then 
        check_method_overriding tr methods2 methods2 p 
      else false
    else check_method_overriding (method1::tr) tl methods2 p
  | (method1::tr),[] -> check_method_overriding tr methods2 methods2 p;;

(* Returns the methods inherited by class `classN` *)

let rec inherited_methods classN p =  
  match p with
    Progr([]) -> raise (Exception "Inheritance not ok")
  | Progr((clasa, ClassDecl(_,_,_,MethDeclList(methods)))::tr) -> if clasa = classN then methods else (inherited_methods classN (Progr(tr)));;

(* Checks if the methods from class `cls` override the ones from the base class properly *)

let rec inheritance_ok cls p =
  match cls with
    ClassDecl(a,b,_,MethDeclList(methods)) -> if inherits (Tclass(a)) p = Tclass("") then false 
    else
    if b = "Object" then true
    else
      (check_method_overriding methods (inherited_methods b p) (inherited_methods b p) p);;

let rec well_typed_classes p notTraversedP env = 
  match notTraversedP with 
    Progr([]) -> true 
  | Progr((_,cls)::tr) -> if no_duplicate_methods_or_fields_in_class cls && inheritance_ok cls p
                             && wellTypedClass p env cls then 
      well_typed_classes p (Progr(tr)) env else false;;

let rec well_typed_program p env = 
  well_founded_classes p && well_typed_classes p p env;;

printf "Program well typed: %b" (well_typed_program program [("c", Tprim(Tint)); ("z", Tclass("A")); ("o1", Tclass("B")); ("o2", Tclass("A")); ("o3", Tclass("A"))]);






