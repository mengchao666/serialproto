//
// Created by zhaoshunxian on 2020/7/29.
//
#include "../Interface/CMessage.h"
#include "include.h"
CMessage::CMessage()
{
}

unsigned short CMessage::GetID()
{
    return message_ID;
}

std::vector<CParameter> CMessage::GetParameters()
{
    return  parameter;
}