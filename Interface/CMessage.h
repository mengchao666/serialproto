//
// Created by zhaoshunxian on 2020/7/29.
//

#ifndef SERIALPROTO__CMESSAGE_H_
#define SERIALPROTO__CMESSAGE_H_

#include "CParameter.h"
#include <vector>
#include <string>
#include "../Sample/types.h"
#include <iostream>

using namespace std;

class CMessage
{
public:
    CMessage();
    unsigned short GetID();
    std::vector<CParameter> GetParameters();

    vector<CParameter> parameter;
    unsigned short message_ID;
private:

};

#endif //SERIALPROTO__CMESSAGE_H_
