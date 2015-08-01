//
//  DirectHangleMaker.h
//  myBooks
//
//  Created by kongbaguni on 2015. 7. 30..
//
//

#ifndef __myBooks__DirectHangleMaker__
#define __myBooks__DirectHangleMaker__
#define DH(__wstring__) DirectHangleMaker::makeDirect(__wstring__)
#include <stdio.h>
#include <string>
class DirectHangleMaker
{
public:
    static std::string makeDirect(std::wstring inputString);
    
};
#endif /* defined(__myBooks__DirectHangleMaker__) */
