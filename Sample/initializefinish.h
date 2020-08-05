#ifndef INITIALIZEFINISH_H
#define INITIALIZEFINISH_H
#include "MessageBase.h"
#include "include.h"
class InitializeFinish : public MessageBase
{
public:
    InitializeFinish();

    int displayParaID(int paraID,int parameter_length , int &flag) override;

    void displayData(int paraID,char paradata) override;

    vector<CParameter> ParameterAnalysis(vector<uint8> receive_package,vector<vector<uint8>>& res_package,vector<CParameter>& parameter,CMessage& message) override;

};

#endif // INITIALIZEFINISH_H
