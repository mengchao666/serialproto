#ifndef TOUCHPADDATA_H
#define TOUCHPADDATA_H
#include "MessageBase.h"
#include "include.h"
struct group
{
    int XCoordinate;
    int YCoordinate;
};

class TouchpadData : public MessageBase
{
public:
    TouchpadData();

    int displayParaID(int paraID,int parameter_length , int &flag) override;

    void displayData(int paraID,char paradata) override;

    vector<CParameter> ParameterAnalysis(vector<uint8> receive_package,vector<vector<uint8>>& res_package,vector<CParameter>& parameter,CMessage& message) override;

private:
    int paraID0;
    group Touchpoints;
};

#endif // TOUCHPADDATA_H
