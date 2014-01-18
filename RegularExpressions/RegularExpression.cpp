//
//  RegularExpression.cpp
//  RegularExpressions
//
//  Created by Rosario Raulin on 18.01.14.
//  Copyright (c) 2014 Rosario Raulin. All rights reserved.
//

#include "RegularExpression.h"

#include <set>
#include <memory>
#include <stack>

typedef DirectedDFS<std::set<int>::const_iterator> RegexDFS;

RegularExpression::RegularExpression(const std::string& re) :
_g(Digraph(re.length()+1)), _re(re), _M(re.length()) {
    std::stack<size_t> ops;
    
    for (size_t i = 0; i < _M; ++i) {
        size_t lp = i;
        
        if (re[i] == '(' || re[i] == '|') {
            ops.push(i);
        } else if (re[i] == ')') {
            size_t orop = ops.top();
            ops.pop();
            if (re[orop] == '|') {
                lp = ops.top();
                ops.pop();
                _g.addEdge((int)lp, (int)(orop + 1));
                _g.addEdge((int)orop, (int)i);
            } else {
                lp = orop;
            }
        }
        if (i < _M-1 && re[i+1] == '*') {
            _g.addEdge((int)lp, (int)(i+1));
            _g.addEdge((int)(i+1), (int)lp);
        }
        if (re[i] == '(' || re[i] == '*' || re[i] == ')') {
            _g.addEdge((int)i, (int)(i+1));
        }
    }
}

bool
RegularExpression::matches(const std::string &text) const {
    std::set<int> pc;
    std::unique_ptr<RegexDFS> dfs(new RegexDFS(_g, 0));
    
    for (int i = 0; i < _g.V(); ++i) {
        if (dfs->marked(i)) {
            pc.insert(i);
        }
    }
    
    for (int i = 0; i < text.length(); ++i) {
        std::set<int> match;
        for (auto it = pc.cbegin(); it != pc.cend(); ++it) {
            if (*it < _M) {
                if (_re[*it] == text[i] || _re[*it] == '.') {
                    match.insert(*it+1);
                }
            }
        }

        pc.clear();
        dfs = std::move(std::unique_ptr<RegexDFS>(new RegexDFS(_g, match.cbegin(), match.cend())));
        for (int j = 0; j < _g.V(); ++j) {
            if (dfs->marked(j)) {
                pc.insert(j);
            }
        }
    }
    
    return pc.find((int)_M) != pc.end();
}