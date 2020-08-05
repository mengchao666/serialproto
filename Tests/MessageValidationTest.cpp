#include <iostream>
#include <memory>
#include "../Interface/CParser.h"
#include "gtest/gtest.h"

//取字的高字节
#define HIBYTE(w)   ((unsigned char) (((unsigned short) (w) >> 8) & 0xFF))
//取字的低字节
#define LOBYTE(w)   ((unsigned char) (w))
//取双字的高位字
#define HIWORD(l)   ((unsigned short) (((unsigned int) (l) >> 16) & 0xFFFF))
//取双字的低位字
#define LOWORD(l)   ((unsigned short) (l))

static const std::vector<unsigned char> default_header = {0xFF, 0x5A, 0x00, 0x05};
static const std::vector<unsigned char> default_message_header = {0x40, 0x40, 0x00, 0x07, 0x00, 0x00};
static const unsigned short default_message_id = 0x5A00;

unsigned char checksum_calculation(std::vector<unsigned char> buffer)
{
    unsigned char sum = 0;
    for (auto data : buffer)
    {
        sum += data;
    }
    return (unsigned char) (0x100 - sum); //取二进制补码
}

unsigned char checkheadersum_calculation(std::vector<unsigned char> buffer)
{
    unsigned char sum = 0;
    for (auto data : buffer)
    {
        sum += data;
    }
    return sum;
}

TEST(MessageValidationTestSuite, HeaderTooShort) {
    std::vector<unsigned char> data {0xFF, 0x5A};
    std::unique_ptr<IParser> parser = std::make_unique<CParser>();
    auto message = parser->Parse(data);
    EXPECT_FALSE((bool)message);
}

TEST(MessageValidationTestSuite, HeaderTooShort2) {
    std::vector<unsigned char> data {0xFF, 0x5A, 0x04};
    std::unique_ptr<IParser> parser = std::make_unique<CParser>();
    auto message = parser->Parse(data);
    EXPECT_FALSE((bool)message);
}

TEST(MessageValidationTestSuite, HeaderNoCheckSum) {
    std::vector<unsigned char> data {0xFF, 0x5A, 0x00, 0x04};
    std::unique_ptr<IParser> parser = std::make_unique<CParser>();
    auto message = parser->Parse(data);
    EXPECT_FALSE((bool)message);
}

TEST(MessageValidationTestSuite, HeaderNoCheckSum2) {
    std::vector<unsigned char> data {0xFF, 0x5A, 0xFF, 0xFF};
    std::unique_ptr<IParser> parser = std::make_unique<CParser>();
    auto message = parser->Parse(data);
    EXPECT_FALSE((bool)message);
}

TEST(MessageValidationTestSuite, HeaderInvalidLength) {
    std::vector<unsigned char> data {0xFF, 0x5A, 0xFF, 0xFF, 0x57};
    std::unique_ptr<IParser> parser = std::make_unique<CParser>();
    auto message = parser->Parse(data);
    EXPECT_FALSE((bool)message);
}

TEST(MessageValidationTestSuite, HeaderInvalidLength2) {
    std::vector<unsigned char> data {0xFF, 0x5A, 0x00, 0x00, 0x5A};
    std::unique_ptr<IParser> parser = std::make_unique<CParser>();
    auto message = parser->Parse(data);
    EXPECT_FALSE((bool)message);
}

TEST(MessageValidationTestSuite, HeaderOnly) {
    std::vector<unsigned char> data = default_header;
    std::unique_ptr<IParser> parser = std::make_unique<CParser>();
    data.push_back(checkheadersum_calculation(data));
    auto message = parser->Parse(data);
    EXPECT_FALSE((bool)message);
}

TEST(MessageValidationTestSuite, MessageOnlyHeader) {
    std::vector<unsigned char> data = default_header;
    std::vector<unsigned char> messagedata {0x40, 0x40};
    auto length = data.size()+1 + messagedata.size()+1;
    data.at(2) = HIBYTE(length);
    data.at(3) = LOBYTE(length);
    data.push_back(checkheadersum_calculation(data));
    data.insert(data.end(), messagedata.begin(), messagedata.end());
    std::unique_ptr<IParser> parser = std::make_unique<CParser>();
    auto message = parser->Parse(data);
    EXPECT_FALSE((bool)message);
}

TEST(MessageValidationTestSuite, MessageInvalidLength) {
    std::vector<unsigned char> data = default_header;
    std::vector<unsigned char> messagedata {0x40, 0x40, 0x00, 0x00};
    auto length = data.size()+1 + messagedata.size()+1;
    data.at(2) = HIBYTE(length);
    data.at(3) = LOBYTE(length);
    data.push_back(checkheadersum_calculation(data));
    data.insert(data.end(), messagedata.begin(), messagedata.end());
    std::unique_ptr<IParser> parser = std::make_unique<CParser>();
    auto message = parser->Parse(data);
    EXPECT_FALSE((bool)message);
}

TEST(MessageValidationTestSuite, MessageInvalidLength2) {
    std::vector<unsigned char> data = default_header;
    std::vector<unsigned char> messagedata {0x40, 0x40, 0x05};
    auto length = data.size()+1 + messagedata.size()+1;
    data.at(2) = HIBYTE(length);
    data.at(3) = LOBYTE(length);
    data.push_back(checkheadersum_calculation(data));
    data.insert(data.end(), messagedata.begin(), messagedata.end());
    std::unique_ptr<IParser> parser = std::make_unique<CParser>();
    auto message = parser->Parse(data);
    EXPECT_FALSE((bool)message);
}

TEST(MessageValidationTestSuite, MessageInvalidLength3) {
    std::vector<unsigned char> data = default_header;
    std::vector<unsigned char> messagedata {0x40, 0x40, 0xFF, 0xFF};
    auto length = data.size()+1 + messagedata.size()+1;
    data.at(2) = HIBYTE(length);
    data.at(3) = LOBYTE(length);
    data.push_back(checkheadersum_calculation(data));
    data.insert(data.end(), messagedata.begin(), messagedata.end());
    std::unique_ptr<IParser> parser = std::make_unique<CParser>();
    auto message = parser->Parse(data);
    EXPECT_FALSE((bool)message);
}

TEST(MessageValidationTestSuite, MessageNoID) {
    std::vector<unsigned char> data = default_header;
    std::vector<unsigned char> messagedata = {0x40, 0x40, 0x00, 0x05, 0x7B};
    auto length = data.size()+1 + messagedata.size()+1;
    data.at(2) = HIBYTE(length);
    data.at(3) = LOBYTE(length);
    data.push_back(checkheadersum_calculation(data));
    data.insert(data.end(), messagedata.begin(), messagedata.end());
    std::unique_ptr<IParser> parser = std::make_unique<CParser>();
    auto message = parser->Parse(data);
    EXPECT_FALSE((bool)message);
}

TEST(MessageValidationTestSuite, MessageOK) {
    unsigned short message_id = default_message_id;
    std::vector<unsigned char> data = default_header;
    std::vector<unsigned char> messagedata = default_message_header;
    auto length = data.size()+1 + messagedata.size()+1;
    data.at(2) = HIBYTE(length);
    data.at(3) = LOBYTE(length);
    data.push_back(checkheadersum_calculation(data));
    messagedata.at(2) = HIBYTE(messagedata.size());
    messagedata.at(3) = LOBYTE(messagedata.size());
    messagedata.at(4) = HIBYTE(message_id);
    messagedata.at(5) = LOBYTE(message_id);
    messagedata.push_back(checksum_calculation(messagedata));
    data.insert(data.end(), messagedata.begin(), messagedata.end());
    std::unique_ptr<IParser> parser = std::make_unique<CParser>();
    auto message = parser->Parse(data);
    EXPECT_TRUE((bool)message);
    if (message) {
        EXPECT_EQ(message->GetID(), message_id);
        EXPECT_TRUE(message->GetParameters().empty());
    }
}

TEST(MessageValidationTestSuite, MessageUint8) {
    unsigned short message_id = default_message_id;
    std::vector<unsigned char> data = default_header;
    std::vector<unsigned char> messagedata = default_message_header;
    std::vector<unsigned char> parameterdata = {0x00,0x05, 0x00, 0x01, 0xA1};
    auto length = data.size()+1 + messagedata.size()+1 + parameterdata.size();
    data.at(2) = HIBYTE(length);
    data.at(3) = LOBYTE(length);
    data.push_back(checkheadersum_calculation(data));
    auto message_length = messagedata.size() + parameterdata.size();
    messagedata.at(2) = HIBYTE(message_length);
    messagedata.at(3) = LOBYTE(message_length);
    messagedata.at(4) = HIBYTE(message_id);
    messagedata.at(5) = LOBYTE(message_id);
    messagedata.insert(messagedata.end(), parameterdata.begin(), parameterdata.end());
    messagedata.push_back(checksum_calculation(messagedata));
    data.insert(data.end(), messagedata.begin(), messagedata.end());
    std::unique_ptr<IParser> parser = std::make_unique<CParser>();
    auto message = parser->Parse(data);
    EXPECT_TRUE((bool)message);
    if (message) {
        EXPECT_EQ(message->GetID(), message_id);
        EXPECT_EQ(message->GetParameters().size(), 1);
        for (auto parameter : message->GetParameters()) {
            EXPECT_EQ(parameter.GetID(), 0x0001);
            EXPECT_TRUE(parameter.GetUint8());
            EXPECT_EQ(*parameter.GetUint8(), 0xA1);
            EXPECT_FALSE(parameter.GetUint16());
            EXPECT_FALSE(parameter.GetUint32());
            EXPECT_FALSE(parameter.GetUint64());
            EXPECT_FALSE(parameter.GetFloat());
            EXPECT_FALSE(parameter.GetDouble());
            EXPECT_TRUE(parameter.GetEnum());
            EXPECT_EQ(*parameter.GetEnum(), 0xA1);
            EXPECT_TRUE(parameter.GetBoolean());
            EXPECT_TRUE(*parameter.GetBoolean());
            EXPECT_FALSE(parameter.GetString());
            EXPECT_TRUE(parameter.GetBlob());
            EXPECT_EQ(parameter.GetBlob()->size(), 1);
            EXPECT_EQ(parameter.GetBlob()->at(0), 0xA1);
            EXPECT_FALSE(parameter.GetNone());
            EXPECT_TRUE(parameter.GetGroup().empty());
        }
    }
}
