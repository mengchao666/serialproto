#ifndef INCLUDE_H
#define INCLUDE_H
#include <iostream>
#include <vector>
#include "types.h"
#include "MessageBase.h"
#include "../Interface/CMessage.h"
#include "../Interface/CParameter.h"
using namespace std;

const uint8 kPackageHeaderMSB = 0xFF;
const uint8 kPackageHeaderLSB = 0x5A;

const uint8 kMessageHeaderMSB = 0x40;
const uint8 kMessageHeaderLSB = 0x40;

const int kPackageHeaderLength = 11;
const int kMessageHeaderLength = 6;
const int kParameterHeaderLength = 4;

const uint8 kSizeofChar = 1;
const uint8 kSizeofInt = 4;
const uint8 kSizeofDouble = 8;

const uint16 kConnectStateChangedMessageID = 0x4800;
const uint16 kStreamsStateChangedMessageID = 0x4801;
const uint16 kShowWindowMessageID = 0x4900;
const uint16 kSetWindowCaptionMessageID = 0x4902;
const uint16 kDuckAudioMessageID = 0x3A00;
const uint16 kUnduckAudioMessageID = 0x3A01;
const uint16 kSetBrakeSignalMessageID = 0x1400;
const uint16 kRequestPhoneKeyMessageID = 0x2C01;
const uint16 kRequestButtonKeyMessageID = 0x2C00;
const uint16 kSetRightHandMessageID = 0x1700;

const uint16 kTouchpadDataInitMessageID = 0x3500;
const uint16 kRequestKnobMessageID = 0x4E00;
const uint16 kTouchpadDataStartMessageID = 0x3501;
const uint16 kTouchpadDataMessageID = 0x3502;
const uint16 kTouchpadDataStopMessageID = 0x3503;

const uint16 kInitializeStartMessageID = 0x5A00;
const uint16 kInitializeRespondMessageID = 0x5A01;
const uint16 kInitializeFinishMessageID = 0x5A02;

struct PackageHeader
{
    uint8 package_header_MSB;
    uint8 package_header_LSB;
    uint8 package_length_MSB;
    uint8 package_length_LSB;
    uint8 package_header_sum;
};

struct MessageHeader
{
    uint8 message_header_MSB;
    uint8 message_header_LSB;
    uint8 message_length_MSB;
    uint8 message_length_LSB;
    uint8 message_id_MSB;
    uint8 message_id_LSB;
};

uint8 my_checksum_calculation(vector<uint8> vc);

int MakeData(int &position ,uint16 &message_ID, vector<uint8> receive_package,
             vector<vector<uint8>>& res_package,vector<CParameter>& parameter,CMessage& message);

#endif // INCLUDE_H
