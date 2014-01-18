//
//  main.cpp
//  RegularExpressions
//
//  Created by Rosario Raulin on 18.01.14.
//  Copyright (c) 2014 Rosario Raulin. All rights reserved.
//

#include <iostream>
#include <cassert>

#include "RegularExpression.h"

int main(int argc, const char * argv[])
{
    RegularExpression re1("(A|B).*");
    
    assert(re1.matches("Aajflkadsfjasjf"));
    assert(re1.matches("A"));
    assert(re1.matches("B"));
    assert(re1.matches("Bajflkadsfjasjf"));
    
    assert(!re1.matches(""));
    assert(!re1.matches("Csdfas"));
    
    // This one should match any string
    RegularExpression re2(".*");
    assert(re2.matches(""));
    assert(re2.matches("8adsfhfjkys8ruh"));
    
    // This one should only match the empty string
    RegularExpression re3("");
    assert(re3.matches(""));
    assert(!re3.matches("8adsfhfjkys8ruh"));
    
    // This is a simple substring search
    RegularExpression re4(".*FINDME.*");
    assert(re4.matches("SOMESTUPIDTEXTBUTFINDMEHERESOMEWHERE"));
    assert(!re4.matches("YOUWANTFINDMAHERE"));
    
    return 0;
}

