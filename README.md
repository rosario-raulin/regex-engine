A simple regex engine
=====================

This project is an implementation of the simple regex engine as described by
Robert Sedgewick, et al. in "Algorithms - Fourth Edition"
(2011, Addison Wesley). It follows the following definition of a regex:

Let A be a (finite) alphabet of characters.

0. . is a regex.
1. The empty string "" is a regex.
2. Some character X from our alphabet A is a regex.
3. Let R be a regex. Then R* is a regex.
4. Let R1 and R2 be regex. Then R1R2 is a regex.
5. Let R1 and R2 be regex. Then (R1|R2) is a regex.
6. R is a regex if and only if it can be build using the rules 0 to 5
for a finite amount of times.

The following function f maps a regex to a set of words.

0. f(".") = A
1. f("") = { e } where e is the empty word.
2. Let x ∈ A. Then f("x") = { x }.
3. Let R1 and R2 be regex. Then f("(R1|R2)") = f(R1) ∪ f(R2)
4. Let R1 and R2 be regex. Then f("R1R2") = { xy | x ∈ f(R1) and y ∈ f(R2) }
5. Let R be a regex. Then R* = Union of all sets { r^n | r ∈ R } for any n >= 0.

regex R is said to match some text S iff S ∈ f(R).
