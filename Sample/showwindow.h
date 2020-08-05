#ifndef SHOWWINDOW_H
#define SHOWWINDOW_H
#include "MessageBase.h"
#include "include.h"
class ShowWindow : public MessageBase
{
public:
    ShowWindow();

    int displayParaID(int paraID,int parameter_length , int &flag) override;

    void displayData(int paraID,char paradata) override;

    vector<CParameter> ParameterAnalysis(vector<uint8> receive_package,vector<vector<uint8>>& res_package,vector<CParameter>& parameter,CMessage& message) override;

private:
    int paraID0;
    uint8 Show;
};

#endif // SHOWWINDOW_H
