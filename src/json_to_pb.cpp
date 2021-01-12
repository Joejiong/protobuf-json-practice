// Copyright (c) 2014 baidu-rpc authors.

#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <sys/time.h>
#include <time.h>
#include <typeinfo>
#include <limits> 

#include "json_to_pb.h"
#include "rapidjson_to_pb_inl.h"

Json2PbOptions::Json2PbOptions()
#ifdef BAIDU_INTERNAL
    : base64_to_bytes(false) {
#else
    : base64_to_bytes(true) {
#endif
}

namespace protobuf_json {
bool ZeroCopyStreamToJson(rapidjson::Document *dest, 
                          google::protobuf::io::ZeroCopyInputStream *stream) {
    ZeroCopyStreamReader stream_reader(stream);
    dest->ParseStream<0, rapidjson::UTF8<> >(stream_reader);
    return !dest->HasParseError();
}
} // namespace protobuf_json

inline bool JsonToProtoMessageInline(const std::string& json_string, 
                        google::protobuf::Message* message,
                        const Json2PbOptions& options,
                        std::string* error) {
    if (error) {
        error->clear();
    }
    rapidjson::Document d;
    d.Parse<0>(json_string.c_str());
    if (d.HasParseError()) {
        J2PERROR(error, "Invalid json format");
        return false;
    }
    return protobuf_json::JsonValueToProtoMessage(d, message, options, error);
}

bool JsonToProtoMessage(const std::string& json_string,
                        google::protobuf::Message* message,
                        const Json2PbOptions& options,
                        std::string* error) {
    return JsonToProtoMessageInline(json_string, message, options, error); 
}

bool JsonToProtoMessage(google::protobuf::io::ZeroCopyInputStream* stream,
                        google::protobuf::Message* message,
                        const Json2PbOptions& options,
                        std::string* error) {
    if (error) {
        error->clear();
    }
    rapidjson::Document d;
    if (!protobuf_json::ZeroCopyStreamToJson(&d, stream)) {
        J2PERROR(error, "Invalid json format");
        return false;
    }
    return protobuf_json::JsonValueToProtoMessage(d, message, options, error);
}

bool JsonToProtoMessage(const std::string& json_string, 
                        google::protobuf::Message* message,
                        std::string* error) {
    return JsonToProtoMessageInline(json_string, message, Json2PbOptions(), error); 
}

// For ABI compatibility with 1.0.0.0
// (https://svn.baidu.com/public/tags/protobuf-json/protobuf-json_1-0-0-0_PD_BL)
// This method should not be exposed in header, otherwise calls to
// JsonToProtoMessage will be ambiguous.
bool JsonToProtoMessage(std::string json_string, 
                        google::protobuf::Message* message,
                        std::string* error) {
    return JsonToProtoMessageInline(json_string, message, Json2PbOptions(), error); 
}

bool JsonToProtoMessage(google::protobuf::io::ZeroCopyInputStream *stream,
                        google::protobuf::Message* message,
                        std::string* error) {
    if (error) {
        error->clear();
    }
    rapidjson::Document d;
    if (!protobuf_json::ZeroCopyStreamToJson(&d, stream)) {
        J2PERROR(error, "Invalid json format");
        return false;
    }
    return protobuf_json::JsonValueToProtoMessage(d, message, Json2PbOptions(), error);
}

#ifdef J2PERROR
#undef J2PERROR
#endif
