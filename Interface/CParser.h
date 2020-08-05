//
// Created by zhaoshunxian on 2020/7/29.
//

#ifndef SERIALPROTO__CPARSER_H_
#define SERIALPROTO__CPARSER_H_

#include "IParser.h"

class CParser : public IParser
{
public:
    std::experimental::optional<CMessage> Parse(std::vector<unsigned char> data) override;
};

#endif //SERIALPROTO__CPARSER_H_
