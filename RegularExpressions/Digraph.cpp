//
//  Digraph.cpp
//  RegularExpressions
//
//  Created by Rosario Raulin on 18.01.14.
//  Copyright (c) 2014 Rosario Raulin. All rights reserved.
//

#include "Digraph.h"

#include <sstream>

Digraph::Digraph(size_t size) : _V(size), _E(0),
    _adj(std::unique_ptr<std::vector<int>[]>(new std::vector<int>[size])) {
}

void
Digraph::addEdge(int from, int to) {
    _adj[from].push_back(to);
}

std::vector<int>::const_iterator
Digraph::cbegin(int from) const {
    return _adj[from].cbegin();
}

std::vector<int>::const_iterator
Digraph::cend(int from) const {
    return _adj[from].cend();
}

size_t
Digraph::V() const {
    return _V;
}

size_t
Digraph::E() const {
    return _E;
}

std::ostream&
operator<<(std::ostream& stream, const Digraph& g) {
    std::stringstream out;
    
    for (size_t v = 0; v < g.V(); ++v) {
        out << v << ": ";
        for (auto adj = g.cbegin((int)v); adj != g.cend((int)v); ++adj) {
            out << *adj << " ";
        }
        out << std::endl;
    }
    
    stream << out.str();
    return stream;
}
