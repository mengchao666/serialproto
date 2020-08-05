#ifndef CONNECTSTATECHANGED_H
#define CONNECTSTATECHANGED_H
#include "MessageBase.h"
#include "include.h"
#include <iostream>
class ConnectStateChanged : public MessageBase
{
public:
    ConnectStateChanged();

    int displayParaID(int paraID,int parameter_length , int &flag) override;

    void displayData(int paraID,char paradata) override;

    vector<CParameter> ParameterAnalysis(vector<uint8> receive_package,vector<vector<uint8>>& res_package,vector<CParameter>& parameter,CMessage& message) override;

private:

};

#endif // CONNECTSTATECHANGED_H
