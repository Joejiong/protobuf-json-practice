/*************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 ************************************************************************/

/**
 * @file rapidjson_to_pb.h
 * @author zhuchao07
 * @email zhuchao07@baidu.com 
 * @date Thu 16 Apr 2020 12:20:14 PM CST
 * @brief
 **/
#ifndef PUBLIC_PROTOBUF_JSON_RAPIDJSON_TO_PB_H
#define PUBLIC_PROTOBUF_JSON_RAPIDJSON_TO_PB_H
#include <type_traits>

#include "json_to_pb.h"
#include "rapidjson_to_pb_inl.h"

template <typename T, typename Enable = void>
struct is_rapidjson {
    static bool const value = false;
};

template <typename T>
struct is_rapidjson<T,
    typename std::enable_if<
        std::is_same<T, rapidjson::GenericValue<typename T::EncodingType, typename T::AllocatorType> >::value
        || std::is_same<T, rapidjson::GenericDocument<typename T::ValueType::EncodingType, typename T::AllocatorType> >::value>::type> {
    static bool const value = true;
};

// convert 'rapidjson document' to protobuf 'message'
template <typename GenericValue,
          typename = typename std::enable_if<is_rapidjson<GenericValue>::value>::type>
bool JsonToProtoMessage(const GenericValue& json_value,
                        google::protobuf::Message* message,
                        const Json2PbOptions& options,
                        std::string* error = NULL) {
    return protobuf_json::JsonValueToProtoMessage(json_value, message, options, error);
}

template <typename GenericValue,
          typename = typename std::enable_if<is_rapidjson<GenericValue>::value>::type>
bool JsonToProtoMessage(const GenericValue& json_value,
                        google::protobuf::Message* message,
                        std::string* error = NULL) {
    return protobuf_json::JsonValueToProtoMessage(json_value, message, Json2PbOptions(), error);
}

#ifdef J2PERROR
#undef J2PERROR
#endif

#endif
