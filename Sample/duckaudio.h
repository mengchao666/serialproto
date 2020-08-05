#ifndef DUCKAUDIO_H
#define DUCKAUDIO_H
#include "MessageBase.h"
#include "include.h"

class DuckAudio : public MessageBase
{
public:
    DuckAudio();

    int displayParaID(int paraID,int parameter_length , int &flag) override;

    void displayData(int paraID,char paradata) override;

    vector<CParameter> ParameterAnalysis(vector<uint8> receive_package,vector<vector<uint8>>& res_package,vector<CParameter>& parameter,CMessage& message) override;


private:
    int paraID0;
    double DurationSecs;
    int paraID1;
    double Volume;
};

#endif // DUCKAUDIO_H
