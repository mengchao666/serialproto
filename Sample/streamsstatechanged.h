#ifndef STREAMSSTATECHANGED_H
#define STREAMSSTATECHANGED_H
#include "MessageBase.h"
#include "include.h"
class StreamsStateChanged : public MessageBase
{
public:
    StreamsStateChanged();

    int displayParaID(int paraID,int parameter_length , int &flag) override;

    void displayData(int paraID,char paradata) override;

    vector<CParameter> ParameterAnalysis(vector<uint8> receive_package,vector<vector<uint8>>& res_package,vector<CParameter>& parameter,CMessage& message) override;

private:
    int paraID0;
    uint8 MainAudio;
    int paraID1;
    uint8 AltAudio;
    int paraID2;
    uint8 MainScreen;
};

#endif // STREAMSSTATECHANGED_H
