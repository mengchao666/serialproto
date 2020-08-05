#ifndef MESSAGEBASE_H
#define MESSAGEBASE_H
#include "types.h"
#include <vector>
#include <iostream>
#include "../Interface/CMessage.h"
#include "../Interface/CParameter.h"

using namespace std;

class MessageBase
{
public:
    MessageBase(int messageID=0,int paranum=0);
    virtual ~MessageBase(){};

    virtual int displayParaID(int paraID , int parameter_length , int &flag){}

    virtual void displayData(int paraID,char paradata){}

    virtual void displayData(int paraID,double paradata){}//重载上面的函数

    virtual void displayData(int paraID,int paradata){}//重载上面的函数

    virtual vector<CParameter> ParameterAnalysis(vector<uint8> receive_package,vector<vector<uint8>>& res_package,vector<CParameter>& parameter,CMessage& message){}

protected:
    short messageID;
    int paranum;
};




#endif
