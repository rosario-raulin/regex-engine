//
//  RegularExpression.h
//  RegularExpressions
//
//  Created by Rosario Raulin on 18.01.14.
//  Copyright (c) 2014 Rosario Raulin. All rights reserved.
//

#ifndef __RegularExpressions__RegularExpression__
#define __RegularExpressions__RegularExpression__

#include "Digraph.h"
#include "DirectedDFS.h"

#include <string>

class RegularExpression {
private:
    Digraph _g;
    std::string _re;
    size_t _M;
    
public:
    RegularExpression(const std::string& re);
    bool matches(const std::string& text) const;
};

#endif /* defined(__RegularExpressions__RegularExpression__) */
