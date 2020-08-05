//
// Created by zhaoshunxian on 2020/7/29.
//

#include "../Interface/CParser.h"
#include "include.h"

std::experimental::optional<CMessage> CParser::Parse(std::vector<unsigned char> data)
{
    int position = 0;
    vector<uint8> res;
    vector<uint8> receive_package;
    uint16 message_ID = 0;
    vector<vector<uint8>> res_package;
    vector<CParameter> parameter;
    CMessage message;

    while(position < data.size())
    {
        if(MakeData(position ,message_ID, data ,res_package,parameter,message) < 0)
        {
            cout << "当前链路包头部解析错误，已结束……" << endl;
        }
        position++;
    }
    message.message_ID = message_ID;
    message.parameter = parameter;
    if(message_ID == 0)
    {
        return {};
    }
    cout << "----------------" << endl;
    cout <<"message.message_ID = " << message.message_ID << endl;
    for(int i=0;i<message.parameter.size();i++)
    {
        cout << "0x" << (int)message.parameter[i].parameter_ID << endl;
        for(int j=0;j<message.parameter[i].parameter_data.size();j++)
        {
            cout << "0x" <<(int)message.parameter[i].parameter_data[j] << endl;
        }

    }
    cout << "----------------" << endl;

    return message;
}
