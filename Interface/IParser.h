//
// Created by zhaoshunxian on 2020/7/29.
//

#ifndef SERIALPROTO__IPARSER_H_
#define SERIALPROTO__IPARSER_H_

#include "CMessage.h"

class IParser
{
public:
    virtual std::experimental::optional<CMessage> Parse(std::vector<unsigned char> data) = 0;
};

#endif //SERIALPROTO__IPARSER_H_
