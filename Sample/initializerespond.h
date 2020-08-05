#ifndef INITIALIZERESPOND_H
#define INITIALIZERESPOND_H
#include "MessageBase.h"
#include "include.h"
class InitializeRespond:public MessageBase
{
public:
    InitializeRespond();

    int displayParaID(int paraID,int parameter_length , int &flag) override;

    void displayData(int paraID,char paradata) override;

    vector<CParameter> ParameterAnalysis(vector<uint8> receive_package,vector<vector<uint8>>& res_package,vector<CParameter>& parameter,CMessage& message) override;

};

#endif // INITIALIZERESPOND_H
