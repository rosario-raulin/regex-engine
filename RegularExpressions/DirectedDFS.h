//
//  DirectedDFS.h
//  RegularExpressions
//
//  Created by Rosario Raulin on 18.01.14.
//  Copyright (c) 2014 Rosario Raulin. All rights reserved.
//

#ifndef __RegularExpressions__DirectedDFS__
#define __RegularExpressions__DirectedDFS__

#include "Digraph.h"

template <class Iterator>
class DirectedDFS {
private:
    std::unique_ptr<bool[]> _marked;
    
    void dfs(const Digraph& graph, int x) {
        //std::cout << "dfs on " << x << std::endl;
        _marked[x] = true;
        for (auto i = graph.cbegin(x); i != graph.cend(x); ++i) {
            if (!_marked[*i]) dfs(graph, *i);
        }
    }
    
public:
    DirectedDFS(const Digraph& graph, int source) :
    _marked(std::unique_ptr<bool[]>(new bool[graph.V()])) {
        for (int i = 0; i < graph.V(); ++i) {
            _marked[i] = false;
        }
        dfs(graph, source);
    };
    
    DirectedDFS(const Digraph& graph, Iterator start, Iterator end) :
    _marked(std::unique_ptr<bool[]>(new bool[graph.V()])) {
        for (int i = 0; i < graph.V(); ++i) {
            _marked[i] = false;
        }
        for (auto i = start; i != end; ++i) {
            if (!_marked[*i]) dfs(graph, *i);
        }
    }
    
    bool marked(int x) {
        return _marked[x];
    }
};

#endif /* defined(__RegularExpressions__DirectedDFS__) */
