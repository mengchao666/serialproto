#ifndef REQUESTPHONEKEY_H
#define REQUESTPHONEKEY_H
#include "MessageBase.h"
#include "include.h"
class RequestPhoneKey : public MessageBase
{
public:
    RequestPhoneKey();

    int displayParaID(int paraID,int parameter_length , int &flag) override;

    void displayData(int paraID,char paradata) override;

    vector<CParameter> ParameterAnalysis(vector<uint8> receive_package,vector<vector<uint8>>& res_package,vector<CParameter>& parameter,CMessage& message) override;

private:
    int paraID0;
    int paraID1;
    int paraID2;
    int paraID3;
    int paraID4;
    int paraID5;
    int paraID6;
    int paraID7;
    int paraID8;
    int paraID9;
    int paraID10;
    int paraID11;
    int paraID12;
    int paraID13;
    int paraID14;
};

#endif // REQUESTPHONEKEY_H
