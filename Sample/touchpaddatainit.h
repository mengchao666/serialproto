#ifndef TOUCHPADDATAINIT_H
#define TOUCHPADDATAINIT_H
#include "MessageBase.h"
#include "include.h"
class TouchpadDataInit : public MessageBase
{
public:
    TouchpadDataInit();

    int displayParaID(int paraID,int parameter_length , int &flag) override;

    void displayData(int paraID,char paradata) override;

    vector<CParameter> ParameterAnalysis(vector<uint8> receive_package,vector<vector<uint8>>& res_package,vector<CParameter>& parameter,CMessage& message) override;

private:
    int paraID0;
    uint8 PointNumber;

    int paraID1;
    int MaxXCoordinate;

    int paraID2;
    int MinXCoordinate;

    int paraID3;
    int MaxYCoordinate;

    int paraID4;
    int MinYCoordinate;
};

#endif // TOUCHPADDATAINIT_H
