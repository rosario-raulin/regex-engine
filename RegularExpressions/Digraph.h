//
//  Digraph.h
//  RegularExpressions
//
//  Created by Rosario Raulin on 18.01.14.
//  Copyright (c) 2014 Rosario Raulin. All rights reserved.
//

#ifndef __RegularExpressions__Digraph__
#define __RegularExpressions__Digraph__

#include <vector>
#include <memory>

class Digraph {
private:
    size_t _V;
    size_t _E;
    std::unique_ptr<std::vector<int>[]> _adj;
    
public:
    Digraph(size_t size);
    void addEdge(int from, int to);
    size_t V() const;
    size_t E() const;
    std::vector<int>::const_iterator cbegin(int from) const;
    std::vector<int>::const_iterator cend(int from) const;
};

std::ostream& operator<<(std::ostream& stream, const Digraph& g);

#endif /* defined(__RegularExpressions__Digraph__) */
