A simple regex engine
=====================

This project is an implementation of the simple regex engine as described by
Robert Sedgewick, et al. in "Algorithms - Fourth Edition"
(2011, Addison Wesley). It follows the following definition of a regex:

A regex is a string that is

1. empty (denoted by "") or
2. some character X or
3. R* where R is some regex or
4. (R1|R2) where R1 and R2 are some regex
5. R1R2 where R1 and R2 are some regex
6. built by applying 1, 2, 3, 4 and 5 a finite amount of times.

A regex is said to match some other string, i. e. there is a function f that
maps some regex R to a set of words. That function is defined like this:

1. f("") = {}
2. f(X) = {X}
3. f(R*) is the set of words formed by appending some strings r1 and r2 from R*. Think of it as this kind of recursive definition:
	1. R* is initially just {r | r ∈ R}.
	2. R* is then set to R* (the old one) ∪ { r | R* }
4. f((R1|R2)) = f(R1) ∪ f(R2)
5. f(R1R2) = { xy | x ∈ f(R1) and y ∈ f(R2) }
6. f(.) = U

The last definition mean that the special character . is reserver for meaning
any character from our alphabet/universe U.

regex R matches some text S with S ∈ f(R).
