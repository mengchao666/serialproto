#ifndef REQUESTKNOB_H
#define REQUESTKNOB_H
#include "MessageBase.h"
#include "include.h"
#include <iostream>
class RequestKnob : public MessageBase
{
public:
    RequestKnob();

    int displayParaID(int paraID,int parameter_length , int &flag) override;

    void displayData(int paraID,char paradata) override;

    vector<CParameter> ParameterAnalysis(vector<uint8> receive_package,vector<vector<uint8>>& res_package,vector<CParameter>& parameter,CMessage& message) override;

private:
    uint16 message_ID;
    int paraID0;

    int paraID1;

    int paraID2;

    int paraID3;
    uint8 X;

    int paraID4;
    uint8 Y;

    int paraID5;
    uint8 Wheel;
};

#endif // REQUESTKNOB_H

